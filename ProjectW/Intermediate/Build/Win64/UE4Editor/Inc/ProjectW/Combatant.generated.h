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

#define ProjectW_Source_ProjectW_Combatant_h_12_SPARSE_DATA
#define ProjectW_Source_ProjectW_Combatant_h_12_RPC_WRAPPERS
#define ProjectW_Source_ProjectW_Combatant_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define ProjectW_Source_ProjectW_Combatant_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACombatant(); \
	friend struct Z_Construct_UClass_ACombatant_Statics; \
public: \
	DECLARE_CLASS(ACombatant, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectW"), NO_API) \
	DECLARE_SERIALIZER(ACombatant)


#define ProjectW_Source_ProjectW_Combatant_h_12_INCLASS \
private: \
	static void StaticRegisterNativesACombatant(); \
	friend struct Z_Construct_UClass_ACombatant_Statics; \
public: \
	DECLARE_CLASS(ACombatant, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectW"), NO_API) \
	DECLARE_SERIALIZER(ACombatant)


#define ProjectW_Source_ProjectW_Combatant_h_12_STANDARD_CONSTRUCTORS \
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


#define ProjectW_Source_ProjectW_Combatant_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACombatant(ACombatant&&); \
	NO_API ACombatant(const ACombatant&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACombatant); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACombatant); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACombatant)


#define ProjectW_Source_ProjectW_Combatant_h_12_PRIVATE_PROPERTY_OFFSET
#define ProjectW_Source_ProjectW_Combatant_h_9_PROLOG
#define ProjectW_Source_ProjectW_Combatant_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ProjectW_Source_ProjectW_Combatant_h_12_PRIVATE_PROPERTY_OFFSET \
	ProjectW_Source_ProjectW_Combatant_h_12_SPARSE_DATA \
	ProjectW_Source_ProjectW_Combatant_h_12_RPC_WRAPPERS \
	ProjectW_Source_ProjectW_Combatant_h_12_INCLASS \
	ProjectW_Source_ProjectW_Combatant_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ProjectW_Source_ProjectW_Combatant_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ProjectW_Source_ProjectW_Combatant_h_12_PRIVATE_PROPERTY_OFFSET \
	ProjectW_Source_ProjectW_Combatant_h_12_SPARSE_DATA \
	ProjectW_Source_ProjectW_Combatant_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	ProjectW_Source_ProjectW_Combatant_h_12_INCLASS_NO_PURE_DECLS \
	ProjectW_Source_ProjectW_Combatant_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECTW_API UClass* StaticClass<class ACombatant>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ProjectW_Source_ProjectW_Combatant_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
