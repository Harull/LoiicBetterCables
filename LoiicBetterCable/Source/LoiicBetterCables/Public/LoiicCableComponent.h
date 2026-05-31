// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/MeshComponent.h"
#include "Grammar/PCGGrammarParser.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "Modules/ModuleManager.h"
#include "LoiicCableComponent.generated.h"

class UMaterialInstance;

class FLoiicBetterCablesModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};


USTRUCT(BlueprintType)
/** Struct containing information about a point along the cable */
struct FCableParticle
{
	GENERATED_USTRUCT_BODY()

	FCableParticle()
		: bFree(true)
		, index(0)
		, position(0, 0, 0)
		, oldPosition(0, 0, 0)
		, upVector(0, 0, 0)
		, sceneComponentAttachedTo(nullptr)
		, positionAttachedTo(0, 0, 0)
	{}

	FCableParticle(const FVector& _position, const int _index)
	{
		bFree = true;
		index = _index;
		position = _position;
		oldPosition = position;
	}

	/** If this point is free (simulating) or fixed to something */
	UPROPERTY(BlueprintReadOnly, Category = "Data") bool bFree;
	/** The index in the particle array */
	UPROPERTY(BlueprintReadOnly, Category = "Data") int index;
	/** Current position of point */
	UPROPERTY(BlueprintReadOnly, Category = "Data") FVector position;
	/** Position of point on previous iteration */
	UPROPERTY(BlueprintReadOnly, Category = "Data") FVector oldPosition;
	/** Up vector, between this particle and the previous, or the simulated previous if is the firs of the list*/
	UPROPERTY(BlueprintReadOnly, Category = "Data") FVector upVector;


	// operator== pour comparer l'égalité des clés
	bool operator==(const FCableParticle& _other) const
	{
		return bFree == _other.bFree && index == _other.index && 
			position == _other.position && oldPosition == _other.oldPosition && 
			upVector == _other.upVector;
	}

	TObjectPtr<USceneComponent> sceneComponentAttachedTo;
	FName socketNameAttachedTo;
	FVector positionAttachedTo;
};

FORCEINLINE uint32 GetTypeHash(const FCableParticle& _struct)
{
	return HashCombine(GetTypeHash(_struct.bFree), GetTypeHash(_struct.index),
		GetTypeHash(_struct.position), GetTypeHash(_struct.oldPosition), GetTypeHash(_struct.upVector));
}
USTRUCT(BlueprintType) 
struct FGrammarMesh
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Data") FName tag;

	//UPROPERTY(EditAnywhere) TArray<TObjectPtr<UStaticMesh>> grammarStaticMeshes;
	UPROPERTY(EditAnywhere, Category = "Data") TObjectPtr<UStaticMesh> staticMesh;
	UPROPERTY(EditAnywhere, Category = "Data") TObjectPtr<UMaterialInstance> material;

public:
	//The grammar cost is the number of static meshes contained in the grammar mesh
	//uint32 GetGrammarCost() const { return grammarStaticMeshes.Num(); }
};



UENUM()
enum EImpulseModifier
{
	EImpulseDefault, EImpulseSpreadsTowardStart, EImpulseSpreadsTowardEnd, EImpulseSpreadsAround, ESpreadAll
};

UENUM()
enum ERenderType
{
	Default,
	SplineMeshes,
	StaticMeshes
};

UENUM()
enum ECableConstraintType
{
	EDefaultConstraint,
	ETowardStartConstraint,
	ETowardEndConstraint
};

UENUM()
enum ECollisionType
{
	ECollisionPrecise,
	ECollisionOptimal
};


class FPrimitiveSceneProxy;
class USplineMeshComponent;

UCLASS(Blueprintable, hidecategories = (Collision, Object, Physics, Activation, "Components|Activation"), ClassGroup = (Rendering), meta = (BlueprintSpawnableComponent))
class LOIICBETTERCABLES_API ULoiicCableComponent : public UMeshComponent 
{
	GENERATED_BODY()

protected:

	UFUNCTION(CallInEditor, Category = "Cable") void UpdatePreview();
	
