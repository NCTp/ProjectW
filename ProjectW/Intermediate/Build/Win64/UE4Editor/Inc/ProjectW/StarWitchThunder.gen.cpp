// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectW/StarWitchThunder.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeStarWitchThunder() {}
// Cross Module References
	PROJECTW_API UClass* Z_Construct_UClass_AStarWitchThunder_NoRegister();
	PROJECTW_API UClass* Z_Construct_UClass_AStarWitchThunder();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_ProjectW();
// End Cross Module References
	void AStarWitchThunder::StaticRegisterNativesAStarWitchThunder()
	{
	}
	UClass* Z_Construct_UClass_AStarWitchThunder_NoRegister()
	{
		return AStarWitchThunder::StaticClass();
	}
	struct Z_Construct_UClass_AStarWitchThunder_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AStarWitchThunder_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_ProjectW,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AStarWitchThunder_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "StarWitchThunder.h" },
		{ "ModuleRelativePath", "StarWitchThunder.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AStarWitchThunder_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AStarWitchThunder>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AStarWitchThunder_Statics::ClassParams = {
		&AStarWitchThunder::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AStarWitchThunder_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AStarWitchThunder_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AStarWitchThunder()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AStarWitchThunder_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AStarWitchThunder, 194186724);
	template<> PROJECTW_API UClass* StaticClass<AStarWitchThunder>()
	{
		return AStarWitchThunder::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AStarWitchThunder(Z_Construct_UClass_AStarWitchThunder, &AStarWitchThunder::StaticClass, TEXT("/Script/ProjectW"), TEXT("AStarWitchThunder"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AStarWitchThunder);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
