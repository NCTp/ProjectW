// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectW/StarWitchTeleportEffects.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeStarWitchTeleportEffects() {}
// Cross Module References
	PROJECTW_API UClass* Z_Construct_UClass_AStarWitchTeleportEffects_NoRegister();
	PROJECTW_API UClass* Z_Construct_UClass_AStarWitchTeleportEffects();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_ProjectW();
// End Cross Module References
	void AStarWitchTeleportEffects::StaticRegisterNativesAStarWitchTeleportEffects()
	{
	}
	UClass* Z_Construct_UClass_AStarWitchTeleportEffects_NoRegister()
	{
		return AStarWitchTeleportEffects::StaticClass();
	}
	struct Z_Construct_UClass_AStarWitchTeleportEffects_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AStarWitchTeleportEffects_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_ProjectW,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AStarWitchTeleportEffects_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "StarWitchTeleportEffects.h" },
		{ "ModuleRelativePath", "StarWitchTeleportEffects.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AStarWitchTeleportEffects_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AStarWitchTeleportEffects>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AStarWitchTeleportEffects_Statics::ClassParams = {
		&AStarWitchTeleportEffects::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AStarWitchTeleportEffects_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AStarWitchTeleportEffects_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AStarWitchTeleportEffects()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AStarWitchTeleportEffects_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AStarWitchTeleportEffects, 3082088387);
	template<> PROJECTW_API UClass* StaticClass<AStarWitchTeleportEffects>()
	{
		return AStarWitchTeleportEffects::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AStarWitchTeleportEffects(Z_Construct_UClass_AStarWitchTeleportEffects, &AStarWitchTeleportEffects::StaticClass, TEXT("/Script/ProjectW"), TEXT("AStarWitchTeleportEffects"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AStarWitchTeleportEffects);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
