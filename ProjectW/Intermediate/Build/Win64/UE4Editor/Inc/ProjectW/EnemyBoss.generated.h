// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PROJECTW_EnemyBoss_generated_h
#error "EnemyBoss.generated.h already included, missing '#pragma once' in EnemyBoss.h"
#endif
#define PROJECTW_EnemyBoss_generated_h

#define ProjectW_Source_ProjectW_EnemyBoss_h_15_SPARSE_DATA
#define ProjectW_Source_ProjectW_EnemyBoss_h_15_RPC_WRAPPERS
#define ProjectW_Source_ProjectW_EnemyBoss_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define ProjectW_Source_ProjectW_EnemyBoss_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAEnemyBoss(); \
	friend struct Z_Construct_UClass_AEnemyBoss_Statics; \
public: \
	DECLARE_CLASS(AEnemyBoss, AEnemyBase, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectW"), NO_API) \
	DECLARE_SERIALIZER(AEnemyBoss)


#define ProjectW_Source_ProjectW_EnemyBoss_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAEnemyBoss(); \
	friend struct Z_Construct_UClass_AEnemyBoss_Statics; \
public: \
	DECLARE_CLASS(AEnemyBoss, AEnemyBase, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectW"), NO_API) \
	DECLARE_SERIALIZER(AEnemyBoss)


#define ProjectW_Source_ProjectW_EnemyBoss_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AEnemyBoss(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AEnemyBoss) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEnemyBoss); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEnemyBoss); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AEnemyBoss(AEnemyBoss&&); \
	NO_API AEnemyBoss(const AEnemyBoss&); \
public:


#define ProjectW_Source_ProjectW_EnemyBoss_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AEnemyBoss() { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AEnemyBoss(AEnemyBoss&&); \
	NO_API AEnemyBoss(const AEnemyBoss&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEnemyBoss); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEnemyBoss); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AEnemyBoss)


#define ProjectW_Source_ProjectW_EnemyBoss_h_15_PRIVATE_PROPERTY_OFFSET
#define ProjectW_Source_ProjectW_EnemyBoss_h_12_PROLOG
#define ProjectW_Source_ProjectW_EnemyBoss_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ProjectW_Source_ProjectW_EnemyBoss_h_15_PRIVATE_PROPERTY_OFFSET \
	ProjectW_Source_ProjectW_EnemyBoss_h_15_SPARSE_DATA \
	ProjectW_Source_ProjectW_EnemyBoss_h_15_RPC_WRAPPERS \
	ProjectW_Source_ProjectW_EnemyBoss_h_15_INCLASS \
	ProjectW_Source_ProjectW_EnemyBoss_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ProjectW_Source_ProjectW_EnemyBoss_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ProjectW_Source_ProjectW_EnemyBoss_h_15_PRIVATE_PROPERTY_OFFSET \
	ProjectW_Source_ProjectW_EnemyBoss_h_15_SPARSE_DATA \
	ProjectW_Source_ProjectW_EnemyBoss_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	ProjectW_Source_ProjectW_EnemyBoss_h_15_INCLASS_NO_PURE_DECLS \
	ProjectW_Source_ProjectW_EnemyBoss_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECTW_API UClass* StaticClass<class AEnemyBoss>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ProjectW_Source_ProjectW_EnemyBoss_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
