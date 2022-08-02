// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectW/StarWitchMark.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeStarWitchMark() {}
// Cross Module References
	PROJECTW_API UClass* Z_Construct_UClass_AStarWitchMark_NoRegister();
	PROJECTW_API UClass* Z_Construct_UClass_AStarWitchMark();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_ProjectW();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	PROJECTW_API UClass* Z_Construct_UClass_AStarWitchThunder_NoRegister();
// End Cross Module References
	void AStarWitchMark::StaticRegisterNativesAStarWitchMark()
	{
	}
	UClass* Z_Construct_UClass_AStarWitchMark_NoRegister()
	{
		return AStarWitchMark::StaticClass();
	}
	struct Z_Construct_UClass_AStarWitchMark_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Effects_Thunder_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_Effects_Thunder;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AStarWitchMark_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_ProjectW,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AStarWitchMark_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "StarWitchMark.h" },
		{ "ModuleRelativePath", "StarWitchMark.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AStarWitchMark_Statics::NewProp_Effects_Thunder_MetaData[] = {
		{ "Category", "Effects" },
		{ "ModuleRelativePath", "StarWitchMark.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AStarWitchMark_Statics::NewProp_Effects_Thunder = { "Effects_Thunder", nullptr, (EPropertyFlags)0x0014000000000015, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AStarWitchMark, Effects_Thunder), Z_Construct_UClass_AStarWitchThunder_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AStarWitchMark_Statics::NewProp_Effects_Thunder_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AStarWitchMark_Statics::NewProp_Effects_Thunder_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AStarWitchMark_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStarWitchMark_Statics::NewProp_Effects_Thunder,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AStarWitchMark_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AStarWitchMark>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AStarWitchMark_Statics::ClassParams = {
		&AStarWitchMark::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AStarWitchMark_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AStarWitchMark_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AStarWitchMark_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AStarWitchMark_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AStarWitchMark()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AStarWitchMark_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AStarWitchMark, 1980461923);
	template<> PROJECTW_API UClass* StaticClass<AStarWitchMark>()
	{
		return AStarWitchMark::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AStarWitchMark(Z_Construct_UClass_AStarWitchMark, &AStarWitchMark::StaticClass, TEXT("/Script/ProjectW"), TEXT("AStarWitchMark"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AStarWitchMark);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
