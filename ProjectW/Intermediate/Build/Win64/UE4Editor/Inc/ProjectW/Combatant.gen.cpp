// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectW/Combatant.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCombatant() {}
// Cross Module References
	PROJECTW_API UClass* Z_Construct_UClass_ACombatant_NoRegister();
	PROJECTW_API UClass* Z_Construct_UClass_ACombatant();
	PAPER2D_API UClass* Z_Construct_UClass_APaperCharacter();
	UPackage* Z_Construct_UPackage__Script_ProjectW();
	PAPER2D_API UClass* Z_Construct_UClass_UPaperFlipbook_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(ACombatant::execGetCurrentRotationSpeed)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetCurrentRotationSpeed();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ACombatant::execAttackNextReady)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AttackNextReady();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ACombatant::execEndStumble)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->EndStumble();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ACombatant::execSetMovingBackwards)
	{
		P_GET_UBOOL(Z_Param_IsMovingBackwards);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetMovingBackwards(Z_Param_IsMovingBackwards);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ACombatant::execSetMovingForward)
	{
		P_GET_UBOOL(Z_Param_IsMovingForward);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetMovingForward(Z_Param_IsMovingForward);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ACombatant::execSetAttackDamaging)
	{
		P_GET_UBOOL(Z_Param_Damaging);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetAttackDamaging(Z_Param_Damaging);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ACombatant::execEndAttack)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->EndAttack();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ACombatant::execAttackLunge)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AttackLunge();
		P_NATIVE_END;
	}
	void ACombatant::StaticRegisterNativesACombatant()
	{
		UClass* Class = ACombatant::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AttackLunge", &ACombatant::execAttackLunge },
			{ "AttackNextReady", &ACombatant::execAttackNextReady },
			{ "EndAttack", &ACombatant::execEndAttack },
			{ "EndStumble", &ACombatant::execEndStumble },
			{ "GetCurrentRotationSpeed", &ACombatant::execGetCurrentRotationSpeed },
			{ "SetAttackDamaging", &ACombatant::execSetAttackDamaging },
			{ "SetMovingBackwards", &ACombatant::execSetMovingBackwards },
			{ "SetMovingForward", &ACombatant::execSetMovingForward },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ACombatant_AttackLunge_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ACombatant_AttackLunge_Statics::Function_MetaDataParams[] = {
		{ "Category", "Combat" },
		{ "Comment", "// anim called: rotate and jump towards target\n" },
		{ "ModuleRelativePath", "Combatant.h" },
		{ "ToolTip", "anim called: rotate and jump towards target" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ACombatant_AttackLunge_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACombatant, nullptr, "AttackLunge", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ACombatant_AttackLunge_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ACombatant_AttackLunge_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ACombatant_AttackLunge()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ACombatant_AttackLunge_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ACombatant_AttackNextReady_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ACombatant_AttackNextReady_Statics::Function_MetaDataParams[] = {
		{ "Category", "Combat" },
		{ "Comment", "// called by anim to singlat that the next attack is potentially allowed\n" },
		{ "ModuleRelativePath", "Combatant.h" },
		{ "ToolTip", "called by anim to singlat that the next attack is potentially allowed" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ACombatant_AttackNextReady_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACombatant, nullptr, "AttackNextReady", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ACombatant_AttackNextReady_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ACombatant_AttackNextReady_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ACombatant_AttackNextReady()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ACombatant_AttackNextReady_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ACombatant_EndAttack_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ACombatant_EndAttack_Statics::Function_MetaDataParams[] = {
		{ "Category", "Combat" },
		{ "Comment", "// anim called: rotate and jump towards target\n" },
		{ "ModuleRelativePath", "Combatant.h" },
		{ "ToolTip", "anim called: rotate and jump towards target" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ACombatant_EndAttack_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACombatant, nullptr, "EndAttack", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ACombatant_EndAttack_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ACombatant_EndAttack_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ACombatant_EndAttack()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ACombatant_EndAttack_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ACombatant_EndStumble_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ACombatant_EndStumble_Statics::Function_MetaDataParams[] = {
		{ "Category", "Animation" },
		{ "Comment", "// anim called: set if moving backwards\n" },
		{ "ModuleRelativePath", "Combatant.h" },
		{ "ToolTip", "anim called: set if moving backwards" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ACombatant_EndStumble_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACombatant, nullptr, "EndStumble", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ACombatant_EndStumble_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ACombatant_EndStumble_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ACombatant_EndStumble()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ACombatant_EndStumble_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ACombatant_GetCurrentRotationSpeed_Statics
	{
		struct Combatant_eventGetCurrentRotationSpeed_Parms
		{
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ACombatant_GetCurrentRotationSpeed_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Combatant_eventGetCurrentRotationSpeed_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACombatant_GetCurrentRotationSpeed_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACombatant_GetCurrentRotationSpeed_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ACombatant_GetCurrentRotationSpeed_Statics::Function_MetaDataParams[] = {
		{ "Category", "Animation" },
		{ "Comment", "// anim called: get rate of actors look rotation\n" },
		{ "ModuleRelativePath", "Combatant.h" },
		{ "ToolTip", "anim called: get rate of actors look rotation" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ACombatant_GetCurrentRotationSpeed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACombatant, nullptr, "GetCurrentRotationSpeed", nullptr, nullptr, sizeof(Combatant_eventGetCurrentRotationSpeed_Parms), Z_Construct_UFunction_ACombatant_GetCurrentRotationSpeed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACombatant_GetCurrentRotationSpeed_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ACombatant_GetCurrentRotationSpeed_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ACombatant_GetCurrentRotationSpeed_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ACombatant_GetCurrentRotationSpeed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ACombatant_GetCurrentRotationSpeed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ACombatant_SetAttackDamaging_Statics
	{
		struct Combatant_eventSetAttackDamaging_Parms
		{
			bool Damaging;
		};
		static void NewProp_Damaging_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_Damaging;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ACombatant_SetAttackDamaging_Statics::NewProp_Damaging_SetBit(void* Obj)
	{
		((Combatant_eventSetAttackDamaging_Parms*)Obj)->Damaging = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ACombatant_SetAttackDamaging_Statics::NewProp_Damaging = { "Damaging", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(Combatant_eventSetAttackDamaging_Parms), &Z_Construct_UFunction_ACombatant_SetAttackDamaging_Statics::NewProp_Damaging_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACombatant_SetAttackDamaging_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACombatant_SetAttackDamaging_Statics::NewProp_Damaging,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ACombatant_SetAttackDamaging_Statics::Function_MetaDataParams[] = {
		{ "Category", "Combat" },
		{ "Comment", "// set if weapon applies damage\n" },
		{ "ModuleRelativePath", "Combatant.h" },
		{ "ToolTip", "set if weapon applies damage" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ACombatant_SetAttackDamaging_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACombatant, nullptr, "SetAttackDamaging", nullptr, nullptr, sizeof(Combatant_eventSetAttackDamaging_Parms), Z_Construct_UFunction_ACombatant_SetAttackDamaging_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACombatant_SetAttackDamaging_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ACombatant_SetAttackDamaging_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ACombatant_SetAttackDamaging_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ACombatant_SetAttackDamaging()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ACombatant_SetAttackDamaging_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ACombatant_SetMovingBackwards_Statics
	{
		struct Combatant_eventSetMovingBackwards_Parms
		{
			bool IsMovingBackwards;
		};
		static void NewProp_IsMovingBackwards_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsMovingBackwards;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ACombatant_SetMovingBackwards_Statics::NewProp_IsMovingBackwards_SetBit(void* Obj)
	{
		((Combatant_eventSetMovingBackwards_Parms*)Obj)->IsMovingBackwards = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ACombatant_SetMovingBackwards_Statics::NewProp_IsMovingBackwards = { "IsMovingBackwards", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(Combatant_eventSetMovingBackwards_Parms), &Z_Construct_UFunction_ACombatant_SetMovingBackwards_Statics::NewProp_IsMovingBackwards_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACombatant_SetMovingBackwards_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACombatant_SetMovingBackwards_Statics::NewProp_IsMovingBackwards,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ACombatant_SetMovingBackwards_Statics::Function_MetaDataParams[] = {
		{ "Category", "Animation" },
		{ "Comment", "// anim called: set if moving backwards\n" },
		{ "ModuleRelativePath", "Combatant.h" },
		{ "ToolTip", "anim called: set if moving backwards" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ACombatant_SetMovingBackwards_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACombatant, nullptr, "SetMovingBackwards", nullptr, nullptr, sizeof(Combatant_eventSetMovingBackwards_Parms), Z_Construct_UFunction_ACombatant_SetMovingBackwards_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACombatant_SetMovingBackwards_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ACombatant_SetMovingBackwards_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ACombatant_SetMovingBackwards_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ACombatant_SetMovingBackwards()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ACombatant_SetMovingBackwards_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ACombatant_SetMovingForward_Statics
	{
		struct Combatant_eventSetMovingForward_Parms
		{
			bool IsMovingForward;
		};
		static void NewProp_IsMovingForward_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsMovingForward;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ACombatant_SetMovingForward_Statics::NewProp_IsMovingForward_SetBit(void* Obj)
	{
		((Combatant_eventSetMovingForward_Parms*)Obj)->IsMovingForward = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ACombatant_SetMovingForward_Statics::NewProp_IsMovingForward = { "IsMovingForward", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(Combatant_eventSetMovingForward_Parms), &Z_Construct_UFunction_ACombatant_SetMovingForward_Statics::NewProp_IsMovingForward_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACombatant_SetMovingForward_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACombatant_SetMovingForward_Statics::NewProp_IsMovingForward,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ACombatant_SetMovingForward_Statics::Function_MetaDataParams[] = {
		{ "Category", "Animation" },
		{ "Comment", "// anim called: set if moving forward\n" },
		{ "ModuleRelativePath", "Combatant.h" },
		{ "ToolTip", "anim called: set if moving forward" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ACombatant_SetMovingForward_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACombatant, nullptr, "SetMovingForward", nullptr, nullptr, sizeof(Combatant_eventSetMovingForward_Parms), Z_Construct_UFunction_ACombatant_SetMovingForward_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACombatant_SetMovingForward_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ACombatant_SetMovingForward_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ACombatant_SetMovingForward_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ACombatant_SetMovingForward()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ACombatant_SetMovingForward_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ACombatant_NoRegister()
	{
		return ACombatant::StaticClass();
	}
	struct Z_Construct_UClass_ACombatant_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TargetLocked_MetaData[];
#endif
		static void NewProp_TargetLocked_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_TargetLocked;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RotationSmoothing_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_RotationSmoothing;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AttackAnimations_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_AttackAnimations;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TakeHit_StumbleBackwards_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_TakeHit_StumbleBackwards;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACombatant_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APaperCharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_ProjectW,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ACombatant_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ACombatant_AttackLunge, "AttackLunge" }, // 2282663159
		{ &Z_Construct_UFunction_ACombatant_AttackNextReady, "AttackNextReady" }, // 4123468348
		{ &Z_Construct_UFunction_ACombatant_EndAttack, "EndAttack" }, // 603436956
		{ &Z_Construct_UFunction_ACombatant_EndStumble, "EndStumble" }, // 3916816412
		{ &Z_Construct_UFunction_ACombatant_GetCurrentRotationSpeed, "GetCurrentRotationSpeed" }, // 1204113458
		{ &Z_Construct_UFunction_ACombatant_SetAttackDamaging, "SetAttackDamaging" }, // 2293853317
		{ &Z_Construct_UFunction_ACombatant_SetMovingBackwards, "SetMovingBackwards" }, // 1795255442
		{ &Z_Construct_UFunction_ACombatant_SetMovingForward, "SetMovingForward" }, // 1003867646
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACombatant_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Combatant.h" },
		{ "ModuleRelativePath", "Combatant.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACombatant_Statics::NewProp_TargetLocked_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Combatant.h" },
	};
#endif
	void Z_Construct_UClass_ACombatant_Statics::NewProp_TargetLocked_SetBit(void* Obj)
	{
		((ACombatant*)Obj)->TargetLocked = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ACombatant_Statics::NewProp_TargetLocked = { "TargetLocked", nullptr, (EPropertyFlags)0x0020080000020015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ACombatant), &Z_Construct_UClass_ACombatant_Statics::NewProp_TargetLocked_SetBit, METADATA_PARAMS(Z_Construct_UClass_ACombatant_Statics::NewProp_TargetLocked_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACombatant_Statics::NewProp_TargetLocked_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACombatant_Statics::NewProp_RotationSmoothing_MetaData[] = {
		{ "Category", "Animation" },
		{ "ModuleRelativePath", "Combatant.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACombatant_Statics::NewProp_RotationSmoothing = { "RotationSmoothing", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACombatant, RotationSmoothing), METADATA_PARAMS(Z_Construct_UClass_ACombatant_Statics::NewProp_RotationSmoothing_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACombatant_Statics::NewProp_RotationSmoothing_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACombatant_Statics::NewProp_AttackAnimations_MetaData[] = {
		{ "Category", "Animations" },
		{ "ModuleRelativePath", "Combatant.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACombatant_Statics::NewProp_AttackAnimations = { "AttackAnimations", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACombatant, AttackAnimations), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACombatant_Statics::NewProp_AttackAnimations_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACombatant_Statics::NewProp_AttackAnimations_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACombatant_Statics::NewProp_TakeHit_StumbleBackwards_MetaData[] = {
		{ "Category", "Animations" },
		{ "ModuleRelativePath", "Combatant.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACombatant_Statics::NewProp_TakeHit_StumbleBackwards = { "TakeHit_StumbleBackwards", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACombatant, TakeHit_StumbleBackwards), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACombatant_Statics::NewProp_TakeHit_StumbleBackwards_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACombatant_Statics::NewProp_TakeHit_StumbleBackwards_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACombatant_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACombatant_Statics::NewProp_TargetLocked,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACombatant_Statics::NewProp_RotationSmoothing,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACombatant_Statics::NewProp_AttackAnimations,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACombatant_Statics::NewProp_TakeHit_StumbleBackwards,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACombatant_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACombatant>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ACombatant_Statics::ClassParams = {
		&ACombatant::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ACombatant_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ACombatant_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ACombatant_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ACombatant_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACombatant()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ACombatant_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ACombatant, 1997160350);
	template<> PROJECTW_API UClass* StaticClass<ACombatant>()
	{
		return ACombatant::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACombatant(Z_Construct_UClass_ACombatant, &ACombatant::StaticClass, TEXT("/Script/ProjectW"), TEXT("ACombatant"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACombatant);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
