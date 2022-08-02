// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PROJECTW_testwitch_generated_h
#error "testwitch.generated.h already included, missing '#pragma once' in testwitch.h"
#endif
#define PROJECTW_testwitch_generated_h

#define ProjectW_Source_ProjectW_testwitch_h_36_SPARSE_DATA
#define ProjectW_Source_ProjectW_testwitch_h_36_RPC_WRAPPERS
#define ProjectW_Source_ProjectW_testwitch_h_36_RPC_WRAPPERS_NO_PURE_DECLS
#define ProjectW_Source_ProjectW_testwitch_h_36_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAtestwitch(); \
	friend struct Z_Construct_UClass_Atestwitch_Statics; \
public: \
	DECLARE_CLASS(Atestwitch, APaperCharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectW"), NO_API) \
	DECLARE_SERIALIZER(Atestwitch)


#define ProjectW_Source_ProjectW_testwitch_h_36_INCLASS \
private: \
	static void StaticRegisterNativesAtestwitch(); \
	friend struct Z_Construct_UClass_Atestwitch_Statics; \
public: \
	DECLARE_CLASS(Atestwitch, APaperCharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectW"), NO_API) \
	DECLARE_SERIALIZER(Atestwitch)


#define ProjectW_Source_ProjectW_testwitch_h_36_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API Atestwitch(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(Atestwitch) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, Atestwitch); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(Atestwitch); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API Atestwitch(Atestwitch&&); \
	NO_API Atestwitch(const Atestwitch&); \
public:


#define ProjectW_Source_ProjectW_testwitch_h_36_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API Atestwitch(Atestwitch&&); \
	NO_API Atestwitch(const Atestwitch&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, Atestwitch); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(Atestwitch); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(Atestwitch)


#define ProjectW_Source_ProjectW_testwitch_h_36_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__ActiveState() { return STRUCT_OFFSET(Atestwitch, ActiveState); } \
	FORCEINLINE static uint32 __PPO__Spell() { return STRUCT_OFFSET(Atestwitch, Spell); } \
	FORCEINLINE static uint32 __PPO__AIController() { return STRUCT_OFFSET(Atestwitch, AIController); }


#define ProjectW_Source_ProjectW_testwitch_h_33_PROLOG
#define ProjectW_Source_ProjectW_testwitch_h_36_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ProjectW_Source_ProjectW_testwitch_h_36_PRIVATE_PROPERTY_OFFSET \
	ProjectW_Source_ProjectW_testwitch_h_36_SPARSE_DATA \
	ProjectW_Source_ProjectW_testwitch_h_36_RPC_WRAPPERS \
	ProjectW_Source_ProjectW_testwitch_h_36_INCLASS \
	ProjectW_Source_ProjectW_testwitch_h_36_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ProjectW_Source_ProjectW_testwitch_h_36_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ProjectW_Source_ProjectW_testwitch_h_36_PRIVATE_PROPERTY_OFFSET \
	ProjectW_Source_ProjectW_testwitch_h_36_SPARSE_DATA \
	ProjectW_Source_ProjectW_testwitch_h_36_RPC_WRAPPERS_NO_PURE_DECLS \
	ProjectW_Source_ProjectW_testwitch_h_36_INCLASS_NO_PURE_DECLS \
	ProjectW_Source_ProjectW_testwitch_h_36_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECTW_API UClass* StaticClass<class Atestwitch>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ProjectW_Source_ProjectW_testwitch_h


#define FOREACH_ENUM_ESPELL(op) \
	op(ESpell::DEFAULT) \
	op(ESpell::CHAIN) \
	op(ESpell::LASER) \
	op(ESpell::SUMMON_GHOUL) \
	op(ESpell::SUMMON_JORMUNGAND) \
	op(ESpell::HEXAGRAM) 

enum class ESpell : uint8;
template<> PROJECTW_API UEnum* StaticEnum<ESpell>();

#define FOREACH_ENUM_ETESTSTATE(op) \
	op(ETestState::DEFAULT) \
	op(ETestState::IDLE) \
	op(ETestState::RUNAWAY) \
	op(ETestState::TELEPORT) \
	op(ETestState::ATTACK) \
	op(ETestState::STUMBLE) \
	op(ETestState::TAUNT) \
	op(ETestState::DEAD) 

enum class ETestState : uint8;
template<> PROJECTW_API UEnum* StaticEnum<ETestState>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