	#pragma region Cable editable settings
	/**
		*	Should we fix the start to something, or leave it free.
		*	If false, component transform is just used for initial location of start of cable
		*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cable")
	bool bAttachStart = true;

	/**
		*	Should we fix the end to something (using AttachEndTo and EndLocation), or leave it free.
		*	If false, AttachEndTo and EndLocation are just used for initial location of end of cable
		*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cable") bool bAttachEnd = true;

	/** Actor or Component that the defines the end position of the cable */
	UPROPERTY(EditAnywhere, Category = "Cable") FComponentReference attachEndTo;

	/* The end scene component attach point, used in game*/
	UPROPERTY() TObjectPtr<USceneComponent> attachEndSceneComponent = nullptr;

	/** Socket name on the AttachEndTo component to attach to */
	UPROPERTY(EditAnywhere, Category = "Cable") FName attachEndToSocketName;

	/** End location of cable, relative to AttachEndTo (or AttachEndToSocketName) if specified, otherwise relative to cable component. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cable", meta = (MakeEditWidget = true)) FVector endLocation = FVector(0, 0, -200);

	/** Length of the cable */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cable", meta = (ClampMin = "1", UIMin = "1", ClampMax = "10000.0", UIMax = "10000.0"))
	float cableLength = 500.f;

	/* If true, the segmentLength will be computed with the numSegment variable, and the length of the cable. 
	If false, the numSegment will be computed with the segmentLength variable, and the length of the cable. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Cable") bool bDefineSubdivisionUsingNumSegment = true;

	/*The number of segment, ie the subdivision of the cable*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Cable", meta = (ClampMin = "2", UIMin = "2", EditCondition = "bDefineSubdivisionUsingNumSegment"))
	int32 numSegment = 30;

	/** The length of a segment*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Cable", meta = (ClampMin = 0.1, UIMin = 0.1, EditCondition = "!bDefineSubdivisionUsingNumSegment"))
	float segmentLength = 20;

	/** The number of solver iterations controls how 'stiff' the cable is */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cable", meta = (UIMin = "1", UIMax = "50", ClampMin = "1", ClampMax = "50"))
	int32 numOfConstraintRuns = 50;

	/*The way the apply constraint works, between the particles of the rope*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cable") TEnumAsByte<ECableConstraintType> constraintType;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cable", meta = (UIMin = "0", UIMax = "1", ClampMin = "0", ClampMax = "1"))
	float dampingFactor = 0.998;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cable")
	bool bShowParticleDebug = false;

	/*Determine the fps of the simulated cable*/
	UPROPERTY(EditAnywhere, AdvancedDisplay, BlueprintReadOnly, Category = "Cable", meta = (ClampMin = "10", UIMin = "10", UIMax = "200"))
	int32 simulationFramePerSeconds = 60;

	/** Controls the simulation substep time for the cable */
	UPROPERTY(VisibleAnywhere, AdvancedDisplay, BlueprintReadOnly, Category = "Cable", meta = (ClampMin = "0.005", UIMin = "0.005", UIMax = "0.1"))
	float substepTime;

