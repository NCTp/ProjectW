// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FHitResult;
#ifdef PROJECTW_Enemy_generated_h
#error "Enemy.generated.h already included, missing '#pragma once' in Enemy.h"
#endif
#define PROJECTW_Enemy_generated_h

#define ProjectW_Source_ProjectW_Enemy_h_34_SPARSE_DATA
#define ProjectW_Source_ProjectW_Enemy_h_34_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnOverlapBegin);


#define ProjectW_Source_ProjectW_Enemy_h_34_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnOverlapBegin);


#define ProjectW_Source_ProjectW_Enemy_h_34_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAEnemy(); \
	friend struct Z_Construct_UClass_AEnemy_Statics; \
public: \
	DECLARE_CLASS(AEnemy, APaperCharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectW"), NO_API) \
	DECLARE_SERIALIZER(AEnemy)


#define ProjectW_Source_ProjectW_Enemy_h_34_INCLASS \
private: \
	static void StaticRegisterNativesAEnemy(); \
	friend struct Z_Construct_UClass_AEnemy_Statics; \
public: \
	DECLARE_CLASS(AEnemy, APaperCharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectW"), NO_API) \
	DECLARE_SERIALIZER(AEnemy)


#define ProjectW_Source_ProjectW_Enemy_h_34_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AEnemy(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AEnemy) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEnemy); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEnemy); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AEnemy(AEnemy&&); \
	NO_API AEnemy(const AEnemy&); \
public:


#define ProjectW_Source_ProjectW_Enemy_h_34_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AEnemy(AEnemy&&); \
	NO_API AEnemy(const AEnemy&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEnemy); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEnemy); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AEnemy)


#define ProjectW_Source_ProjectW_Enemy_h_34_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__RunningAnimation() { return STRUCT_OFFSET(AEnemy, RunningAnimation); } \
	FORCEINLINE static uint32 __PPO__IdleAnimation() { return STRUCT_OFFSET(AEnemy, IdleAnimation); } \
	FORCEINLINE static uint32 __PPO__AttackAnimation() { return STRUCT_OFFSET(AEnemy, AttackAnimation); } \
	FORCEINLINE static uint32 __PPO__projectile() { return STRUCT_OFFSET(AEnemy, projectile); }


#define ProjectW_Source_ProjectW_Enemy_h_31_PROLOG
#define ProjectW_Source_ProjectW_Enemy_h_34_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ProjectW_Source_ProjectW_Enemy_h_34_PRIVATE_PROPERTY_OFFSET \
	ProjectW_Source_ProjectW_Enemy_h_34_SPARSE_DATA \
	ProjectW_Source_ProjectW_Enemy_h_34_RPC_WRAPPERS \
	ProjectW_Source_ProjectW_Enemy_h_34_INCLASS \
	ProjectW_Source_ProjectW_Enemy_h_34_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ProjectW_Source_ProjectW_Enemy_h_34_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ProjectW_Source_ProjectW_Enemy_h_34_PRIVATE_PROPERTY_OFFSET \
	ProjectW_Source_ProjectW_Enemy_h_34_SPARSE_DATA \
	ProjectW_Source_ProjectW_Enemy_h_34_RPC_WRAPPERS_NO_PURE_DECLS \
	ProjectW_Source_ProjectW_Enemy_h_34_INCLASS_NO_PURE_DECLS \
	ProjectW_Source_ProjectW_Enemy_h_34_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECTW_API UClass* StaticClass<class AEnemy>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ProjectW_Source_ProjectW_Enemy_h


#define FOREACH_ENUM_STATE(op) \
	op(State::IDLE) \
	op(State::CLOSE) \
	op(State::FAR) \
	op(State::MELEE_ATTACK_01) \
	op(State::MELEE_ATTACK_02) \
	op(State::RANGE_ATTACK_01) \
	op(State::RANGE_ATTACK_02) \
	op(State::AREA_ATTACK_01) \
	op(State::AREA_ATTACK_02) \
	op(State::TELEPORT) \
	op(State::GIMMICK) \
	op(State::DEAD) 

enum class State : uint8;
template<> PROJECTW_API UEnum* StaticEnum<State>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
