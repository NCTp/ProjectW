// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectW/StarWitch.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeStarWitch() {}
// Cross Module References
	PROJECTW_API UEnum* Z_Construct_UEnum_ProjectW_EActorState();
	UPackage* Z_Construct_UPackage__Script_ProjectW();
	PROJECTW_API UClass* Z_Construct_UClass_AStarWitch_NoRegister();
	PROJECTW_API UClass* Z_Construct_UClass_AStarWitch();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	PAPER2D_API UClass* Z_Construct_UClass_UPaperFlipbookComponent_NoRegister();
	PAPER2D_API UClass* Z_Construct_UClass_UPaperFlipbook_NoRegister();
// End Cross Module References
	static UEnum* EActorState_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_ProjectW_EActorState, Z_Construct_UPackage__Script_ProjectW(), TEXT("EActorState"));
		}
		return Singleton;
	}
	template<> PROJECTW_API UEnum* StaticEnum<EActorState>()
	{
		return EActorState_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EActorState(EActorState_StaticEnum, TEXT("/Script/ProjectW"), TEXT("EActorState"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_ProjectW_EActorState_Hash() { return 2047201944U; }
	UEnum* Z_Construct_UEnum_ProjectW_EActorState()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_ProjectW();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EActorState"), 0, Get_Z_Construct_UEnum_ProjectW_EActorState_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EActorState::StarWitchState_Idle", (int64)EActorState::StarWitchState_Idle },
				{ "EActorState::StarWitchState_Walking", (int64)EActorState::StarWitchState_Walking },
				{ "EActorState::StarWitchState_Attack_01", (int64)EActorState::StarWitchState_Attack_01 },
				{ "EActorState::StarWitchState_Attack_02", (int64)EActorState::StarWitchState_Attack_02 },
				{ "EActorState::StarWitchState_Attack_03", (int64)EActorState::StarWitchState_Attack_03 },
				{ "EActorState::StarWitchState_CounterReady", (int64)EActorState::StarWitchState_CounterReady },
				{ "EActorState::StarWitchState_Dead", (int64)EActorState::StarWitchState_Dead },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "ModuleRelativePath", "StarWitch.h" },
				{ "StarWitchState_Attack_01.DisplayName", "Attack_01" },
				{ "StarWitchState_Attack_01.Name", "EActorState::StarWitchState_Attack_01" },
				{ "StarWitchState_Attack_02.DisplayName", "Attack_02" },
				{ "StarWitchState_Attack_02.Name", "EActorState::StarWitchState_Attack_02" },
				{ "StarWitchState_Attack_03.DIsplayName", "Attack_03" },
				{ "StarWitchState_Attack_03.Name", "EActorState::StarWitchState_Attack_03" },
				{ "StarWitchState_CounterReady.DisplayNmae", "CounterReady" },
				{ "StarWitchState_CounterReady.Name", "EActorState::StarWitchState_CounterReady" },
				{ "StarWitchState_Dead.DisplayNmae", "Dead" },
				{ "StarWitchState_Dead.Name", "EActorState::StarWitchState_Dead" },
				{ "StarWitchState_Idle.DisplayName", "Idle" },
				{ "StarWitchState_Idle.Name", "EActorState::StarWitchState_Idle" },
				{ "StarWitchState_Walking.DisplayName", "Walking" },
				{ "StarWitchState_Walking.Name", "EActorState::StarWitchState_Walking" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_ProjectW,
				nullptr,
				"EActorState",
				"EActorState",
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
	void AStarWitch::StaticRegisterNativesAStarWitch()
	{
	}
	UClass* Z_Construct_UClass_AStarWitch_NoRegister()
	{
		return AStarWitch::StaticClass();
	}
	struct Z_Construct_UClass_AStarWitch_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FlipbookComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_FlipbookComponent;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_StarWitchState_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_StarWitchState_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_StarWitchState;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IdleAnim_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_IdleAnim;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WalkingAnim_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WalkingAnim;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CastingAnim_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CastingAnim;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CastingAnim_02_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CastingAnim_02;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CounterReadyAnim_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CounterReadyAnim;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CounterAnim_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CounterAnim;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TeleportAnim_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_TeleportAnim;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_isFarFromPlayer_MetaData[];
#endif
		static void NewProp_m_isFarFromPlayer_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_m_isFarFromPlayer;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_isCloseToPlayer_MetaData[];
#endif
		static void NewProp_m_isCloseToPlayer_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_m_isCloseToPlayer;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_isPhaseOne_MetaData[];
#endif
		static void NewProp_m_isPhaseOne_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_m_isPhaseOne;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_isPhaseTwo_MetaData[];
#endif
		static void NewProp_m_isPhaseTwo_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_m_isPhaseTwo;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_isPhaseThree_MetaData[];
#endif
		static void NewProp_m_isPhaseThree_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_m_isPhaseThree;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AStarWitch_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_ProjectW,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AStarWitch_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "StarWitch.h" },
		{ "ModuleRelativePath", "StarWitch.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AStarWitch_Statics::NewProp_FlipbookComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Animation" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "StarWitch.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AStarWitch_Statics::NewProp_FlipbookComponent = { "FlipbookComponent", nullptr, (EPropertyFlags)0x00400000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AStarWitch, FlipbookComponent), Z_Construct_UClass_UPaperFlipbookComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AStarWitch_Statics::NewProp_FlipbookComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AStarWitch_Statics::NewProp_FlipbookComponent_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_AStarWitch_Statics::NewProp_StarWitchState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AStarWitch_Statics::NewProp_StarWitchState_MetaData[] = {
		{ "Category", "State" },
		{ "ModuleRelativePath", "StarWitch.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AStarWitch_Statics::NewProp_StarWitchState = { "StarWitchState", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AStarWitch, StarWitchState), Z_Construct_UEnum_ProjectW_EActorState, METADATA_PARAMS(Z_Construct_UClass_AStarWitch_Statics::NewProp_StarWitchState_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AStarWitch_Statics::NewProp_StarWitchState_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AStarWitch_Statics::NewProp_IdleAnim_MetaData[] = {
		{ "Category", "Animations" },
		{ "Comment", "////////// Animations ///////////\n// Idle Animation\n" },
		{ "ModuleRelativePath", "StarWitch.h" },
		{ "ToolTip", "/ Animations\n Idle Animation" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AStarWitch_Statics::NewProp_IdleAnim = { "IdleAnim", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AStarWitch, IdleAnim), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AStarWitch_Statics::NewProp_IdleAnim_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AStarWitch_Statics::NewProp_IdleAnim_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AStarWitch_Statics::NewProp_WalkingAnim_MetaData[] = {
		{ "Category", "Animations" },
		{ "Comment", "// Walking Animation\n" },
		{ "ModuleRelativePath", "StarWitch.h" },
		{ "ToolTip", "Walking Animation" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AStarWitch_Statics::NewProp_WalkingAnim = { "WalkingAnim", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AStarWitch, WalkingAnim), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AStarWitch_Statics::NewProp_WalkingAnim_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AStarWitch_Statics::NewProp_WalkingAnim_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AStarWitch_Statics::NewProp_CastingAnim_MetaData[] = {
		{ "Category", "Animations" },
		{ "Comment", "// Casting Animation\n" },
		{ "ModuleRelativePath", "StarWitch.h" },
		{ "ToolTip", "Casting Animation" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AStarWitch_Statics::NewProp_CastingAnim = { "CastingAnim", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AStarWitch, CastingAnim), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AStarWitch_Statics::NewProp_CastingAnim_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AStarWitch_Statics::NewProp_CastingAnim_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AStarWitch_Statics::NewProp_CastingAnim_02_MetaData[] = {
		{ "Category", "Animations" },
		{ "Comment", "// Casting when casting Shotgun Laser (Attack02)\n" },
		{ "ModuleRelativePath", "StarWitch.h" },
		{ "ToolTip", "Casting when casting Shotgun Laser (Attack02)" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AStarWitch_Statics::NewProp_CastingAnim_02 = { "CastingAnim_02", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AStarWitch, CastingAnim_02), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AStarWitch_Statics::NewProp_CastingAnim_02_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AStarWitch_Statics::NewProp_CastingAnim_02_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AStarWitch_Statics::NewProp_CounterReadyAnim_MetaData[] = {
		{ "Category", "Animations" },
		{ "Comment", "// Counter Ready Animation\n" },
		{ "ModuleRelativePath", "StarWitch.h" },
		{ "ToolTip", "Counter Ready Animation" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AStarWitch_Statics::NewProp_CounterReadyAnim = { "CounterReadyAnim", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AStarWitch, CounterReadyAnim), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AStarWitch_Statics::NewProp_CounterReadyAnim_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AStarWitch_Statics::NewProp_CounterReadyAnim_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AStarWitch_Statics::NewProp_CounterAnim_MetaData[] = {
		{ "Category", "Animations" },
		{ "Comment", "// Animation played when counter success\n" },
		{ "ModuleRelativePath", "StarWitch.h" },
		{ "ToolTip", "Animation played when counter success" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AStarWitch_Statics::NewProp_CounterAnim = { "CounterAnim", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AStarWitch, CounterAnim), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AStarWitch_Statics::NewProp_CounterAnim_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AStarWitch_Statics::NewProp_CounterAnim_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AStarWitch_Statics::NewProp_TeleportAnim_MetaData[] = {
		{ "Category", "Animations" },
		{ "Comment", "// Teleport Animation\n" },
		{ "ModuleRelativePath", "StarWitch.h" },
		{ "ToolTip", "Teleport Animation" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AStarWitch_Statics::NewProp_TeleportAnim = { "TeleportAnim", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AStarWitch, TeleportAnim), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AStarWitch_Statics::NewProp_TeleportAnim_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AStarWitch_Statics::NewProp_TeleportAnim_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AStarWitch_Statics::NewProp_m_isFarFromPlayer_MetaData[] = {
		{ "Category", "State" },
		{ "Comment", "////////// States ///////////\n" },
		{ "ModuleRelativePath", "StarWitch.h" },
		{ "ToolTip", "/ States" },
	};
#endif
	void Z_Construct_UClass_AStarWitch_Statics::NewProp_m_isFarFromPlayer_SetBit(void* Obj)
	{
		((AStarWitch*)Obj)->m_isFarFromPlayer = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AStarWitch_Statics::NewProp_m_isFarFromPlayer = { "m_isFarFromPlayer", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AStarWitch), &Z_Construct_UClass_AStarWitch_Statics::NewProp_m_isFarFromPlayer_SetBit, METADATA_PARAMS(Z_Construct_UClass_AStarWitch_Statics::NewProp_m_isFarFromPlayer_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AStarWitch_Statics::NewProp_m_isFarFromPlayer_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AStarWitch_Statics::NewProp_m_isCloseToPlayer_MetaData[] = {
		{ "Category", "State" },
		{ "ModuleRelativePath", "StarWitch.h" },
	};
#endif
	void Z_Construct_UClass_AStarWitch_Statics::NewProp_m_isCloseToPlayer_SetBit(void* Obj)
	{
		((AStarWitch*)Obj)->m_isCloseToPlayer = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AStarWitch_Statics::NewProp_m_isCloseToPlayer = { "m_isCloseToPlayer", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AStarWitch), &Z_Construct_UClass_AStarWitch_Statics::NewProp_m_isCloseToPlayer_SetBit, METADATA_PARAMS(Z_Construct_UClass_AStarWitch_Statics::NewProp_m_isCloseToPlayer_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AStarWitch_Statics::NewProp_m_isCloseToPlayer_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AStarWitch_Statics::NewProp_m_isPhaseOne_MetaData[] = {
		{ "Category", "State" },
		{ "ModuleRelativePath", "StarWitch.h" },
	};
#endif
	void Z_Construct_UClass_AStarWitch_Statics::NewProp_m_isPhaseOne_SetBit(void* Obj)
	{
		((AStarWitch*)Obj)->m_isPhaseOne = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AStarWitch_Statics::NewProp_m_isPhaseOne = { "m_isPhaseOne", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AStarWitch), &Z_Construct_UClass_AStarWitch_Statics::NewProp_m_isPhaseOne_SetBit, METADATA_PARAMS(Z_Construct_UClass_AStarWitch_Statics::NewProp_m_isPhaseOne_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AStarWitch_Statics::NewProp_m_isPhaseOne_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AStarWitch_Statics::NewProp_m_isPhaseTwo_MetaData[] = {
		{ "Category", "State" },
		{ "ModuleRelativePath", "StarWitch.h" },
	};
#endif
	void Z_Construct_UClass_AStarWitch_Statics::NewProp_m_isPhaseTwo_SetBit(void* Obj)
	{
		((AStarWitch*)Obj)->m_isPhaseTwo = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AStarWitch_Statics::NewProp_m_isPhaseTwo = { "m_isPhaseTwo", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AStarWitch), &Z_Construct_UClass_AStarWitch_Statics::NewProp_m_isPhaseTwo_SetBit, METADATA_PARAMS(Z_Construct_UClass_AStarWitch_Statics::NewProp_m_isPhaseTwo_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AStarWitch_Statics::NewProp_m_isPhaseTwo_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AStarWitch_Statics::NewProp_m_isPhaseThree_MetaData[] = {
		{ "Category", "State" },
		{ "ModuleRelativePath", "StarWitch.h" },
	};
#endif
	void Z_Construct_UClass_AStarWitch_Statics::NewProp_m_isPhaseThree_SetBit(void* Obj)
	{
		((AStarWitch*)Obj)->m_isPhaseThree = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AStarWitch_Statics::NewProp_m_isPhaseThree = { "m_isPhaseThree", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AStarWitch), &Z_Construct_UClass_AStarWitch_Statics::NewProp_m_isPhaseThree_SetBit, METADATA_PARAMS(Z_Construct_UClass_AStarWitch_Statics::NewProp_m_isPhaseThree_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AStarWitch_Statics::NewProp_m_isPhaseThree_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AStarWitch_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStarWitch_Statics::NewProp_FlipbookComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStarWitch_Statics::NewProp_StarWitchState_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStarWitch_Statics::NewProp_StarWitchState,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStarWitch_Statics::NewProp_IdleAnim,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStarWitch_Statics::NewProp_WalkingAnim,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStarWitch_Statics::NewProp_CastingAnim,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStarWitch_Statics::NewProp_CastingAnim_02,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStarWitch_Statics::NewProp_CounterReadyAnim,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStarWitch_Statics::NewProp_CounterAnim,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStarWitch_Statics::NewProp_TeleportAnim,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStarWitch_Statics::NewProp_m_isFarFromPlayer,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStarWitch_Statics::NewProp_m_isCloseToPlayer,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStarWitch_Statics::NewProp_m_isPhaseOne,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStarWitch_Statics::NewProp_m_isPhaseTwo,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStarWitch_Statics::NewProp_m_isPhaseThree,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AStarWitch_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AStarWitch>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AStarWitch_Statics::ClassParams = {
		&AStarWitch::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AStarWitch_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AStarWitch_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AStarWitch_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AStarWitch_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AStarWitch()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AStarWitch_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AStarWitch, 4126442244);
	template<> PROJECTW_API UClass* StaticClass<AStarWitch>()
	{
		return AStarWitch::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AStarWitch(Z_Construct_UClass_AStarWitch, &AStarWitch::StaticClass, TEXT("/Script/ProjectW"), TEXT("AStarWitch"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AStarWitch);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
