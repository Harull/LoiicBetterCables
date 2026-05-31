// Fill out your copyright notice in the Description page of Project Settings.


// Fill out your copyright notice in the Description page of Project Settings.

//source https://www.youtube.com/watch?v=bxG3XP4MVzk
#include "LoiicCableComponent.h"
#include "CoreMinimal.h"
#include "Materials/MaterialInstance.h"
#include "Engine/World.h"
#include "Engine/Engine.h"
#include "Runtime/Engine/Public/EngineGlobals.h"

#include "PrimitiveSceneProxy.h"
#include "Materials/MaterialRenderProxy.h"
#include "DynamicMeshBuilder.h"
#include "MaterialDomain.h"

#include <Kismet/KismetSystemLibrary.h>
#include <Kismet/KismetMathLibrary.h>
#include <Components/SplineMeshComponent.h>
#include <Components/SkeletalMeshComponent.h>

#include "Rendering/StaticMeshVertexBuffer.h"
#include "LocalVertexFactory.h"
#include "Materials/Material.h"
#include "StaticMeshResources.h"
#include "SceneInterface.h"
#include "SceneView.h"


IMPLEMENT_MODULE(FLoiicBetterCablesModule, LoiicBetterCables)
DEFINE_RENDER_COMMAND_PIPE(LoiicCable, ERenderCommandPipeFlags::None);


//////////////////////////////////////////////////////////////////////////

/** Index Buffer */
class FCableIndexBuffer : public FIndexBuffer
{
public:
	virtual void InitRHI(FRHICommandListBase& RHICmdList) override
	{
		FRHIResourceCreateInfo CreateInfo(TEXT("FCableIndexBuffer"));
		IndexBufferRHI = RHICmdList.CreateIndexBuffer(sizeof(int32), NumIndices * sizeof(int32), BUF_Dynamic, CreateInfo);
	}

	int32 NumIndices;
};

/** Dynamic data sent to render thread */
struct FCableDynamicData
{
	/** Array of points */
	TArray<FVector> CablePoints;
};

//////////////////////////////////////////////////////////////////////////
// FLoiicCableSceneProxy

class FLoiicCableSceneProxy final : public FPrimitiveSceneProxy
{

private:

	UMaterialInterface* material;
	FStaticMeshVertexBuffers vertexBuffers;
	FCableIndexBuffer indexBuffer;
	FLocalVertexFactory vertexFactory;

	FMaterialRelevance materialRelevance;

	int32 numSegments;

	float cableWidth;

	int32 numSides;

	float tileMaterial;

public:
	SIZE_T GetTypeHash() const override
	{
		static size_t UniquePointer;
		return reinterpret_cast<size_t>(&UniquePointer);
	}

	FLoiicCableSceneProxy(ULoiicCableComponent* _component)
		: FPrimitiveSceneProxy(_component)
		, material(NULL)
		, vertexFactory(GetScene().GetFeatureLevel(), "FLoiicCableSceneProxy")
		, materialRelevance(_component->GetMaterialRelevance(GetScene().GetFeatureLevel()))
		, numSegments(_component->numSegment)
		, cableWidth(_component->cableWidth)
		, numSides(_component->numSides)
		, tileMaterial(_component->tileMaterial)
	{
		vertexBuffers.InitWithDummyData(&UE::RenderCommandPipe::LoiicCable, &vertexFactory, GetRequiredVertexCount());

		indexBuffer.NumIndices = GetRequiredIndexCount();

		// Grab material
		material = _component->GetMaterial(0);
		if (material == NULL)
		{
			material = UMaterial::GetDefaultMaterial(MD_Surface);
		}


		ENQUEUE_RENDER_COMMAND(InitCableResources)(UE::RenderCommandPipe::LoiicCable,
			[this](FRHICommandList& RHICmdList)
			{
				indexBuffer.InitResource(RHICmdList);

			});
	}

	virtual ~FLoiicCableSceneProxy()
	{
		vertexBuffers.PositionVertexBuffer.ReleaseResource();
		vertexBuffers.StaticMeshVertexBuffer.ReleaseResource();
		vertexBuffers.ColorVertexBuffer.ReleaseResource();
		indexBuffer.ReleaseResource();
		vertexFactory.ReleaseResource();
	}

	int32 GetRequiredVertexCount() const
	{
		return (numSegments) * (numSides + 1);
	}

	int32 GetRequiredIndexCount() const
	{
		return ((numSegments - 1) * numSides * 2) * 3;
	}

	int32 GetVertIndex(int32 AlongIdx, int32 AroundIdx) const
	{
		return (AlongIdx * (numSides + 1)) + AroundIdx;
	}

	void BuildCableMesh(const TArray<FVector>& InPoints, TArray<FDynamicMeshVertex>& OutVertices, TArray<int32>& OutIndices)
	{
		const FColor VertexColor(255, 255, 255);
		const int32 NumPoints = InPoints.Num();
		const int32 SegmentCount = NumPoints - 1;

		// Build vertices

		// We double up the first and last vert of the ring, because the UVs are different
		int32 NumRingVerts = numSides + 1;

		// For each point along spline..
		for (int32 PointIdx = 0; PointIdx < NumPoints; PointIdx++)
		{
			const float AlongFrac = (float)PointIdx / (float)SegmentCount; // Distance along cable

			// Find direction of cable at this point, by averaging previous and next points
			const int32 PrevIndex = FMath::Max(0, PointIdx - 1);
			const int32 NextIndex = FMath::Min(PointIdx + 1, NumPoints - 1);
			const FVector ForwardDir = (InPoints[NextIndex] - InPoints[PrevIndex]).GetSafeNormal();

			// Find quat from up (Z) vector to forward
			const FQuat DeltaQuat = FQuat::FindBetween(FVector(0, 0, -1), ForwardDir);

			// Apply quat orth vectors
			const FVector RightDir = DeltaQuat.RotateVector(FVector(0, 1, 0));
			const FVector UpDir = DeltaQuat.RotateVector(FVector(1, 0, 0));

			// Generate a ring of verts
			for (int32 VertIdx = 0; VertIdx < NumRingVerts; VertIdx++)
			{
				const float AroundFrac = float(VertIdx) / float(numSides);
				// Find angle around the ring
				const float RadAngle = 2.f * PI * AroundFrac;
				// Find direction from center of cable to this vertex
				const FVector OutDir = (FMath::Cos(RadAngle) * UpDir) + (FMath::Sin(RadAngle) * RightDir);

				FDynamicMeshVertex Vert;
				Vert.Position = FVector3f(InPoints[PointIdx] + (OutDir * 0.5f * cableWidth));
				Vert.TextureCoordinate[0] = FVector2f(AlongFrac * tileMaterial, AroundFrac);
				Vert.Color = VertexColor;
				Vert.SetTangents((FVector3f)ForwardDir, FVector3f(OutDir ^ ForwardDir), (FVector3f)OutDir);
				OutVertices.Add(Vert);
			}
		}

		// Build triangles
		for (int32 SegIdx = 0; SegIdx < SegmentCount; SegIdx++)
		{
			for (int32 SideIdx = 0; SideIdx < numSides; SideIdx++)
			{
				int32 TL = GetVertIndex(SegIdx, SideIdx);
				int32 BL = GetVertIndex(SegIdx, SideIdx + 1);
				int32 TR = GetVertIndex(SegIdx + 1, SideIdx);
				int32 BR = GetVertIndex(SegIdx + 1, SideIdx + 1);

				OutIndices.Add(TL);
				OutIndices.Add(BL);
				OutIndices.Add(TR);

				OutIndices.Add(TR);
				OutIndices.Add(BL);
				OutIndices.Add(BR);
			}
		}
	}

