// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "LoiicCableComponent.h"

#ifdef LOIICBETTERCABLES_LoiicCableComponent_generated_h
#error "LoiicCableComponent.generated.h already included, missing '#pragma once' in LoiicCableComponent.h"
#endif
#define LOIICBETTERCABLES_LoiicCableComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class AActor;
class USceneComponent;
struct FCableParticle;

// ********** Begin ScriptStruct FCableParticle ****************************************************
#define FID_Users_loicg_Github_LoiicBetterCables_HostProject_Plugins_LoiicBetterCables_Source_LoiicBetterCables_Public_LoiicCableComponent_h_29_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FCableParticle_Statics; \
	LOIICBETTERCABLES_API static class UScriptStruct* StaticStruct();


struct FCableParticle;
// ********** End ScriptStruct FCableParticle ******************************************************

// ********** Begin ScriptStruct FGrammarMesh ******************************************************
#define FID_Users_loicg_Github_LoiicBetterCables_HostProject_Plugins_LoiicBetterCables_Source_LoiicBetterCables_Public_LoiicCableComponent_h_82_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FGrammarMesh_Statics; \
	LOIICBETTERCABLES_API static class UScriptStruct* StaticStruct();


struct FGrammarMesh;
// ********** End ScriptStruct FGrammarMesh ********************************************************

// ********** Begin Delegate FOnBeginOverlap *******************************************************
#define FID_Users_loicg_Github_LoiicBetterCables_HostProject_Plugins_LoiicBetterCables_Source_LoiicBetterCables_Public_LoiicCableComponent_h_244_DELEGATE \
static void FOnBeginOverlap_DelegateWrapper(const FMulticastScriptDelegate& OnBeginOverlap, AActor* _overlappingActor, FCableParticle const& _particleHit);


// ********** End Delegate FOnBeginOverlap *********************************************************

// ********** Begin Delegate FOnEndOverlap *********************************************************
#define FID_Users_loicg_Github_LoiicBetterCables_HostProject_Plugins_LoiicBetterCables_Source_LoiicBetterCables_Public_LoiicCableComponent_h_246_DELEGATE \
static void FOnEndOverlap_DelegateWrapper(const FMulticastScriptDelegate& OnEndOverlap, AActor* _endOverlappingActor);


// ********** End Delegate FOnEndOverlap ***********************************************************

// ********** Begin Class ULoiicCableComponent *****************************************************
#define FID_Users_loicg_Github_LoiicBetterCables_HostProject_Plugins_LoiicBetterCables_Source_LoiicBetterCables_Public_LoiicCableComponent_h_133_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execResetCable); \
	DECLARE_FUNCTION(execStopAllVelocities); \
	DECLARE_FUNCTION(execAddImpulseAtParticleIndex); \
	DECLARE_FUNCTION(execAddImpulseAtParticle); \
	DECLARE_FUNCTION(execGetAttachedParticles); \
	DECLARE_FUNCTION(execDetachParticleIndex); \
	DECLARE_FUNCTION(execDetachParticle); \
	DECLARE_FUNCTION(execAttachParticleIndexToSceneComponent); \
	DECLARE_FUNCTION(execAttachParticleToSceneComponent); \
	DECLARE_FUNCTION(execAttachParticleIndexAtPosition); \
	DECLARE_FUNCTION(execAttachParticleAtPosition); \
	DECLARE_FUNCTION(execGetClosestPositionAlongRopeFromSceneComponent); \
	DECLARE_FUNCTION(execGetClosestPositionAlongRopeFromActor); \
	DECLARE_FUNCTION(execGetClosestPositionAlongRope); \
	DECLARE_FUNCTION(execGetClosestParticleDataFromActor); \
	DECLARE_FUNCTION(execGetClosestParticleDataFromSceneComponent); \
	DECLARE_FUNCTION(execGetClosestParticleData); \
	DECLARE_FUNCTION(execGetPositionAtIndex); \
	DECLARE_FUNCTION(execGetLengthAtPosition); \
	DECLARE_FUNCTION(execGetLengthAtIndex); \
	DECLARE_FUNCTION(execGetPositionAtLength); \
	DECLARE_FUNCTION(execGetCableParticle); \
	DECLARE_FUNCTION(execGetCableParticles); \
	DECLARE_FUNCTION(execGetParticlesCount); \
	DECLARE_FUNCTION(execGetLastAverageVelocityComputed); \
	DECLARE_FUNCTION(execUpdatePreview);


