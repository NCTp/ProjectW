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
#ifdef PROJECTW_ProjectWCharacter_generated_h
#error "ProjectWCharacter.generated.h already included, missing '#pragma once' in ProjectWCharacter.h"
#endif
#define PROJECTW_ProjectWCharacter_generated_h

#define ProjectW_Source_ProjectW_ProjectWCharacter_h_23_SPARSE_DATA
#define ProjectW_Source_ProjectW_ProjectWCharacter_h_23_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnOverlapBegin);


#define ProjectW_Source_ProjectW_ProjectWCharacter_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnOverlapBegin);


#define ProjectW_Source_ProjectW_ProjectWCharacter_h_23_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAProjectWCharacter(); \
	friend struct Z_Construct_UClass_AProjectWCharacter_Statics; \
public: \
	DECLARE_CLASS(AProjectWCharacter, APaperCharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectW"), NO_API) \
	DECLARE_SERIALIZER(AProjectWCharacter)


#define ProjectW_Source_ProjectW_ProjectWCharacter_h_23_INCLASS \
private: \
	static void StaticRegisterNativesAProjectWCharacter(); \
	friend struct Z_Construct_UClass_AProjectWCharacter_Statics; \
public: \
	DECLARE_CLASS(AProjectWCharacter, APaperCharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectW"), NO_API) \
	DECLARE_SERIALIZER(AProjectWCharacter)


#define ProjectW_Source_ProjectW_ProjectWCharacter_h_23_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AProjectWCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AProjectWCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AProjectWCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProjectWCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AProjectWCharacter(AProjectWCharacter&&); \
	NO_API AProjectWCharacter(const AProjectWCharacter&); \
public:


#define ProjectW_Source_ProjectW_ProjectWCharacter_h_23_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AProjectWCharacter(AProjectWCharacter&&); \
	NO_API AProjectWCharacter(const AProjectWCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AProjectWCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProjectWCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AProjectWCharacter)


#define ProjectW_Source_ProjectW_ProjectWCharacter_h_23_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__SideViewCameraComponent() { return STRUCT_OFFSET(AProjectWCharacter, SideViewCameraComponent); } \
	FORCEINLINE static uint32 __PPO__CameraBoom() { return STRUCT_OFFSET(AProjectWCharacter, CameraBoom); } \
	FORCEINLINE static uint32 __PPO__RunningAnimation() { return STRUCT_OFFSET(AProjectWCharacter, RunningAnimation); } \
	FORCEINLINE static uint32 __PPO__IdleAnimation() { return STRUCT_OFFSET(AProjectWCharacter, IdleAnimation); } \
	FORCEINLINE static uint32 __PPO__AttackAnimation() { return STRUCT_OFFSET(AProjectWCharacter, AttackAnimation); } \
	FORCEINLINE static uint32 __PPO__spawnBox() { return STRUCT_OFFSET(AProjectWCharacter, spawnBox); } \
	FORCEINLINE static uint32 __PPO__attackEffects() { return STRUCT_OFFSET(AProjectWCharacter, attackEffects); } \
	FORCEINLINE static uint32 __PPO__health() { return STRUCT_OFFSET(AProjectWCharacter, health); }


#define ProjectW_Source_ProjectW_ProjectWCharacter_h_20_PROLOG
#define ProjectW_Source_ProjectW_ProjectWCharacter_h_23_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ProjectW_Source_ProjectW_ProjectWCharacter_h_23_PRIVATE_PROPERTY_OFFSET \
	ProjectW_Source_ProjectW_ProjectWCharacter_h_23_SPARSE_DATA \
	ProjectW_Source_ProjectW_ProjectWCharacter_h_23_RPC_WRAPPERS \
	ProjectW_Source_ProjectW_ProjectWCharacter_h_23_INCLASS \
	ProjectW_Source_ProjectW_ProjectWCharacter_h_23_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ProjectW_Source_ProjectW_ProjectWCharacter_h_23_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ProjectW_Source_ProjectW_ProjectWCharacter_h_23_PRIVATE_PROPERTY_OFFSET \
	ProjectW_Source_ProjectW_ProjectWCharacter_h_23_SPARSE_DATA \
	ProjectW_Source_ProjectW_ProjectWCharacter_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	ProjectW_Source_ProjectW_ProjectWCharacter_h_23_INCLASS_NO_PURE_DECLS \
	ProjectW_Source_ProjectW_ProjectWCharacter_h_23_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECTW_API UClass* StaticClass<class AProjectWCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ProjectW_Source_ProjectW_ProjectWCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
