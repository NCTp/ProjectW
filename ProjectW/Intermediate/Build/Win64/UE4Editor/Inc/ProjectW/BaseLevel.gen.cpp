// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectW/BaseLevel.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBaseLevel() {}
// Cross Module References
	PROJECTW_API UClass* Z_Construct_UClass_ABaseLevel_NoRegister();
	PROJECTW_API UClass* Z_Construct_UClass_ABaseLevel();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_ProjectW();
// End Cross Module References
	void ABaseLevel::StaticRegisterNativesABaseLevel()
	{
	}
	UClass* Z_Construct_UClass_ABaseLevel_NoRegister()
	{
		return ABaseLevel::StaticClass();
	}
	struct Z_Construct_UClass_ABaseLevel_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABaseLevel_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_ProjectW,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABaseLevel_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "BaseLevel.h" },
		{ "ModuleRelativePath", "BaseLevel.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABaseLevel_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABaseLevel>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ABaseLevel_Statics::ClassParams = {
		&ABaseLevel::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ABaseLevel_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ABaseLevel_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ABaseLevel()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ABaseLevel_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ABaseLevel, 851584561);
	template<> PROJECTW_API UClass* StaticClass<ABaseLevel>()
	{
		return ABaseLevel::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABaseLevel(Z_Construct_UClass_ABaseLevel, &ABaseLevel::StaticClass, TEXT("/Script/ProjectW"), TEXT("ABaseLevel"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABaseLevel);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