	/** Should you limit the movement of the rope on to a 2D plane.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category = "Cable")
	bool bLimitMovementOnToOnePlane = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category = "Cable", meta = (EditCondition = "bLimitMovementOnToOnePlane"))
	bool bShowPlaneDebug = true;
	
	/** The forward vector of the plane you want to limit. The up vector will be taken along the Z axis automatically, meaning the plane is necessarely vertical*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category = "Cable", meta=(EditCondition = "bLimitMovementOnToOnePlane"))
	
	FVector forwardOfTheLimitPlane = FVector::ForwardVector;

#pragma endregion

protected:
	#pragma region Collision related

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cable|Custom Collision")
	bool bEnableCollision = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cable|Custom Collision")
	bool bGenerateCustomOverlapEvents = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cable|Custom Collision", 
		meta = (EditCondition = "bGenerateCustomOverlapEvents", UIMin = .1, ClampMin = .1))
	float overlapExtraExtent = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cable|Custom Collision", meta = (ClampMin = "0.01", UIMin = "0.01"))
	float cableWidthForCollisions = cableWidth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cable|Custom Collision", meta = (ClampMin = "0", UIMin = "0"))
	float bounceFactor = .1f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cable|Custom Collision", meta = (ClampMin = "0", UIMin = "0"))
	float correctionClampAmount = .1f;

	/* Determines the collision handling method calls frequency, precise cost a lot, and is mainly used for when the cable moves because of constraints. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cable|Custom Collision") TEnumAsByte<ECollisionType> collisionType = ECollisionType::ECollisionOptimal;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cable|Custom Collision") FName collisionProfile = "BlockAllDynamic";

	/*Actors to ignore during collision check*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cable|Custom Collision") TArray<TObjectPtr<AActor>> actorsToIgnoreDuringCollision;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBeginOverlap, AActor*, _overlappingActor, const FCableParticle&, _particleHit);
	FOnBeginOverlap onBeginOverlap;
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEndOverlap, AActor*, _endOverlappingActor);
	FOnEndOverlap onEndOverlap;


	#pragma endregion

protected:
	#pragma region Cable optimisation
	
	//should skip the cable update when the cable is not visible ? 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cable|Optimisation ") bool bSkipCableUpdateWhenNotVisible = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cable|Optimisation ") bool bDebugOptimisation = false;
	//if the average particle velocity is lower than this variable for variable_name amount of seconds,
	//the cable goes in "sleep" state, and is no longer physically updated
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cable|Optimisation ", meta = (UIMin = 0, ClampMin = 0)) float minVelocityBeforeSleep = 0.15;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cable|Optimisation", meta = (UIMin = 0, ClampMin = 0, Units = "s")) float timeInSecondsBeforeSleep = 1;
	
	#pragma endregion

protected:
	#pragma region Rendering


	/*Let's you chose how you want the cable to be rendered*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Cable|Rendering") TEnumAsByte<ERenderType> renderType = Default;

	/////////////////////////////////////////////////////////////////////// First render type: default
	
	/** Number of sides of the cable geometry */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Cable|Rendering", meta = (ClampMin = "1", ClampMax = "16", EditCondition = "renderType == ERenderType::Default", EditConditionHides))
	int32 numSides = 4;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cable|Rendering", meta = (ClampMin = "0.01", UIMin = "0.01", UIMax = "50.0", EditCondition = "renderType == ERenderType::Default", EditConditionHides))
	float cableWidth = 10.f;

	/** How many times to repeat the material along the length of the cable */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cable|Rendering", meta = (UIMin = "0.1", UIMax = "8", EditCondition = "renderType == ERenderType::Default", EditConditionHides))
	float tileMaterial = 1.f;

	/////////////////////////////////////////////////////////////////////// Second and third render type: custom meshes (spline meshes and static meshes)



	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cable|Rendering", meta = (EditCondition = "renderType != ERenderType::Default", EditConditionHides))
	TArray<FGrammarMesh> grammarMeshes;

