// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectW/NightWitch.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNightWitch() {}
// Cross Module References
	PROJECTW_API UEnum* Z_Construct_UEnum_ProjectW_EState();
	UPackage* Z_Construct_UPackage__Script_ProjectW();
	PROJECTW_API UClass* Z_Construct_UClass_ANightWitch_NoRegister();
	PROJECTW_API UClass* Z_Construct_UClass_ANightWitch();
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	PAPER2D_API UClass* Z_Construct_UClass_UPaperFlipbookComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCapsuleComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UArrowComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCharacterMovementComponent_NoRegister();
// End Cross Module References
	static UEnum* EState_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_ProjectW_EState, Z_Construct_UPackage__Script_ProjectW(), TEXT("EState"));
		}
		return Singleton;
	}
	template<> PROJECTW_API UEnum* StaticEnum<EState>()
	{
		return EState_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EState(EState_StaticEnum, TEXT("/Script/ProjectW"), TEXT("EState"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_ProjectW_EState_Hash() { return 3218407084U; }
	UEnum* Z_Construct_UEnum_ProjectW_EState()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_ProjectW();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EState"), 0, Get_Z_Construct_UEnum_ProjectW_EState_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EState::DEFAULT", (int64)EState::DEFAULT },
				{ "EState::IDLE", (int64)EState::IDLE },
				{ "EState::CHASE", (int64)EState::CHASE },
				{ "EState::TELEPORT", (int64)EState::TELEPORT },
				{ "EState::ATTACK", (int64)EState::ATTACK },
				{ "EState::STUMBLE", (int64)EState::STUMBLE },
				{ "EState::TAUNT", (int64)EState::TAUNT },
				{ "EState::DEAD", (int64)EState::DEAD },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "ATTACK.Comment", "// Teleport(Far)\n" },
				{ "ATTACK.Name", "EState::ATTACK" },
				{ "ATTACK.ToolTip", "Teleport(Far)" },
				{ "BlueprintType", "true" },
				{ "CHASE.Comment", "// Idle\n" },
				{ "CHASE.Name", "EState::CHASE" },
				{ "CHASE.ToolTip", "Idle" },
				{ "DEAD.Comment", "// Taunt\n" },
				{ "DEAD.Name", "EState::DEAD" },
				{ "DEAD.ToolTip", "Taunt" },
				{ "DEFAULT.Name", "EState::DEFAULT" },
				{ "IDLE.Comment", "// Default\n" },
				{ "IDLE.Name", "EState::IDLE" },
				{ "IDLE.ToolTip", "Default" },
				{ "ModuleRelativePath", "NightWitch.h" },
				{ "STUMBLE.Comment", "// Attack\n" },
				{ "STUMBLE.Name", "EState::STUMBLE" },
				{ "STUMBLE.ToolTip", "Attack" },
				{ "TAUNT.Comment", "// Stumble\n" },
				{ "TAUNT.Name", "EState::TAUNT" },
				{ "TAUNT.ToolTip", "Stumble" },
				{ "TELEPORT.Comment", "// Chase(Close)\n" },
				{ "TELEPORT.Name", "EState::TELEPORT" },
				{ "TELEPORT.ToolTip", "Chase(Close)" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_ProjectW,
				nullptr,
				"EState",
				"EState",
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
	void ANightWitch::StaticRegisterNativesANightWitch()
	{
	}
	UClass* Z_Construct_UClass_ANightWitch_NoRegister()
	{
		return ANightWitch::StaticClass();
	}
	struct Z_Construct_UClass_ANightWitch_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NightWitchFlipbook_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_NightWitchFlipbook;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CapsuleCollision_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CapsuleCollision;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Arrow_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Arrow;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Movement_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Movement;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ActiveState_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ActiveState_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_ActiveState;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ANightWitch_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APawn,
		(UObject* (*)())Z_Construct_UPackage__Script_ProjectW,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANightWitch_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "NightWitch.h" },
		{ "ModuleRelativePath", "NightWitch.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANightWitch_Statics::NewProp_NightWitchFlipbook_MetaData[] = {
		{ "Category", "Flipbook" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "NightWitch.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANightWitch_Statics::NewProp_NightWitchFlipbook = { "NightWitchFlipbook", nullptr, (EPropertyFlags)0x0020080000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ANightWitch, NightWitchFlipbook), Z_Construct_UClass_UPaperFlipbookComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ANightWitch_Statics::NewProp_NightWitchFlipbook_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ANightWitch_Statics::NewProp_NightWitchFlipbook_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANightWitch_Statics::NewProp_CapsuleCollision_MetaData[] = {
		{ "Category", "Capsule Collision" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "NightWitch.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANightWitch_Statics::NewProp_CapsuleCollision = { "CapsuleCollision", nullptr, (EPropertyFlags)0x0020080000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ANightWitch, CapsuleCollision), Z_Construct_UClass_UCapsuleComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ANightWitch_Statics::NewProp_CapsuleCollision_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ANightWitch_Statics::NewProp_CapsuleCollision_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANightWitch_Statics::NewProp_Arrow_MetaData[] = {
		{ "Category", "Direction Arrow" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "NightWitch.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANightWitch_Statics::NewProp_Arrow = { "Arrow", nullptr, (EPropertyFlags)0x0020080000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ANightWitch, Arrow), Z_Construct_UClass_UArrowComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ANightWitch_Statics::NewProp_Arrow_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ANightWitch_Statics::NewProp_Arrow_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANightWitch_Statics::NewProp_Movement_MetaData[] = {
		{ "Category", "Movement" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "NightWitch.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANightWitch_Statics::NewProp_Movement = { "Movement", nullptr, (EPropertyFlags)0x0020080000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ANightWitch, Movement), Z_Construct_UClass_UCharacterMovementComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ANightWitch_Statics::NewProp_Movement_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ANightWitch_Statics::NewProp_Movement_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_ANightWitch_Statics::NewProp_ActiveState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANightWitch_Statics::NewProp_ActiveState_MetaData[] = {
		{ "Category", "State" },
		{ "ModuleRelativePath", "NightWitch.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_ANightWitch_Statics::NewProp_ActiveState = { "ActiveState", nullptr, (EPropertyFlags)0x0020080000020001, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ANightWitch, ActiveState), Z_Construct_UEnum_ProjectW_EState, METADATA_PARAMS(Z_Construct_UClass_ANightWitch_Statics::NewProp_ActiveState_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ANightWitch_Statics::NewProp_ActiveState_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ANightWitch_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANightWitch_Statics::NewProp_NightWitchFlipbook,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANightWitch_Statics::NewProp_CapsuleCollision,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANightWitch_Statics::NewProp_Arrow,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANightWitch_Statics::NewProp_Movement,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANightWitch_Statics::NewProp_ActiveState_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANightWitch_Statics::NewProp_ActiveState,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ANightWitch_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ANightWitch>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ANightWitch_Statics::ClassParams = {
		&ANightWitch::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ANightWitch_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ANightWitch_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ANightWitch_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ANightWitch_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ANightWitch()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ANightWitch_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ANightWitch, 987153514);
	template<> PROJECTW_API UClass* StaticClass<ANightWitch>()
	{
		return ANightWitch::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ANightWitch(Z_Construct_UClass_ANightWitch, &ANightWitch::StaticClass, TEXT("/Script/ProjectW"), TEXT("ANightWitch"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ANightWitch);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