	/** Called on render thread to assign new dynamic data */
	void SetDynamicData_RenderThread(FRHICommandListBase& RHICmdList, FCableDynamicData* NewDynamicData)
	{
		if (NewDynamicData != nullptr)
		{
			// Build mesh from cable points
			TArray<FDynamicMeshVertex> _vertices;
			TArray<int32> _indices;
			BuildCableMesh(NewDynamicData->CablePoints, _vertices, _indices);

			check(_vertices.Num() == GetRequiredVertexCount());
			check(_indices.Num() == GetRequiredIndexCount());

			for (int i = 0; i < _vertices.Num(); i++)
			{
				const FDynamicMeshVertex& _vertex = _vertices[i];

				vertexBuffers.PositionVertexBuffer.VertexPosition(i) = _vertex.Position;
				vertexBuffers.StaticMeshVertexBuffer.SetVertexTangents(i, _vertex.TangentX.ToFVector3f(), _vertex.GetTangentY(), _vertex.TangentZ.ToFVector3f());
				vertexBuffers.StaticMeshVertexBuffer.SetVertexUV(i, 0, _vertex.TextureCoordinate[0]);
				vertexBuffers.ColorVertexBuffer.VertexColor(i) = _vertex.Color;
			}

			{
				auto& _vertexBuffer = vertexBuffers.PositionVertexBuffer;
				void* _vertexBufferData = RHICmdList.LockBuffer(_vertexBuffer.VertexBufferRHI, 0, _vertexBuffer.GetNumVertices() * _vertexBuffer.GetStride(), RLM_WriteOnly);
				FMemory::Memcpy(_vertexBufferData, _vertexBuffer.GetVertexData(), _vertexBuffer.GetNumVertices() * _vertexBuffer.GetStride());
				RHICmdList.UnlockBuffer(_vertexBuffer.VertexBufferRHI);
			}

			{
				auto& _vertexBuffer = vertexBuffers.ColorVertexBuffer;
				void* _vertexBufferData = RHICmdList.LockBuffer(_vertexBuffer.VertexBufferRHI, 0, _vertexBuffer.GetNumVertices() * _vertexBuffer.GetStride(), RLM_WriteOnly);
				FMemory::Memcpy(_vertexBufferData, _vertexBuffer.GetVertexData(), _vertexBuffer.GetNumVertices() * _vertexBuffer.GetStride());
				RHICmdList.UnlockBuffer(_vertexBuffer.VertexBufferRHI);
			}

			{
				auto& _vertexBuffer = vertexBuffers.StaticMeshVertexBuffer;
				void* _vertexBufferData = RHICmdList.LockBuffer(_vertexBuffer.TangentsVertexBuffer.VertexBufferRHI, 0, _vertexBuffer.GetTangentSize(), RLM_WriteOnly);
				FMemory::Memcpy(_vertexBufferData, _vertexBuffer.GetTangentData(), _vertexBuffer.GetTangentSize());
				RHICmdList.UnlockBuffer(_vertexBuffer.TangentsVertexBuffer.VertexBufferRHI);
			}

			{
				auto& _vertexBuffer = vertexBuffers.StaticMeshVertexBuffer;
				void* _vertexBufferData = RHICmdList.LockBuffer(_vertexBuffer.TexCoordVertexBuffer.VertexBufferRHI, 0, _vertexBuffer.GetTexCoordSize(), RLM_WriteOnly);
				FMemory::Memcpy(_vertexBufferData, _vertexBuffer.GetTexCoordData(), _vertexBuffer.GetTexCoordSize());
				RHICmdList.UnlockBuffer(_vertexBuffer.TexCoordVertexBuffer.VertexBufferRHI);
			}

			void* _indexBufferData = RHICmdList.LockBuffer(indexBuffer.IndexBufferRHI, 0, _indices.Num() * sizeof(int32), RLM_WriteOnly);
			FMemory::Memcpy(_indexBufferData, &_indices[0], _indices.Num() * sizeof(int32));
			RHICmdList.UnlockBuffer(indexBuffer.IndexBufferRHI);

			delete NewDynamicData;
			NewDynamicData = NULL;
		}
	}

	virtual void DrawStaticElements(FStaticPrimitiveDrawInterface* PDI) override
	{
		checkSlow(IsInParallelRenderingThread());
		if (!HasViewDependentDPG())
		{
			FMeshBatch _mesh;
			_mesh.VertexFactory = &vertexFactory;
			_mesh.MaterialRenderProxy = material->GetRenderProxy();
			_mesh.ReverseCulling = IsLocalToWorldDeterminantNegative();
			_mesh.Type = PT_TriangleList;
			_mesh.DepthPriorityGroup = SDPG_World;
			_mesh.MeshIdInPrimitive = 0;
			_mesh.LODIndex = 0;
			_mesh.SegmentIndex = 0;

			FMeshBatchElement& _batchElement = _mesh.Elements[0];
			_batchElement.IndexBuffer = &indexBuffer;
			_batchElement.FirstIndex = 0;
			_batchElement.NumPrimitives = GetRequiredIndexCount() / 3;
			_batchElement.MinVertexIndex = 0;
			_batchElement.MaxVertexIndex = GetRequiredVertexCount();

			PDI->DrawMesh(_mesh, FLT_MAX);
		}
	}

	virtual void GetDynamicMeshElements(const TArray<const FSceneView*>& Views, const FSceneViewFamily& ViewFamily, uint32 VisibilityMap, FMeshElementCollector& Collector) const override
	{
		QUICK_SCOPE_CYCLE_COUNTER(STAT_CableSceneProxy_GetDynamicMeshElements);

		const bool _bWireframe = AllowDebugViewmodes() && ViewFamily.EngineShowFlags.Wireframe;

		auto _wireframeMaterialInstance = new FColoredMaterialRenderProxy(
			GEngine->WireframeMaterial ? GEngine->WireframeMaterial->GetRenderProxy() : NULL,
			FLinearColor(0, 0.5f, 1.f)
		);

		Collector.RegisterOneFrameMaterialProxy(_wireframeMaterialInstance);

		FMaterialRenderProxy* _materialProxy = NULL;
		if (_bWireframe)
		{
			_materialProxy = _wireframeMaterialInstance;
		}
		else
		{
			_materialProxy = material->GetRenderProxy();
		}

		for (int32 _viewIndex = 0; _viewIndex < Views.Num(); _viewIndex++)
		{
			if (VisibilityMap & (1 << _viewIndex))
			{
				const FSceneView* View = Views[_viewIndex];
				// Draw the mesh.
				FMeshBatch& _mesh = Collector.AllocateMesh();
				FMeshBatchElement& _batchElement = _mesh.Elements[0];
				_batchElement.IndexBuffer = &indexBuffer;
				_mesh.bWireframe = _bWireframe;
				_mesh.VertexFactory = &vertexFactory;
				_mesh.MaterialRenderProxy = _materialProxy;

				bool _hasPrecomputedVolumetricLightmap;
				FMatrix _previousLocalToWorld;
				int32 _singleCaptureIndex;
				bool _bOutputVelocity;
				GetScene().GetPrimitiveUniformShaderParameters_RenderThread(GetPrimitiveSceneInfo(), _hasPrecomputedVolumetricLightmap, _previousLocalToWorld, _singleCaptureIndex, _bOutputVelocity);
				_bOutputVelocity |= AlwaysHasVelocity();

				FDynamicPrimitiveUniformBuffer& _dynamicPrimitiveUniformBuffer = Collector.AllocateOneFrameResource<FDynamicPrimitiveUniformBuffer>();
				_dynamicPrimitiveUniformBuffer.Set(Collector.GetRHICommandList(), GetLocalToWorld(), _previousLocalToWorld, GetBounds(), GetLocalBounds(), GetLocalBounds(), true, _hasPrecomputedVolumetricLightmap, _bOutputVelocity, GetCustomPrimitiveData());
				_batchElement.PrimitiveUniformBufferResource = &_dynamicPrimitiveUniformBuffer.UniformBuffer;

				_batchElement.FirstIndex = 0;
				_batchElement.NumPrimitives = GetRequiredIndexCount() / 3;
				_batchElement.MinVertexIndex = 0;
				_batchElement.MaxVertexIndex = GetRequiredVertexCount();
				_mesh.ReverseCulling = IsLocalToWorldDeterminantNegative();
				_mesh.Type = PT_TriangleList;
				_mesh.DepthPriorityGroup = SDPG_World;
				_mesh.bCanApplyViewModeOverrides = false;

				Collector.AddMesh(_viewIndex, _mesh);

#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
				// Render bounds
				RenderBounds(Collector.GetPDI(_viewIndex), ViewFamily.EngineShowFlags, GetBounds(), IsSelected());
#endif
			}
		}
	}

