// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectW/Fighter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFighter() {}
// Cross Module References
	PROJECTW_API UClass* Z_Construct_UClass_AFighter_NoRegister();
	PROJECTW_API UClass* Z_Construct_UClass_AFighter();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_ProjectW();
// End Cross Module References
	void AFighter::StaticRegisterNativesAFighter()
	{
	}
	UClass* Z_Construct_UClass_AFighter_NoRegister()
	{
		return AFighter::StaticClass();
	}
	struct Z_Construct_UClass_AFighter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFighter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_ProjectW,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFighter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Fighter.h" },
		{ "ModuleRelativePath", "Fighter.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFighter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFighter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AFighter_Statics::ClassParams = {
		&AFighter::StaticClass,
		"Game",
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
		METADATA_PARAMS(Z_Construct_UClass_AFighter_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AFighter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AFighter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AFighter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AFighter, 749436396);
	template<> PROJECTW_API UClass* StaticClass<AFighter>()
	{
		return AFighter::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AFighter(Z_Construct_UClass_AFighter, &AFighter::StaticClass, TEXT("/Script/ProjectW"), TEXT("AFighter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFighter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
