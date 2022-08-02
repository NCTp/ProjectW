// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectW/testwitch.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodetestwitch() {}
// Cross Module References
	PROJECTW_API UEnum* Z_Construct_UEnum_ProjectW_ESpell();
	UPackage* Z_Construct_UPackage__Script_ProjectW();
	PROJECTW_API UEnum* Z_Construct_UEnum_ProjectW_ETestState();
	PROJECTW_API UClass* Z_Construct_UClass_Atestwitch_NoRegister();
	PROJECTW_API UClass* Z_Construct_UClass_Atestwitch();
	PAPER2D_API UClass* Z_Construct_UClass_APaperCharacter();
	AIMODULE_API UClass* Z_Construct_UClass_AAIController_NoRegister();
// End Cross Module References
	static UEnum* ESpell_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_ProjectW_ESpell, Z_Construct_UPackage__Script_ProjectW(), TEXT("ESpell"));
		}
		return Singleton;
	}
	template<> PROJECTW_API UEnum* StaticEnum<ESpell>()
	{
		return ESpell_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ESpell(ESpell_StaticEnum, TEXT("/Script/ProjectW"), TEXT("ESpell"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_ProjectW_ESpell_Hash() { return 1623933187U; }
	UEnum* Z_Construct_UEnum_ProjectW_ESpell()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_ProjectW();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ESpell"), 0, Get_Z_Construct_UEnum_ProjectW_ESpell_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ESpell::DEFAULT", (int64)ESpell::DEFAULT },
				{ "ESpell::CHAIN", (int64)ESpell::CHAIN },
				{ "ESpell::LASER", (int64)ESpell::LASER },
				{ "ESpell::SUMMON_GHOUL", (int64)ESpell::SUMMON_GHOUL },
				{ "ESpell::SUMMON_JORMUNGAND", (int64)ESpell::SUMMON_JORMUNGAND },
				{ "ESpell::HEXAGRAM", (int64)ESpell::HEXAGRAM },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "CHAIN.DisplayName", "Chain" },
				{ "CHAIN.Name", "ESpell::CHAIN" },
				{ "DEFAULT.DisplayName", "Default" },
				{ "DEFAULT.Name", "ESpell::DEFAULT" },
				{ "HEXAGRAM.DisplayName", "Hexagram" },
				{ "HEXAGRAM.Name", "ESpell::HEXAGRAM" },
				{ "LASER.DisplayName", "Laser" },
				{ "LASER.Name", "ESpell::LASER" },
				{ "ModuleRelativePath", "testwitch.h" },
				{ "SUMMON_GHOUL.DisplayName", "Summon" },
				{ "SUMMON_GHOUL.Name", "ESpell::SUMMON_GHOUL" },
				{ "SUMMON_JORMUNGAND.DisplayName", "Summon" },
				{ "SUMMON_JORMUNGAND.Name", "ESpell::SUMMON_JORMUNGAND" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_ProjectW,
				nullptr,
				"ESpell",
				"ESpell",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* ETestState_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_ProjectW_ETestState, Z_Construct_UPackage__Script_ProjectW(), TEXT("ETestState"));
		}
		return Singleton;
	}
	template<> PROJECTW_API UEnum* StaticEnum<ETestState>()
	{
		return ETestState_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ETestState(ETestState_StaticEnum, TEXT("/Script/ProjectW"), TEXT("ETestState"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_ProjectW_ETestState_Hash() { return 2711453495U; }
	UEnum* Z_Construct_UEnum_ProjectW_ETestState()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_ProjectW();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ETestState"), 0, Get_Z_Construct_UEnum_ProjectW_ETestState_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ETestState::DEFAULT", (int64)ETestState::DEFAULT },
				{ "ETestState::IDLE", (int64)ETestState::IDLE },
				{ "ETestState::RUNAWAY", (int64)ETestState::RUNAWAY },
				{ "ETestState::TELEPORT", (int64)ETestState::TELEPORT },
				{ "ETestState::ATTACK", (int64)ETestState::ATTACK },
				{ "ETestState::STUMBLE", (int64)ETestState::STUMBLE },
				{ "ETestState::TAUNT", (int64)ETestState::TAUNT },
				{ "ETestState::DEAD", (int64)ETestState::DEAD },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "ATTACK.DisplayName", "Attack" },
				{ "ATTACK.Name", "ETestState::ATTACK" },
				{ "BlueprintType", "true" },
				{ "DEAD.DisplayName", "Dead" },
				{ "DEAD.Name", "ETestState::DEAD" },
				{ "DEFAULT.DisplayName", "Default" },
				{ "DEFAULT.Name", "ETestState::DEFAULT" },
				{ "IDLE.DisplayName", "Idle" },
				{ "IDLE.Name", "ETestState::IDLE" },
				{ "ModuleRelativePath", "testwitch.h" },
				{ "RUNAWAY.DisplayName", "Runaway" },
				{ "RUNAWAY.Name", "ETestState::RUNAWAY" },
				{ "STUMBLE.DisplayName", "Stumble" },
				{ "STUMBLE.Name", "ETestState::STUMBLE" },
				{ "TAUNT.DisplayName", "Tarunt" },
				{ "TAUNT.Name", "ETestState::TAUNT" },
				{ "TELEPORT.DisplayName", "Teleport" },
				{ "TELEPORT.Name", "ETestState::TELEPORT" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_ProjectW,
				nullptr,
				"ETestState",
				"ETestState",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	void Atestwitch::StaticRegisterNativesAtestwitch()
	{
	}
	UClass* Z_Construct_UClass_Atestwitch_NoRegister()
	{
		return Atestwitch::StaticClass();
	}
	struct Z_Construct_UClass_Atestwitch_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ActiveState_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ActiveState_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_ActiveState;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Spell_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Spell_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Spell;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AIController_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_AIController;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_Atestwitch_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APaperCharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_ProjectW,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_Atestwitch_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "testwitch.h" },
		{ "ModuleRelativePath", "testwitch.h" },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_Atestwitch_Statics::NewProp_ActiveState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_Atestwitch_Statics::NewProp_ActiveState_MetaData[] = {
		{ "Category", "State" },
		{ "ModuleRelativePath", "testwitch.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_Atestwitch_Statics::NewProp_ActiveState = { "ActiveState", nullptr, (EPropertyFlags)0x0020080000020001, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Atestwitch, ActiveState), Z_Construct_UEnum_ProjectW_ETestState, METADATA_PARAMS(Z_Construct_UClass_Atestwitch_Statics::NewProp_ActiveState_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_Atestwitch_Statics::NewProp_ActiveState_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_Atestwitch_Statics::NewProp_Spell_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_Atestwitch_Statics::NewProp_Spell_MetaData[] = {
		{ "Category", "Spell" },
		{ "ModuleRelativePath", "testwitch.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_Atestwitch_Statics::NewProp_Spell = { "Spell", nullptr, (EPropertyFlags)0x0020080000020001, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Atestwitch, Spell), Z_Construct_UEnum_ProjectW_ESpell, METADATA_PARAMS(Z_Construct_UClass_Atestwitch_Statics::NewProp_Spell_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_Atestwitch_Statics::NewProp_Spell_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_Atestwitch_Statics::NewProp_AIController_MetaData[] = {
		{ "ModuleRelativePath", "testwitch.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_Atestwitch_Statics::NewProp_AIController = { "AIController", nullptr, (EPropertyFlags)0x0020080000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Atestwitch, AIController), Z_Construct_UClass_AAIController_NoRegister, METADATA_PARAMS(Z_Construct_UClass_Atestwitch_Statics::NewProp_AIController_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_Atestwitch_Statics::NewProp_AIController_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_Atestwitch_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_Atestwitch_Statics::NewProp_ActiveState_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_Atestwitch_Statics::NewProp_ActiveState,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_Atestwitch_Statics::NewProp_Spell_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_Atestwitch_Statics::NewProp_Spell,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_Atestwitch_Statics::NewProp_AIController,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_Atestwitch_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<Atestwitch>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_Atestwitch_Statics::ClassParams = {
		&Atestwitch::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_Atestwitch_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_Atestwitch_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_Atestwitch_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_Atestwitch_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_Atestwitch()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_Atestwitch_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(Atestwitch, 4267301244);
	template<> PROJECTW_API UClass* StaticClass<Atestwitch>()
	{
		return Atestwitch::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_Atestwitch(Z_Construct_UClass_Atestwitch, &Atestwitch::StaticClass, TEXT("/Script/ProjectW"), TEXT("Atestwitch"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(Atestwitch);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
