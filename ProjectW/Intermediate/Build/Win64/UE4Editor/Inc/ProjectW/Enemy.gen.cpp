// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectW/Enemy.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEnemy() {}
// Cross Module References
	PROJECTW_API UEnum* Z_Construct_UEnum_ProjectW_State();
	UPackage* Z_Construct_UPackage__Script_ProjectW();
	PROJECTW_API UClass* Z_Construct_UClass_AEnemy_NoRegister();
	PROJECTW_API UClass* Z_Construct_UClass_AEnemy();
	PAPER2D_API UClass* Z_Construct_UClass_APaperCharacter();
	ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	ENGINE_API UClass* Z_Construct_UClass_APawn_NoRegister();
	PAPER2D_API UClass* Z_Construct_UClass_UPaperFlipbook_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	PROJECTW_API UClass* Z_Construct_UClass_AProjectiles_NoRegister();
// End Cross Module References
	static UEnum* State_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_ProjectW_State, Z_Construct_UPackage__Script_ProjectW(), TEXT("State"));
		}
		return Singleton;
	}
	template<> PROJECTW_API UEnum* StaticEnum<State>()
	{
		return State_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_State(State_StaticEnum, TEXT("/Script/ProjectW"), TEXT("State"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_ProjectW_State_Hash() { return 2159600846U; }
	UEnum* Z_Construct_UEnum_ProjectW_State()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_ProjectW();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("State"), 0, Get_Z_Construct_UEnum_ProjectW_State_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "State::IDLE", (int64)State::IDLE },
				{ "State::CLOSE", (int64)State::CLOSE },
				{ "State::FAR", (int64)State::FAR },
				{ "State::MELEE_ATTACK_01", (int64)State::MELEE_ATTACK_01 },
				{ "State::MELEE_ATTACK_02", (int64)State::MELEE_ATTACK_02 },
				{ "State::RANGE_ATTACK_01", (int64)State::RANGE_ATTACK_01 },
				{ "State::RANGE_ATTACK_02", (int64)State::RANGE_ATTACK_02 },
				{ "State::AREA_ATTACK_01", (int64)State::AREA_ATTACK_01 },
				{ "State::AREA_ATTACK_02", (int64)State::AREA_ATTACK_02 },
				{ "State::TELEPORT", (int64)State::TELEPORT },
				{ "State::GIMMICK", (int64)State::GIMMICK },
				{ "State::DEAD", (int64)State::DEAD },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "AREA_ATTACK_01.Name", "State::AREA_ATTACK_01" },
				{ "AREA_ATTACK_02.Name", "State::AREA_ATTACK_02" },
				{ "BlueprintType", "true" },
				{ "CLOSE.Name", "State::CLOSE" },
				{ "DEAD.Name", "State::DEAD" },
				{ "FAR.Name", "State::FAR" },
				{ "GIMMICK.Name", "State::GIMMICK" },
				{ "IDLE.Name", "State::IDLE" },
				{ "MELEE_ATTACK_01.Name", "State::MELEE_ATTACK_01" },
				{ "MELEE_ATTACK_02.Name", "State::MELEE_ATTACK_02" },
				{ "ModuleRelativePath", "Enemy.h" },
				{ "RANGE_ATTACK_01.Name", "State::RANGE_ATTACK_01" },
				{ "RANGE_ATTACK_02.Name", "State::RANGE_ATTACK_02" },
				{ "TELEPORT.Name", "State::TELEPORT" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_ProjectW,
				nullptr,
				"State",
				"State",
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
	DEFINE_FUNCTION(AEnemy::execOnOverlapBegin)
	{
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComp);
		P_GET_OBJECT(AActor,Z_Param_OtherActor);
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp);
		P_GET_PROPERTY(FIntProperty,Z_Param_OtherBodyIndex);
		P_GET_UBOOL(Z_Param_bFromSweep);
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnOverlapBegin(Z_Param_OverlappedComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult);
		P_NATIVE_END;
	}
	void AEnemy::StaticRegisterNativesAEnemy()
	{
		UClass* Class = AEnemy::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnOverlapBegin", &AEnemy::execOnOverlapBegin },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AEnemy_OnOverlapBegin_Statics
	{
		struct Enemy_eventOnOverlapBegin_Parms
		{
			UPrimitiveComponent* OverlappedComp;
			AActor* OtherActor;
			UPrimitiveComponent* OtherComp;
			int32 OtherBodyIndex;
			bool bFromSweep;
			FHitResult SweepResult;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OverlappedComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OverlappedComp;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OtherComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherComp;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_OtherBodyIndex;
		static void NewProp_bFromSweep_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bFromSweep;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SweepResult_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_SweepResult;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AEnemy_OnOverlapBegin_Statics::NewProp_OverlappedComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AEnemy_OnOverlapBegin_Statics::NewProp_OverlappedComp = { "OverlappedComp", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Enemy_eventOnOverlapBegin_Parms, OverlappedComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_AEnemy_OnOverlapBegin_Statics::NewProp_OverlappedComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemy_OnOverlapBegin_Statics::NewProp_OverlappedComp_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AEnemy_OnOverlapBegin_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Enemy_eventOnOverlapBegin_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AEnemy_OnOverlapBegin_Statics::NewProp_OtherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AEnemy_OnOverlapBegin_Statics::NewProp_OtherComp = { "OtherComp", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Enemy_eventOnOverlapBegin_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_AEnemy_OnOverlapBegin_Statics::NewProp_OtherComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemy_OnOverlapBegin_Statics::NewProp_OtherComp_MetaData)) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AEnemy_OnOverlapBegin_Statics::NewProp_OtherBodyIndex = { "OtherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Enemy_eventOnOverlapBegin_Parms, OtherBodyIndex), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_AEnemy_OnOverlapBegin_Statics::NewProp_bFromSweep_SetBit(void* Obj)
	{
		((Enemy_eventOnOverlapBegin_Parms*)Obj)->bFromSweep = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AEnemy_OnOverlapBegin_Statics::NewProp_bFromSweep = { "bFromSweep", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(Enemy_eventOnOverlapBegin_Parms), &Z_Construct_UFunction_AEnemy_OnOverlapBegin_Statics::NewProp_bFromSweep_SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AEnemy_OnOverlapBegin_Statics::NewProp_SweepResult_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEnemy_OnOverlapBegin_Statics::NewProp_SweepResult = { "SweepResult", nullptr, (EPropertyFlags)0x0010008008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Enemy_eventOnOverlapBegin_Parms, SweepResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(Z_Construct_UFunction_AEnemy_OnOverlapBegin_Statics::NewProp_SweepResult_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemy_OnOverlapBegin_Statics::NewProp_SweepResult_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEnemy_OnOverlapBegin_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEnemy_OnOverlapBegin_Statics::NewProp_OverlappedComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEnemy_OnOverlapBegin_Statics::NewProp_OtherActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEnemy_OnOverlapBegin_Statics::NewProp_OtherComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEnemy_OnOverlapBegin_Statics::NewProp_OtherBodyIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEnemy_OnOverlapBegin_Statics::NewProp_bFromSweep,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEnemy_OnOverlapBegin_Statics::NewProp_SweepResult,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AEnemy_OnOverlapBegin_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Enemy.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AEnemy_OnOverlapBegin_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEnemy, nullptr, "OnOverlapBegin", nullptr, nullptr, sizeof(Enemy_eventOnOverlapBegin_Parms), Z_Construct_UFunction_AEnemy_OnOverlapBegin_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemy_OnOverlapBegin_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AEnemy_OnOverlapBegin_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemy_OnOverlapBegin_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AEnemy_OnOverlapBegin()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AEnemy_OnOverlapBegin_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AEnemy_NoRegister()
	{
		return AEnemy::StaticClass();
	}
	struct Z_Construct_UClass_AEnemy_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_activeState_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_activeState_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_activeState;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_health_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_health;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_target_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_target;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RunningAnimation_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_RunningAnimation;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IdleAnimation_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_IdleAnimation;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AttackAnimation_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_AttackAnimation;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_projectile_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_projectile;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEnemy_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APaperCharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_ProjectW,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AEnemy_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AEnemy_OnOverlapBegin, "OnOverlapBegin" }, // 1920808167
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemy_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Enemy.h" },
		{ "ModuleRelativePath", "Enemy.h" },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_AEnemy_Statics::NewProp_activeState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemy_Statics::NewProp_activeState_MetaData[] = {
		{ "Category", "Finite State Machine" },
		{ "ModuleRelativePath", "Enemy.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AEnemy_Statics::NewProp_activeState = { "activeState", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemy, activeState), Z_Construct_UEnum_ProjectW_State, METADATA_PARAMS(Z_Construct_UClass_AEnemy_Statics::NewProp_activeState_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Statics::NewProp_activeState_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemy_Statics::NewProp_health_MetaData[] = {
		{ "Category", "Health" },
		{ "ModuleRelativePath", "Enemy.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEnemy_Statics::NewProp_health = { "health", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemy, health), METADATA_PARAMS(Z_Construct_UClass_AEnemy_Statics::NewProp_health_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Statics::NewProp_health_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemy_Statics::NewProp_target_MetaData[] = {
		{ "Category", "Target" },
		{ "ModuleRelativePath", "Enemy.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemy_Statics::NewProp_target = { "target", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemy, target), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AEnemy_Statics::NewProp_target_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Statics::NewProp_target_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemy_Statics::NewProp_RunningAnimation_MetaData[] = {
		{ "Category", "Animations" },
		{ "ModuleRelativePath", "Enemy.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemy_Statics::NewProp_RunningAnimation = { "RunningAnimation", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemy, RunningAnimation), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AEnemy_Statics::NewProp_RunningAnimation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Statics::NewProp_RunningAnimation_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemy_Statics::NewProp_IdleAnimation_MetaData[] = {
		{ "Category", "Animations" },
		{ "Comment", "// The animation to play while idle (standing still)\n" },
		{ "ModuleRelativePath", "Enemy.h" },
		{ "ToolTip", "The animation to play while idle (standing still)" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemy_Statics::NewProp_IdleAnimation = { "IdleAnimation", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemy, IdleAnimation), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AEnemy_Statics::NewProp_IdleAnimation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Statics::NewProp_IdleAnimation_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemy_Statics::NewProp_AttackAnimation_MetaData[] = {
		{ "Category", "Animations" },
		{ "ModuleRelativePath", "Enemy.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemy_Statics::NewProp_AttackAnimation = { "AttackAnimation", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemy, AttackAnimation), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AEnemy_Statics::NewProp_AttackAnimation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Statics::NewProp_AttackAnimation_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemy_Statics::NewProp_projectile_MetaData[] = {
		{ "Category", "Enemy" },
		{ "ModuleRelativePath", "Enemy.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AEnemy_Statics::NewProp_projectile = { "projectile", nullptr, (EPropertyFlags)0x0024080000000001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemy, projectile), Z_Construct_UClass_AProjectiles_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AEnemy_Statics::NewProp_projectile_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Statics::NewProp_projectile_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEnemy_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemy_Statics::NewProp_activeState_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemy_Statics::NewProp_activeState,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemy_Statics::NewProp_health,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemy_Statics::NewProp_target,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemy_Statics::NewProp_RunningAnimation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemy_Statics::NewProp_IdleAnimation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemy_Statics::NewProp_AttackAnimation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemy_Statics::NewProp_projectile,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEnemy_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEnemy>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AEnemy_Statics::ClassParams = {
		&AEnemy::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AEnemy_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AEnemy_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEnemy()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AEnemy_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEnemy, 1055913316);
	template<> PROJECTW_API UClass* StaticClass<AEnemy>()
	{
		return AEnemy::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEnemy(Z_Construct_UClass_AEnemy, &AEnemy::StaticClass, TEXT("/Script/ProjectW"), TEXT("AEnemy"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEnemy);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