	virtual FPrimitiveViewRelevance GetViewRelevance(const FSceneView* View) const override
	{
		FPrimitiveViewRelevance Result;
		Result.bDrawRelevance = IsShown(View);
		Result.bShadowRelevance = IsShadowCast(View);
		Result.bRenderCustomDepth = ShouldRenderCustomDepth();
		Result.bRenderInMainPass = ShouldRenderInMainPass();
		Result.bUsesLightingChannels = GetLightingChannelMask() != GetDefaultLightingChannelMask();
		Result.bTranslucentSelfShadow = bCastVolumetricTranslucentShadow;
		const bool bAllowStaticLighting = IsStaticLightingAllowed();
		if (
#if !(UE_BUILD_SHIPPING) || WITH_EDITOR
			IsRichView(*View->Family) ||
			View->Family->EngineShowFlags.Collision ||
			View->Family->EngineShowFlags.Bounds ||
			View->Family->EngineShowFlags.VisualizeInstanceUpdates ||
#endif
#if WITH_EDITOR
			(IsSelected() && View->Family->EngineShowFlags.VertexColors) ||
			(IsSelected() && View->Family->EngineShowFlags.PhysicalMaterialMasks) ||
#endif
			// Force down dynamic rendering path if invalid lightmap settings, so we can apply an error material in DrawRichMesh
			(bAllowStaticLighting && HasStaticLighting() && !HasValidSettingsForStaticLighting()) ||
			HasViewDependentDPG()
			)
		{
			Result.bDynamicRelevance = true;
		}
		else
		{
			Result.bStaticRelevance = true;

#if WITH_EDITOR
			//only check these in the editor
			Result.bEditorVisualizeLevelInstanceRelevance = IsEditingLevelInstanceChild();
			Result.bEditorStaticSelectionRelevance = (IsSelected() || IsHovered());
#endif
		}

		materialRelevance.SetPrimitiveViewRelevance(Result);

		Result.bVelocityRelevance = DrawsVelocity() && Result.bOpaque && Result.bRenderInMainPass;

		return Result;
	}

	virtual uint32 GetMemoryFootprint(void) const override { return(sizeof(*this) + GetAllocatedSize()); }

	uint32 GetAllocatedSize(void) const { return(FPrimitiveSceneProxy::GetAllocatedSize()); }



};



//////////////////////////////////////////////////////////////////////////



void ULoiicCableComponent::UpdatePreview()
{
	#if WITH_EDITOR
	Modify();
	ReregisterComponent();
	MarkRenderStateDirty();
	#endif
}

// Sets default values for this component's properties
ULoiicCableComponent::ULoiicCableComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	bTickInEditor = true;
	bAutoActivate = true;
	this->SetMobility(EComponentMobility::Movable);

	// ...
}

void ULoiicCableComponent::SendRenderDynamicData_Concurrent()
{
	if (SceneProxy)
	{
		// Allocate cable dynamic data
		FCableDynamicData* _dynamicData = new FCableDynamicData;

		// Transform current positions from particles into component-space array
		const FTransform& _componentTransform = GetComponentTransform();
		int32 _numPoints = numSegment = particles.Num();
		_dynamicData->CablePoints.AddUninitialized(_numPoints);
		for (int32 _pointIdx = 0; _pointIdx < _numPoints; _pointIdx++)
		{
			const FCableParticle& _currentParticle = particles[_pointIdx];
			_dynamicData->CablePoints[_pointIdx] = _componentTransform.InverseTransformPosition(FMath::Lerp(_currentParticle.oldPosition, _currentParticle.position, timeRemainder / substepTime)); //Lerp from 0 to substepTime, using the timeRemainder
		}

		// Enqueue command to send to render thread
		FLoiicCableSceneProxy* _cableSceneProxy = (FLoiicCableSceneProxy*)SceneProxy;
		ENQUEUE_RENDER_COMMAND(FSendCableDynamicData)(UE::RenderCommandPipe::LoiicCable,
			[_cableSceneProxy, _dynamicData](FRHICommandListBase& RHICmdList)
			{
				_cableSceneProxy->SetDynamicData_RenderThread(RHICmdList, _dynamicData);
			});
	}
}

void ULoiicCableComponent::CreateRenderState_Concurrent(FRegisterComponentContext* Context)
{
	Super::CreateRenderState_Concurrent(Context);

	FRegisterComponentContext::SendRenderDynamicData(Context, this);
}

void ULoiicCableComponent::ApplyWorldOffset(const FVector& InOffset, bool bWorldShift)
{
	Super::ApplyWorldOffset(InOffset, bWorldShift);

	for (FCableParticle& _particle : particles)
	{
		_particle.position += InOffset;
		_particle.oldPosition += InOffset;
	}
}

FBoxSphereBounds ULoiicCableComponent::CalcBounds(const FTransform& LocalToWorld) const
{
	// Calculate bounding box of cable points
	FBox _cableBox(ForceInit);

	const FTransform& _componentTransform = GetComponentTransform();

	for (int32 _particleIndex = 0; _particleIndex < particles.Num(); _particleIndex++)
	{
		const FCableParticle& Particle = particles[_particleIndex];
		_cableBox += _componentTransform.InverseTransformPosition(Particle.position);
	}

	// Expand by cable radius (half cable width)
	return FBoxSphereBounds(_cableBox.ExpandBy(0.5f * cableWidth)).TransformBy(LocalToWorld);
}


FPrimitiveSceneProxy* ULoiicCableComponent::CreateSceneProxy()
{
	return renderType == ERenderType::Default ? new FLoiicCableSceneProxy(this) : nullptr;
}

int32 ULoiicCableComponent::GetNumMaterials() const
{
	return 1;
}

float ULoiicCableComponent::GetLastAverageVelocityComputed() const
{
	return lastAverageVelocityComputed;
}

//void ULoiicCableComponent::BeginPlay()
//{
//	Super::BeginPlay();
//
//	memoryCableLength = cableLength;
//	InitSegmentLength();
//	InitStartAndEndPosition();
//	InitParticleArray();
//}

void ULoiicCableComponent::OnRegister()
{
	Super::OnRegister();
	forwardOfTheLimitPlane.Normalize();
	memoryCableLength = cableLength;
	substepTime = FMath::Clamp(1.f / static_cast<float>(simulationFramePerSeconds), 0.005, 0.1);
	InitAll();
}

// Called every frame
void ULoiicCableComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (CheckCableLengthChanged()) OnCableLengthChanged();

	if (bSkipCableUpdateWhenNotVisible && !IsVisible())return;

	UpdateStartAndEndPosition();
	UpdateAttachedParticlesPosition();

	if (!bIsSleeping)
	{
		UpdateToSleepTransition();
		RopePhysicsRelated(DeltaTime);
		UpdateUpVectors();
	}
	else
	{
		HandleCollisions();
	}

	HandleOverlaps();

	Render();
}

void ULoiicCableComponent::PerformSubstep(const float _substepTime)
{
	Simulate(_substepTime);

	if(collisionType == ECollisionType::ECollisionOptimal)
		HandleCollisions();

	for (int32 _i = 0; _i < numOfConstraintRuns; _i++)
	{
		ApplyConstraints();
		if (collisionType == ECollisionType::ECollisionPrecise)
			HandleCollisions();
	}
}

void ULoiicCableComponent::RopePhysicsRelated(const float _deltaTime)
{
	// Ensure non zerto substep time
	const float _substepTime = FMath::Max(substepTime, 0.005f);
	
	// Simulation substep
	timeRemainder += _deltaTime;
	float _copyOfTimeRemainder = timeRemainder;

	while (timeRemainder > substepTime)
	{
		PerformSubstep(_substepTime);
		timeRemainder -= _substepTime;
	}

	if (!bCancelVelocities || impulseParticleBuffer.Num() > 0) //If the next physic state we are not canceling the velocities, then we apply the impulse buffers
	{
		//Apply impulse buffers
		while (_copyOfTimeRemainder > substepTime)
		{
			ApplyImpulseBuffers();
			_copyOfTimeRemainder -= _substepTime;
		}

		impulseParticleBuffer.Empty();
	}
	
	bCancelVelocities = false;
}

void ULoiicCableComponent::InitAll()
{
	InitSegmentLength();
	InitStartAndEndPosition();
	InitParticleArray();
	InitMeshes();
	Wake();
}

void ULoiicCableComponent::InitSegmentLength()
{
	AssignSegmentLength();
}

void ULoiicCableComponent::AssignSegmentLength()
{
	if (bDefineSubdivisionUsingNumSegment)
		segmentLength = cableLength / (numSegment - 1);
	else
	{
		segmentLength = FMath::Min(segmentLength, cableLength);
		numSegment = FMath::Max(FMath::Floor((cableLength / segmentLength)+1), 2);
	}
}

void ULoiicCableComponent::InitParticleArray()
{
	particles.Reset();
	particles.Reserve(numSegment);

	const FVector& _delta = endPos - startPos;
	for (size_t _i = 0; _i < numSegment; _i++)
	{
		const float _alpha = static_cast<float>(_i) / static_cast<float>(numSegment);
		const FVector& _initialPosition = startPos + _delta * _alpha; /* startPos + (FVector(0, 0, -1) * segmentLength * _i);*/
		particles.Add(FCableParticle(_initialPosition, _i));
	}

	particles[0].bFree = !bAttachStart;

	if (bAttachEnd)
	{
		particles[numSegment - 1].bFree = false;
		particles[numSegment - 1].position = particles[numSegment - 1].oldPosition = endPos;
	}
}

