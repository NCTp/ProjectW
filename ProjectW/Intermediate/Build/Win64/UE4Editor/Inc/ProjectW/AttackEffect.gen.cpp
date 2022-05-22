// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectW/AttackEffect.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAttackEffect() {}
// Cross Module References
	PROJECTW_API UClass* Z_Construct_UClass_AAttackEffect_NoRegister();
	PROJECTW_API UClass* Z_Construct_UClass_AAttackEffect();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_ProjectW();
// End Cross Module References
	void AAttackEffect::StaticRegisterNativesAAttackEffect()
	{
	}
	UClass* Z_Construct_UClass_AAttackEffect_NoRegister()
	{
		return AAttackEffect::StaticClass();
	}
	struct Z_Construct_UClass_AAttackEffect_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AAttackEffect_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_ProjectW,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAttackEffect_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "AttackEffect.h" },
		{ "ModuleRelativePath", "AttackEffect.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AAttackEffect_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AAttackEffect>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AAttackEffect_Statics::ClassParams = {
		&AAttackEffect::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AAttackEffect_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AAttackEffect_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AAttackEffect()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AAttackEffect_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AAttackEffect, 3779754326);
	template<> PROJECTW_API UClass* StaticClass<AAttackEffect>()
	{
		return AAttackEffect::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AAttackEffect(Z_Construct_UClass_AAttackEffect, &AAttackEffect::StaticClass, TEXT("/Script/ProjectW"), TEXT("AAttackEffect"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AAttackEffect);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
