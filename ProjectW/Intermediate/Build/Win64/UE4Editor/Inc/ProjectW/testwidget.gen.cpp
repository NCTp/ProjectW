// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectW/testwidget.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodetestwidget() {}
// Cross Module References
	PROJECTW_API UClass* Z_Construct_UClass_Utestwidget_NoRegister();
	PROJECTW_API UClass* Z_Construct_UClass_Utestwidget();
	UMGEDITOR_API UClass* Z_Construct_UClass_UWidgetBlueprint();
	UPackage* Z_Construct_UPackage__Script_ProjectW();
// End Cross Module References
	void Utestwidget::StaticRegisterNativesUtestwidget()
	{
	}
	UClass* Z_Construct_UClass_Utestwidget_NoRegister()
	{
		return Utestwidget::StaticClass();
	}
	struct Z_Construct_UClass_Utestwidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_Utestwidget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UWidgetBlueprint,
		(UObject* (*)())Z_Construct_UPackage__Script_ProjectW,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_Utestwidget_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "testwidget.h" },
		{ "ModuleRelativePath", "testwidget.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_Utestwidget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<Utestwidget>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_Utestwidget_Statics::ClassParams = {
		&Utestwidget::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_Utestwidget_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_Utestwidget_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_Utestwidget()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_Utestwidget_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(Utestwidget, 289343464);
	template<> PROJECTW_API UClass* StaticClass<Utestwidget>()
	{
		return Utestwidget::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_Utestwidget(Z_Construct_UClass_Utestwidget, &Utestwidget::StaticClass, TEXT("/Script/ProjectW"), TEXT("Utestwidget"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(Utestwidget);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