void ULoiicCableComponent::InitStartAndEndPosition()
{
	startPos = GetStartPosition();
	endPos = GetEndPosition();
}


void ULoiicCableComponent::InitMeshes()
{
	ClearMeshes();

	bUsesGrammar ? InitMeshesUsingGrammar() : InitMeshesWithoutGrammar();

	UpdateMeshesPositions();
}

void ULoiicCableComponent::InitMeshesWithoutGrammar()
{
	if (grammarMeshes.IsEmpty())return;

	//Find the first mesh given in the grammarStaticMeshes array
	FGrammarMesh _firstGrammarMeshWValidMeshFound = FGrammarMesh();
	for (auto& _grammarMesh : grammarMeshes)
	{
		TObjectPtr<UStaticMesh> _mesh = _grammarMesh.staticMesh;
		if (_mesh)
		{
			_firstGrammarMeshWValidMeshFound = _grammarMesh;
			break;
		}

		/*
		TArray<TObjectPtr<UStaticMesh>> _meshes = _grammarMesh.grammarStaticMeshes;
		if (_meshes.IsEmpty())continue;

		for (auto& _mesh : _grammarMesh.grammarStaticMeshes)
			if (_mesh) _firstMeshFound = _mesh;
		*/
	}

	if (!_firstGrammarMeshWValidMeshFound.staticMesh)return;

	for (size_t _i = 0; _i < numSegment - 1; _i++)
		CreateNewStaticMeshComponent(_firstGrammarMeshWValidMeshFound.staticMesh, _firstGrammarMeshWValidMeshFound.material);
}

void ULoiicCableComponent::CreateNewStaticMeshComponent(TObjectPtr<UStaticMesh>& _firstMeshFound, TObjectPtr<UMaterialInstance> _materialInstance)
{
	if (!_firstMeshFound)
	{
		createdMeshes.Add(nullptr);
		return;
	}
	TObjectPtr<UStaticMeshComponent> _createdMesh = renderType == ERenderType::SplineMeshes ? NewObject<USplineMeshComponent>(GetOwner()) : NewObject<UStaticMeshComponent>(GetOwner());
	_createdMesh->CreationMethod = EComponentCreationMethod::UserConstructionScript;
	_createdMesh->SetMobility(EComponentMobility::Movable);
	_createdMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	_createdMesh->SetStaticMesh(_firstMeshFound);
	if (_materialInstance)
		_createdMesh->SetMaterial(0, _materialInstance);
	_createdMesh->SetSimulatePhysics(false);
	_createdMesh->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);
	_createdMesh->RegisterComponent();
	createdMeshes.Add(_createdMesh);
}

void ULoiicCableComponent::InitMeshesUsingGrammar()
{
	/*
	Let's set the rules for the grammar:
	I think we take approximately the same grammar as the one used in unreal's pcg:
	https://dev.epicgames.com/documentation/en-us/unreal-engine/using-shape-grammar-with-pcg-in-unreal-engine
	
	Let's take a module A, and a module B.
	We can note modules like so : A, B (wil put a A module and then a B)
	We can hook them together [A,B]
	We can write how many we want, example [A,B]2 (so cost of 4, will output A,B,A,B along the cable)
	The nubmer of how many we want can be "*" meaning "as many as possible"
	The curly brackets alows to impement random {A:2, B:3}, the number here is the weight/ratio for the random 
	*/

	//The "available cost" represent how many meshes are possible to place along the cable
	const uint32& _availableCost = numSegment - 1;
	
	//Develop the grammar, from [A,B]3 to A,B,A,B,A,B for example
	const FString& _developedGrammar = DevelopGrammar(grammar.ToString());

	//Apply the grammar(developed grammar)
	ApplyGrammar(_developedGrammar);
}

void ULoiicCableComponent::ClearMeshes()
{
	int32 _size = createdMeshes.Num();
	for (size_t _i = 0; _i < _size; _i++)
	{
		TObjectPtr<UStaticMeshComponent> _current = createdMeshes[_i];
		if (!_current)continue;
		if(_current->IsRegistered())
			_current->UnregisterComponent();
		if(!_current->IsBeingDestroyed())
			_current->DestroyComponent();
	}
	createdMeshes.Empty();
}

void ULoiicCableComponent::UpdateMeshesPositions()
{
	const int32& _size = createdMeshes.Num();


	for (size_t _i = 0; _i < _size; _i++)
	{
		const FCableParticle& _startParticle = particles[_i];
		const FCableParticle& _endParticle = particles[_i + 1];

		const FVector& _startParticlePosLerped = FMath::Lerp(_startParticle.oldPosition, _startParticle.position, timeRemainder / substepTime);
		const FVector& _endParticlePosLerped = FMath::Lerp(_endParticle.oldPosition, _endParticle.position, timeRemainder / substepTime);

		TObjectPtr<UStaticMeshComponent> _concernedMesh = createdMeshes[_i];
		if (!_concernedMesh)continue;

		switch (renderType)
		{
		case SplineMeshes:
			if (TObjectPtr<USplineMeshComponent> _asSplineMesh = Cast<USplineMeshComponent>(_concernedMesh))
			{
				const FVector& _inTangentUsed = (_i <= 0) ? _startParticle.upVector : _endParticlePosLerped - particles[_i - 1].position;
				const FVector& _outTangentUsed = (_i + 2 >= _size) ? _endParticle.upVector : particles[_i + 2].position - _startParticlePosLerped;

				DrawDebugLine(GetWorld(), _endParticlePosLerped, _endParticlePosLerped + _outTangentUsed.GetClampedToSize(20, 20), FColor::Orange, false, -1, 0, 4);
				DrawDebugLine(GetWorld(), _endParticlePosLerped, _endParticlePosLerped - _outTangentUsed.GetClampedToSize(20, 20), FColor::Orange, false, -1, 0, 4);

				_asSplineMesh->SetStartAndEnd(_startParticlePosLerped, _inTangentUsed, _endParticlePosLerped, _outTangentUsed);
			}
			break;

		case StaticMeshes:
			_concernedMesh->SetWorldLocation(_startParticlePosLerped);
			const FRotator _desiredRotation = UKismetMathLibrary::MakeRotFromZX(_endParticlePosLerped - _startParticlePosLerped, this->GetForwardVector());
			_concernedMesh->SetWorldRotation(_desiredRotation);
			break;

		default:
			break;
		}
	}
}

FString ULoiicCableComponent::DevelopGrammar(const FString& _inGrammar)
{
	//Develop the bracket modules ([a,b]2 => a,b,a,b)
	//for (size_t i = 0; i < length; i++)
	//{

	//}
	FPCGGrammarResult _grammarResult = PCGGrammar::Parse(_inGrammar);
	const TArray<FPCGGrammarResult::FLog>& _logs = _grammarResult.GetLogs();


	//TODO Get:
	//int iteration of module to repeat infinitely
	int _iterationOfModuleRepeatableInfinitely = 0;
	//int total cost of non repetable module
	int _totalCostOfNonRepetableModule = 0;

	GetInfoModule(_grammarResult.Root, _iterationOfModuleRepeatableInfinitely, _totalCostOfNonRepetableModule);

	//LOG("Get info module returned : rep inf mod: " + FString::FromInt(_iterationOfModuleRepeatableInfinitely) + " total cost of non repetable: " + FString::FromInt(_totalCostOfNonRepetableModule));

	int32 _costAvailable = numSegment - 1;
	return TranslateModule(_grammarResult.Root, _costAvailable, _iterationOfModuleRepeatableInfinitely, _totalCostOfNonRepetableModule);
}

void ULoiicCableComponent::GetInfoModule(const PCGGrammar::FModuleDescriptor& _module, int& _infiniteRepetableModuleCount, int& _literalModuleCount)
{
	if (_module.Type == PCGGrammar::EModuleType::Literal)
	{
		_literalModuleCount++;
		return;
	}

	// Treat submodules recursively
	for (const PCGGrammar::FModuleDescriptor& _submodule : _module.Submodules)
	{
		if (_submodule.Repetitions == -1) //infinite repetition detected
			_infiniteRepetableModuleCount++;
		else
		{
			for (int _i = 0; _i < _submodule.Repetitions; _i++)
				GetInfoModule(_submodule, _infiniteRepetableModuleCount, _literalModuleCount);
		}
	}
}

