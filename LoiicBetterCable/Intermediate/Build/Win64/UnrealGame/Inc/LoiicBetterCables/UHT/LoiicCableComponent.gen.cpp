// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LoiicCableComponent.h"
#include "Engine/EngineTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeLoiicCableComponent() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UMaterialInstance_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UMeshComponent();
ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FComponentReference();
LOIICBETTERCABLES_API UClass* Z_Construct_UClass_ULoiicCableComponent();
LOIICBETTERCABLES_API UClass* Z_Construct_UClass_ULoiicCableComponent_NoRegister();
LOIICBETTERCABLES_API UEnum* Z_Construct_UEnum_LoiicBetterCables_ECableConstraintType();
LOIICBETTERCABLES_API UEnum* Z_Construct_UEnum_LoiicBetterCables_ECollisionType();
LOIICBETTERCABLES_API UEnum* Z_Construct_UEnum_LoiicBetterCables_EImpulseModifier();
LOIICBETTERCABLES_API UEnum* Z_Construct_UEnum_LoiicBetterCables_ERenderType();
LOIICBETTERCABLES_API UFunction* Z_Construct_UDelegateFunction_ULoiicCableComponent_OnBeginOverlap__DelegateSignature();
LOIICBETTERCABLES_API UFunction* Z_Construct_UDelegateFunction_ULoiicCableComponent_OnEndOverlap__DelegateSignature();
LOIICBETTERCABLES_API UScriptStruct* Z_Construct_UScriptStruct_FCableParticle();
LOIICBETTERCABLES_API UScriptStruct* Z_Construct_UScriptStruct_FGrammarMesh();
UPackage* Z_Construct_UPackage__Script_LoiicBetterCables();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FCableParticle ****************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FCableParticle;
class UScriptStruct* FCableParticle::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FCableParticle.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FCableParticle.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FCableParticle, (UObject*)Z_Construct_UPackage__Script_LoiicBetterCables(), TEXT("CableParticle"));
	}
	return Z_Registration_Info_UScriptStruct_FCableParticle.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FCableParticle_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/** Struct containing information about a point along the cable */" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "Struct containing information about a point along the cable" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bFree_MetaData[] = {
		{ "Category", "Data" },
		{ "Comment", "/** If this point is free (simulating) or fixed to something */" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "If this point is free (simulating) or fixed to something" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_index_MetaData[] = {
		{ "Category", "Data" },
		{ "Comment", "/** The index in the particle array */" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "The index in the particle array" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_position_MetaData[] = {
		{ "Category", "Data" },
		{ "Comment", "/** Current position of point */" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "Current position of point" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_oldPosition_MetaData[] = {
		{ "Category", "Data" },
		{ "Comment", "/** Position of point on previous iteration */" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "Position of point on previous iteration" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_upVector_MetaData[] = {
		{ "Category", "Data" },
		{ "Comment", "/** Up vector, between this particle and the previous, or the simulated previous if is the firs of the list*/" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "Up vector, between this particle and the previous, or the simulated previous if is the firs of the list" },
	};
#endif // WITH_METADATA
	static void NewProp_bFree_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bFree;
	static const UECodeGen_Private::FIntPropertyParams NewProp_index;
	static const UECodeGen_Private::FStructPropertyParams NewProp_position;
	static const UECodeGen_Private::FStructPropertyParams NewProp_oldPosition;
	static const UECodeGen_Private::FStructPropertyParams NewProp_upVector;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCableParticle>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
void Z_Construct_UScriptStruct_FCableParticle_Statics::NewProp_bFree_SetBit(void* Obj)
{
	((FCableParticle*)Obj)->bFree = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FCableParticle_Statics::NewProp_bFree = { "bFree", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FCableParticle), &Z_Construct_UScriptStruct_FCableParticle_Statics::NewProp_bFree_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bFree_MetaData), NewProp_bFree_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FCableParticle_Statics::NewProp_index = { "index", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCableParticle, index), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_index_MetaData), NewProp_index_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCableParticle_Statics::NewProp_position = { "position", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCableParticle, position), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_position_MetaData), NewProp_position_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCableParticle_Statics::NewProp_oldPosition = { "oldPosition", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCableParticle, oldPosition), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_oldPosition_MetaData), NewProp_oldPosition_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCableParticle_Statics::NewProp_upVector = { "upVector", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCableParticle, upVector), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_upVector_MetaData), NewProp_upVector_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCableParticle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCableParticle_Statics::NewProp_bFree,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCableParticle_Statics::NewProp_index,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCableParticle_Statics::NewProp_position,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCableParticle_Statics::NewProp_oldPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCableParticle_Statics::NewProp_upVector,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCableParticle_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCableParticle_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_LoiicBetterCables,
	nullptr,
	&NewStructOps,
	"CableParticle",
	Z_Construct_UScriptStruct_FCableParticle_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCableParticle_Statics::PropPointers),
	sizeof(FCableParticle),
	alignof(FCableParticle),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCableParticle_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FCableParticle_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FCableParticle()
{
	if (!Z_Registration_Info_UScriptStruct_FCableParticle.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FCableParticle.InnerSingleton, Z_Construct_UScriptStruct_FCableParticle_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FCableParticle.InnerSingleton;
}
// ********** End ScriptStruct FCableParticle ******************************************************

// ********** Begin ScriptStruct FGrammarMesh ******************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FGrammarMesh;
class UScriptStruct* FGrammarMesh::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FGrammarMesh.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FGrammarMesh.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FGrammarMesh, (UObject*)Z_Construct_UPackage__Script_LoiicBetterCables(), TEXT("GrammarMesh"));
	}
	return Z_Registration_Info_UScriptStruct_FGrammarMesh.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FGrammarMesh_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_tag_MetaData[] = {
		{ "Category", "Data" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_staticMesh_MetaData[] = {
		{ "Category", "Data" },
		{ "Comment", "//UPROPERTY(EditAnywhere) TArray<TObjectPtr<UStaticMesh>> grammarStaticMeshes;\n" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "UPROPERTY(EditAnywhere) TArray<TObjectPtr<UStaticMesh>> grammarStaticMeshes;" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_material_MetaData[] = {
		{ "Category", "Data" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_tag;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_staticMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_material;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FGrammarMesh>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FGrammarMesh_Statics::NewProp_tag = { "tag", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGrammarMesh, tag), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_tag_MetaData), NewProp_tag_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FGrammarMesh_Statics::NewProp_staticMesh = { "staticMesh", nullptr, (EPropertyFlags)0x0114000000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGrammarMesh, staticMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_staticMesh_MetaData), NewProp_staticMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FGrammarMesh_Statics::NewProp_material = { "material", nullptr, (EPropertyFlags)0x0114000000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGrammarMesh, material), Z_Construct_UClass_UMaterialInstance_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_material_MetaData), NewProp_material_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FGrammarMesh_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGrammarMesh_Statics::NewProp_tag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGrammarMesh_Statics::NewProp_staticMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGrammarMesh_Statics::NewProp_material,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGrammarMesh_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FGrammarMesh_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_LoiicBetterCables,
	nullptr,
	&NewStructOps,
	"GrammarMesh",
	Z_Construct_UScriptStruct_FGrammarMesh_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGrammarMesh_Statics::PropPointers),
	sizeof(FGrammarMesh),
	alignof(FGrammarMesh),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGrammarMesh_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FGrammarMesh_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FGrammarMesh()
{
	if (!Z_Registration_Info_UScriptStruct_FGrammarMesh.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FGrammarMesh.InnerSingleton, Z_Construct_UScriptStruct_FGrammarMesh_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FGrammarMesh.InnerSingleton;
}
// ********** End ScriptStruct FGrammarMesh ********************************************************

// ********** Begin Enum EImpulseModifier **********************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EImpulseModifier;
static UEnum* EImpulseModifier_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EImpulseModifier.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EImpulseModifier.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_LoiicBetterCables_EImpulseModifier, (UObject*)Z_Construct_UPackage__Script_LoiicBetterCables(), TEXT("EImpulseModifier"));
	}
	return Z_Registration_Info_UEnum_EImpulseModifier.OuterSingleton;
}
template<> LOIICBETTERCABLES_API UEnum* StaticEnum<EImpulseModifier>()
{
	return EImpulseModifier_StaticEnum();
}
struct Z_Construct_UEnum_LoiicBetterCables_EImpulseModifier_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "EImpulseDefault.Name", "EImpulseDefault" },
		{ "EImpulseSpreadsAround.Name", "EImpulseSpreadsAround" },
		{ "EImpulseSpreadsTowardEnd.Name", "EImpulseSpreadsTowardEnd" },
		{ "EImpulseSpreadsTowardStart.Name", "EImpulseSpreadsTowardStart" },
		{ "ESpreadAll.Name", "ESpreadAll" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EImpulseDefault", (int64)EImpulseDefault },
		{ "EImpulseSpreadsTowardStart", (int64)EImpulseSpreadsTowardStart },
		{ "EImpulseSpreadsTowardEnd", (int64)EImpulseSpreadsTowardEnd },
		{ "EImpulseSpreadsAround", (int64)EImpulseSpreadsAround },
		{ "ESpreadAll", (int64)ESpreadAll },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_LoiicBetterCables_EImpulseModifier_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_LoiicBetterCables,
	nullptr,
	"EImpulseModifier",
	"EImpulseModifier",
	Z_Construct_UEnum_LoiicBetterCables_EImpulseModifier_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_LoiicBetterCables_EImpulseModifier_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::Regular,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_LoiicBetterCables_EImpulseModifier_Statics::Enum_MetaDataParams), Z_Construct_UEnum_LoiicBetterCables_EImpulseModifier_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_LoiicBetterCables_EImpulseModifier()
{
	if (!Z_Registration_Info_UEnum_EImpulseModifier.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EImpulseModifier.InnerSingleton, Z_Construct_UEnum_LoiicBetterCables_EImpulseModifier_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EImpulseModifier.InnerSingleton;
}
// ********** End Enum EImpulseModifier ************************************************************

// ********** Begin Enum ERenderType ***************************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ERenderType;
static UEnum* ERenderType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ERenderType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ERenderType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_LoiicBetterCables_ERenderType, (UObject*)Z_Construct_UPackage__Script_LoiicBetterCables(), TEXT("ERenderType"));
	}
	return Z_Registration_Info_UEnum_ERenderType.OuterSingleton;
}
template<> LOIICBETTERCABLES_API UEnum* StaticEnum<ERenderType>()
{
	return ERenderType_StaticEnum();
}
struct Z_Construct_UEnum_LoiicBetterCables_ERenderType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Default.Name", "Default" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "SplineMeshes.Name", "SplineMeshes" },
		{ "StaticMeshes.Name", "StaticMeshes" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "Default", (int64)Default },
		{ "SplineMeshes", (int64)SplineMeshes },
		{ "StaticMeshes", (int64)StaticMeshes },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_LoiicBetterCables_ERenderType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_LoiicBetterCables,
	nullptr,
	"ERenderType",
	"ERenderType",
	Z_Construct_UEnum_LoiicBetterCables_ERenderType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_LoiicBetterCables_ERenderType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::Regular,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_LoiicBetterCables_ERenderType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_LoiicBetterCables_ERenderType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_LoiicBetterCables_ERenderType()
{
	if (!Z_Registration_Info_UEnum_ERenderType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ERenderType.InnerSingleton, Z_Construct_UEnum_LoiicBetterCables_ERenderType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ERenderType.InnerSingleton;
}
// ********** End Enum ERenderType *****************************************************************

// ********** Begin Enum ECableConstraintType ******************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ECableConstraintType;
static UEnum* ECableConstraintType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ECableConstraintType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ECableConstraintType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_LoiicBetterCables_ECableConstraintType, (UObject*)Z_Construct_UPackage__Script_LoiicBetterCables(), TEXT("ECableConstraintType"));
	}
	return Z_Registration_Info_UEnum_ECableConstraintType.OuterSingleton;
}
template<> LOIICBETTERCABLES_API UEnum* StaticEnum<ECableConstraintType>()
{
	return ECableConstraintType_StaticEnum();
}
struct Z_Construct_UEnum_LoiicBetterCables_ECableConstraintType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "EDefaultConstraint.Name", "EDefaultConstraint" },
		{ "ETowardEndConstraint.Name", "ETowardEndConstraint" },
		{ "ETowardStartConstraint.Name", "ETowardStartConstraint" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EDefaultConstraint", (int64)EDefaultConstraint },
		{ "ETowardStartConstraint", (int64)ETowardStartConstraint },
		{ "ETowardEndConstraint", (int64)ETowardEndConstraint },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_LoiicBetterCables_ECableConstraintType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_LoiicBetterCables,
	nullptr,
	"ECableConstraintType",
	"ECableConstraintType",
	Z_Construct_UEnum_LoiicBetterCables_ECableConstraintType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_LoiicBetterCables_ECableConstraintType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::Regular,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_LoiicBetterCables_ECableConstraintType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_LoiicBetterCables_ECableConstraintType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_LoiicBetterCables_ECableConstraintType()
{
	if (!Z_Registration_Info_UEnum_ECableConstraintType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ECableConstraintType.InnerSingleton, Z_Construct_UEnum_LoiicBetterCables_ECableConstraintType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ECableConstraintType.InnerSingleton;
}
// ********** End Enum ECableConstraintType ********************************************************

// ********** Begin Enum ECollisionType ************************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ECollisionType;
static UEnum* ECollisionType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ECollisionType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ECollisionType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_LoiicBetterCables_ECollisionType, (UObject*)Z_Construct_UPackage__Script_LoiicBetterCables(), TEXT("ECollisionType"));
	}
	return Z_Registration_Info_UEnum_ECollisionType.OuterSingleton;
}
template<> LOIICBETTERCABLES_API UEnum* StaticEnum<ECollisionType>()
{
	return ECollisionType_StaticEnum();
}
struct Z_Construct_UEnum_LoiicBetterCables_ECollisionType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "ECollisionOptimal.Name", "ECollisionOptimal" },
		{ "ECollisionPrecise.Name", "ECollisionPrecise" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ECollisionPrecise", (int64)ECollisionPrecise },
		{ "ECollisionOptimal", (int64)ECollisionOptimal },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_LoiicBetterCables_ECollisionType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_LoiicBetterCables,
	nullptr,
	"ECollisionType",
	"ECollisionType",
	Z_Construct_UEnum_LoiicBetterCables_ECollisionType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_LoiicBetterCables_ECollisionType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::Regular,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_LoiicBetterCables_ECollisionType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_LoiicBetterCables_ECollisionType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_LoiicBetterCables_ECollisionType()
{
	if (!Z_Registration_Info_UEnum_ECollisionType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ECollisionType.InnerSingleton, Z_Construct_UEnum_LoiicBetterCables_ECollisionType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ECollisionType.InnerSingleton;
}
// ********** End Enum ECollisionType **************************************************************

// ********** Begin Delegate FOnBeginOverlap *******************************************************
struct Z_Construct_UDelegateFunction_ULoiicCableComponent_OnBeginOverlap__DelegateSignature_Statics
{
	struct LoiicCableComponent_eventOnBeginOverlap_Parms
	{
		AActor* _overlappingActor;
		FCableParticle _particleHit;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__particleHit_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp__overlappingActor;
	static const UECodeGen_Private::FStructPropertyParams NewProp__particleHit;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_ULoiicCableComponent_OnBeginOverlap__DelegateSignature_Statics::NewProp__overlappingActor = { "_overlappingActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LoiicCableComponent_eventOnBeginOverlap_Parms, _overlappingActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_ULoiicCableComponent_OnBeginOverlap__DelegateSignature_Statics::NewProp__particleHit = { "_particleHit", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LoiicCableComponent_eventOnBeginOverlap_Parms, _particleHit), Z_Construct_UScriptStruct_FCableParticle, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__particleHit_MetaData), NewProp__particleHit_MetaData) }; // 2651070506
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ULoiicCableComponent_OnBeginOverlap__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ULoiicCableComponent_OnBeginOverlap__DelegateSignature_Statics::NewProp__overlappingActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ULoiicCableComponent_OnBeginOverlap__DelegateSignature_Statics::NewProp__particleHit,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ULoiicCableComponent_OnBeginOverlap__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_ULoiicCableComponent_OnBeginOverlap__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULoiicCableComponent, nullptr, "OnBeginOverlap__DelegateSignature", Z_Construct_UDelegateFunction_ULoiicCableComponent_OnBeginOverlap__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ULoiicCableComponent_OnBeginOverlap__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_ULoiicCableComponent_OnBeginOverlap__DelegateSignature_Statics::LoiicCableComponent_eventOnBeginOverlap_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ULoiicCableComponent_OnBeginOverlap__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_ULoiicCableComponent_OnBeginOverlap__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_ULoiicCableComponent_OnBeginOverlap__DelegateSignature_Statics::LoiicCableComponent_eventOnBeginOverlap_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_ULoiicCableComponent_OnBeginOverlap__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ULoiicCableComponent_OnBeginOverlap__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void ULoiicCableComponent::FOnBeginOverlap_DelegateWrapper(const FMulticastScriptDelegate& OnBeginOverlap, AActor* _overlappingActor, FCableParticle const& _particleHit)
{
	struct LoiicCableComponent_eventOnBeginOverlap_Parms
	{
		AActor* _overlappingActor;
		FCableParticle _particleHit;
	};
	LoiicCableComponent_eventOnBeginOverlap_Parms Parms;
	Parms._overlappingActor=_overlappingActor;
	Parms._particleHit=_particleHit;
	OnBeginOverlap.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnBeginOverlap *********************************************************

// ********** Begin Delegate FOnEndOverlap *********************************************************
struct Z_Construct_UDelegateFunction_ULoiicCableComponent_OnEndOverlap__DelegateSignature_Statics
{
	struct LoiicCableComponent_eventOnEndOverlap_Parms
	{
		AActor* _endOverlappingActor;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp__endOverlappingActor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_ULoiicCableComponent_OnEndOverlap__DelegateSignature_Statics::NewProp__endOverlappingActor = { "_endOverlappingActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LoiicCableComponent_eventOnEndOverlap_Parms, _endOverlappingActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ULoiicCableComponent_OnEndOverlap__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ULoiicCableComponent_OnEndOverlap__DelegateSignature_Statics::NewProp__endOverlappingActor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ULoiicCableComponent_OnEndOverlap__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_ULoiicCableComponent_OnEndOverlap__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULoiicCableComponent, nullptr, "OnEndOverlap__DelegateSignature", Z_Construct_UDelegateFunction_ULoiicCableComponent_OnEndOverlap__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ULoiicCableComponent_OnEndOverlap__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_ULoiicCableComponent_OnEndOverlap__DelegateSignature_Statics::LoiicCableComponent_eventOnEndOverlap_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ULoiicCableComponent_OnEndOverlap__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_ULoiicCableComponent_OnEndOverlap__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_ULoiicCableComponent_OnEndOverlap__DelegateSignature_Statics::LoiicCableComponent_eventOnEndOverlap_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_ULoiicCableComponent_OnEndOverlap__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ULoiicCableComponent_OnEndOverlap__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void ULoiicCableComponent::FOnEndOverlap_DelegateWrapper(const FMulticastScriptDelegate& OnEndOverlap, AActor* _endOverlappingActor)
{
	struct LoiicCableComponent_eventOnEndOverlap_Parms
	{
		AActor* _endOverlappingActor;
	};
	LoiicCableComponent_eventOnEndOverlap_Parms Parms;
	Parms._endOverlappingActor=_endOverlappingActor;
	OnEndOverlap.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnEndOverlap ***********************************************************

// ********** Begin Class ULoiicCableComponent Function AddImpulseAtParticle ***********************
struct Z_Construct_UFunction_ULoiicCableComponent_AddImpulseAtParticle_Statics
{
	struct LoiicCableComponent_eventAddImpulseAtParticle_Parms
	{
		FCableParticle _particleToInpulse;
		FVector _vector;
		TEnumAsByte<EImpulseModifier> _impulse;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AutoCreateRefTerm", "_impulse" },
		{ "Category", "Cable|Utility" },
		{ "Comment", "/// <summary>\n/// Add an inpulse at a particle. \n/// If the particle is attached, this will have no effect.\n/// </summary>\n" },
		{ "CPP_Default__impulse", "EImpulseDefault" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "<summary>\nAdd an inpulse at a particle.\nIf the particle is attached, this will have no effect.\n</summary>" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__particleToInpulse_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__vector_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__impulse_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp__particleToInpulse;
	static const UECodeGen_Private::FStructPropertyParams NewProp__vector;
	static const UECodeGen_Private::FBytePropertyParams NewProp__impulse;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULoiicCableComponent_AddImpulseAtParticle_Statics::NewProp__particleToInpulse = { "_particleToInpulse", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LoiicCableComponent_eventAddImpulseAtParticle_Parms, _particleToInpulse), Z_Construct_UScriptStruct_FCableParticle, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__particleToInpulse_MetaData), NewProp__particleToInpulse_MetaData) }; // 2651070506
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULoiicCableComponent_AddImpulseAtParticle_Statics::NewProp__vector = { "_vector", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LoiicCableComponent_eventAddImpulseAtParticle_Parms, _vector), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__vector_MetaData), NewProp__vector_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_ULoiicCableComponent_AddImpulseAtParticle_Statics::NewProp__impulse = { "_impulse", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LoiicCableComponent_eventAddImpulseAtParticle_Parms, _impulse), Z_Construct_UEnum_LoiicBetterCables_EImpulseModifier, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__impulse_MetaData), NewProp__impulse_MetaData) }; // 1234036419
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULoiicCableComponent_AddImpulseAtParticle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoiicCableComponent_AddImpulseAtParticle_Statics::NewProp__particleToInpulse,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoiicCableComponent_AddImpulseAtParticle_Statics::NewProp__vector,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoiicCableComponent_AddImpulseAtParticle_Statics::NewProp__impulse,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_AddImpulseAtParticle_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULoiicCableComponent_AddImpulseAtParticle_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULoiicCableComponent, nullptr, "AddImpulseAtParticle", Z_Construct_UFunction_ULoiicCableComponent_AddImpulseAtParticle_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_AddImpulseAtParticle_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULoiicCableComponent_AddImpulseAtParticle_Statics::LoiicCableComponent_eventAddImpulseAtParticle_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_AddImpulseAtParticle_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULoiicCableComponent_AddImpulseAtParticle_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULoiicCableComponent_AddImpulseAtParticle_Statics::LoiicCableComponent_eventAddImpulseAtParticle_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULoiicCableComponent_AddImpulseAtParticle()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULoiicCableComponent_AddImpulseAtParticle_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULoiicCableComponent::execAddImpulseAtParticle)
{
	P_GET_STRUCT_REF(FCableParticle,Z_Param_Out__particleToInpulse);
	P_GET_STRUCT_REF(FVector,Z_Param_Out__vector);
	P_GET_PROPERTY_REF(FByteProperty,Z_Param_Out__impulse);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AddImpulseAtParticle(Z_Param_Out__particleToInpulse,Z_Param_Out__vector,(TEnumAsByte<EImpulseModifier>&)(Z_Param_Out__impulse));
	P_NATIVE_END;
}
// ********** End Class ULoiicCableComponent Function AddImpulseAtParticle *************************

// ********** Begin Class ULoiicCableComponent Function AddImpulseAtParticleIndex ******************
struct Z_Construct_UFunction_ULoiicCableComponent_AddImpulseAtParticleIndex_Statics
{
	struct LoiicCableComponent_eventAddImpulseAtParticleIndex_Parms
	{
		int32 _particleIndexToInpulse;
		FVector _vector;
		TEnumAsByte<EImpulseModifier> _impulse;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AutoCreateRefTerm", "_impulse" },
		{ "Category", "Cable|Utility" },
		{ "Comment", "/// <summary>\n/// Add an inpulse at a particle using it's index. \n/// If the particle is attached, this will have no effect.\n/// </summary>\n" },
		{ "CPP_Default__impulse", "EImpulseDefault" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "<summary>\nAdd an inpulse at a particle using it's index.\nIf the particle is attached, this will have no effect.\n</summary>" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__particleIndexToInpulse_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__vector_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__impulse_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp__particleIndexToInpulse;
	static const UECodeGen_Private::FStructPropertyParams NewProp__vector;
	static const UECodeGen_Private::FBytePropertyParams NewProp__impulse;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ULoiicCableComponent_AddImpulseAtParticleIndex_Statics::NewProp__particleIndexToInpulse = { "_particleIndexToInpulse", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LoiicCableComponent_eventAddImpulseAtParticleIndex_Parms, _particleIndexToInpulse), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__particleIndexToInpulse_MetaData), NewProp__particleIndexToInpulse_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULoiicCableComponent_AddImpulseAtParticleIndex_Statics::NewProp__vector = { "_vector", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LoiicCableComponent_eventAddImpulseAtParticleIndex_Parms, _vector), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__vector_MetaData), NewProp__vector_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_ULoiicCableComponent_AddImpulseAtParticleIndex_Statics::NewProp__impulse = { "_impulse", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LoiicCableComponent_eventAddImpulseAtParticleIndex_Parms, _impulse), Z_Construct_UEnum_LoiicBetterCables_EImpulseModifier, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__impulse_MetaData), NewProp__impulse_MetaData) }; // 1234036419
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULoiicCableComponent_AddImpulseAtParticleIndex_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoiicCableComponent_AddImpulseAtParticleIndex_Statics::NewProp__particleIndexToInpulse,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoiicCableComponent_AddImpulseAtParticleIndex_Statics::NewProp__vector,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoiicCableComponent_AddImpulseAtParticleIndex_Statics::NewProp__impulse,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_AddImpulseAtParticleIndex_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULoiicCableComponent_AddImpulseAtParticleIndex_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULoiicCableComponent, nullptr, "AddImpulseAtParticleIndex", Z_Construct_UFunction_ULoiicCableComponent_AddImpulseAtParticleIndex_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_AddImpulseAtParticleIndex_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULoiicCableComponent_AddImpulseAtParticleIndex_Statics::LoiicCableComponent_eventAddImpulseAtParticleIndex_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_AddImpulseAtParticleIndex_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULoiicCableComponent_AddImpulseAtParticleIndex_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULoiicCableComponent_AddImpulseAtParticleIndex_Statics::LoiicCableComponent_eventAddImpulseAtParticleIndex_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULoiicCableComponent_AddImpulseAtParticleIndex()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULoiicCableComponent_AddImpulseAtParticleIndex_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULoiicCableComponent::execAddImpulseAtParticleIndex)
{
	P_GET_PROPERTY(FIntProperty,Z_Param__particleIndexToInpulse);
	P_GET_STRUCT_REF(FVector,Z_Param_Out__vector);
	P_GET_PROPERTY_REF(FByteProperty,Z_Param_Out__impulse);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AddImpulseAtParticleIndex(Z_Param__particleIndexToInpulse,Z_Param_Out__vector,(TEnumAsByte<EImpulseModifier>&)(Z_Param_Out__impulse));
	P_NATIVE_END;
}
// ********** End Class ULoiicCableComponent Function AddImpulseAtParticleIndex ********************

// ********** Begin Class ULoiicCableComponent Function AttachParticleAtPosition *******************
struct Z_Construct_UFunction_ULoiicCableComponent_AttachParticleAtPosition_Statics
{
	struct LoiicCableComponent_eventAttachParticleAtPosition_Parms
	{
		FCableParticle _particleToAttach;
		FVector _position;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cable|Utility" },
		{ "Comment", "/// <summary>\n/// Attach a particle to a position, freezing the particle, meaning it is no longer affected by gravity.\n/// </summary>\n" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "<summary>\nAttach a particle to a position, freezing the particle, meaning it is no longer affected by gravity.\n</summary>" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__particleToAttach_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__position_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp__particleToAttach;
	static const UECodeGen_Private::FStructPropertyParams NewProp__position;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULoiicCableComponent_AttachParticleAtPosition_Statics::NewProp__particleToAttach = { "_particleToAttach", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LoiicCableComponent_eventAttachParticleAtPosition_Parms, _particleToAttach), Z_Construct_UScriptStruct_FCableParticle, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__particleToAttach_MetaData), NewProp__particleToAttach_MetaData) }; // 2651070506
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULoiicCableComponent_AttachParticleAtPosition_Statics::NewProp__position = { "_position", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LoiicCableComponent_eventAttachParticleAtPosition_Parms, _position), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__position_MetaData), NewProp__position_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULoiicCableComponent_AttachParticleAtPosition_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoiicCableComponent_AttachParticleAtPosition_Statics::NewProp__particleToAttach,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoiicCableComponent_AttachParticleAtPosition_Statics::NewProp__position,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_AttachParticleAtPosition_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULoiicCableComponent_AttachParticleAtPosition_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULoiicCableComponent, nullptr, "AttachParticleAtPosition", Z_Construct_UFunction_ULoiicCableComponent_AttachParticleAtPosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_AttachParticleAtPosition_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULoiicCableComponent_AttachParticleAtPosition_Statics::LoiicCableComponent_eventAttachParticleAtPosition_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_AttachParticleAtPosition_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULoiicCableComponent_AttachParticleAtPosition_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULoiicCableComponent_AttachParticleAtPosition_Statics::LoiicCableComponent_eventAttachParticleAtPosition_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULoiicCableComponent_AttachParticleAtPosition()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULoiicCableComponent_AttachParticleAtPosition_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULoiicCableComponent::execAttachParticleAtPosition)
{
	P_GET_STRUCT_REF(FCableParticle,Z_Param_Out__particleToAttach);
	P_GET_STRUCT_REF(FVector,Z_Param_Out__position);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AttachParticleAtPosition(Z_Param_Out__particleToAttach,Z_Param_Out__position);
	P_NATIVE_END;
}
// ********** End Class ULoiicCableComponent Function AttachParticleAtPosition *********************