LOIICBETTERCABLES_API UClass* Z_Construct_UClass_ULoiicCableComponent_NoRegister();

#define FID_Users_loicg_Github_LoiicBetterCables_HostProject_Plugins_LoiicBetterCables_Source_LoiicBetterCables_Public_LoiicCableComponent_h_133_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULoiicCableComponent(); \
	friend struct Z_Construct_UClass_ULoiicCableComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend LOIICBETTERCABLES_API UClass* Z_Construct_UClass_ULoiicCableComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(ULoiicCableComponent, UMeshComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/LoiicBetterCables"), Z_Construct_UClass_ULoiicCableComponent_NoRegister) \
	DECLARE_SERIALIZER(ULoiicCableComponent)


#define FID_Users_loicg_Github_LoiicBetterCables_HostProject_Plugins_LoiicBetterCables_Source_LoiicBetterCables_Public_LoiicCableComponent_h_133_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	ULoiicCableComponent(ULoiicCableComponent&&) = delete; \
	ULoiicCableComponent(const ULoiicCableComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULoiicCableComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULoiicCableComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ULoiicCableComponent) \
	NO_API virtual ~ULoiicCableComponent();


#define FID_Users_loicg_Github_LoiicBetterCables_HostProject_Plugins_LoiicBetterCables_Source_LoiicBetterCables_Public_LoiicCableComponent_h_130_PROLOG
#define FID_Users_loicg_Github_LoiicBetterCables_HostProject_Plugins_LoiicBetterCables_Source_LoiicBetterCables_Public_LoiicCableComponent_h_133_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_loicg_Github_LoiicBetterCables_HostProject_Plugins_LoiicBetterCables_Source_LoiicBetterCables_Public_LoiicCableComponent_h_133_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_loicg_Github_LoiicBetterCables_HostProject_Plugins_LoiicBetterCables_Source_LoiicBetterCables_Public_LoiicCableComponent_h_133_INCLASS_NO_PURE_DECLS \
	FID_Users_loicg_Github_LoiicBetterCables_HostProject_Plugins_LoiicBetterCables_Source_LoiicBetterCables_Public_LoiicCableComponent_h_133_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ULoiicCableComponent;

// ********** End Class ULoiicCableComponent *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_loicg_Github_LoiicBetterCables_HostProject_Plugins_LoiicBetterCables_Source_LoiicBetterCables_Public_LoiicCableComponent_h

// ********** Begin Enum EImpulseModifier **********************************************************
#define FOREACH_ENUM_EIMPULSEMODIFIER(op) \
	op(EImpulseDefault) \
	op(EImpulseSpreadsTowardStart) \
	op(EImpulseSpreadsTowardEnd) \
	op(EImpulseSpreadsAround) \
	op(ESpreadAll) 
// ********** End Enum EImpulseModifier ************************************************************

// ********** Begin Enum ERenderType ***************************************************************
#define FOREACH_ENUM_ERENDERTYPE(op) \
	op(Default) \
	op(SplineMeshes) \
	op(StaticMeshes) 
// ********** End Enum ERenderType *****************************************************************

// ********** Begin Enum ECableConstraintType ******************************************************
#define FOREACH_ENUM_ECABLECONSTRAINTTYPE(op) \
	op(EDefaultConstraint) \
	op(ETowardStartConstraint) \
	op(ETowardEndConstraint) 
// ********** End Enum ECableConstraintType ********************************************************

// ********** Begin Enum ECollisionType ************************************************************
#define FOREACH_ENUM_ECOLLISIONTYPE(op) \
	op(ECollisionPrecise) \
	op(ECollisionOptimal) 
// ********** End Enum ECollisionType **************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