FString ULoiicCableComponent::TranslateModule(const PCGGrammar::FModuleDescriptor& _module, int32& _costAvailable, const int _infiniteRepetableModuleCount, const int _literalModuleCount)
{
	//TODO find a better way to include repetitions in the grammar, and handle the infinite repetition even in stochastic submodules.

	//if (_module.Repetitions == -1) // infinite repetition detected
	//	LOG("this should be repeated infinitely: " + _module.Symbol.ToString());

	//if (_module.Type == PCGGrammar::EModuleType::Priority)
	//	LOG("This is priority: " + _module.Symbol.ToString());

	//Handle stochastic module type
	if (_module.Type == PCGGrammar::EModuleType::Stochastic)
	{
		///Chose randomly between theses submoduels:
		int32 _totalWeight = 0;
		TArray<PCGGrammar::FModuleDescriptor> _subModules = _module.Submodules;
		for (auto& _submodule : _subModules)
			_totalWeight += _submodule.Weight;

		const int32& _randomlyChosenWeight = FMath::RandRange(1, _totalWeight);

		int32 _currentTotWeight = 0;
		for (auto& _submodule : _subModules)
		{
			_currentTotWeight += _submodule.Weight;
			if (_currentTotWeight >= _randomlyChosenWeight)
			{
				//Todo here, if we want to apply the repetition logic in stochastic modules
				/*_submodule
				for (size_t _i = 0; _i < length; _i++)
				{

				}*/
				return TranslateModule(_submodule, _costAvailable, _infiniteRepetableModuleCount, _literalModuleCount);
			}
		}
	}

	if (_module.Type == PCGGrammar::EModuleType::Literal)
	{
		//LOG("This is Literal returned: " + _module.Symbol.ToString() + ", repetition: " + FString::FromInt(_module.GetMinNumberOfRepetitions()));
		_costAvailable--;
		return _module.Symbol.ToString() + ",";
	}
	
	FString _toReturn;
	// Treat submodules recursively
	for (const PCGGrammar::FModuleDescriptor& _submodule : _module.Submodules)
	{
		if (_submodule.Repetitions == -1) //infinite repetition detected
		{
			const int _numberOfModules = (numSegment - 1 - _literalModuleCount) / _infiniteRepetableModuleCount;
			for (size_t _i = 0; _i < _numberOfModules; _i++)
			{
				if (_costAvailable < 0) break;
				_toReturn += TranslateModule(_submodule, _costAvailable, _infiniteRepetableModuleCount, _literalModuleCount);
			}
		}
		else
		{
			for (int _i = 0; _i < _submodule.Repetitions; _i++)
			{
				_toReturn += TranslateModule(_submodule, _costAvailable, _infiniteRepetableModuleCount, _literalModuleCount);
				if (_costAvailable <= 0) break;
			}
		}
	}

	return _toReturn;
}

void ULoiicCableComponent::ApplyGrammar(const FString& _developpedGrammar)
{
	TArray<FString> _arrayOfTagsForMesh;
	_developpedGrammar.ParseIntoArray(_arrayOfTagsForMesh, TEXT(","), false);
	
	int32 _costAvailable = numSegment - 1;
	const int32& _arraySize = _arrayOfTagsForMesh.Num();

	for (int32 _i = 0; _i < _arraySize; _i++)
	{
		if (_costAvailable <= 0) break;
		const FString& _tag = _arrayOfTagsForMesh[_i];

		FGrammarMesh _correspondingGrammarMesh = GetCorrespondingGrammarMesh(_tag);

		CreateNewStaticMeshComponent(_correspondingGrammarMesh.staticMesh, _correspondingGrammarMesh.material);

		_costAvailable--;
		/* OLD
		int32 _constructionCost = _correspondingGrammarMesh.GetGrammarCost();
		const int32& _previewOfCost = _costAvailable - _constructionCost;

		if (_previewOfCost < 0) //we don't have enough to fully construct
			_constructionCost += _previewOfCost; //preview of cost is negative here

		for (int32 _j = 0; _j < _constructionCost; _j++)
			CreateNewStaticMeshComponent(_correspondingGrammarMesh.grammarStaticMeshes[_j]);

		_costAvailable = _previewOfCost;
		*/
	}
}

FGrammarMesh ULoiicCableComponent::GetCorrespondingGrammarMesh(const FString& _tagAsString)
{
	for (auto& _grammarMesh : grammarMeshes)
		if (_grammarMesh.tag == _tagAsString) return _grammarMesh;
	return FGrammarMesh();
}

void ULoiicCableComponent::UpdateStartAndEndPosition()
{
	startPos = GetStartPosition();
	endPos = GetEndPosition();

	FCableParticle& _startParticle = particles[0];
	_startParticle.bFree = !bAttachStart;
	if (bAttachStart)
		_startParticle.positionAttachedTo = startPos;

	FCableParticle& _endParticle = particles[particles.Num() - 1];
	_endParticle.bFree = !bAttachEnd;
	if (bAttachEnd)
		_endParticle.positionAttachedTo = endPos;
}

void ULoiicCableComponent::UpdateAttachedParticlesPosition()
{
	for (FCableParticle& _particle : particles)
	{
		if (_particle.bFree) continue;
		_particle.oldPosition = _particle.position;
		
		if (_particle.sceneComponentAttachedTo) // if is attached to a scene component
		{
			TObjectPtr<USkeletalMeshComponent> _skm = Cast<USkeletalMeshComponent>(_particle.sceneComponentAttachedTo);

			if (_skm && _particle.socketNameAttachedTo != NAME_None)// if a socket name is inputed, and the scene is a skeletal mesh 
				_particle.position = _skm->GetSocketLocation(_particle.socketNameAttachedTo);
			else
				_particle.position = _particle.sceneComponentAttachedTo->GetComponentLocation();
		}
		else
			_particle.position = _particle.positionAttachedTo;

		//if the update of the attached particle is causing the velocity of the point is high enough, wake the rope physics
		if (FVector::DistSquared(_particle.oldPosition, _particle.position) > FMath::Square(minVelocityBeforeSleep)) Wake();
	}
}

void ULoiicCableComponent::UpdateUpVectors()
{
	const int32 _length = GetParticlesCount();

	//Computes the up vector "simulated" for the first point (based on the next point)
	FVector _downVector = particles[1].position - particles[0].position;
	_downVector.Normalize();
	particles[0].upVector = -_downVector;


	for (int32 _i = 1; _i < _length; _i++)
	{
		FCableParticle& _toModify = particles[_i];
		FVector _upVector = particles[_i - 1].position - particles[_i].position;
		_upVector.Normalize();
		_toModify.upVector = _upVector;
	}
}

void ULoiicCableComponent::UpdateToSleepTransition()
{
	// Here we will compare the lastAverageVelocityComputed with the minVelocityBeforeSleep 
	// to determine if we should start counting down for the time sleep delay

	if (!bIsSleeping)
	{
		if (lastAverageVelocityComputed <= minVelocityBeforeSleep)
			currentTimeBeforeSleep -= GetWorld()->DeltaTimeSeconds;
		else
			currentTimeBeforeSleep = timeInSecondsBeforeSleep;

		if (currentTimeBeforeSleep <= 0) Sleep();
	}
}

FVector ULoiicCableComponent::GetStartPosition()const
{
	return GetComponentLocation();
}

FVector ULoiicCableComponent::GetEndPosition()
{
	USceneComponent* _endComponent = attachEndSceneComponent ? attachEndSceneComponent.Get() : Cast<USceneComponent>(attachEndTo.GetComponent(GetOwner()));

	if (!_endComponent || (GetOwner() && _endComponent == GetOwner()->GetRootComponent()))
	{
		if (attachEndToSocketName != NAME_None) return this->GetComponentTransform().TransformPosition(endLocation);
		return this->GetSocketTransform(attachEndToSocketName).TransformPosition(endLocation);
	}
	if (attachEndToSocketName != NAME_None)
		return _endComponent->GetSocketLocation(attachEndToSocketName);
	return _endComponent->GetComponentLocation();
}

FVector ULoiicCableComponent::TryAndLimitVectorOnToSelectedPlane(const FVector& _vector)
{
	if (!bLimitMovementOnToOnePlane) return _vector;
	const FVector& _forwardOfTheLimitPlaneWorld = UKismetMathLibrary::Quat_RotateVector(GetComponentQuat(), forwardOfTheLimitPlane);
	return UKismetMathLibrary::ProjectVectorOnToPlane(_vector, _forwardOfTheLimitPlaneWorld.RotateAngleAxis(90, FVector::UpVector));
}