// ********** Begin Class ULoiicCableComponent Function AttachParticleIndexAtPosition **************
struct Z_Construct_UFunction_ULoiicCableComponent_AttachParticleIndexAtPosition_Statics
{
	struct LoiicCableComponent_eventAttachParticleIndexAtPosition_Parms
	{
		int32 _indexOfParticleToAttach;
		FVector _position;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cable|Utility" },
		{ "Comment", "/// <summary>\n/// Attach a particle to a position using the index of the particle, freezing the particle, meaning it is no longer affected by gravity.\n/// </summary>\n" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "<summary>\nAttach a particle to a position using the index of the particle, freezing the particle, meaning it is no longer affected by gravity.\n</summary>" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__indexOfParticleToAttach_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__position_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp__indexOfParticleToAttach;
	static const UECodeGen_Private::FStructPropertyParams NewProp__position;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ULoiicCableComponent_AttachParticleIndexAtPosition_Statics::NewProp__indexOfParticleToAttach = { "_indexOfParticleToAttach", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LoiicCableComponent_eventAttachParticleIndexAtPosition_Parms, _indexOfParticleToAttach), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__indexOfParticleToAttach_MetaData), NewProp__indexOfParticleToAttach_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULoiicCableComponent_AttachParticleIndexAtPosition_Statics::NewProp__position = { "_position", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LoiicCableComponent_eventAttachParticleIndexAtPosition_Parms, _position), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__position_MetaData), NewProp__position_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULoiicCableComponent_AttachParticleIndexAtPosition_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoiicCableComponent_AttachParticleIndexAtPosition_Statics::NewProp__indexOfParticleToAttach,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoiicCableComponent_AttachParticleIndexAtPosition_Statics::NewProp__position,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_AttachParticleIndexAtPosition_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULoiicCableComponent_AttachParticleIndexAtPosition_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULoiicCableComponent, nullptr, "AttachParticleIndexAtPosition", Z_Construct_UFunction_ULoiicCableComponent_AttachParticleIndexAtPosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_AttachParticleIndexAtPosition_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULoiicCableComponent_AttachParticleIndexAtPosition_Statics::LoiicCableComponent_eventAttachParticleIndexAtPosition_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_AttachParticleIndexAtPosition_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULoiicCableComponent_AttachParticleIndexAtPosition_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULoiicCableComponent_AttachParticleIndexAtPosition_Statics::LoiicCableComponent_eventAttachParticleIndexAtPosition_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULoiicCableComponent_AttachParticleIndexAtPosition()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULoiicCableComponent_AttachParticleIndexAtPosition_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULoiicCableComponent::execAttachParticleIndexAtPosition)
{
	P_GET_PROPERTY(FIntProperty,Z_Param__indexOfParticleToAttach);
	P_GET_STRUCT_REF(FVector,Z_Param_Out__position);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AttachParticleIndexAtPosition(Z_Param__indexOfParticleToAttach,Z_Param_Out__position);
	P_NATIVE_END;
}
// ********** End Class ULoiicCableComponent Function AttachParticleIndexAtPosition ****************

