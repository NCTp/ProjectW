// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectW/EnemyBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEnemyBase() {}
// Cross Module References
	PROJECTW_API UClass* Z_Construct_UClass_AEnemyBase_NoRegister();
	PROJECTW_API UClass* Z_Construct_UClass_AEnemyBase();
	PROJECTW_API UClass* Z_Construct_UClass_ACombatant();
	UPackage* Z_Construct_UPackage__Script_ProjectW();
// End Cross Module References
	void AEnemyBase::StaticRegisterNativesAEnemyBase()
	{
	}
	UClass* Z_Construct_UClass_AEnemyBase_NoRegister()
	{
		return AEnemyBase::StaticClass();
	}
	struct Z_Construct_UClass_AEnemyBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEnemyBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACombatant,
		(UObject* (*)())Z_Construct_UPackage__Script_ProjectW,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemyBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "EnemyBase.h" },
		{ "ModuleRelativePath", "EnemyBase.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEnemyBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEnemyBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AEnemyBase_Statics::ClassParams = {
		&AEnemyBase::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AEnemyBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemyBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEnemyBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AEnemyBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEnemyBase, 1612791214);
	template<> PROJECTW_API UClass* StaticClass<AEnemyBase>()
	{
		return AEnemyBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEnemyBase(Z_Construct_UClass_AEnemyBase, &AEnemyBase::StaticClass, TEXT("/Script/ProjectW"), TEXT("AEnemyBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEnemyBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