bool ULoiicCableComponent::CheckCableLengthChanged()
{
	const bool _toReturn = memoryCableLength != cableLength;
	memoryCableLength = cableLength;
	return _toReturn;
}

void ULoiicCableComponent::OnCableLengthChanged()
{
	AssignSegmentLength();
}

int32 ULoiicCableComponent::GetParticlesCount()const
{
	return particles.Num();
}

TArray<FCableParticle>& ULoiicCableComponent::GetCableParticles() 
{
	return particles;
}

FCableParticle& ULoiicCableComponent::GetCableParticle(const int _index)
{
	return particles[_index];
}

FVector ULoiicCableComponent::GetPositionAtLength(const float _length)
{
	const float _lengthClamped = FMath::Clamp(_length, 0, cableLength);
	const float _floatIndex = _lengthClamped / segmentLength;

	FVector _pos = GetPositionAtIndex(_floatIndex);
	//UKismetSystemLibrary::PrintString(this, "sent current pos length : " + FString::SanitizeFloat(_length) + " clamped to : " + FString::SanitizeFloat(_lengthClamped) + "sent float index : " + FString::SanitizeFloat(_floatIndex) + " recieved position:  " + _pos.ToString(), true, true);
	return _pos;
}

float ULoiicCableComponent::GetLengthAtIndex(const float _floatIndex)
{
	return _floatIndex * (cableLength / numSegment);
}

float ULoiicCableComponent::GetLengthAtPosition(const FVector& _position)
{
	return GetLengthAtIndex(static_cast<float>(GetClosestParticleData(_position).index));
}

FVector ULoiicCableComponent::GetPositionAtIndex(const float _floatIndex)
{
	const int _firstParticleIndex = FMath::Clamp(FMath::Floor(_floatIndex), 0, particles.Num() - 1);
	const int _secondParticleIndex = FMath::Clamp(_firstParticleIndex + 1, 0, particles.Num() - 1);
	const float _decimal = _floatIndex - static_cast<float>(_firstParticleIndex);

	return UKismetMathLibrary::VLerp(particles[_firstParticleIndex].position, particles[_secondParticleIndex].position, _decimal);
}

FCableParticle ULoiicCableComponent::GetClosestParticleData(const FVector& _location)
{
	int32 _closestIndex = 0;
	float _smallestDistanceSquarred = FVector::DistSquared(_location, particles[0].position);

	const int32& _length = particles.Num();
	for (int _i = 1; _i < _length; _i++)
	{
		float _newDist = FVector::DistSquared(_location, particles[_i].position);
		if (_newDist <= _smallestDistanceSquarred)
		{
			_closestIndex = _i;
			_smallestDistanceSquarred = _newDist;
		}
	}
	return particles[_closestIndex];
}

FCableParticle ULoiicCableComponent::GetClosestParticleDataFromSceneComponent(USceneComponent* _sceneComponent)
{
	return GetClosestParticleData(_sceneComponent->GetComponentLocation());
}

FCableParticle ULoiicCableComponent::GetClosestParticleDataFromActor(AActor* _actor)
{
	return GetClosestParticleData(_actor->GetActorLocation());
}

FVector ULoiicCableComponent::GetClosestPositionAlongRope(const FVector& _location)
{
	const FCableParticle& _closestParticle = GetClosestParticleData(_location);
	const FCableParticle& _closestNeighborParticle = GetClosestNeighborParticle(_closestParticle.index, _location);
	UKismetSystemLibrary::DrawDebugBox(this, _closestNeighborParticle.position, FVector(14, 14, 14), FLinearColor::Blue);

	const FVector& _vectA = _location - _closestParticle.position;
	const FVector& _vectB = _closestNeighborParticle.position - _closestParticle.position;

	return (_vectB.IsZero() ? FVector::ZeroVector : UKismetMathLibrary::ProjectVectorOnToVector(_vectA, _vectB)) + _closestParticle.position;
}

FVector ULoiicCableComponent::GetClosestPositionAlongRopeFromActor(AActor* _actor)
{
	return GetClosestPositionAlongRope(_actor->GetActorLocation());
}

FVector ULoiicCableComponent::GetClosestPositionAlongRopeFromSceneComponent(USceneComponent* _sceneComponent)
{
	return GetClosestPositionAlongRope(_sceneComponent->GetComponentLocation());
}

FCableParticle ULoiicCableComponent::GetClosestNeighborParticle(const int _indexOfParticle, const FVector& _location) //TODO fix clamp position when index is out of range and has only one neighbor
{
	int _firstPointIndex = _indexOfParticle + 1;
	if (_firstPointIndex >= particles.Num())
		_firstPointIndex = _indexOfParticle;

	float _firstPointDistSquared = FVector::DistSquared(_location, particles[_firstPointIndex].position);

	int _secondPointIndex = _indexOfParticle - 1;
	if (_secondPointIndex < 0)
		_secondPointIndex = _indexOfParticle;

	float _secondPointDistSquared = FVector::DistSquared(_location, particles[_secondPointIndex].position);

	if (_firstPointDistSquared < _secondPointDistSquared)
		return particles[_firstPointIndex];
	return particles[_secondPointIndex];
}

void ULoiicCableComponent::AttachParticleAtPosition(const FCableParticle& _particleToAttach, const FVector& _position)
{
	AttachParticleIndexAtPosition(_particleToAttach.index, _position);
}

void ULoiicCableComponent::AttachParticleIndexAtPosition(const int _indexOfParticleToAttach, const FVector& _position)
{
	FCableParticle& _particleRef = particles[_indexOfParticleToAttach];
	_particleRef.bFree = false;
	_particleRef.positionAttachedTo = _position;
	Wake();
}


void ULoiicCableComponent::AttachParticleToSceneComponent(const FCableParticle& _particleToAttach, USceneComponent* _sceneComponent, const FName& _optionnalSocket)
{
	AttachParticleIndexToSceneComponent(_particleToAttach.index, _sceneComponent, _optionnalSocket);
}

void ULoiicCableComponent::AttachParticleIndexToSceneComponent(const int _particleIndexToAttach, USceneComponent* _sceneComponent, const FName& _optionnalSocket)
{
	FCableParticle& _particleRef = particles[_particleIndexToAttach];
	_particleRef.bFree = false;
	_particleRef.sceneComponentAttachedTo = _sceneComponent;
	_particleRef.socketNameAttachedTo = _optionnalSocket;
	Wake();
}

void ULoiicCableComponent::DetachParticle(const FCableParticle& _particleToDetach)
{
	DetachParticleIndex(_particleToDetach.index);
}

void ULoiicCableComponent::DetachParticleIndex(const int _particleIndexToDetach)
{
	FCableParticle& _particleToDetach = particles[_particleIndexToDetach];
	_particleToDetach.bFree = true;
	_particleToDetach.sceneComponentAttachedTo = nullptr;
	_particleToDetach.positionAttachedTo = FVector::ZeroVector;
	_particleToDetach.socketNameAttachedTo = FName();

	Wake();
}

TArray<FCableParticle> ULoiicCableComponent::GetAttachedParticles(const bool _includesStartAndEnd)
{
	TArray<FCableParticle> _toReturn;
	const int _particleCount = particles.Num();
	for (int _i = 0 + (!_includesStartAndEnd); _i < _particleCount - (!_includesStartAndEnd); _i++)
	{
		FCableParticle& _currentParticle = particles[_i];
		if (!_currentParticle.bFree)_toReturn.Add(_currentParticle);
	}
	return _toReturn;
}

void ULoiicCableComponent::AddImpulseAtParticle(const FCableParticle& _particleToInpulse, const FVector& _vector, const EImpulseModifier& _impulse)
{
	AddImpulseAtParticleIndex(_particleToInpulse.index, _vector, _impulse);
}