	/*Should you be using grammar in order to populate the cable, if false will use the first mesh found in the array of grammar above*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cable|Rendering", meta = (EditCondition = "renderType != ERenderType::Default", EditConditionHides))
	bool bUsesGrammar = false;

	/*The input grammar, use this in order to populate your cable with meshes follwing a logic*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cable|Rendering", meta = (MultiLine, EditCondition = "renderType != ERenderType::Default && bUsesGrammar", EditConditionHides))
	FName grammar;


	UPROPERTY(BlueprintReadWrite, Category = "Cable|Rendering") TArray<TObjectPtr<UStaticMeshComponent>> createdMeshes;

	#pragma endregion

protected:
	#pragma region UsefullInternalData

	//The length of the cable before play (the base cable length)
	float memoryCableLength;

	// tmap, int corresponds to the index of the particle that got add impulsed, FVector is the impulse vector
	TMap<int, FVector> impulseParticleBuffer;

	//all the particles of the cable
	TArray<FCableParticle> particles;

	//Start position of the cable
	FVector startPos;
	FVector endPos;

	//All the actors that are currently overlapping this component
	TArray<TObjectPtr<AActor>> overlappingActors;

	//The last average velocity of this cable
	float lastAverageVelocityComputed = 1;

	//Is sleeping = is the cable deactivated by the optimisation setup
	bool bIsSleeping = false;
	//if this variable hits 0, go in sleep state
	float currentTimeBeforeSleep = timeInSecondsBeforeSleep;

	//Amount of time 'left over' from last tick
	float timeRemainder;

	//Should be canceling velocities on the next physic update ? 
	bool bCancelVelocities = false;

#pragma endregion

public:
	ULoiicCableComponent();

public:

	#pragma region UActorComponent_Interface.
	virtual void SendRenderDynamicData_Concurrent() override;
	virtual void CreateRenderState_Concurrent(FRegisterComponentContext* Context) override;
	virtual void ApplyWorldOffset(const FVector& InOffset, bool bWorldShift) override;
#pragma endregion

	#pragma region USceneComponent_Interface
	virtual FBoxSphereBounds CalcBounds(const FTransform& LocalToWorld) const override;
#pragma endregion

	#pragma region UPrimitiveComponent_Interface
	virtual FPrimitiveSceneProxy* CreateSceneProxy() override;
	#pragma endregion

	#pragma region UMeshComponent_Interface
	virtual int32 GetNumMaterials() const override;
#pragma endregion

	

public:
	#pragma region Getters

	FORCEINLINE float GetCableLength()const { return cableLength;}
	FORCEINLINE float GetSegmentLength()const { return segmentLength; }
	FORCEINLINE int32 GetParticleCount()const { return numSegment;}
	FORCEINLINE TArray<TObjectPtr<AActor>>& GetActorsToIgnoreDuringCollision() { return actorsToIgnoreDuringCollision; }
	UFUNCTION(BlueprintCallable, Category = "Cable|Utility") float GetLastAverageVelocityComputed() const;
	FORCEINLINE float GetDampingFactor() const {return dampingFactor; }
	FORCEINLINE FVector GetForwardOfTheLimitedPlane(const bool _inWorldSpace = true) const 
	{
		return _inWorldSpace ? UKismetMathLibrary::Quat_RotateVector(GetComponentQuat(), forwardOfTheLimitPlane) : forwardOfTheLimitPlane;
	}
	FORCEINLINE bool GetBLimitMovementOnToOnePlane() const { return bLimitMovementOnToOnePlane; }
	#pragma endregion

	#pragma region Event Getters

	FORCEINLINE FOnBeginOverlap& OnBeginOverlap() { return onBeginOverlap;}
	FORCEINLINE FOnEndOverlap& OnEndOverlap() { return onEndOverlap; }
	#pragma endregion

	#pragma region Setters

	FORCEINLINE void SetAttachStart(const bool _bAttachStart) { bAttachStart = _bAttachStart; }
	FORCEINLINE void SetAttachEnd(const bool _bAttachEnd) { bAttachEnd = _bAttachEnd; }
	FORCEINLINE void SetAttachEndTo(const FComponentReference& _attachEndTo) { attachEndTo = _attachEndTo; }
	FORCEINLINE void SetAttachEndTo(const FName& _attachEndTo) { attachEndToSocketName = _attachEndTo; }
	FORCEINLINE void SetAttachEndTo(TObjectPtr<USceneComponent> _attachEndTo) { attachEndSceneComponent = _attachEndTo; }
	FORCEINLINE void SetCableLength(const float _newLength)	
	{ 
		cableLength = FMath::Max(1,_newLength); 
		//InitSegmentLength();
	}
	FORCEINLINE void SetEnableCollisions(const bool _enableCollision) { bEnableCollision = _enableCollision; }
	FORCEINLINE void SetActorsToIgnoreDuringCollision(const TArray<TObjectPtr<AActor>>& _actorsToIgnore) { actorsToIgnoreDuringCollision = _actorsToIgnore; }
	FORCEINLINE void SetEndLocation(const FVector& _newEndLocation) { endLocation = _newEndLocation; }
	FORCEINLINE void SetDampingFactor(const float& _dampingFactor) { dampingFactor = _dampingFactor; }
	FORCEINLINE void SetBLimitMovementOnToOnePlane(const bool _boolean) { bLimitMovementOnToOnePlane = _boolean; }
	FORCEINLINE void SetForwardOfTheLimitPlane(const FVector& _newForward) { forwardOfTheLimitPlane = _newForward; }
#pragma endregion


	//Wakes the rope physics
	FORCEINLINE void Wake() { 
		bIsSleeping = false;
		currentTimeBeforeSleep = timeInSecondsBeforeSleep;
	}
	//Sleeps the rope physics
	FORCEINLINE void Sleep() { bIsSleeping = true; }

protected:
	//virtual void BeginPlay() override;
	virtual void OnRegister() override;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void PerformSubstep(const float _substepTime);
	void RopePhysicsRelated(const float _deltaTime);


private:
	void InitAll();
	void InitSegmentLength();
	void AssignSegmentLength();
	void InitParticleArray();
	void InitStartAndEndPosition();

private: 
	/////////////////	Everything below is related to the ERenderType::CustomMeshes.
	void InitMeshes();
	void InitMeshesWithoutGrammar();
	//Create a 
	void CreateNewStaticMeshComponent(TObjectPtr<UStaticMesh>& _firstMeshFound, TObjectPtr<UMaterialInstance> _materialInstance = nullptr);
	void InitMeshesUsingGrammar();

	void ClearMeshes();
	void UpdateMeshesPositions();

	/////////////////	Everything related to grammar
	FString DevelopGrammar(const FString& _inGrammar);
	

	/// <summary>
	/// Returns by reference the number of infinite repetable module, and number of literal module.
	/// </summary>
	void GetInfoModule(const PCGGrammar::FModuleDescriptor& _module, int& _infiniteRepetableModuleCount, int& _literalModuleCount);


	/// <summary>
	/// Recursive function that create a final string used to apply the grammar.
	/// Meant to transform [a,b]2 into "a,b,a,b," for example 
	/// </summary>
	/// <param name="_module"></param>
	/// <returns></returns>
	FString TranslateModule(const PCGGrammar::FModuleDescriptor& _module, int32& _costAvailable, const int _infiniteRepetableModuleCount, const int _literalModuleCount);


	/// <summary>
	/// Apply the grammar means convert the FString input parameter, into created meshes that are put along the cable
	/// </summary>
	/// <param name="_developpedGrammar">The grammar given, but exetented to a final and easy grammar to follow, example: A,B,A,B,B. Use DevelopGrammar method beforehand </param>
	void ApplyGrammar(const FString& _developpedGrammar);

	/// <summary>
	/// Search in the grammarMeshes array, for the mesh FGrammarMesh corresponding to the tag as string
	/// </summary>
	/// <returns></returns>
	FGrammarMesh GetCorrespondingGrammarMesh(const FString& _tagAsString);

private:
	void UpdateStartAndEndPosition();
	void UpdateAttachedParticlesPosition();
	void UpdateUpVectors();
	void UpdateToSleepTransition();
	FVector GetStartPosition()const;
	FVector GetEndPosition();
	/// <summary>
	/// Limits the input vector to the plane of the forward vector "forwardOfTheLimitPlane" and the up vector "FVector::Up", if bLimitMovementOnToOnePlane is true
	/// </summary>
	FVector TryAndLimitVectorOnToSelectedPlane(const FVector& _vector);

private:
	bool CheckCableLengthChanged();
	void OnCableLengthChanged();

public:
	#pragma region Utility/Maths method

	/// <summary>
	/// Returns the number of particles/segments of the rope
	/// </summary>
	UFUNCTION(BlueprintCallable, Category = "Cable|Utility") int32 GetParticlesCount() const;
	/// <summary>
	/// Returns the cable particle array
	/// </summary>
	UFUNCTION(BlueprintCallable, Category = "Cable|Utility") TArray<FCableParticle>& GetCableParticles();
	UFUNCTION(BlueprintCallable, Category = "Cable|Utility") FCableParticle& GetCableParticle(const int _index);

	/// <summary>
	/// Get the position of a point on the rope, relative to the length given.
	/// </summary>
	/// <param name="_length">Input length</param>
	/// <returns>Position</returns>
	UFUNCTION(BlueprintCallable, Category = "Cable|Utility") FVector GetPositionAtLength(const float _length);

	/// <summary>
	/// Gets the length from the start point of the rope, 
	/// to the corresponding point on the rope at the given float index.
	/// The integer part of the float is the index of the particle/segment, and the decimal part is 
	/// the position in between the indexed particle/segment, and the next one. 
	/// </summary>
	/// <param name="_floatIndex">Float index</param>
	/// <returns>Length</returns>
	UFUNCTION(BlueprintCallable, Category = "Cable|Utility") float GetLengthAtIndex(const float _floatIndex);
	/// <summary>
	/// Gets the length from the start point of the rope, 
	/// to the corresponding point on the rope at the given _position.
	/// This methods gives an approximate result, use float index for precise result
	/// </summary>
	/// <param name="_position">Position along the rope</param>
	/// <returns>Length</returns>
	UFUNCTION(BlueprintCallable, Category = "Cable|Utility") float GetLengthAtPosition(const FVector& _position);

	/// <summary>
	/// Get the position of a point on the rope, based on a float index.
	/// The integer part of the float is the index of the particle/segment, and the decimal part is 
	/// the position in between the indexed particle/segment, and the next one. 
	/// Giving index 1.5 will return the point in between the first and the second particle/segment.
	/// </summary>
	/// <param name="_floatIndex">Float index</param>
	/// <returns>Position</returns>
	UFUNCTION(BlueprintCallable, Category = "Cable|Utility") FVector GetPositionAtIndex(const float _floatIndex);

	/// <summary>
	/// This method returns the closest particle to a given location. 
	/// A Particle is technically a segment's position.
	/// </summary>
	/// <param name="_location">Location in world space</param>
	/// <returns>Particle data struct</returns>
	UFUNCTION(BlueprintCallable, Category = "Cable|Utility") FCableParticle GetClosestParticleData(const FVector& _location);
	/// <summary>
	/// This method returns the closest particle to a given scene component. 
	/// A Particle is technically a segment's position.
	/// </summary>
	/// <returns>Particle data struct</returns>
	UFUNCTION(BlueprintCallable, Category = "Cable|Utility") FCableParticle GetClosestParticleDataFromSceneComponent(USceneComponent* _sceneComponent);
	/// <summary>
	/// This method returns the closest particle to a given actor. 
	/// A Particle is technically a segment's position.
	/// </summary>
	/// <returns>Particle data struct</returns>
	UFUNCTION(BlueprintCallable, Category = "Cable|Utility") FCableParticle GetClosestParticleDataFromActor(AActor* _actor);

	/// <summary>
	/// Returns the closest position along the rope, i.e it's not necessarely a particle/segment.
	/// It can be in between.
	/// </summary>
	/// <param name="_location">Location in world space</param>
	/// <returns>Closest Position</returns>
	UFUNCTION(BlueprintCallable, Category = "Cable|Utility") FVector GetClosestPositionAlongRope(const FVector& _location);
	/// <summary>
	/// Returns the closest position along the rope, i.e it's not necessarely a particle/segment.
	/// It can be in between.
	/// </summary>
	/// <param name="_actor">Actor</param>
	/// <returns>Closest Position</returns>
	UFUNCTION(BlueprintCallable, Category = "Cable|Utility") FVector GetClosestPositionAlongRopeFromActor(AActor* _actor);
	/// <summary>
	/// Returns the closest position along the rope, i.e it's not necessarely a particle/segment.
	/// It can be in between.
	/// </summary>
	/// <param name="_sceneComponent">Scene Component</param>
	/// <returns>Closest Position</returns>
	UFUNCTION(BlueprintCallable, Category = "Cable|Utility") FVector GetClosestPositionAlongRopeFromSceneComponent(USceneComponent* _sceneComponent);
	#pragma endregion

private:
	/// <summary>
	/// Compare the distance between the location given, and the neighbor of the index of the particle given.
	/// Returns between the neighbor of the indexed particle, the closest to the location parameter.
	/// </summary>
	FCableParticle GetClosestNeighborParticle(const int _indexOfParticle, const FVector& _location);

public:
	/// <summary>
	/// Attach a particle to a position, freezing the particle, meaning it is no longer affected by gravity.
	/// </summary>
	UFUNCTION(BlueprintCallable, Category = "Cable|Utility") void AttachParticleAtPosition(const FCableParticle& _particleToAttach, const FVector& _position);
	/// <summary>
	/// Attach a particle to a position using the index of the particle, freezing the particle, meaning it is no longer affected by gravity.
	/// </summary>
	UFUNCTION(BlueprintCallable, Category = "Cable|Utility") void AttachParticleIndexAtPosition(const int _indexOfParticleToAttach, const FVector& _position);

	/// <summary>
	/// Attach a particle to a scene component, freezing the particle, meaning it is no longer affected by gravity.
	/// It will follow the scene component.
	/// </summary>
	UFUNCTION(BlueprintCallable, Category = "Cable|Utility", meta = (AutoCreateRefTerm = "_optionnalSocket")) void AttachParticleToSceneComponent(const FCableParticle& _particleToAttach, USceneComponent* _sceneComponent, const FName& _optionnalSocket = NAME_None);
	/// <summary>
	/// Attach a particle to a scene component using the index of the particle, freezing the particle, meaning it is no longer affected by gravity.
	/// It will follow the scene component.
	/// </summary>
	UFUNCTION(BlueprintCallable, Category = "Cable|Utility", meta = (AutoCreateRefTerm = "_optionnalSocket")) void AttachParticleIndexToSceneComponent(const int _particleIndexToAttach, USceneComponent* _sceneComponent, const FName& _optionnalSocket = NAME_None);

	/// <summary>
	/// Detaching a particle, meaning it's not longer frozen, and is now affected by gravity and constraints.
	/// This methods does nothing if the particle is already free.
	/// </summary>
	UFUNCTION(BlueprintCallable, Category = "Cable|Utility") void DetachParticle(const FCableParticle& _particleToDetach);
	/// <summary>
	/// Detaching a particle using the particle's index, meaning it's not longer frozen, and is now affected by gravity and constraints.
	/// This methods does nothing if the particle is already free.
	/// </summary>
	UFUNCTION(BlueprintCallable, Category = "Cable|Utility") void DetachParticleIndex(const int _particleIndexToDetach);

	/// <summary>
	/// Returns in an array all the particles that are attached to something.
	/// </summary>
	/// <param name="_includesStartAndEnd">Should return the start and end particle if they are attached ? </param>
	UFUNCTION(BlueprintCallable, Category = "Cable|Utility") TArray<FCableParticle> GetAttachedParticles(const bool _includesStartAndEnd = false);

	/// <summary>
	/// Add an inpulse at a particle. 
	/// If the particle is attached, this will have no effect.
	/// </summary>
	UFUNCTION(BlueprintCallable, Category = "Cable|Utility", meta = (AutoCreateRefTerm = "_impulse")) void AddImpulseAtParticle(const FCableParticle& _particleToInpulse, const FVector& _vector, const EImpulseModifier& _impulse = EImpulseDefault);
	/// <summary>
	/// Add an inpulse at a particle using it's index. 
	/// If the particle is attached, this will have no effect.
	/// </summary>
	UFUNCTION(BlueprintCallable, Category = "Cable|Utility", meta = (AutoCreateRefTerm = "_impulse")) void AddImpulseAtParticleIndex(const int _particleIndexToInpulse, const FVector& _vector, const EImpulseModifier& _impulse = EImpulseDefault);

	/// <summary>
	/// This function will cancel all the velocity accumulated when called
	/// </summary>
	UFUNCTION(BlueprintCallable, Category = "Cable|Utility") void StopAllVelocities();

	/// <summary>
	/// Method from where you can re initialize the cable
	/// </summary>
	UFUNCTION(BlueprintCallable, Category = "Cable|Utility") void ResetCable();
private:
	void AddOrCreateVectorToImpulseBuffer(const int _particleIndexToInpulse, const FVector& _vector);

	/// <summary>
	/// Apply all the "add impulse" stored. Consumes the impulses.
	/// </summary>
	void ApplyImpulseBuffers();

private:
	/// <summary>
	/// Simulate physics
	/// </summary>
	void Simulate(const float _substepTime);

	/// <summary>
	/// Apply rope constraint on each segments
	/// </summary>
	void ApplyConstraints();


	void HandleCollisions();

	//This should be more optimized but less precise colision testing
	void HandleCollisionsV2();
	bool CheckCollisionRecurs(const TArray<FCableParticle>& _arrayOfParticle, TMap<FCableParticle, TArray<FHitResult>>& _outHitResult);
	bool CheckCollisionRecursV2(int32 _startIndex, int32 _endIndex, TMap<int32, TArray<FHitResult>>& _outHitResult);

	void HandleOverlaps();

	/// <summary>
	/// Renders the rope
	/// </summary>
	void Render();

	/// <summary>
	/// Debugs the rope
	/// </summary>
	void DrawDebug();

	void DrawPlaneDebug();

	void DrawParticleDebug();

	friend class FLoiicCableSceneProxy;
};
