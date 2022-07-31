// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectW/StarWitchLaser.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeStarWitchLaser() {}
// Cross Module References
	PROJECTW_API UClass* Z_Construct_UClass_AStarWitchLaser_NoRegister();
	PROJECTW_API UClass* Z_Construct_UClass_AStarWitchLaser();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_ProjectW();
// End Cross Module References
	void AStarWitchLaser::StaticRegisterNativesAStarWitchLaser()
	{
	}
	UClass* Z_Construct_UClass_AStarWitchLaser_NoRegister()
	{
		return AStarWitchLaser::StaticClass();
	}
	struct Z_Construct_UClass_AStarWitchLaser_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AStarWitchLaser_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_ProjectW,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AStarWitchLaser_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "StarWitchLaser.h" },
		{ "ModuleRelativePath", "StarWitchLaser.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AStarWitchLaser_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AStarWitchLaser>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AStarWitchLaser_Statics::ClassParams = {
		&AStarWitchLaser::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AStarWitchLaser_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AStarWitchLaser_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AStarWitchLaser()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AStarWitchLaser_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AStarWitchLaser, 1840829281);
	template<> PROJECTW_API UClass* StaticClass<AStarWitchLaser>()
	{
		return AStarWitchLaser::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AStarWitchLaser(Z_Construct_UClass_AStarWitchLaser, &AStarWitchLaser::StaticClass, TEXT("/Script/ProjectW"), TEXT("AStarWitchLaser"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AStarWitchLaser);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