void ULoiicCableComponent::AddImpulseAtParticleIndex(const int _particleIndexToInpulse, const FVector& _vector, const EImpulseModifier& _impulse)
{
	if (_vector == FVector::ZeroVector)return;
	int32 _j;
	switch (_impulse)
	{
	case EImpulseDefault:
		AddOrCreateVectorToImpulseBuffer(_particleIndexToInpulse, _vector);
		break;
	case EImpulseSpreadsTowardStart:

		//Toward start mean toward particle of index 0
		_j = 1;
		for (int32 _i = _particleIndexToInpulse; _i >= 0; _i--, _j++)
			AddOrCreateVectorToImpulseBuffer(_i, _vector / FMath::Pow(2.f, _j));

		break;
	case EImpulseSpreadsTowardEnd:

		//Toward end mean toward particle of index len of cable
		_j = 1;
		for (int32 _i = _particleIndexToInpulse; _i < numSegment; _i++, _j++)
			AddOrCreateVectorToImpulseBuffer(_i, _vector / FMath::Pow(2.f, _j));

		break;
	case EImpulseSpreadsAround:

		//arround mean impulse like a chain aroundApplyImpulseBuffers

		AddOrCreateVectorToImpulseBuffer(_particleIndexToInpulse, _vector / 3.f);
		//Toward start
		_j = 2;
		for (int32 _i = _particleIndexToInpulse - 1; _i >= 0; _i--, _j++)
			AddOrCreateVectorToImpulseBuffer(_i, _vector / FMath::Pow(1.5f, _j));

		//Toward end
		_j = 2;
		for (int32 _i = _particleIndexToInpulse + 1; _i < numSegment; _i++, _j++)
			AddOrCreateVectorToImpulseBuffer(_i, _vector / FMath::Pow(1.5f, _j));

		break;

	case ESpreadAll:

		for (int32 _i = 0; _i < numSegment; _i++)
			AddOrCreateVectorToImpulseBuffer(_i, _vector);

		break;

	default:
		break;
	}

	Wake();
}

void ULoiicCableComponent::StopAllVelocities()
{
	if(!bIsSleeping)
		bCancelVelocities = true;
}

void ULoiicCableComponent::ResetCable()
{
	InitAll();
}

void ULoiicCableComponent::AddOrCreateVectorToImpulseBuffer(const int _particleIndexToInpulse, const FVector& _vector)
{
	if (impulseParticleBuffer.Contains(_particleIndexToInpulse))
		//I fouind the *numSegment usefull to make it so the rope gets the same behaviour regardless of the segment count 
		//the division by 30 it's so early prototype metrics done in the project don't break with the changes, additionnaly, it gives a better ratio for metrics
		impulseParticleBuffer[_particleIndexToInpulse] += _vector * substepTime / 30 * numSegment;
	else
		impulseParticleBuffer.Add(_particleIndexToInpulse, _vector * substepTime / 30 * numSegment);
	Wake();
}

void ULoiicCableComponent::ApplyImpulseBuffers()
{
	//If there is no particle to impulse in the buffer, or the next physic step is gonna be a stop of the velocity
	if (impulseParticleBuffer.Num() <= 0)return; 
	for (auto& _pair : impulseParticleBuffer)
	{
		FCableParticle& _concernedParticle = particles[_pair.Key];
		if (!_concernedParticle.bFree)continue;

		_concernedParticle.position += TryAndLimitVectorOnToSelectedPlane(_pair.Value);
	}

}


void ULoiicCableComponent::Simulate(const float _substepTime)
{
	const size_t& _particleCount = particles.Num();
	//The number of velocity accumulated, used to compute the average velocity of the rope
	float _velocityAccumulated = 0;
	for (size_t _i = 0; _i < _particleCount; _i++)
	{
		FCableParticle& _currentParticle = particles[_i];
		if (!_currentParticle.bFree) continue;
		FVector _velocity = (_currentParticle.position - _currentParticle.oldPosition);

		_currentParticle.oldPosition = _currentParticle.position;

		_currentParticle.position += TryAndLimitVectorOnToSelectedPlane(_velocity) * dampingFactor + FVector::UpVector * GetWorld()->GetGravityZ() * FMath::Square(_substepTime);
	
		if (bCancelVelocities)
			_currentParticle.oldPosition = _currentParticle.position;

		_velocityAccumulated += FVector::Dist(_currentParticle.position, _currentParticle.oldPosition);
		particles[_i] = _currentParticle;
	}

	lastAverageVelocityComputed = _velocityAccumulated / _particleCount;
}

void ULoiicCableComponent::ApplyConstraints()
{
	for (size_t _i = 0; _i < particles.Num() - 1; _i++)
	{
		FCableParticle& _currentPart = particles[_i];
		FCableParticle& _nextPart = particles[_i + 1];

		float _dist = FVector::Distance(_currentPart.position, _nextPart.position);
		float _difference = (_dist - segmentLength);

		if (_difference <= 0) continue;

		FVector _changeDir = (_currentPart.position - _nextPart.position);
		_changeDir.Normalize();
		FVector _changeVector = (_changeDir * _difference); 

		if (_currentPart.bFree)
		{
			if (_nextPart.bFree) //If both of the particles are free
			{
				switch (constraintType)
				{
				case EDefaultConstraint:
					_currentPart.position -= (_changeVector * .5f);
					_nextPart.position += (_changeVector * .5f);
					break;

				case ETowardStartConstraint:
					_currentPart.position -= (_changeVector * .51f);
					_nextPart.position += (_changeVector * .49f);
					break;

				case ETowardEndConstraint:
					_currentPart.position -= (_changeVector * .49f);
					_nextPart.position += (_changeVector * .51f);
					break;

				default:
					break;
				}
				
			}
			else
				_currentPart.position -= _changeVector;
		}
		else if (_nextPart.bFree)
		{
			_nextPart.position += _changeVector;
		}
	}
}


void ULoiicCableComponent::HandleCollisions()
{
	if (!bEnableCollision)return;
	const size_t& _particleCount = particles.Num();


	for (size_t _i = 0; _i < _particleCount; _i++)
	{
		FCableParticle& _currentParticle = particles[_i];
		if (!_currentParticle.bFree) continue;
		FVector _velocity = (_currentParticle.position - _currentParticle.oldPosition) * dampingFactor;

		//FHitResult _result;
		//bool _bHitSomething = UKismetSystemLibrary::SphereTraceSingleByProfile(this, _currentParticle.oldPosition, _currentParticle.position, cableWidthForCollisions / 2.f,
		//	collisionProfile, false, actorsToIgnoreDuringCollision, EDrawDebugTrace::None, _result, true);
		
		
		FHitResult _result;
		FCollisionQueryParams _param;
		_param.AddIgnoredActors(actorsToIgnoreDuringCollision);
		_param.bTraceComplex = false;
		_param.TraceTag = FName("CableSweep");

		const bool _bHitSomething = GetWorld()->SweepSingleByProfile(_result, _currentParticle.oldPosition, _currentParticle.position, FQuat::Identity,
			collisionProfile, FCollisionShape::MakeSphere(cableWidthForCollisions /2.f), _param);

		if (!_bHitSomething)continue;
		 
		//Resolve the collision

		FVector _closestPoint = _result.ImpactPoint;
		float _distanceSquared = FVector::DistSquared(_currentParticle.position, _closestPoint);

		//if within the collision radius, we resolve
		if (_distanceSquared < cableWidthForCollisions * cableWidthForCollisions)
		{
			FVector _normal = _result.ImpactNormal;

			if (_normal == FVector::ZeroVector)//fallback method
				_normal = (_currentParticle.position - _result.GetActor()->GetActorLocation()).GetSafeNormal();

			_normal = TryAndLimitVectorOnToSelectedPlane(_normal).GetSafeNormal();
			float _depth = _result.PenetrationDepth;
			_currentParticle.position += _normal * _depth;

			_velocity = _velocity.MirrorByVector(_normal) * bounceFactor;
			if (_depth > minVelocityBeforeSleep)
				Wake();
		}

		_currentParticle.oldPosition = _currentParticle.position - _velocity;
		particles[_i] = _currentParticle;
	}
}

//This uses the idea of "divide and conquer | Diviser pour mieux régner"
void ULoiicCableComponent::HandleCollisionsV2()
{
	if (!bEnableCollision)return;
	const size_t& _particleCount = particles.Num();

	//TMap<FCableParticle, TArray<FHitResult>> _outHitResult;
	TMap<int32, TArray<FHitResult>> _outHitResult;
	bool _hit = CheckCollisionRecursV2(0, _particleCount - 1, _outHitResult);
	
	//Let's resolve the collision handling that we know it collides

	for (const TPair<int32, TArray<FHitResult>>& _result : _outHitResult)
	{
		FCableParticle& _particleToResolve = GetCableParticle(_result.Key);
		const TArray<FHitResult>& _array = _result.Value;
		
		FVector _velocity = (_particleToResolve.position - _particleToResolve.oldPosition) * dampingFactor;

		for (const FHitResult& _hitResult : _array)
		{
			const FVector& _closestPointLocation = _hitResult.ImpactPoint;
			float _distance = FVector::Dist(_particleToResolve.position, _closestPointLocation);
			
			//if within the collision radius, we resolve
			if (_distance < cableWidthForCollisions)
			{
				FVector _normal = _hitResult.ImpactNormal;

				if (_normal == FVector::ZeroVector)//fallback method
					_normal = (_particleToResolve.position - _hitResult.GetActor()->GetActorLocation()).GetSafeNormal();

				_normal = TryAndLimitVectorOnToSelectedPlane(_normal).GetSafeNormal();
				float _depth = _hitResult.PenetrationDepth;
				_particleToResolve.position += _normal * _depth;

				_velocity = _velocity.MirrorByVector(_normal) * bounceFactor;
				if (_depth > minVelocityBeforeSleep)
					Wake();
			}
		}
		_particleToResolve.oldPosition = _particleToResolve.position - _velocity;
		particles[_particleToResolve.index] = _particleToResolve;
	}
}

