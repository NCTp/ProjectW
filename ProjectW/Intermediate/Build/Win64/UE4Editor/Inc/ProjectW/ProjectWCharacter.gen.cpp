// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectW/ProjectWCharacter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeProjectWCharacter() {}
// Cross Module References
	PROJECTW_API UEnum* Z_Construct_UEnum_ProjectW_ECharacterState();
	UPackage* Z_Construct_UPackage__Script_ProjectW();
	PROJECTW_API UClass* Z_Construct_UClass_AProjectWCharacter_NoRegister();
	PROJECTW_API UClass* Z_Construct_UClass_AProjectWCharacter();
	PAPER2D_API UClass* Z_Construct_UClass_APaperCharacter();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	PAPER2D_API UClass* Z_Construct_UClass_UPaperFlipbook_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	PROJECTW_API UClass* Z_Construct_UClass_AProjectile_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UArrowComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
// End Cross Module References
	static UEnum* ECharacterState_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_ProjectW_ECharacterState, Z_Construct_UPackage__Script_ProjectW(), TEXT("ECharacterState"));
		}
		return Singleton;
	}
	template<> PROJECTW_API UEnum* StaticEnum<ECharacterState>()
	{
		return ECharacterState_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ECharacterState(ECharacterState_StaticEnum, TEXT("/Script/ProjectW"), TEXT("ECharacterState"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_ProjectW_ECharacterState_Hash() { return 3612030155U; }
	UEnum* Z_Construct_UEnum_ProjectW_ECharacterState()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_ProjectW();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ECharacterState"), 0, Get_Z_Construct_UEnum_ProjectW_ECharacterState_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ECharacterState::Default", (int64)ECharacterState::Default },
				{ "ECharacterState::Idle", (int64)ECharacterState::Idle },
				{ "ECharacterState::Run", (int64)ECharacterState::Run },
				{ "ECharacterState::Jump", (int64)ECharacterState::Jump },
				{ "ECharacterState::Fall", (int64)ECharacterState::Fall },
				{ "ECharacterState::Roll", (int64)ECharacterState::Roll },
				{ "ECharacterState::Fire", (int64)ECharacterState::Fire },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "Default.DisplayName", "Default" },
				{ "Default.Name", "ECharacterState::Default" },
				{ "Fall.DisplayName", "Fall" },
				{ "Fall.Name", "ECharacterState::Fall" },
				{ "Fire.DisplayName", "Fire" },
				{ "Fire.Name", "ECharacterState::Fire" },
				{ "Idle.DisplayName", "Idle" },
				{ "Idle.Name", "ECharacterState::Idle" },
				{ "Jump.DisplayName", "Jump" },
				{ "Jump.Name", "ECharacterState::Jump" },
				{ "ModuleRelativePath", "ProjectWCharacter.h" },
				{ "Roll.DisplayName", "Roll" },
				{ "Roll.Name", "ECharacterState::Roll" },
				{ "Run.DisplayName", "Run" },
				{ "Run.Name", "ECharacterState::Run" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_ProjectW,
				nullptr,
				"ECharacterState",
				"ECharacterState",
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
	void AProjectWCharacter::StaticRegisterNativesAProjectWCharacter()
	{
	}
	UClass* Z_Construct_UClass_AProjectWCharacter_NoRegister()
	{
		return AProjectWCharacter::StaticClass();
	}
	struct Z_Construct_UClass_AProjectWCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SideViewCameraComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SideViewCameraComponent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CameraBoom_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CameraBoom;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RifleIdleAnimation_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_RifleIdleAnimation;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RifleRunningAnimation_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_RifleRunningAnimation;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RifleJumpingAnimation_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_RifleJumpingAnimation;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RifleFallingAnimation_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_RifleFallingAnimation;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RifleRollingAnimation_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_RifleRollingAnimation;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RifleFiringAnimation_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_RifleFiringAnimation;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ShotgunIdleAnimation_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ShotgunIdleAnimation;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ShotgunRunningAnimation_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ShotgunRunningAnimation;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ShotgunJumpingAnimation_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ShotgunJumpingAnimation;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ShotgunFallingAnimation_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ShotgunFallingAnimation;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ShotgunRollingAnimation_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ShotgunRollingAnimation;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ShotgunFiringAnimation_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ShotgunFiringAnimation;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_CharacterState_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CharacterState_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_CharacterState;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_bIsFiring_MetaData[];
#endif
		static void NewProp_m_bIsFiring_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_m_bIsFiring;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_bIsRolling_MetaData[];
#endif
		static void NewProp_m_bIsRolling_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_m_bIsRolling;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_fRollingCount_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_m_fRollingCount;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_uCurrentWeapon_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_m_uCurrentWeapon;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Projectile_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_Projectile;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FireSound_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_FireSound;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MuzzlePoint_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MuzzlePoint;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MuzzleLocation_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MuzzleLocation;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AProjectWCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APaperCharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_ProjectW,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProjectWCharacter_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * This class is the default character for ProjectW, and it is responsible for all\n * physical interaction between the player and the world.\n *\n * The capsule component (inherited from ACharacter) handles collision with the world\n * The CharacterMovementComponent (inherited from ACharacter) handles movement of the collision capsule\n * The Sprite component (inherited from APaperCharacter) handles the visuals\n */" },
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "ProjectWCharacter.h" },
		{ "ModuleRelativePath", "ProjectWCharacter.h" },
		{ "ToolTip", "This class is the default character for ProjectW, and it is responsible for all\nphysical interaction between the player and the world.\n\nThe capsule component (inherited from ACharacter) handles collision with the world\nThe CharacterMovementComponent (inherited from ACharacter) handles movement of the collision capsule\nThe Sprite component (inherited from APaperCharacter) handles the visuals" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_SideViewCameraComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "Comment", "/** Side view camera */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ProjectWCharacter.h" },
		{ "ToolTip", "Side view camera" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_SideViewCameraComponent = { "SideViewCameraComponent", nullptr, (EPropertyFlags)0x00400000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AProjectWCharacter, SideViewCameraComponent), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_SideViewCameraComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_SideViewCameraComponent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_CameraBoom_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "Comment", "/** Camera boom positioning the camera beside the character */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ProjectWCharacter.h" },
		{ "ToolTip", "Camera boom positioning the camera beside the character" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_CameraBoom = { "CameraBoom", nullptr, (EPropertyFlags)0x00400000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AProjectWCharacter, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_CameraBoom_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_CameraBoom_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_RifleIdleAnimation_MetaData[] = {
		{ "Category", "Animations" },
		{ "Comment", "// The animation to play while idle (standing still)\n" },
		{ "ModuleRelativePath", "ProjectWCharacter.h" },
		{ "ToolTip", "The animation to play while idle (standing still)" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_RifleIdleAnimation = { "RifleIdleAnimation", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AProjectWCharacter, RifleIdleAnimation), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_RifleIdleAnimation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_RifleIdleAnimation_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_RifleRunningAnimation_MetaData[] = {
		{ "Category", "Animations" },
		{ "Comment", "// The animation to play while running around\n" },
		{ "ModuleRelativePath", "ProjectWCharacter.h" },
		{ "ToolTip", "The animation to play while running around" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_RifleRunningAnimation = { "RifleRunningAnimation", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AProjectWCharacter, RifleRunningAnimation), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_RifleRunningAnimation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_RifleRunningAnimation_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_RifleJumpingAnimation_MetaData[] = {
		{ "Category", "Animations" },
		{ "Comment", "// The animation to play while jumping\n" },
		{ "ModuleRelativePath", "ProjectWCharacter.h" },
		{ "ToolTip", "The animation to play while jumping" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_RifleJumpingAnimation = { "RifleJumpingAnimation", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AProjectWCharacter, RifleJumpingAnimation), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_RifleJumpingAnimation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_RifleJumpingAnimation_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_RifleFallingAnimation_MetaData[] = {
		{ "Category", "Animations" },
		{ "Comment", "// The animation to play while Falling\n" },
		{ "ModuleRelativePath", "ProjectWCharacter.h" },
		{ "ToolTip", "The animation to play while Falling" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_RifleFallingAnimation = { "RifleFallingAnimation", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AProjectWCharacter, RifleFallingAnimation), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_RifleFallingAnimation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_RifleFallingAnimation_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_RifleRollingAnimation_MetaData[] = {
		{ "Category", "Animations" },
		{ "Comment", "// The animation to play while Rolling\n" },
		{ "ModuleRelativePath", "ProjectWCharacter.h" },
		{ "ToolTip", "The animation to play while Rolling" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_RifleRollingAnimation = { "RifleRollingAnimation", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AProjectWCharacter, RifleRollingAnimation), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_RifleRollingAnimation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_RifleRollingAnimation_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_RifleFiringAnimation_MetaData[] = {
		{ "Category", "Animations" },
		{ "Comment", "// The animation to play while Firing\n" },
		{ "ModuleRelativePath", "ProjectWCharacter.h" },
		{ "ToolTip", "The animation to play while Firing" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_RifleFiringAnimation = { "RifleFiringAnimation", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AProjectWCharacter, RifleFiringAnimation), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_RifleFiringAnimation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_RifleFiringAnimation_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_ShotgunIdleAnimation_MetaData[] = {
		{ "Category", "Animations" },
		{ "Comment", "// The animation to play while idle (standing still)\n" },
		{ "ModuleRelativePath", "ProjectWCharacter.h" },
		{ "ToolTip", "The animation to play while idle (standing still)" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_ShotgunIdleAnimation = { "ShotgunIdleAnimation", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AProjectWCharacter, ShotgunIdleAnimation), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_ShotgunIdleAnimation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_ShotgunIdleAnimation_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_ShotgunRunningAnimation_MetaData[] = {
		{ "Category", "Animations" },
		{ "Comment", "// The animation to play while running around\n" },
		{ "ModuleRelativePath", "ProjectWCharacter.h" },
		{ "ToolTip", "The animation to play while running around" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_ShotgunRunningAnimation = { "ShotgunRunningAnimation", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AProjectWCharacter, ShotgunRunningAnimation), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_ShotgunRunningAnimation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_ShotgunRunningAnimation_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_ShotgunJumpingAnimation_MetaData[] = {
		{ "Category", "Animations" },
		{ "Comment", "// The animation to play while jumping\n" },
		{ "ModuleRelativePath", "ProjectWCharacter.h" },
		{ "ToolTip", "The animation to play while jumping" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_ShotgunJumpingAnimation = { "ShotgunJumpingAnimation", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AProjectWCharacter, ShotgunJumpingAnimation), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_ShotgunJumpingAnimation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_ShotgunJumpingAnimation_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_ShotgunFallingAnimation_MetaData[] = {
		{ "Category", "Animations" },
		{ "Comment", "// The animation to play while Falling\n" },
		{ "ModuleRelativePath", "ProjectWCharacter.h" },
		{ "ToolTip", "The animation to play while Falling" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_ShotgunFallingAnimation = { "ShotgunFallingAnimation", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AProjectWCharacter, ShotgunFallingAnimation), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_ShotgunFallingAnimation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_ShotgunFallingAnimation_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_ShotgunRollingAnimation_MetaData[] = {
		{ "Category", "Animations" },
		{ "Comment", "// The animation to play while Rolling\n" },
		{ "ModuleRelativePath", "ProjectWCharacter.h" },
		{ "ToolTip", "The animation to play while Rolling" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_ShotgunRollingAnimation = { "ShotgunRollingAnimation", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AProjectWCharacter, ShotgunRollingAnimation), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_ShotgunRollingAnimation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_ShotgunRollingAnimation_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_ShotgunFiringAnimation_MetaData[] = {
		{ "Category", "Animations" },
		{ "Comment", "// The animation to play while Firing\n" },
		{ "ModuleRelativePath", "ProjectWCharacter.h" },
		{ "ToolTip", "The animation to play while Firing" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_ShotgunFiringAnimation = { "ShotgunFiringAnimation", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AProjectWCharacter, ShotgunFiringAnimation), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_ShotgunFiringAnimation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_ShotgunFiringAnimation_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_CharacterState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_CharacterState_MetaData[] = {
		{ "Category", "ProjectWCharacter" },
		{ "ModuleRelativePath", "ProjectWCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_CharacterState = { "CharacterState", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AProjectWCharacter, CharacterState), Z_Construct_UEnum_ProjectW_ECharacterState, METADATA_PARAMS(Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_CharacterState_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_CharacterState_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_m_bIsFiring_MetaData[] = {
		{ "Category", "IsFiring" },
		{ "ModuleRelativePath", "ProjectWCharacter.h" },
	};
#endif
	void Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_m_bIsFiring_SetBit(void* Obj)
	{
		((AProjectWCharacter*)Obj)->m_bIsFiring = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_m_bIsFiring = { "m_bIsFiring", nullptr, (EPropertyFlags)0x0020080000022015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AProjectWCharacter), &Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_m_bIsFiring_SetBit, METADATA_PARAMS(Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_m_bIsFiring_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_m_bIsFiring_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_m_bIsRolling_MetaData[] = {
		{ "Category", "IsRolling" },
		{ "ModuleRelativePath", "ProjectWCharacter.h" },
	};
#endif
	void Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_m_bIsRolling_SetBit(void* Obj)
	{
		((AProjectWCharacter*)Obj)->m_bIsRolling = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_m_bIsRolling = { "m_bIsRolling", nullptr, (EPropertyFlags)0x0020080000022015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AProjectWCharacter), &Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_m_bIsRolling_SetBit, METADATA_PARAMS(Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_m_bIsRolling_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_m_bIsRolling_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_m_fRollingCount_MetaData[] = {
		{ "Category", "IsRolling" },
		{ "ModuleRelativePath", "ProjectWCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_m_fRollingCount = { "m_fRollingCount", nullptr, (EPropertyFlags)0x0020080000022015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AProjectWCharacter, m_fRollingCount), METADATA_PARAMS(Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_m_fRollingCount_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_m_fRollingCount_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_m_uCurrentWeapon_MetaData[] = {
		{ "Category", "CurrentWeapon" },
		{ "Comment", "// Current Weapon Type\n// 0 : Rifle, 1 : Shotgun\n" },
		{ "ModuleRelativePath", "ProjectWCharacter.h" },
		{ "ToolTip", "Current Weapon Type\n0 : Rifle, 1 : Shotgun" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_m_uCurrentWeapon = { "m_uCurrentWeapon", nullptr, (EPropertyFlags)0x0020080000022015, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AProjectWCharacter, m_uCurrentWeapon), METADATA_PARAMS(Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_m_uCurrentWeapon_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_m_uCurrentWeapon_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_Projectile_MetaData[] = {
		{ "Category", "Projectile" },
		{ "ModuleRelativePath", "ProjectWCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_Projectile = { "Projectile", nullptr, (EPropertyFlags)0x0014000000010001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AProjectWCharacter, Projectile), Z_Construct_UClass_AProjectile_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_Projectile_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_Projectile_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_FireSound_MetaData[] = {
		{ "Category", "Gameplay" },
		{ "ModuleRelativePath", "ProjectWCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_FireSound = { "FireSound", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AProjectWCharacter, FireSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_FireSound_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_FireSound_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_MuzzlePoint_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "MuzzlePoint" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ProjectWCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_MuzzlePoint = { "MuzzlePoint", nullptr, (EPropertyFlags)0x001000000008000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AProjectWCharacter, MuzzlePoint), Z_Construct_UClass_UArrowComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_MuzzlePoint_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_MuzzlePoint_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_MuzzleLocation_MetaData[] = {
		{ "Category", "MuzzlePoint" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ProjectWCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_MuzzleLocation = { "MuzzleLocation", nullptr, (EPropertyFlags)0x001000000008000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AProjectWCharacter, MuzzleLocation), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_MuzzleLocation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_MuzzleLocation_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AProjectWCharacter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_SideViewCameraComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_CameraBoom,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_RifleIdleAnimation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_RifleRunningAnimation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_RifleJumpingAnimation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_RifleFallingAnimation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_RifleRollingAnimation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_RifleFiringAnimation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_ShotgunIdleAnimation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_ShotgunRunningAnimation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_ShotgunJumpingAnimation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_ShotgunFallingAnimation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_ShotgunRollingAnimation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_ShotgunFiringAnimation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_CharacterState_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_CharacterState,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_m_bIsFiring,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_m_bIsRolling,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_m_fRollingCount,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_m_uCurrentWeapon,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_Projectile,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_FireSound,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_MuzzlePoint,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProjectWCharacter_Statics::NewProp_MuzzleLocation,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AProjectWCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AProjectWCharacter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AProjectWCharacter_Statics::ClassParams = {
		&AProjectWCharacter::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AProjectWCharacter_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AProjectWCharacter_Statics::PropPointers),
		0,
		0x008000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AProjectWCharacter_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AProjectWCharacter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AProjectWCharacter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AProjectWCharacter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AProjectWCharacter, 2886237127);
	template<> PROJECTW_API UClass* StaticClass<AProjectWCharacter>()
	{
		return AProjectWCharacter::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AProjectWCharacter(Z_Construct_UClass_AProjectWCharacter, &AProjectWCharacter::StaticClass, TEXT("/Script/ProjectW"), TEXT("AProjectWCharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AProjectWCharacter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
