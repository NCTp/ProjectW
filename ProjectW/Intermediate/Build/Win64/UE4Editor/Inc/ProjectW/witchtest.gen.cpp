// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectW/witchtest.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodewitchtest() {}
// Cross Module References
	PROJECTW_API UClass* Z_Construct_UClass_Awitchtest_NoRegister();
	PROJECTW_API UClass* Z_Construct_UClass_Awitchtest();
	PAPER2D_API UClass* Z_Construct_UClass_APaperCharacter();
	UPackage* Z_Construct_UPackage__Script_ProjectW();
// End Cross Module References
	void Awitchtest::StaticRegisterNativesAwitchtest()
	{
	}
	UClass* Z_Construct_UClass_Awitchtest_NoRegister()
	{
		return Awitchtest::StaticClass();
	}
	struct Z_Construct_UClass_Awitchtest_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_Awitchtest_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APaperCharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_ProjectW,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_Awitchtest_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "witchtest.h" },
		{ "ModuleRelativePath", "witchtest.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_Awitchtest_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<Awitchtest>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_Awitchtest_Statics::ClassParams = {
		&Awitchtest::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_Awitchtest_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_Awitchtest_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_Awitchtest()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_Awitchtest_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(Awitchtest, 974452535);
	template<> PROJECTW_API UClass* StaticClass<Awitchtest>()
	{
		return Awitchtest::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_Awitchtest(Z_Construct_UClass_Awitchtest, &Awitchtest::StaticClass, TEXT("/Script/ProjectW"), TEXT("Awitchtest"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(Awitchtest);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