bool ULoiicCableComponent::CheckCollisionRecursV2(int32 _startIndex, int32 _endIndex, TMap<int32, TArray<FHitResult>>& _outHitResult)
{
	if (_startIndex > _endIndex) return false;

	if (_startIndex == _endIndex)
	{
		const FCableParticle& _particle = particles[_startIndex];
		TArray<FHitResult> _outResult;

		bool _bHitSomething = UKismetSystemLibrary::SphereTraceMultiByProfile(
			this,
			_particle.oldPosition,
			_particle.position,
			cableWidth / 2.f,
			collisionProfile,
			false,
			actorsToIgnoreDuringCollision,
			EDrawDebugTrace::None,
			_outResult,
			true
		);

		if (!_bHitSomething) return false;

		_outHitResult.Add(_startIndex, _outResult);
		return true;
	}

	const FCableParticle& _startParticle = particles[_startIndex];
	const FCableParticle& _endParticle = particles[_endIndex];

	TArray<FHitResult> _outResult;

	bool _bHitSomething = UKismetSystemLibrary::SphereTraceMultiByProfile(
		this,
		_startParticle.position,
		_endParticle.position,
		cableWidth / 2.f,
		collisionProfile,
		false,
		actorsToIgnoreDuringCollision,
		EDrawDebugTrace::None,
		_outResult,
		true
	);

	if (!_bHitSomething) return false;

	const int32 _splitIndex = (_startIndex + _endIndex) / 2;

	bool _bHitLeft = CheckCollisionRecursV2(_startIndex, _splitIndex, _outHitResult);
	bool _bHitRight = CheckCollisionRecursV2(_splitIndex + 1, _endIndex, _outHitResult);

	return _bHitLeft || _bHitRight;
}
bool ULoiicCableComponent::CheckCollisionRecurs(const TArray<FCableParticle>& _arrayOfParticle, TMap<FCableParticle, TArray<FHitResult>>& _outHitResult)
{
	if (_arrayOfParticle.Num() == 0) return false;
	if (_arrayOfParticle.Num() == 1)
	{
		const FCableParticle& _particle = _arrayOfParticle[0];
		TArray<FHitResult> _outResult;

		bool _bHitSomething = UKismetSystemLibrary::SphereTraceMultiByProfile(this, _particle.oldPosition, _particle.position, cableWidth / 2.f,
			collisionProfile, false, actorsToIgnoreDuringCollision, EDrawDebugTrace::None, _outResult, true);

		if (!_bHitSomething) return false;
		_outHitResult.Add(_particle, _outResult);
		return true;
	}
	//we check the collision between the two extrimities of the given array, if they collide with something, it means something is overlapping in between,
	//we will then divide by 2 our array, and check collision recurs again.
	const FCableParticle& _startParticle = _arrayOfParticle[0];
	const FCableParticle& _endParticle = _arrayOfParticle[_arrayOfParticle.Num() - 1];

	TArray<FHitResult> _outResult;
	bool _bHitSomething = UKismetSystemLibrary::SphereTraceMultiByProfile(this, _startParticle.position, _endParticle.position, cableWidth / 2.f,
		collisionProfile, false, actorsToIgnoreDuringCollision, EDrawDebugTrace::None, _outResult, true);

	if (!_bHitSomething)return false;

	TArray<FCableParticle> _firstPart;
	TArray<FCableParticle> _secondPart;
	const int _particleCount = _arrayOfParticle.Num();
	const int _splitIndex = _particleCount / 2;

	_firstPart.Append(_arrayOfParticle.GetData(), _splitIndex);
	_secondPart.Append(_arrayOfParticle.GetData() + _splitIndex, _particleCount - _splitIndex);

	return CheckCollisionRecurs(_firstPart, _outHitResult) || CheckCollisionRecurs(_secondPart, _outHitResult);
	//return false;
}

void ULoiicCableComponent::HandleOverlaps()
{
	if (!bGenerateCustomOverlapEvents)return;

	const size_t& _particleCount = particles.Num();
	TArray<TObjectPtr<AActor>> _actorsCurrentlyOverlapping;

	for (size_t _i = 0; _i < _particleCount; _i++)
	{
		const FCableParticle& _prevCableParticle = particles[FMath::Clamp(_i - 1, 0, _particleCount - 1)];
		const FCableParticle& _cableParticle = particles[_i];
		const FVector& _prevCableParticlePos = _prevCableParticle.position;
		const FVector& _particlePos = _cableParticle.position;
		TArray<FHitResult> _results;

		bool _hasHit = UKismetSystemLibrary::SphereTraceMultiByProfile(this, _prevCableParticlePos, _particlePos, cableWidthForCollisions / 2.f + overlapExtraExtent,
			collisionProfile, false, {}, EDrawDebugTrace::None, _results, true);

		if (!_hasHit)continue;

		for (auto _result : _results)
		{
			TObjectPtr<AActor> _resultActor = _result.GetActor();

			if (!(_actorsCurrentlyOverlapping.Contains(_resultActor) || overlappingActors.Contains(_resultActor)))
				onBeginOverlap.Broadcast(_resultActor, _cableParticle);
			_actorsCurrentlyOverlapping.AddUnique(_resultActor);
		}
	}

	for (auto _previousOverlappingActor : overlappingActors)
	{
		if (!_actorsCurrentlyOverlapping.Contains(_previousOverlappingActor))
			onEndOverlap.Broadcast(_previousOverlappingActor);
	}

	overlappingActors = _actorsCurrentlyOverlapping;
}


void ULoiicCableComponent::Render()
{
	MarkRenderDynamicDataDirty();
	UpdateComponentToWorld();
	UpdateMeshesPositions();
	DrawDebug();
}

void ULoiicCableComponent::DrawDebug()
{
	if (bShowParticleDebug)
		DrawParticleDebug();
	if (bLimitMovementOnToOnePlane && bShowPlaneDebug)
		DrawPlaneDebug();
	if (bDebugOptimisation)
		DrawDebugSphere(GetWorld(), particles[0].position + FVector::UpVector * 100, 20, 10, bIsSleeping ? FColor::Red : FColor::Green);
	//FRAME_LOG(FString::SanitizeFloat(lastAverageVelocityComputed));
}

void ULoiicCableComponent::DrawPlaneDebug()
{
	const float _planeDebugLength = 50.f;
	const FVector& _pointLocation = GetComponentLocation() - (_planeDebugLength * FVector::UpVector);
	const FVector& _forwardOfTheLimitPlaneWorld = UKismetMathLibrary::Quat_RotateVector(GetComponentQuat(), forwardOfTheLimitPlane);
	UKismetSystemLibrary::DrawDebugPlane(this, UKismetMathLibrary::MakePlaneFromPointAndNormal(_pointLocation, _forwardOfTheLimitPlaneWorld.RotateAngleAxis(90, FVector::UpVector)),
		_pointLocation, _planeDebugLength);
}

void ULoiicCableComponent::DrawParticleDebug()
{
	int _currentIndex = 0;
	for (const auto& _particle : particles)
	{
		UKismetSystemLibrary::DrawDebugSphere(this, _particle.position, cableWidth / 2, 12, FLinearColor::Green);

		if (_currentIndex > 0)
			UKismetSystemLibrary::DrawDebugLine(this, particles[_currentIndex - 1].position, _particle.position, FLinearColor(11, 79, 29));

		_currentIndex++;
	}

	FCableParticle& _startParticle = particles[0];
	FCableParticle& _endParticle = particles[particles.Num() - 1];
}

void FLoiicBetterCablesModule::StartupModule()
{
}

void FLoiicBetterCablesModule::ShutdownModule()
{
}
