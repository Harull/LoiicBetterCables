// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLoiicBetterCables_init() {}
	LOIICBETTERCABLES_API UFunction* Z_Construct_UDelegateFunction_ULoiicCableComponent_OnBeginOverlap__DelegateSignature();
	LOIICBETTERCABLES_API UFunction* Z_Construct_UDelegateFunction_ULoiicCableComponent_OnEndOverlap__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_LoiicBetterCables;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_LoiicBetterCables()
	{
		if (!Z_Registration_Info_UPackage__Script_LoiicBetterCables.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_ULoiicCableComponent_OnBeginOverlap__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_ULoiicCableComponent_OnEndOverlap__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/LoiicBetterCables",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0xBFD49211,
				0xD30AD417,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_LoiicBetterCables.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_LoiicBetterCables.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_LoiicBetterCables(Z_Construct_UPackage__Script_LoiicBetterCables, TEXT("/Script/LoiicBetterCables"), Z_Registration_Info_UPackage__Script_LoiicBetterCables, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xBFD49211, 0xD30AD417));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