// ********** Begin Class ULoiicCableComponent Function AttachParticleIndexToSceneComponent ********
struct Z_Construct_UFunction_ULoiicCableComponent_AttachParticleIndexToSceneComponent_Statics
{
	struct LoiicCableComponent_eventAttachParticleIndexToSceneComponent_Parms
	{
		int32 _particleIndexToAttach;
		USceneComponent* _sceneComponent;
		FName _optionnalSocket;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AutoCreateRefTerm", "_optionnalSocket" },
		{ "Category", "Cable|Utility" },
		{ "Comment", "/// <summary>\n/// Attach a particle to a scene component using the index of the particle, freezing the particle, meaning it is no longer affected by gravity.\n/// It will follow the scene component.\n/// </summary>\n" },
		{ "CPP_Default__optionnalSocket", "None" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "<summary>\nAttach a particle to a scene component using the index of the particle, freezing the particle, meaning it is no longer affected by gravity.\nIt will follow the scene component.\n</summary>" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__particleIndexToAttach_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__sceneComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__optionnalSocket_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp__particleIndexToAttach;
	static const UECodeGen_Private::FObjectPropertyParams NewProp__sceneComponent;
	static const UECodeGen_Private::FNamePropertyParams NewProp__optionnalSocket;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ULoiicCableComponent_AttachParticleIndexToSceneComponent_Statics::NewProp__particleIndexToAttach = { "_particleIndexToAttach", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LoiicCableComponent_eventAttachParticleIndexToSceneComponent_Parms, _particleIndexToAttach), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__particleIndexToAttach_MetaData), NewProp__particleIndexToAttach_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULoiicCableComponent_AttachParticleIndexToSceneComponent_Statics::NewProp__sceneComponent = { "_sceneComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LoiicCableComponent_eventAttachParticleIndexToSceneComponent_Parms, _sceneComponent), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__sceneComponent_MetaData), NewProp__sceneComponent_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ULoiicCableComponent_AttachParticleIndexToSceneComponent_Statics::NewProp__optionnalSocket = { "_optionnalSocket", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LoiicCableComponent_eventAttachParticleIndexToSceneComponent_Parms, _optionnalSocket), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__optionnalSocket_MetaData), NewProp__optionnalSocket_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULoiicCableComponent_AttachParticleIndexToSceneComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoiicCableComponent_AttachParticleIndexToSceneComponent_Statics::NewProp__particleIndexToAttach,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoiicCableComponent_AttachParticleIndexToSceneComponent_Statics::NewProp__sceneComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoiicCableComponent_AttachParticleIndexToSceneComponent_Statics::NewProp__optionnalSocket,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_AttachParticleIndexToSceneComponent_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULoiicCableComponent_AttachParticleIndexToSceneComponent_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULoiicCableComponent, nullptr, "AttachParticleIndexToSceneComponent", Z_Construct_UFunction_ULoiicCableComponent_AttachParticleIndexToSceneComponent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_AttachParticleIndexToSceneComponent_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULoiicCableComponent_AttachParticleIndexToSceneComponent_Statics::LoiicCableComponent_eventAttachParticleIndexToSceneComponent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_AttachParticleIndexToSceneComponent_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULoiicCableComponent_AttachParticleIndexToSceneComponent_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULoiicCableComponent_AttachParticleIndexToSceneComponent_Statics::LoiicCableComponent_eventAttachParticleIndexToSceneComponent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULoiicCableComponent_AttachParticleIndexToSceneComponent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULoiicCableComponent_AttachParticleIndexToSceneComponent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULoiicCableComponent::execAttachParticleIndexToSceneComponent)
{
	P_GET_PROPERTY(FIntProperty,Z_Param__particleIndexToAttach);
	P_GET_OBJECT(USceneComponent,Z_Param__sceneComponent);
	P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out__optionnalSocket);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AttachParticleIndexToSceneComponent(Z_Param__particleIndexToAttach,Z_Param__sceneComponent,Z_Param_Out__optionnalSocket);
	P_NATIVE_END;
}
// ********** End Class ULoiicCableComponent Function AttachParticleIndexToSceneComponent **********

// ********** Begin Class ULoiicCableComponent Function AttachParticleToSceneComponent *************
struct Z_Construct_UFunction_ULoiicCableComponent_AttachParticleToSceneComponent_Statics
{
	struct LoiicCableComponent_eventAttachParticleToSceneComponent_Parms
	{
		FCableParticle _particleToAttach;
		USceneComponent* _sceneComponent;
		FName _optionnalSocket;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AutoCreateRefTerm", "_optionnalSocket" },
		{ "Category", "Cable|Utility" },
		{ "Comment", "/// <summary>\n/// Attach a particle to a scene component, freezing the particle, meaning it is no longer affected by gravity.\n/// It will follow the scene component.\n/// </summary>\n" },
		{ "CPP_Default__optionnalSocket", "None" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "<summary>\nAttach a particle to a scene component, freezing the particle, meaning it is no longer affected by gravity.\nIt will follow the scene component.\n</summary>" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__particleToAttach_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__sceneComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__optionnalSocket_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp__particleToAttach;
	static const UECodeGen_Private::FObjectPropertyParams NewProp__sceneComponent;
	static const UECodeGen_Private::FNamePropertyParams NewProp__optionnalSocket;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULoiicCableComponent_AttachParticleToSceneComponent_Statics::NewProp__particleToAttach = { "_particleToAttach", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LoiicCableComponent_eventAttachParticleToSceneComponent_Parms, _particleToAttach), Z_Construct_UScriptStruct_FCableParticle, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__particleToAttach_MetaData), NewProp__particleToAttach_MetaData) }; // 2651070506
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULoiicCableComponent_AttachParticleToSceneComponent_Statics::NewProp__sceneComponent = { "_sceneComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LoiicCableComponent_eventAttachParticleToSceneComponent_Parms, _sceneComponent), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__sceneComponent_MetaData), NewProp__sceneComponent_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ULoiicCableComponent_AttachParticleToSceneComponent_Statics::NewProp__optionnalSocket = { "_optionnalSocket", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LoiicCableComponent_eventAttachParticleToSceneComponent_Parms, _optionnalSocket), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__optionnalSocket_MetaData), NewProp__optionnalSocket_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULoiicCableComponent_AttachParticleToSceneComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoiicCableComponent_AttachParticleToSceneComponent_Statics::NewProp__particleToAttach,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoiicCableComponent_AttachParticleToSceneComponent_Statics::NewProp__sceneComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoiicCableComponent_AttachParticleToSceneComponent_Statics::NewProp__optionnalSocket,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_AttachParticleToSceneComponent_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULoiicCableComponent_AttachParticleToSceneComponent_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULoiicCableComponent, nullptr, "AttachParticleToSceneComponent", Z_Construct_UFunction_ULoiicCableComponent_AttachParticleToSceneComponent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_AttachParticleToSceneComponent_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULoiicCableComponent_AttachParticleToSceneComponent_Statics::LoiicCableComponent_eventAttachParticleToSceneComponent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_AttachParticleToSceneComponent_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULoiicCableComponent_AttachParticleToSceneComponent_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULoiicCableComponent_AttachParticleToSceneComponent_Statics::LoiicCableComponent_eventAttachParticleToSceneComponent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULoiicCableComponent_AttachParticleToSceneComponent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULoiicCableComponent_AttachParticleToSceneComponent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULoiicCableComponent::execAttachParticleToSceneComponent)
{
	P_GET_STRUCT_REF(FCableParticle,Z_Param_Out__particleToAttach);
	P_GET_OBJECT(USceneComponent,Z_Param__sceneComponent);
	P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out__optionnalSocket);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AttachParticleToSceneComponent(Z_Param_Out__particleToAttach,Z_Param__sceneComponent,Z_Param_Out__optionnalSocket);
	P_NATIVE_END;
}
// ********** End Class ULoiicCableComponent Function AttachParticleToSceneComponent ***************

// ********** Begin Class ULoiicCableComponent Function DetachParticle *****************************
struct Z_Construct_UFunction_ULoiicCableComponent_DetachParticle_Statics
{
	struct LoiicCableComponent_eventDetachParticle_Parms
	{
		FCableParticle _particleToDetach;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cable|Utility" },
		{ "Comment", "/// <summary>\n/// Detaching a particle, meaning it's not longer frozen, and is now affected by gravity and constraints.\n/// This methods does nothing if the particle is already free.\n/// </summary>\n" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "<summary>\nDetaching a particle, meaning it's not longer frozen, and is now affected by gravity and constraints.\nThis methods does nothing if the particle is already free.\n</summary>" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__particleToDetach_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp__particleToDetach;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULoiicCableComponent_DetachParticle_Statics::NewProp__particleToDetach = { "_particleToDetach", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LoiicCableComponent_eventDetachParticle_Parms, _particleToDetach), Z_Construct_UScriptStruct_FCableParticle, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__particleToDetach_MetaData), NewProp__particleToDetach_MetaData) }; // 2651070506
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULoiicCableComponent_DetachParticle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoiicCableComponent_DetachParticle_Statics::NewProp__particleToDetach,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_DetachParticle_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULoiicCableComponent_DetachParticle_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULoiicCableComponent, nullptr, "DetachParticle", Z_Construct_UFunction_ULoiicCableComponent_DetachParticle_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_DetachParticle_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULoiicCableComponent_DetachParticle_Statics::LoiicCableComponent_eventDetachParticle_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_DetachParticle_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULoiicCableComponent_DetachParticle_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULoiicCableComponent_DetachParticle_Statics::LoiicCableComponent_eventDetachParticle_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULoiicCableComponent_DetachParticle()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULoiicCableComponent_DetachParticle_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULoiicCableComponent::execDetachParticle)
{
	P_GET_STRUCT_REF(FCableParticle,Z_Param_Out__particleToDetach);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DetachParticle(Z_Param_Out__particleToDetach);
	P_NATIVE_END;
}
// ********** End Class ULoiicCableComponent Function DetachParticle *******************************

// ********** Begin Class ULoiicCableComponent Function DetachParticleIndex ************************
struct Z_Construct_UFunction_ULoiicCableComponent_DetachParticleIndex_Statics
{
	struct LoiicCableComponent_eventDetachParticleIndex_Parms
	{
		int32 _particleIndexToDetach;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cable|Utility" },
		{ "Comment", "/// <summary>\n/// Detaching a particle using the particle's index, meaning it's not longer frozen, and is now affected by gravity and constraints.\n/// This methods does nothing if the particle is already free.\n/// </summary>\n" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "<summary>\nDetaching a particle using the particle's index, meaning it's not longer frozen, and is now affected by gravity and constraints.\nThis methods does nothing if the particle is already free.\n</summary>" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__particleIndexToDetach_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp__particleIndexToDetach;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ULoiicCableComponent_DetachParticleIndex_Statics::NewProp__particleIndexToDetach = { "_particleIndexToDetach", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LoiicCableComponent_eventDetachParticleIndex_Parms, _particleIndexToDetach), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__particleIndexToDetach_MetaData), NewProp__particleIndexToDetach_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULoiicCableComponent_DetachParticleIndex_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoiicCableComponent_DetachParticleIndex_Statics::NewProp__particleIndexToDetach,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_DetachParticleIndex_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULoiicCableComponent_DetachParticleIndex_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULoiicCableComponent, nullptr, "DetachParticleIndex", Z_Construct_UFunction_ULoiicCableComponent_DetachParticleIndex_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_DetachParticleIndex_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULoiicCableComponent_DetachParticleIndex_Statics::LoiicCableComponent_eventDetachParticleIndex_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_DetachParticleIndex_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULoiicCableComponent_DetachParticleIndex_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULoiicCableComponent_DetachParticleIndex_Statics::LoiicCableComponent_eventDetachParticleIndex_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULoiicCableComponent_DetachParticleIndex()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULoiicCableComponent_DetachParticleIndex_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULoiicCableComponent::execDetachParticleIndex)
{
	P_GET_PROPERTY(FIntProperty,Z_Param__particleIndexToDetach);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DetachParticleIndex(Z_Param__particleIndexToDetach);
	P_NATIVE_END;
}
// ********** End Class ULoiicCableComponent Function DetachParticleIndex **************************

// ********** Begin Class ULoiicCableComponent Function GetAttachedParticles ***********************
struct Z_Construct_UFunction_ULoiicCableComponent_GetAttachedParticles_Statics
{
	struct LoiicCableComponent_eventGetAttachedParticles_Parms
	{
		bool _includesStartAndEnd;
		TArray<FCableParticle> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cable|Utility" },
		{ "Comment", "/// <summary>\n/// Returns in an array all the particles that are attached to something.\n/// </summary>\n/// <param name=\"_includesStartAndEnd\">Should return the start and end particle if they are attached ? </param>\n" },
		{ "CPP_Default__includesStartAndEnd", "false" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "<summary>\nReturns in an array all the particles that are attached to something.\n</summary>\n<param name=\"_includesStartAndEnd\">Should return the start and end particle if they are attached ? </param>" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__includesStartAndEnd_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static void NewProp__includesStartAndEnd_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp__includesStartAndEnd;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_ULoiicCableComponent_GetAttachedParticles_Statics::NewProp__includesStartAndEnd_SetBit(void* Obj)
{
	((LoiicCableComponent_eventGetAttachedParticles_Parms*)Obj)->_includesStartAndEnd = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ULoiicCableComponent_GetAttachedParticles_Statics::NewProp__includesStartAndEnd = { "_includesStartAndEnd", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(LoiicCableComponent_eventGetAttachedParticles_Parms), &Z_Construct_UFunction_ULoiicCableComponent_GetAttachedParticles_Statics::NewProp__includesStartAndEnd_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__includesStartAndEnd_MetaData), NewProp__includesStartAndEnd_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULoiicCableComponent_GetAttachedParticles_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FCableParticle, METADATA_PARAMS(0, nullptr) }; // 2651070506
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ULoiicCableComponent_GetAttachedParticles_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LoiicCableComponent_eventGetAttachedParticles_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 2651070506
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULoiicCableComponent_GetAttachedParticles_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoiicCableComponent_GetAttachedParticles_Statics::NewProp__includesStartAndEnd,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoiicCableComponent_GetAttachedParticles_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoiicCableComponent_GetAttachedParticles_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_GetAttachedParticles_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULoiicCableComponent_GetAttachedParticles_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULoiicCableComponent, nullptr, "GetAttachedParticles", Z_Construct_UFunction_ULoiicCableComponent_GetAttachedParticles_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_GetAttachedParticles_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULoiicCableComponent_GetAttachedParticles_Statics::LoiicCableComponent_eventGetAttachedParticles_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_GetAttachedParticles_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULoiicCableComponent_GetAttachedParticles_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULoiicCableComponent_GetAttachedParticles_Statics::LoiicCableComponent_eventGetAttachedParticles_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULoiicCableComponent_GetAttachedParticles()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULoiicCableComponent_GetAttachedParticles_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULoiicCableComponent::execGetAttachedParticles)
{
	P_GET_UBOOL(Z_Param__includesStartAndEnd);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FCableParticle>*)Z_Param__Result=P_THIS->GetAttachedParticles(Z_Param__includesStartAndEnd);
	P_NATIVE_END;
}
// ********** End Class ULoiicCableComponent Function GetAttachedParticles *************************

// ********** Begin Class ULoiicCableComponent Function GetCableParticle ***************************
struct Z_Construct_UFunction_ULoiicCableComponent_GetCableParticle_Statics
{
	struct LoiicCableComponent_eventGetCableParticle_Parms
	{
		int32 _index;
		FCableParticle ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cable|Utility" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__index_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp__index;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ULoiicCableComponent_GetCableParticle_Statics::NewProp__index = { "_index", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LoiicCableComponent_eventGetCableParticle_Parms, _index), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__index_MetaData), NewProp__index_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULoiicCableComponent_GetCableParticle_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LoiicCableComponent_eventGetCableParticle_Parms, ReturnValue), Z_Construct_UScriptStruct_FCableParticle, METADATA_PARAMS(0, nullptr) }; // 2651070506
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULoiicCableComponent_GetCableParticle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoiicCableComponent_GetCableParticle_Statics::NewProp__index,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoiicCableComponent_GetCableParticle_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_GetCableParticle_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULoiicCableComponent_GetCableParticle_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULoiicCableComponent, nullptr, "GetCableParticle", Z_Construct_UFunction_ULoiicCableComponent_GetCableParticle_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_GetCableParticle_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULoiicCableComponent_GetCableParticle_Statics::LoiicCableComponent_eventGetCableParticle_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_GetCableParticle_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULoiicCableComponent_GetCableParticle_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULoiicCableComponent_GetCableParticle_Statics::LoiicCableComponent_eventGetCableParticle_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULoiicCableComponent_GetCableParticle()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULoiicCableComponent_GetCableParticle_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULoiicCableComponent::execGetCableParticle)
{
	P_GET_PROPERTY(FIntProperty,Z_Param__index);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FCableParticle*)Z_Param__Result=P_THIS->GetCableParticle(Z_Param__index);
	P_NATIVE_END;
}
// ********** End Class ULoiicCableComponent Function GetCableParticle *****************************

// ********** Begin Class ULoiicCableComponent Function GetCableParticles **************************
struct Z_Construct_UFunction_ULoiicCableComponent_GetCableParticles_Statics
{
	struct LoiicCableComponent_eventGetCableParticles_Parms
	{
		TArray<FCableParticle> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cable|Utility" },
		{ "Comment", "/// <summary>\n/// Returns the cable particle array\n/// </summary>\n" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "<summary>\nReturns the cable particle array\n</summary>" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULoiicCableComponent_GetCableParticles_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FCableParticle, METADATA_PARAMS(0, nullptr) }; // 2651070506
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ULoiicCableComponent_GetCableParticles_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LoiicCableComponent_eventGetCableParticles_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 2651070506
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULoiicCableComponent_GetCableParticles_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoiicCableComponent_GetCableParticles_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoiicCableComponent_GetCableParticles_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_GetCableParticles_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULoiicCableComponent_GetCableParticles_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULoiicCableComponent, nullptr, "GetCableParticles", Z_Construct_UFunction_ULoiicCableComponent_GetCableParticles_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_GetCableParticles_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULoiicCableComponent_GetCableParticles_Statics::LoiicCableComponent_eventGetCableParticles_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_GetCableParticles_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULoiicCableComponent_GetCableParticles_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULoiicCableComponent_GetCableParticles_Statics::LoiicCableComponent_eventGetCableParticles_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULoiicCableComponent_GetCableParticles()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULoiicCableComponent_GetCableParticles_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULoiicCableComponent::execGetCableParticles)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FCableParticle>*)Z_Param__Result=P_THIS->GetCableParticles();
	P_NATIVE_END;
}
// ********** End Class ULoiicCableComponent Function GetCableParticles ****************************

// ********** Begin Class ULoiicCableComponent Function GetClosestParticleData *********************
struct Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleData_Statics
{
	struct LoiicCableComponent_eventGetClosestParticleData_Parms
	{
		FVector _location;
		FCableParticle ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cable|Utility" },
		{ "Comment", "/// <summary>\n/// This method returns the closest particle to a given location. \n/// A Particle is technically a segment's position.\n/// </summary>\n/// <param name=\"_location\">Location in world space</param>\n/// <returns>Particle data struct</returns>\n" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "<summary>\nThis method returns the closest particle to a given location.\nA Particle is technically a segment's position.\n</summary>\n<param name=\"_location\">Location in world space</param>\n<returns>Particle data struct</returns>" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__location_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp__location;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleData_Statics::NewProp__location = { "_location", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LoiicCableComponent_eventGetClosestParticleData_Parms, _location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__location_MetaData), NewProp__location_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LoiicCableComponent_eventGetClosestParticleData_Parms, ReturnValue), Z_Construct_UScriptStruct_FCableParticle, METADATA_PARAMS(0, nullptr) }; // 2651070506
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleData_Statics::NewProp__location,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleData_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULoiicCableComponent, nullptr, "GetClosestParticleData", Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleData_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleData_Statics::LoiicCableComponent_eventGetClosestParticleData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleData_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleData_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleData_Statics::LoiicCableComponent_eventGetClosestParticleData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULoiicCableComponent::execGetClosestParticleData)
{
	P_GET_STRUCT_REF(FVector,Z_Param_Out__location);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FCableParticle*)Z_Param__Result=P_THIS->GetClosestParticleData(Z_Param_Out__location);
	P_NATIVE_END;
}
// ********** End Class ULoiicCableComponent Function GetClosestParticleData ***********************

// ********** Begin Class ULoiicCableComponent Function GetClosestParticleDataFromActor ************
struct Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleDataFromActor_Statics
{
	struct LoiicCableComponent_eventGetClosestParticleDataFromActor_Parms
	{
		AActor* _actor;
		FCableParticle ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cable|Utility" },
		{ "Comment", "/// <summary>\n/// This method returns the closest particle to a given actor. \n/// A Particle is technically a segment's position.\n/// </summary>\n/// <returns>Particle data struct</returns>\n" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "<summary>\nThis method returns the closest particle to a given actor.\nA Particle is technically a segment's position.\n</summary>\n<returns>Particle data struct</returns>" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp__actor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleDataFromActor_Statics::NewProp__actor = { "_actor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LoiicCableComponent_eventGetClosestParticleDataFromActor_Parms, _actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleDataFromActor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LoiicCableComponent_eventGetClosestParticleDataFromActor_Parms, ReturnValue), Z_Construct_UScriptStruct_FCableParticle, METADATA_PARAMS(0, nullptr) }; // 2651070506
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleDataFromActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleDataFromActor_Statics::NewProp__actor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleDataFromActor_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleDataFromActor_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleDataFromActor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULoiicCableComponent, nullptr, "GetClosestParticleDataFromActor", Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleDataFromActor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleDataFromActor_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleDataFromActor_Statics::LoiicCableComponent_eventGetClosestParticleDataFromActor_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleDataFromActor_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleDataFromActor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleDataFromActor_Statics::LoiicCableComponent_eventGetClosestParticleDataFromActor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleDataFromActor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleDataFromActor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULoiicCableComponent::execGetClosestParticleDataFromActor)
{
	P_GET_OBJECT(AActor,Z_Param__actor);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FCableParticle*)Z_Param__Result=P_THIS->GetClosestParticleDataFromActor(Z_Param__actor);
	P_NATIVE_END;
}
// ********** End Class ULoiicCableComponent Function GetClosestParticleDataFromActor **************

// ********** Begin Class ULoiicCableComponent Function GetClosestParticleDataFromSceneComponent ***
struct Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleDataFromSceneComponent_Statics
{
	struct LoiicCableComponent_eventGetClosestParticleDataFromSceneComponent_Parms
	{
		USceneComponent* _sceneComponent;
		FCableParticle ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cable|Utility" },
		{ "Comment", "/// <summary>\n/// This method returns the closest particle to a given scene component. \n/// A Particle is technically a segment's position.\n/// </summary>\n/// <returns>Particle data struct</returns>\n" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "<summary>\nThis method returns the closest particle to a given scene component.\nA Particle is technically a segment's position.\n</summary>\n<returns>Particle data struct</returns>" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__sceneComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp__sceneComponent;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleDataFromSceneComponent_Statics::NewProp__sceneComponent = { "_sceneComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LoiicCableComponent_eventGetClosestParticleDataFromSceneComponent_Parms, _sceneComponent), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__sceneComponent_MetaData), NewProp__sceneComponent_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleDataFromSceneComponent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LoiicCableComponent_eventGetClosestParticleDataFromSceneComponent_Parms, ReturnValue), Z_Construct_UScriptStruct_FCableParticle, METADATA_PARAMS(0, nullptr) }; // 2651070506
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleDataFromSceneComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleDataFromSceneComponent_Statics::NewProp__sceneComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleDataFromSceneComponent_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleDataFromSceneComponent_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleDataFromSceneComponent_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULoiicCableComponent, nullptr, "GetClosestParticleDataFromSceneComponent", Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleDataFromSceneComponent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleDataFromSceneComponent_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleDataFromSceneComponent_Statics::LoiicCableComponent_eventGetClosestParticleDataFromSceneComponent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleDataFromSceneComponent_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleDataFromSceneComponent_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleDataFromSceneComponent_Statics::LoiicCableComponent_eventGetClosestParticleDataFromSceneComponent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleDataFromSceneComponent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleDataFromSceneComponent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULoiicCableComponent::execGetClosestParticleDataFromSceneComponent)
{
	P_GET_OBJECT(USceneComponent,Z_Param__sceneComponent);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FCableParticle*)Z_Param__Result=P_THIS->GetClosestParticleDataFromSceneComponent(Z_Param__sceneComponent);
	P_NATIVE_END;
}
// ********** End Class ULoiicCableComponent Function GetClosestParticleDataFromSceneComponent *****

// ********** Begin Class ULoiicCableComponent Function GetClosestPositionAlongRope ****************
struct Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRope_Statics
{
	struct LoiicCableComponent_eventGetClosestPositionAlongRope_Parms
	{
		FVector _location;
		FVector ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cable|Utility" },
		{ "Comment", "/// <summary>\n/// Returns the closest position along the rope, i.e it's not necessarely a particle/segment.\n/// It can be in between.\n/// </summary>\n/// <param name=\"_location\">Location in world space</param>\n/// <returns>Closest Position</returns>\n" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "<summary>\nReturns the closest position along the rope, i.e it's not necessarely a particle/segment.\nIt can be in between.\n</summary>\n<param name=\"_location\">Location in world space</param>\n<returns>Closest Position</returns>" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__location_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp__location;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRope_Statics::NewProp__location = { "_location", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LoiicCableComponent_eventGetClosestPositionAlongRope_Parms, _location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__location_MetaData), NewProp__location_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRope_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LoiicCableComponent_eventGetClosestPositionAlongRope_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRope_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRope_Statics::NewProp__location,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRope_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRope_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRope_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULoiicCableComponent, nullptr, "GetClosestPositionAlongRope", Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRope_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRope_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRope_Statics::LoiicCableComponent_eventGetClosestPositionAlongRope_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRope_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRope_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRope_Statics::LoiicCableComponent_eventGetClosestPositionAlongRope_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRope()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRope_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULoiicCableComponent::execGetClosestPositionAlongRope)
{
	P_GET_STRUCT_REF(FVector,Z_Param_Out__location);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector*)Z_Param__Result=P_THIS->GetClosestPositionAlongRope(Z_Param_Out__location);
	P_NATIVE_END;
}
// ********** End Class ULoiicCableComponent Function GetClosestPositionAlongRope ******************

// ********** Begin Class ULoiicCableComponent Function GetClosestPositionAlongRopeFromActor *******
struct Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRopeFromActor_Statics
{
	struct LoiicCableComponent_eventGetClosestPositionAlongRopeFromActor_Parms
	{
		AActor* _actor;
		FVector ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cable|Utility" },
		{ "Comment", "/// <summary>\n/// Returns the closest position along the rope, i.e it's not necessarely a particle/segment.\n/// It can be in between.\n/// </summary>\n/// <param name=\"_actor\">Actor</param>\n/// <returns>Closest Position</returns>\n" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "<summary>\nReturns the closest position along the rope, i.e it's not necessarely a particle/segment.\nIt can be in between.\n</summary>\n<param name=\"_actor\">Actor</param>\n<returns>Closest Position</returns>" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp__actor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRopeFromActor_Statics::NewProp__actor = { "_actor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LoiicCableComponent_eventGetClosestPositionAlongRopeFromActor_Parms, _actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRopeFromActor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LoiicCableComponent_eventGetClosestPositionAlongRopeFromActor_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRopeFromActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRopeFromActor_Statics::NewProp__actor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRopeFromActor_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRopeFromActor_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRopeFromActor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULoiicCableComponent, nullptr, "GetClosestPositionAlongRopeFromActor", Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRopeFromActor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRopeFromActor_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRopeFromActor_Statics::LoiicCableComponent_eventGetClosestPositionAlongRopeFromActor_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRopeFromActor_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRopeFromActor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRopeFromActor_Statics::LoiicCableComponent_eventGetClosestPositionAlongRopeFromActor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRopeFromActor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRopeFromActor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULoiicCableComponent::execGetClosestPositionAlongRopeFromActor)
{
	P_GET_OBJECT(AActor,Z_Param__actor);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector*)Z_Param__Result=P_THIS->GetClosestPositionAlongRopeFromActor(Z_Param__actor);
	P_NATIVE_END;
}
// ********** End Class ULoiicCableComponent Function GetClosestPositionAlongRopeFromActor *********

// ********** Begin Class ULoiicCableComponent Function GetClosestPositionAlongRopeFromSceneComponent 
struct Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRopeFromSceneComponent_Statics
{
	struct LoiicCableComponent_eventGetClosestPositionAlongRopeFromSceneComponent_Parms
	{
		USceneComponent* _sceneComponent;
		FVector ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cable|Utility" },
		{ "Comment", "/// <summary>\n/// Returns the closest position along the rope, i.e it's not necessarely a particle/segment.\n/// It can be in between.\n/// </summary>\n/// <param name=\"_sceneComponent\">Scene Component</param>\n/// <returns>Closest Position</returns>\n" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "<summary>\nReturns the closest position along the rope, i.e it's not necessarely a particle/segment.\nIt can be in between.\n</summary>\n<param name=\"_sceneComponent\">Scene Component</param>\n<returns>Closest Position</returns>" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__sceneComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp__sceneComponent;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRopeFromSceneComponent_Statics::NewProp__sceneComponent = { "_sceneComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LoiicCableComponent_eventGetClosestPositionAlongRopeFromSceneComponent_Parms, _sceneComponent), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__sceneComponent_MetaData), NewProp__sceneComponent_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRopeFromSceneComponent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LoiicCableComponent_eventGetClosestPositionAlongRopeFromSceneComponent_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRopeFromSceneComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRopeFromSceneComponent_Statics::NewProp__sceneComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRopeFromSceneComponent_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRopeFromSceneComponent_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRopeFromSceneComponent_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULoiicCableComponent, nullptr, "GetClosestPositionAlongRopeFromSceneComponent", Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRopeFromSceneComponent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRopeFromSceneComponent_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRopeFromSceneComponent_Statics::LoiicCableComponent_eventGetClosestPositionAlongRopeFromSceneComponent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRopeFromSceneComponent_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRopeFromSceneComponent_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRopeFromSceneComponent_Statics::LoiicCableComponent_eventGetClosestPositionAlongRopeFromSceneComponent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRopeFromSceneComponent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRopeFromSceneComponent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULoiicCableComponent::execGetClosestPositionAlongRopeFromSceneComponent)
{
	P_GET_OBJECT(USceneComponent,Z_Param__sceneComponent);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector*)Z_Param__Result=P_THIS->GetClosestPositionAlongRopeFromSceneComponent(Z_Param__sceneComponent);
	P_NATIVE_END;
}
// ********** End Class ULoiicCableComponent Function GetClosestPositionAlongRopeFromSceneComponent 

// ********** Begin Class ULoiicCableComponent Function GetLastAverageVelocityComputed *************
struct Z_Construct_UFunction_ULoiicCableComponent_GetLastAverageVelocityComputed_Statics
{
	struct LoiicCableComponent_eventGetLastAverageVelocityComputed_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cable|Utility" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULoiicCableComponent_GetLastAverageVelocityComputed_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LoiicCableComponent_eventGetLastAverageVelocityComputed_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULoiicCableComponent_GetLastAverageVelocityComputed_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoiicCableComponent_GetLastAverageVelocityComputed_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_GetLastAverageVelocityComputed_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULoiicCableComponent_GetLastAverageVelocityComputed_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULoiicCableComponent, nullptr, "GetLastAverageVelocityComputed", Z_Construct_UFunction_ULoiicCableComponent_GetLastAverageVelocityComputed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_GetLastAverageVelocityComputed_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULoiicCableComponent_GetLastAverageVelocityComputed_Statics::LoiicCableComponent_eventGetLastAverageVelocityComputed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_GetLastAverageVelocityComputed_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULoiicCableComponent_GetLastAverageVelocityComputed_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULoiicCableComponent_GetLastAverageVelocityComputed_Statics::LoiicCableComponent_eventGetLastAverageVelocityComputed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULoiicCableComponent_GetLastAverageVelocityComputed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULoiicCableComponent_GetLastAverageVelocityComputed_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULoiicCableComponent::execGetLastAverageVelocityComputed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetLastAverageVelocityComputed();
	P_NATIVE_END;
}
// ********** End Class ULoiicCableComponent Function GetLastAverageVelocityComputed ***************

// ********** Begin Class ULoiicCableComponent Function GetLengthAtIndex ***************************
struct Z_Construct_UFunction_ULoiicCableComponent_GetLengthAtIndex_Statics
{
	struct LoiicCableComponent_eventGetLengthAtIndex_Parms
	{
		float _floatIndex;
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cable|Utility" },
		{ "Comment", "/// <summary>\n/// Gets the length from the start point of the rope, \n/// to the corresponding point on the rope at the given float index.\n/// The integer part of the float is the index of the particle/segment, and the decimal part is \n/// the position in between the indexed particle/segment, and the next one. \n/// </summary>\n/// <param name=\"_floatIndex\">Float index</param>\n/// <returns>Length</returns>\n" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "<summary>\nGets the length from the start point of the rope,\nto the corresponding point on the rope at the given float index.\nThe integer part of the float is the index of the particle/segment, and the decimal part is\nthe position in between the indexed particle/segment, and the next one.\n</summary>\n<param name=\"_floatIndex\">Float index</param>\n<returns>Length</returns>" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__floatIndex_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp__floatIndex;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULoiicCableComponent_GetLengthAtIndex_Statics::NewProp__floatIndex = { "_floatIndex", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LoiicCableComponent_eventGetLengthAtIndex_Parms, _floatIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__floatIndex_MetaData), NewProp__floatIndex_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULoiicCableComponent_GetLengthAtIndex_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LoiicCableComponent_eventGetLengthAtIndex_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULoiicCableComponent_GetLengthAtIndex_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoiicCableComponent_GetLengthAtIndex_Statics::NewProp__floatIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoiicCableComponent_GetLengthAtIndex_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_GetLengthAtIndex_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULoiicCableComponent_GetLengthAtIndex_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULoiicCableComponent, nullptr, "GetLengthAtIndex", Z_Construct_UFunction_ULoiicCableComponent_GetLengthAtIndex_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_GetLengthAtIndex_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULoiicCableComponent_GetLengthAtIndex_Statics::LoiicCableComponent_eventGetLengthAtIndex_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_GetLengthAtIndex_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULoiicCableComponent_GetLengthAtIndex_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULoiicCableComponent_GetLengthAtIndex_Statics::LoiicCableComponent_eventGetLengthAtIndex_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULoiicCableComponent_GetLengthAtIndex()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULoiicCableComponent_GetLengthAtIndex_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULoiicCableComponent::execGetLengthAtIndex)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param__floatIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetLengthAtIndex(Z_Param__floatIndex);
	P_NATIVE_END;
}
// ********** End Class ULoiicCableComponent Function GetLengthAtIndex *****************************

// ********** Begin Class ULoiicCableComponent Function GetLengthAtPosition ************************
struct Z_Construct_UFunction_ULoiicCableComponent_GetLengthAtPosition_Statics
{
	struct LoiicCableComponent_eventGetLengthAtPosition_Parms
	{
		FVector _position;
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cable|Utility" },
		{ "Comment", "/// <summary>\n/// Gets the length from the start point of the rope, \n/// to the corresponding point on the rope at the given _position.\n/// This methods gives an approximate result, use float index for precise result\n/// </summary>\n/// <param name=\"_position\">Position along the rope</param>\n/// <returns>Length</returns>\n" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "<summary>\nGets the length from the start point of the rope,\nto the corresponding point on the rope at the given _position.\nThis methods gives an approximate result, use float index for precise result\n</summary>\n<param name=\"_position\">Position along the rope</param>\n<returns>Length</returns>" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__position_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp__position;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULoiicCableComponent_GetLengthAtPosition_Statics::NewProp__position = { "_position", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LoiicCableComponent_eventGetLengthAtPosition_Parms, _position), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__position_MetaData), NewProp__position_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULoiicCableComponent_GetLengthAtPosition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LoiicCableComponent_eventGetLengthAtPosition_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULoiicCableComponent_GetLengthAtPosition_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoiicCableComponent_GetLengthAtPosition_Statics::NewProp__position,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoiicCableComponent_GetLengthAtPosition_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_GetLengthAtPosition_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULoiicCableComponent_GetLengthAtPosition_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULoiicCableComponent, nullptr, "GetLengthAtPosition", Z_Construct_UFunction_ULoiicCableComponent_GetLengthAtPosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_GetLengthAtPosition_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULoiicCableComponent_GetLengthAtPosition_Statics::LoiicCableComponent_eventGetLengthAtPosition_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_GetLengthAtPosition_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULoiicCableComponent_GetLengthAtPosition_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULoiicCableComponent_GetLengthAtPosition_Statics::LoiicCableComponent_eventGetLengthAtPosition_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULoiicCableComponent_GetLengthAtPosition()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULoiicCableComponent_GetLengthAtPosition_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULoiicCableComponent::execGetLengthAtPosition)
{
	P_GET_STRUCT_REF(FVector,Z_Param_Out__position);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetLengthAtPosition(Z_Param_Out__position);
	P_NATIVE_END;
}
// ********** End Class ULoiicCableComponent Function GetLengthAtPosition **************************

// ********** Begin Class ULoiicCableComponent Function GetParticlesCount **************************
struct Z_Construct_UFunction_ULoiicCableComponent_GetParticlesCount_Statics
{
	struct LoiicCableComponent_eventGetParticlesCount_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cable|Utility" },
		{ "Comment", "/// <summary>\n/// Returns the number of particles/segments of the rope\n/// </summary>\n" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "<summary>\nReturns the number of particles/segments of the rope\n</summary>" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ULoiicCableComponent_GetParticlesCount_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LoiicCableComponent_eventGetParticlesCount_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULoiicCableComponent_GetParticlesCount_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoiicCableComponent_GetParticlesCount_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_GetParticlesCount_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULoiicCableComponent_GetParticlesCount_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULoiicCableComponent, nullptr, "GetParticlesCount", Z_Construct_UFunction_ULoiicCableComponent_GetParticlesCount_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_GetParticlesCount_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULoiicCableComponent_GetParticlesCount_Statics::LoiicCableComponent_eventGetParticlesCount_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_GetParticlesCount_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULoiicCableComponent_GetParticlesCount_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULoiicCableComponent_GetParticlesCount_Statics::LoiicCableComponent_eventGetParticlesCount_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULoiicCableComponent_GetParticlesCount()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULoiicCableComponent_GetParticlesCount_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULoiicCableComponent::execGetParticlesCount)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetParticlesCount();
	P_NATIVE_END;
}
// ********** End Class ULoiicCableComponent Function GetParticlesCount ****************************

// ********** Begin Class ULoiicCableComponent Function GetPositionAtIndex *************************
struct Z_Construct_UFunction_ULoiicCableComponent_GetPositionAtIndex_Statics
{
	struct LoiicCableComponent_eventGetPositionAtIndex_Parms
	{
		float _floatIndex;
		FVector ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cable|Utility" },
		{ "Comment", "/// <summary>\n/// Get the position of a point on the rope, based on a float index.\n/// The integer part of the float is the index of the particle/segment, and the decimal part is \n/// the position in between the indexed particle/segment, and the next one. \n/// Giving index 1.5 will return the point in between the first and the second particle/segment.\n/// </summary>\n/// <param name=\"_floatIndex\">Float index</param>\n/// <returns>Position</returns>\n" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "<summary>\nGet the position of a point on the rope, based on a float index.\nThe integer part of the float is the index of the particle/segment, and the decimal part is\nthe position in between the indexed particle/segment, and the next one.\nGiving index 1.5 will return the point in between the first and the second particle/segment.\n</summary>\n<param name=\"_floatIndex\">Float index</param>\n<returns>Position</returns>" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__floatIndex_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp__floatIndex;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULoiicCableComponent_GetPositionAtIndex_Statics::NewProp__floatIndex = { "_floatIndex", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LoiicCableComponent_eventGetPositionAtIndex_Parms, _floatIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__floatIndex_MetaData), NewProp__floatIndex_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULoiicCableComponent_GetPositionAtIndex_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LoiicCableComponent_eventGetPositionAtIndex_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULoiicCableComponent_GetPositionAtIndex_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoiicCableComponent_GetPositionAtIndex_Statics::NewProp__floatIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoiicCableComponent_GetPositionAtIndex_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_GetPositionAtIndex_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULoiicCableComponent_GetPositionAtIndex_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULoiicCableComponent, nullptr, "GetPositionAtIndex", Z_Construct_UFunction_ULoiicCableComponent_GetPositionAtIndex_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_GetPositionAtIndex_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULoiicCableComponent_GetPositionAtIndex_Statics::LoiicCableComponent_eventGetPositionAtIndex_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_GetPositionAtIndex_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULoiicCableComponent_GetPositionAtIndex_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULoiicCableComponent_GetPositionAtIndex_Statics::LoiicCableComponent_eventGetPositionAtIndex_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULoiicCableComponent_GetPositionAtIndex()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULoiicCableComponent_GetPositionAtIndex_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULoiicCableComponent::execGetPositionAtIndex)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param__floatIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector*)Z_Param__Result=P_THIS->GetPositionAtIndex(Z_Param__floatIndex);
	P_NATIVE_END;
}
// ********** End Class ULoiicCableComponent Function GetPositionAtIndex ***************************

// ********** Begin Class ULoiicCableComponent Function GetPositionAtLength ************************
struct Z_Construct_UFunction_ULoiicCableComponent_GetPositionAtLength_Statics
{
	struct LoiicCableComponent_eventGetPositionAtLength_Parms
	{
		float _length;
		FVector ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cable|Utility" },
		{ "Comment", "/// <summary>\n/// Get the position of a point on the rope, relative to the length given.\n/// </summary>\n/// <param name=\"_length\">Input length</param>\n/// <returns>Position</returns>\n" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "<summary>\nGet the position of a point on the rope, relative to the length given.\n</summary>\n<param name=\"_length\">Input length</param>\n<returns>Position</returns>" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__length_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp__length;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULoiicCableComponent_GetPositionAtLength_Statics::NewProp__length = { "_length", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LoiicCableComponent_eventGetPositionAtLength_Parms, _length), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__length_MetaData), NewProp__length_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULoiicCableComponent_GetPositionAtLength_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LoiicCableComponent_eventGetPositionAtLength_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULoiicCableComponent_GetPositionAtLength_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoiicCableComponent_GetPositionAtLength_Statics::NewProp__length,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoiicCableComponent_GetPositionAtLength_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_GetPositionAtLength_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULoiicCableComponent_GetPositionAtLength_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULoiicCableComponent, nullptr, "GetPositionAtLength", Z_Construct_UFunction_ULoiicCableComponent_GetPositionAtLength_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_GetPositionAtLength_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULoiicCableComponent_GetPositionAtLength_Statics::LoiicCableComponent_eventGetPositionAtLength_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_GetPositionAtLength_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULoiicCableComponent_GetPositionAtLength_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULoiicCableComponent_GetPositionAtLength_Statics::LoiicCableComponent_eventGetPositionAtLength_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULoiicCableComponent_GetPositionAtLength()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULoiicCableComponent_GetPositionAtLength_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULoiicCableComponent::execGetPositionAtLength)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param__length);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector*)Z_Param__Result=P_THIS->GetPositionAtLength(Z_Param__length);
	P_NATIVE_END;
}
// ********** End Class ULoiicCableComponent Function GetPositionAtLength **************************

// ********** Begin Class ULoiicCableComponent Function ResetCable *********************************
struct Z_Construct_UFunction_ULoiicCableComponent_ResetCable_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cable|Utility" },
		{ "Comment", "/// <summary>\n/// Method from where you can re initialize the cable\n/// </summary>\n" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "<summary>\nMethod from where you can re initialize the cable\n</summary>" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULoiicCableComponent_ResetCable_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULoiicCableComponent, nullptr, "ResetCable", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_ResetCable_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULoiicCableComponent_ResetCable_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_ULoiicCableComponent_ResetCable()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULoiicCableComponent_ResetCable_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULoiicCableComponent::execResetCable)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ResetCable();
	P_NATIVE_END;
}
// ********** End Class ULoiicCableComponent Function ResetCable ***********************************

// ********** Begin Class ULoiicCableComponent Function StopAllVelocities **************************
struct Z_Construct_UFunction_ULoiicCableComponent_StopAllVelocities_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cable|Utility" },
		{ "Comment", "/// <summary>\n/// This function will cancel all the velocity accumulated when called\n/// </summary>\n" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "<summary>\nThis function will cancel all the velocity accumulated when called\n</summary>" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULoiicCableComponent_StopAllVelocities_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULoiicCableComponent, nullptr, "StopAllVelocities", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_StopAllVelocities_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULoiicCableComponent_StopAllVelocities_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_ULoiicCableComponent_StopAllVelocities()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULoiicCableComponent_StopAllVelocities_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULoiicCableComponent::execStopAllVelocities)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StopAllVelocities();
	P_NATIVE_END;
}
// ********** End Class ULoiicCableComponent Function StopAllVelocities ****************************

// ********** Begin Class ULoiicCableComponent Function UpdatePreview ******************************
struct Z_Construct_UFunction_ULoiicCableComponent_UpdatePreview_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Cable" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULoiicCableComponent_UpdatePreview_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULoiicCableComponent, nullptr, "UpdatePreview", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoiicCableComponent_UpdatePreview_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULoiicCableComponent_UpdatePreview_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_ULoiicCableComponent_UpdatePreview()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULoiicCableComponent_UpdatePreview_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULoiicCableComponent::execUpdatePreview)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UpdatePreview();
	P_NATIVE_END;
}
// ********** End Class ULoiicCableComponent Function UpdatePreview ********************************

// ********** Begin Class ULoiicCableComponent *****************************************************
void ULoiicCableComponent::StaticRegisterNativesULoiicCableComponent()
{
	UClass* Class = ULoiicCableComponent::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "AddImpulseAtParticle", &ULoiicCableComponent::execAddImpulseAtParticle },
		{ "AddImpulseAtParticleIndex", &ULoiicCableComponent::execAddImpulseAtParticleIndex },
		{ "AttachParticleAtPosition", &ULoiicCableComponent::execAttachParticleAtPosition },
		{ "AttachParticleIndexAtPosition", &ULoiicCableComponent::execAttachParticleIndexAtPosition },
		{ "AttachParticleIndexToSceneComponent", &ULoiicCableComponent::execAttachParticleIndexToSceneComponent },
		{ "AttachParticleToSceneComponent", &ULoiicCableComponent::execAttachParticleToSceneComponent },
		{ "DetachParticle", &ULoiicCableComponent::execDetachParticle },
		{ "DetachParticleIndex", &ULoiicCableComponent::execDetachParticleIndex },
		{ "GetAttachedParticles", &ULoiicCableComponent::execGetAttachedParticles },
		{ "GetCableParticle", &ULoiicCableComponent::execGetCableParticle },
		{ "GetCableParticles", &ULoiicCableComponent::execGetCableParticles },
		{ "GetClosestParticleData", &ULoiicCableComponent::execGetClosestParticleData },
		{ "GetClosestParticleDataFromActor", &ULoiicCableComponent::execGetClosestParticleDataFromActor },
		{ "GetClosestParticleDataFromSceneComponent", &ULoiicCableComponent::execGetClosestParticleDataFromSceneComponent },
		{ "GetClosestPositionAlongRope", &ULoiicCableComponent::execGetClosestPositionAlongRope },
		{ "GetClosestPositionAlongRopeFromActor", &ULoiicCableComponent::execGetClosestPositionAlongRopeFromActor },
		{ "GetClosestPositionAlongRopeFromSceneComponent", &ULoiicCableComponent::execGetClosestPositionAlongRopeFromSceneComponent },
		{ "GetLastAverageVelocityComputed", &ULoiicCableComponent::execGetLastAverageVelocityComputed },
		{ "GetLengthAtIndex", &ULoiicCableComponent::execGetLengthAtIndex },
		{ "GetLengthAtPosition", &ULoiicCableComponent::execGetLengthAtPosition },
		{ "GetParticlesCount", &ULoiicCableComponent::execGetParticlesCount },
		{ "GetPositionAtIndex", &ULoiicCableComponent::execGetPositionAtIndex },
		{ "GetPositionAtLength", &ULoiicCableComponent::execGetPositionAtLength },
		{ "ResetCable", &ULoiicCableComponent::execResetCable },
		{ "StopAllVelocities", &ULoiicCableComponent::execStopAllVelocities },
		{ "UpdatePreview", &ULoiicCableComponent::execUpdatePreview },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_ULoiicCableComponent;
UClass* ULoiicCableComponent::GetPrivateStaticClass()
{
	using TClass = ULoiicCableComponent;
	if (!Z_Registration_Info_UClass_ULoiicCableComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("LoiicCableComponent"),
			Z_Registration_Info_UClass_ULoiicCableComponent.InnerSingleton,
			StaticRegisterNativesULoiicCableComponent,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_ULoiicCableComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_ULoiicCableComponent_NoRegister()
{
	return ULoiicCableComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ULoiicCableComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "Rendering" },
		{ "HideCategories", "Collision Object Physics Activation Components|Activation Mobility Trigger" },
		{ "IncludePath", "LoiicCableComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAttachStart_MetaData[] = {
		{ "Category", "Cable" },
		{ "Comment", "/**\n\x09\x09*\x09Should we fix the start to something, or leave it free.\n\x09\x09*\x09If false, component transform is just used for initial location of start of cable\n\x09\x09*/" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "Should we fix the start to something, or leave it free.\nIf false, component transform is just used for initial location of start of cable" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAttachEnd_MetaData[] = {
		{ "Category", "Cable" },
		{ "Comment", "/**\n\x09\x09*\x09Should we fix the end to something (using AttachEndTo and EndLocation), or leave it free.\n\x09\x09*\x09If false, AttachEndTo and EndLocation are just used for initial location of end of cable\n\x09\x09*/" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "Should we fix the end to something (using AttachEndTo and EndLocation), or leave it free.\nIf false, AttachEndTo and EndLocation are just used for initial location of end of cable" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_attachEndTo_MetaData[] = {
		{ "Category", "Cable" },
		{ "Comment", "/** Actor or Component that the defines the end position of the cable */" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "Actor or Component that the defines the end position of the cable" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_attachEndSceneComponent_MetaData[] = {
		{ "Comment", "/* The end scene component attach point, used in game*/" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "The end scene component attach point, used in game" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_attachEndToSocketName_MetaData[] = {
		{ "Category", "Cable" },
		{ "Comment", "/** Socket name on the AttachEndTo component to attach to */" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "Socket name on the AttachEndTo component to attach to" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_endLocation_MetaData[] = {
		{ "Category", "Cable" },
		{ "Comment", "/** End location of cable, relative to AttachEndTo (or AttachEndToSocketName) if specified, otherwise relative to cable component. */" },
		{ "MakeEditWidget", "TRUE" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "End location of cable, relative to AttachEndTo (or AttachEndToSocketName) if specified, otherwise relative to cable component." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_cableLength_MetaData[] = {
		{ "Category", "Cable" },
		{ "ClampMax", "10000.0" },
		{ "ClampMin", "1" },
		{ "Comment", "/** Length of the cable */" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "Length of the cable" },
		{ "UIMax", "10000.0" },
		{ "UIMin", "1" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDefineSubdivisionUsingNumSegment_MetaData[] = {
		{ "Category", "Cable" },
		{ "Comment", "/* If true, the segmentLength will be computed with the numSegment variable, and the length of the cable. \n\x09If false, the numSegment will be computed with the segmentLength variable, and the length of the cable. */" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "If true, the segmentLength will be computed with the numSegment variable, and the length of the cable.\n      If false, the numSegment will be computed with the segmentLength variable, and the length of the cable." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_numSegment_MetaData[] = {
		{ "Category", "Cable" },
		{ "ClampMin", "2" },
		{ "Comment", "/*The number of segment, ie the subdivision of the cable*/" },
		{ "EditCondition", "bDefineSubdivisionUsingNumSegment" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "The number of segment, ie the subdivision of the cable" },
		{ "UIMin", "2" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_segmentLength_MetaData[] = {
		{ "Category", "Cable" },
		{ "ClampMin", "0.100000" },
		{ "Comment", "/** The length of a segment*/" },
		{ "EditCondition", "!bDefineSubdivisionUsingNumSegment" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "The length of a segment" },
		{ "UIMin", "0.100000" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_numOfConstraintRuns_MetaData[] = {
		{ "Category", "Cable" },
		{ "ClampMax", "50" },
		{ "ClampMin", "1" },
		{ "Comment", "/** The number of solver iterations controls how 'stiff' the cable is */" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "The number of solver iterations controls how 'stiff' the cable is" },
		{ "UIMax", "50" },
		{ "UIMin", "1" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_constraintType_MetaData[] = {
		{ "Category", "Cable" },
		{ "Comment", "/*The way the apply constraint works, between the particles of the rope*/" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "The way the apply constraint works, between the particles of the rope" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_dampingFactor_MetaData[] = {
		{ "Category", "Cable" },
		{ "ClampMax", "1" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "UIMax", "1" },
		{ "UIMin", "0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowParticleDebug_MetaData[] = {
		{ "Category", "Cable" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_simulationFramePerSeconds_MetaData[] = {
		{ "Category", "Cable" },
		{ "ClampMin", "10" },
		{ "Comment", "/*Determine the fps of the simulated cable*/" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "Determine the fps of the simulated cable" },
		{ "UIMax", "200" },
		{ "UIMin", "10" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_substepTime_MetaData[] = {
		{ "Category", "Cable" },
		{ "ClampMin", "0.005" },
		{ "Comment", "/** Controls the simulation substep time for the cable */" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "Controls the simulation substep time for the cable" },
		{ "UIMax", "0.1" },
		{ "UIMin", "0.005" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bLimitMovementOnToOnePlane_MetaData[] = {
		{ "Category", "Cable" },
		{ "Comment", "/** Should you limit the movement of the rope on to a 2D plane.*/" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "Should you limit the movement of the rope on to a 2D plane." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowPlaneDebug_MetaData[] = {
		{ "Category", "Cable" },
		{ "EditCondition", "bLimitMovementOnToOnePlane" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_forwardOfTheLimitPlane_MetaData[] = {
		{ "Category", "Cable" },
		{ "Comment", "/** The forward vector of the plane you want to limit. The up vector will be taken along the Z axis automatically, meaning the plane is necessarely vertical*/" },
		{ "EditCondition", "bLimitMovementOnToOnePlane" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "The forward vector of the plane you want to limit. The up vector will be taken along the Z axis automatically, meaning the plane is necessarely vertical" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableCollision_MetaData[] = {
		{ "Category", "Cable|Custom Collision" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bGenerateCustomOverlapEvents_MetaData[] = {
		{ "Category", "Cable|Custom Collision" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_overlapExtraExtent_MetaData[] = {
		{ "Category", "Cable|Custom Collision" },
		{ "ClampMin", "0.100000" },
		{ "EditCondition", "bGenerateCustomOverlapEvents" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "UIMin", "0.100000" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_cableWidthForCollisions_MetaData[] = {
		{ "Category", "Cable|Custom Collision" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "UIMin", "0.01" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bounceFactor_MetaData[] = {
		{ "Category", "Cable|Custom Collision" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "UIMin", "0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_correctionClampAmount_MetaData[] = {
		{ "Category", "Cable|Custom Collision" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "UIMin", "0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_collisionType_MetaData[] = {
		{ "Category", "Cable|Custom Collision" },
		{ "Comment", "/* Determines the collision handling method calls frequency, precise cost a lot, and is mainly used for when the cable moves because of constraints. */" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "Determines the collision handling method calls frequency, precise cost a lot, and is mainly used for when the cable moves because of constraints." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_collisionProfile_MetaData[] = {
		{ "Category", "Cable|Custom Collision" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_actorsToIgnoreDuringCollision_MetaData[] = {
		{ "Category", "Cable|Custom Collision" },
		{ "Comment", "/*Actors to ignore during collision check*/" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "Actors to ignore during collision check" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSkipCableUpdateWhenNotVisible_MetaData[] = {
		{ "Category", "Cable|Optimisation" },
		{ "Comment", "//should skip the cable update when the cable is not visible ? \n" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "should skip the cable update when the cable is not visible ?" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDebugOptimisation_MetaData[] = {
		{ "Category", "Cable|Optimisation" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_minVelocityBeforeSleep_MetaData[] = {
		{ "Category", "Cable|Optimisation" },
		{ "ClampMin", "0" },
		{ "Comment", "//if the average particle velocity is lower than this variable for variable_name amount of seconds,\n//the cable goes in \"sleep\" state, and is no longer physically updated\n" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "if the average particle velocity is lower than this variable for variable_name amount of seconds,\nthe cable goes in \"sleep\" state, and is no longer physically updated" },
		{ "UIMin", "0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_timeInSecondsBeforeSleep_MetaData[] = {
		{ "Category", "Cable|Optimisation" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "UIMin", "0" },
		{ "Units", "s" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_renderType_MetaData[] = {
		{ "Category", "Cable|Rendering" },
		{ "Comment", "/*Let's you chose how you want the cable to be rendered*/" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "Let's you chose how you want the cable to be rendered" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_numSides_MetaData[] = {
		{ "Category", "Cable|Rendering" },
		{ "ClampMax", "16" },
		{ "ClampMin", "1" },
		{ "Comment", "/** Number of sides of the cable geometry */" },
		{ "EditCondition", "renderType == ERenderType::Default" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "Number of sides of the cable geometry" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_cableWidth_MetaData[] = {
		{ "Category", "Cable|Rendering" },
		{ "ClampMin", "0.01" },
		{ "EditCondition", "renderType == ERenderType::Default" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "UIMax", "50.0" },
		{ "UIMin", "0.01" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_tileMaterial_MetaData[] = {
		{ "Category", "Cable|Rendering" },
		{ "Comment", "/** How many times to repeat the material along the length of the cable */" },
		{ "EditCondition", "renderType == ERenderType::Default" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "How many times to repeat the material along the length of the cable" },
		{ "UIMax", "8" },
		{ "UIMin", "0.1" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_grammarMeshes_MetaData[] = {
		{ "Category", "Cable|Rendering" },
		{ "Comment", "/////////////////////////////////////////////////////////////////////// Second and third render type: custom meshes (spline meshes and static meshes)\n" },
		{ "EditCondition", "renderType != ERenderType::Default" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "Second and third render type: custom meshes (spline meshes and static meshes)" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUsesGrammar_MetaData[] = {
		{ "Category", "Cable|Rendering" },
		{ "Comment", "/*Should you be using grammar in order to populate the cable, if false will use the first mesh found in the array of grammar above*/" },
		{ "EditCondition", "renderType != ERenderType::Default" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "ToolTip", "Should you be using grammar in order to populate the cable, if false will use the first mesh found in the array of grammar above" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_grammar_MetaData[] = {
		{ "Category", "Cable|Rendering" },
		{ "Comment", "/*The input grammar, use this in order to populate your cable with meshes follwing a logic*/" },
		{ "EditCondition", "renderType != ERenderType::Default && bUsesGrammar" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
		{ "MultiLine", "" },
		{ "ToolTip", "The input grammar, use this in order to populate your cable with meshes follwing a logic" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_createdMeshes_MetaData[] = {
		{ "Category", "Cable|Rendering" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/LoiicCableComponent.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bAttachStart_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAttachStart;
	static void NewProp_bAttachEnd_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAttachEnd;
	static const UECodeGen_Private::FStructPropertyParams NewProp_attachEndTo;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_attachEndSceneComponent;
	static const UECodeGen_Private::FNamePropertyParams NewProp_attachEndToSocketName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_endLocation;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_cableLength;
	static void NewProp_bDefineSubdivisionUsingNumSegment_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDefineSubdivisionUsingNumSegment;
	static const UECodeGen_Private::FIntPropertyParams NewProp_numSegment;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_segmentLength;
	static const UECodeGen_Private::FIntPropertyParams NewProp_numOfConstraintRuns;
	static const UECodeGen_Private::FBytePropertyParams NewProp_constraintType;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_dampingFactor;
	static void NewProp_bShowParticleDebug_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowParticleDebug;
	static const UECodeGen_Private::FIntPropertyParams NewProp_simulationFramePerSeconds;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_substepTime;
	static void NewProp_bLimitMovementOnToOnePlane_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bLimitMovementOnToOnePlane;
	static void NewProp_bShowPlaneDebug_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowPlaneDebug;
	static const UECodeGen_Private::FStructPropertyParams NewProp_forwardOfTheLimitPlane;
	static void NewProp_bEnableCollision_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableCollision;
	static void NewProp_bGenerateCustomOverlapEvents_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bGenerateCustomOverlapEvents;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_overlapExtraExtent;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_cableWidthForCollisions;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_bounceFactor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_correctionClampAmount;
	static const UECodeGen_Private::FBytePropertyParams NewProp_collisionType;
	static const UECodeGen_Private::FNamePropertyParams NewProp_collisionProfile;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_actorsToIgnoreDuringCollision_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_actorsToIgnoreDuringCollision;
	static void NewProp_bSkipCableUpdateWhenNotVisible_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSkipCableUpdateWhenNotVisible;
	static void NewProp_bDebugOptimisation_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDebugOptimisation;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_minVelocityBeforeSleep;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_timeInSecondsBeforeSleep;
	static const UECodeGen_Private::FBytePropertyParams NewProp_renderType;
	static const UECodeGen_Private::FIntPropertyParams NewProp_numSides;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_cableWidth;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_tileMaterial;
	static const UECodeGen_Private::FStructPropertyParams NewProp_grammarMeshes_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_grammarMeshes;
	static void NewProp_bUsesGrammar_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUsesGrammar;
	static const UECodeGen_Private::FNamePropertyParams NewProp_grammar;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_createdMeshes_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_createdMeshes;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ULoiicCableComponent_AddImpulseAtParticle, "AddImpulseAtParticle" }, // 3729923884
		{ &Z_Construct_UFunction_ULoiicCableComponent_AddImpulseAtParticleIndex, "AddImpulseAtParticleIndex" }, // 2575489871
		{ &Z_Construct_UFunction_ULoiicCableComponent_AttachParticleAtPosition, "AttachParticleAtPosition" }, // 2954908786
		{ &Z_Construct_UFunction_ULoiicCableComponent_AttachParticleIndexAtPosition, "AttachParticleIndexAtPosition" }, // 3643454465
		{ &Z_Construct_UFunction_ULoiicCableComponent_AttachParticleIndexToSceneComponent, "AttachParticleIndexToSceneComponent" }, // 1508082364
		{ &Z_Construct_UFunction_ULoiicCableComponent_AttachParticleToSceneComponent, "AttachParticleToSceneComponent" }, // 1474748799
		{ &Z_Construct_UFunction_ULoiicCableComponent_DetachParticle, "DetachParticle" }, // 1283019267
		{ &Z_Construct_UFunction_ULoiicCableComponent_DetachParticleIndex, "DetachParticleIndex" }, // 2373491746
		{ &Z_Construct_UFunction_ULoiicCableComponent_GetAttachedParticles, "GetAttachedParticles" }, // 217190621
		{ &Z_Construct_UFunction_ULoiicCableComponent_GetCableParticle, "GetCableParticle" }, // 2731614038
		{ &Z_Construct_UFunction_ULoiicCableComponent_GetCableParticles, "GetCableParticles" }, // 1380979229
		{ &Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleData, "GetClosestParticleData" }, // 1434284338
		{ &Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleDataFromActor, "GetClosestParticleDataFromActor" }, // 4098785292
		{ &Z_Construct_UFunction_ULoiicCableComponent_GetClosestParticleDataFromSceneComponent, "GetClosestParticleDataFromSceneComponent" }, // 3654533594
		{ &Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRope, "GetClosestPositionAlongRope" }, // 2154190350
		{ &Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRopeFromActor, "GetClosestPositionAlongRopeFromActor" }, // 905435402
		{ &Z_Construct_UFunction_ULoiicCableComponent_GetClosestPositionAlongRopeFromSceneComponent, "GetClosestPositionAlongRopeFromSceneComponent" }, // 3368913544
		{ &Z_Construct_UFunction_ULoiicCableComponent_GetLastAverageVelocityComputed, "GetLastAverageVelocityComputed" }, // 1523994774
		{ &Z_Construct_UFunction_ULoiicCableComponent_GetLengthAtIndex, "GetLengthAtIndex" }, // 856159650
		{ &Z_Construct_UFunction_ULoiicCableComponent_GetLengthAtPosition, "GetLengthAtPosition" }, // 2975530087
		{ &Z_Construct_UFunction_ULoiicCableComponent_GetParticlesCount, "GetParticlesCount" }, // 3912509433
		{ &Z_Construct_UFunction_ULoiicCableComponent_GetPositionAtIndex, "GetPositionAtIndex" }, // 4277930073
		{ &Z_Construct_UFunction_ULoiicCableComponent_GetPositionAtLength, "GetPositionAtLength" }, // 1497863402
		{ &Z_Construct_UDelegateFunction_ULoiicCableComponent_OnBeginOverlap__DelegateSignature, "OnBeginOverlap__DelegateSignature" }, // 2571883767
		{ &Z_Construct_UDelegateFunction_ULoiicCableComponent_OnEndOverlap__DelegateSignature, "OnEndOverlap__DelegateSignature" }, // 916177585
		{ &Z_Construct_UFunction_ULoiicCableComponent_ResetCable, "ResetCable" }, // 4288738088
		{ &Z_Construct_UFunction_ULoiicCableComponent_StopAllVelocities, "StopAllVelocities" }, // 3341681368
		{ &Z_Construct_UFunction_ULoiicCableComponent_UpdatePreview, "UpdatePreview" }, // 2173564249
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULoiicCableComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
void Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_bAttachStart_SetBit(void* Obj)
{
	((ULoiicCableComponent*)Obj)->bAttachStart = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_bAttachStart = { "bAttachStart", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ULoiicCableComponent), &Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_bAttachStart_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAttachStart_MetaData), NewProp_bAttachStart_MetaData) };
void Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_bAttachEnd_SetBit(void* Obj)
{
	((ULoiicCableComponent*)Obj)->bAttachEnd = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_bAttachEnd = { "bAttachEnd", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ULoiicCableComponent), &Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_bAttachEnd_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAttachEnd_MetaData), NewProp_bAttachEnd_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_attachEndTo = { "attachEndTo", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULoiicCableComponent, attachEndTo), Z_Construct_UScriptStruct_FComponentReference, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_attachEndTo_MetaData), NewProp_attachEndTo_MetaData) }; // 2130483024
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_attachEndSceneComponent = { "attachEndSceneComponent", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULoiicCableComponent, attachEndSceneComponent), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_attachEndSceneComponent_MetaData), NewProp_attachEndSceneComponent_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_attachEndToSocketName = { "attachEndToSocketName", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULoiicCableComponent, attachEndToSocketName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_attachEndToSocketName_MetaData), NewProp_attachEndToSocketName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_endLocation = { "endLocation", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULoiicCableComponent, endLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_endLocation_MetaData), NewProp_endLocation_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_cableLength = { "cableLength", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULoiicCableComponent, cableLength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_cableLength_MetaData), NewProp_cableLength_MetaData) };
void Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_bDefineSubdivisionUsingNumSegment_SetBit(void* Obj)
{
	((ULoiicCableComponent*)Obj)->bDefineSubdivisionUsingNumSegment = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_bDefineSubdivisionUsingNumSegment = { "bDefineSubdivisionUsingNumSegment", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ULoiicCableComponent), &Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_bDefineSubdivisionUsingNumSegment_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDefineSubdivisionUsingNumSegment_MetaData), NewProp_bDefineSubdivisionUsingNumSegment_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_numSegment = { "numSegment", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULoiicCableComponent, numSegment), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_numSegment_MetaData), NewProp_numSegment_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_segmentLength = { "segmentLength", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULoiicCableComponent, segmentLength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_segmentLength_MetaData), NewProp_segmentLength_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_numOfConstraintRuns = { "numOfConstraintRuns", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULoiicCableComponent, numOfConstraintRuns), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_numOfConstraintRuns_MetaData), NewProp_numOfConstraintRuns_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_constraintType = { "constraintType", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULoiicCableComponent, constraintType), Z_Construct_UEnum_LoiicBetterCables_ECableConstraintType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_constraintType_MetaData), NewProp_constraintType_MetaData) }; // 622000886
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_dampingFactor = { "dampingFactor", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULoiicCableComponent, dampingFactor), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_dampingFactor_MetaData), NewProp_dampingFactor_MetaData) };
void Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_bShowParticleDebug_SetBit(void* Obj)
{
	((ULoiicCableComponent*)Obj)->bShowParticleDebug = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_bShowParticleDebug = { "bShowParticleDebug", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ULoiicCableComponent), &Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_bShowParticleDebug_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowParticleDebug_MetaData), NewProp_bShowParticleDebug_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_simulationFramePerSeconds = { "simulationFramePerSeconds", nullptr, (EPropertyFlags)0x00200c0000000015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULoiicCableComponent, simulationFramePerSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_simulationFramePerSeconds_MetaData), NewProp_simulationFramePerSeconds_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_substepTime = { "substepTime", nullptr, (EPropertyFlags)0x00200c0000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULoiicCableComponent, substepTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_substepTime_MetaData), NewProp_substepTime_MetaData) };
void Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_bLimitMovementOnToOnePlane_SetBit(void* Obj)
{
	((ULoiicCableComponent*)Obj)->bLimitMovementOnToOnePlane = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_bLimitMovementOnToOnePlane = { "bLimitMovementOnToOnePlane", nullptr, (EPropertyFlags)0x00200c0000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ULoiicCableComponent), &Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_bLimitMovementOnToOnePlane_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bLimitMovementOnToOnePlane_MetaData), NewProp_bLimitMovementOnToOnePlane_MetaData) };
void Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_bShowPlaneDebug_SetBit(void* Obj)
{
	((ULoiicCableComponent*)Obj)->bShowPlaneDebug = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_bShowPlaneDebug = { "bShowPlaneDebug", nullptr, (EPropertyFlags)0x00200c0000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ULoiicCableComponent), &Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_bShowPlaneDebug_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowPlaneDebug_MetaData), NewProp_bShowPlaneDebug_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_forwardOfTheLimitPlane = { "forwardOfTheLimitPlane", nullptr, (EPropertyFlags)0x00200c0000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULoiicCableComponent, forwardOfTheLimitPlane), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_forwardOfTheLimitPlane_MetaData), NewProp_forwardOfTheLimitPlane_MetaData) };
void Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_bEnableCollision_SetBit(void* Obj)
{
	((ULoiicCableComponent*)Obj)->bEnableCollision = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_bEnableCollision = { "bEnableCollision", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ULoiicCableComponent), &Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_bEnableCollision_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableCollision_MetaData), NewProp_bEnableCollision_MetaData) };
void Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_bGenerateCustomOverlapEvents_SetBit(void* Obj)
{
	((ULoiicCableComponent*)Obj)->bGenerateCustomOverlapEvents = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_bGenerateCustomOverlapEvents = { "bGenerateCustomOverlapEvents", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ULoiicCableComponent), &Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_bGenerateCustomOverlapEvents_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bGenerateCustomOverlapEvents_MetaData), NewProp_bGenerateCustomOverlapEvents_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_overlapExtraExtent = { "overlapExtraExtent", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULoiicCableComponent, overlapExtraExtent), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_overlapExtraExtent_MetaData), NewProp_overlapExtraExtent_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_cableWidthForCollisions = { "cableWidthForCollisions", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULoiicCableComponent, cableWidthForCollisions), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_cableWidthForCollisions_MetaData), NewProp_cableWidthForCollisions_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_bounceFactor = { "bounceFactor", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULoiicCableComponent, bounceFactor), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bounceFactor_MetaData), NewProp_bounceFactor_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_correctionClampAmount = { "correctionClampAmount", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULoiicCableComponent, correctionClampAmount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_correctionClampAmount_MetaData), NewProp_correctionClampAmount_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_collisionType = { "collisionType", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULoiicCableComponent, collisionType), Z_Construct_UEnum_LoiicBetterCables_ECollisionType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_collisionType_MetaData), NewProp_collisionType_MetaData) }; // 1183468431
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_collisionProfile = { "collisionProfile", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULoiicCableComponent, collisionProfile), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_collisionProfile_MetaData), NewProp_collisionProfile_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_actorsToIgnoreDuringCollision_Inner = { "actorsToIgnoreDuringCollision", nullptr, (EPropertyFlags)0x0104000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_actorsToIgnoreDuringCollision = { "actorsToIgnoreDuringCollision", nullptr, (EPropertyFlags)0x0124080000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULoiicCableComponent, actorsToIgnoreDuringCollision), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_actorsToIgnoreDuringCollision_MetaData), NewProp_actorsToIgnoreDuringCollision_MetaData) };
void Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_bSkipCableUpdateWhenNotVisible_SetBit(void* Obj)
{
	((ULoiicCableComponent*)Obj)->bSkipCableUpdateWhenNotVisible = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_bSkipCableUpdateWhenNotVisible = { "bSkipCableUpdateWhenNotVisible", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ULoiicCableComponent), &Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_bSkipCableUpdateWhenNotVisible_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSkipCableUpdateWhenNotVisible_MetaData), NewProp_bSkipCableUpdateWhenNotVisible_MetaData) };
void Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_bDebugOptimisation_SetBit(void* Obj)
{
	((ULoiicCableComponent*)Obj)->bDebugOptimisation = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_bDebugOptimisation = { "bDebugOptimisation", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ULoiicCableComponent), &Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_bDebugOptimisation_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDebugOptimisation_MetaData), NewProp_bDebugOptimisation_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_minVelocityBeforeSleep = { "minVelocityBeforeSleep", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULoiicCableComponent, minVelocityBeforeSleep), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_minVelocityBeforeSleep_MetaData), NewProp_minVelocityBeforeSleep_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_timeInSecondsBeforeSleep = { "timeInSecondsBeforeSleep", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULoiicCableComponent, timeInSecondsBeforeSleep), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_timeInSecondsBeforeSleep_MetaData), NewProp_timeInSecondsBeforeSleep_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_renderType = { "renderType", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULoiicCableComponent, renderType), Z_Construct_UEnum_LoiicBetterCables_ERenderType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_renderType_MetaData), NewProp_renderType_MetaData) }; // 2693219592
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_numSides = { "numSides", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULoiicCableComponent, numSides), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_numSides_MetaData), NewProp_numSides_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_cableWidth = { "cableWidth", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULoiicCableComponent, cableWidth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_cableWidth_MetaData), NewProp_cableWidth_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_tileMaterial = { "tileMaterial", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULoiicCableComponent, tileMaterial), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_tileMaterial_MetaData), NewProp_tileMaterial_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_grammarMeshes_Inner = { "grammarMeshes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FGrammarMesh, METADATA_PARAMS(0, nullptr) }; // 2727877752
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_grammarMeshes = { "grammarMeshes", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULoiicCableComponent, grammarMeshes), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_grammarMeshes_MetaData), NewProp_grammarMeshes_MetaData) }; // 2727877752
void Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_bUsesGrammar_SetBit(void* Obj)
{
	((ULoiicCableComponent*)Obj)->bUsesGrammar = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_bUsesGrammar = { "bUsesGrammar", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ULoiicCableComponent), &Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_bUsesGrammar_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUsesGrammar_MetaData), NewProp_bUsesGrammar_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_grammar = { "grammar", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULoiicCableComponent, grammar), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_grammar_MetaData), NewProp_grammar_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_createdMeshes_Inner = { "createdMeshes", nullptr, (EPropertyFlags)0x0104000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_createdMeshes = { "createdMeshes", nullptr, (EPropertyFlags)0x012408800000000c, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULoiicCableComponent, createdMeshes), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_createdMeshes_MetaData), NewProp_createdMeshes_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ULoiicCableComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_bAttachStart,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_bAttachEnd,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_attachEndTo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_attachEndSceneComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_attachEndToSocketName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_endLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_cableLength,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_bDefineSubdivisionUsingNumSegment,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_numSegment,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_segmentLength,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_numOfConstraintRuns,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_constraintType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_dampingFactor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_bShowParticleDebug,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_simulationFramePerSeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_substepTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_bLimitMovementOnToOnePlane,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_bShowPlaneDebug,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_forwardOfTheLimitPlane,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_bEnableCollision,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_bGenerateCustomOverlapEvents,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_overlapExtraExtent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_cableWidthForCollisions,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_bounceFactor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_correctionClampAmount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_collisionType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_collisionProfile,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_actorsToIgnoreDuringCollision_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_actorsToIgnoreDuringCollision,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_bSkipCableUpdateWhenNotVisible,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_bDebugOptimisation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_minVelocityBeforeSleep,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_timeInSecondsBeforeSleep,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_renderType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_numSides,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_cableWidth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_tileMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_grammarMeshes_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_grammarMeshes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_bUsesGrammar,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_grammar,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_createdMeshes_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoiicCableComponent_Statics::NewProp_createdMeshes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULoiicCableComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ULoiicCableComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UMeshComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_LoiicBetterCables,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULoiicCableComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ULoiicCableComponent_Statics::ClassParams = {
	&ULoiicCableComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ULoiicCableComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ULoiicCableComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ULoiicCableComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_ULoiicCableComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ULoiicCableComponent()
{
	if (!Z_Registration_Info_UClass_ULoiicCableComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULoiicCableComponent.OuterSingleton, Z_Construct_UClass_ULoiicCableComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ULoiicCableComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ULoiicCableComponent);
ULoiicCableComponent::~ULoiicCableComponent() {}
// ********** End Class ULoiicCableComponent *******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_loicg_Github_LoiicBetterCables_HostProject_Plugins_LoiicBetterCables_Source_LoiicBetterCables_Public_LoiicCableComponent_h__Script_LoiicBetterCables_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EImpulseModifier_StaticEnum, TEXT("EImpulseModifier"), &Z_Registration_Info_UEnum_EImpulseModifier, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1234036419U) },
		{ ERenderType_StaticEnum, TEXT("ERenderType"), &Z_Registration_Info_UEnum_ERenderType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2693219592U) },
		{ ECableConstraintType_StaticEnum, TEXT("ECableConstraintType"), &Z_Registration_Info_UEnum_ECableConstraintType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 622000886U) },
		{ ECollisionType_StaticEnum, TEXT("ECollisionType"), &Z_Registration_Info_UEnum_ECollisionType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1183468431U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FCableParticle::StaticStruct, Z_Construct_UScriptStruct_FCableParticle_Statics::NewStructOps, TEXT("CableParticle"), &Z_Registration_Info_UScriptStruct_FCableParticle, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FCableParticle), 2651070506U) },
		{ FGrammarMesh::StaticStruct, Z_Construct_UScriptStruct_FGrammarMesh_Statics::NewStructOps, TEXT("GrammarMesh"), &Z_Registration_Info_UScriptStruct_FGrammarMesh, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FGrammarMesh), 2727877752U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ULoiicCableComponent, ULoiicCableComponent::StaticClass, TEXT("ULoiicCableComponent"), &Z_Registration_Info_UClass_ULoiicCableComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULoiicCableComponent), 1978734736U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_loicg_Github_LoiicBetterCables_HostProject_Plugins_LoiicBetterCables_Source_LoiicBetterCables_Public_LoiicCableComponent_h__Script_LoiicBetterCables_982103643(TEXT("/Script/LoiicBetterCables"),
	Z_CompiledInDeferFile_FID_Users_loicg_Github_LoiicBetterCables_HostProject_Plugins_LoiicBetterCables_Source_LoiicBetterCables_Public_LoiicCableComponent_h__Script_LoiicBetterCables_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_loicg_Github_LoiicBetterCables_HostProject_Plugins_LoiicBetterCables_Source_LoiicBetterCables_Public_LoiicCableComponent_h__Script_LoiicBetterCables_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Users_loicg_Github_LoiicBetterCables_HostProject_Plugins_LoiicBetterCables_Source_LoiicBetterCables_Public_LoiicCableComponent_h__Script_LoiicBetterCables_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_loicg_Github_LoiicBetterCables_HostProject_Plugins_LoiicBetterCables_Source_LoiicBetterCables_Public_LoiicCableComponent_h__Script_LoiicBetterCables_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_Users_loicg_Github_LoiicBetterCables_HostProject_Plugins_LoiicBetterCables_Source_LoiicBetterCables_Public_LoiicCableComponent_h__Script_LoiicBetterCables_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_loicg_Github_LoiicBetterCables_HostProject_Plugins_LoiicBetterCables_Source_LoiicBetterCables_Public_LoiicCableComponent_h__Script_LoiicBetterCables_Statics::EnumInfo));
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
