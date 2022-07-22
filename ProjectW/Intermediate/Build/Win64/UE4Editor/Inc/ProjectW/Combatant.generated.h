// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PROJECTW_Combatant_generated_h
#error "Combatant.generated.h already included, missing '#pragma once' in Combatant.h"
#endif
#define PROJECTW_Combatant_generated_h

#define ProjectW_Source_ProjectW_Combatant_h_15_SPARSE_DATA
#define ProjectW_Source_ProjectW_Combatant_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetCurrentRotationSpeed); \
	DECLARE_FUNCTION(execAttackNextReady); \
	DECLARE_FUNCTION(execEndStumble); \
	DECLARE_FUNCTION(execSetMovingBackwards); \
	DECLARE_FUNCTION(execSetMovingForward); \
	DECLARE_FUNCTION(execSetAttackDamaging); \
	DECLARE_FUNCTION(execEndAttack); \
	DECLARE_FUNCTION(execAttackLunge);


#define ProjectW_Source_ProjectW_Combatant_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetCurrentRotationSpeed); \
	DECLARE_FUNCTION(execAttackNextReady); \
	DECLARE_FUNCTION(execEndStumble); \
	DECLARE_FUNCTION(execSetMovingBackwards); \
	DECLARE_FUNCTION(execSetMovingForward); \
	DECLARE_FUNCTION(execSetAttackDamaging); \
	DECLARE_FUNCTION(execEndAttack); \
	DECLARE_FUNCTION(execAttackLunge);


#define ProjectW_Source_ProjectW_Combatant_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACombatant(); \
	friend struct Z_Construct_UClass_ACombatant_Statics; \
public: \
	DECLARE_CLASS(ACombatant, APaperCharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectW"), NO_API) \
	DECLARE_SERIALIZER(ACombatant)


#define ProjectW_Source_ProjectW_Combatant_h_15_INCLASS \
private: \
	static void StaticRegisterNativesACombatant(); \
	friend struct Z_Construct_UClass_ACombatant_Statics; \
public: \
	DECLARE_CLASS(ACombatant, APaperCharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectW"), NO_API) \
	DECLARE_SERIALIZER(ACombatant)


#define ProjectW_Source_ProjectW_Combatant_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ACombatant(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ACombatant) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACombatant); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACombatant); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACombatant(ACombatant&&); \
	NO_API ACombatant(const ACombatant&); \
public:


#define ProjectW_Source_ProjectW_Combatant_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACombatant(ACombatant&&); \
	NO_API ACombatant(const ACombatant&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACombatant); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACombatant); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACombatant)


#define ProjectW_Source_ProjectW_Combatant_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__TargetLocked() { return STRUCT_OFFSET(ACombatant, TargetLocked); } \
	FORCEINLINE static uint32 __PPO__RotationSmoothing() { return STRUCT_OFFSET(ACombatant, RotationSmoothing); } \
	FORCEINLINE static uint32 __PPO__AttackAnimations() { return STRUCT_OFFSET(ACombatant, AttackAnimations); } \
	FORCEINLINE static uint32 __PPO__TakeHit_StumbleBackwards() { return STRUCT_OFFSET(ACombatant, TakeHit_StumbleBackwards); }


#define ProjectW_Source_ProjectW_Combatant_h_12_PROLOG
#define ProjectW_Source_ProjectW_Combatant_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ProjectW_Source_ProjectW_Combatant_h_15_PRIVATE_PROPERTY_OFFSET \
	ProjectW_Source_ProjectW_Combatant_h_15_SPARSE_DATA \
	ProjectW_Source_ProjectW_Combatant_h_15_RPC_WRAPPERS \
	ProjectW_Source_ProjectW_Combatant_h_15_INCLASS \
	ProjectW_Source_ProjectW_Combatant_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ProjectW_Source_ProjectW_Combatant_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ProjectW_Source_ProjectW_Combatant_h_15_PRIVATE_PROPERTY_OFFSET \
	ProjectW_Source_ProjectW_Combatant_h_15_SPARSE_DATA \
	ProjectW_Source_ProjectW_Combatant_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	ProjectW_Source_ProjectW_Combatant_h_15_INCLASS_NO_PURE_DECLS \
	ProjectW_Source_ProjectW_Combatant_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECTW_API UClass* StaticClass<class ACombatant>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ProjectW_Source_ProjectW_Combatant_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
