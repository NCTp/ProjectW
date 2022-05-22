// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PROJECTW_Projectiles_generated_h
#error "Projectiles.generated.h already included, missing '#pragma once' in Projectiles.h"
#endif
#define PROJECTW_Projectiles_generated_h

#define ProjectW_Source_ProjectW_Projectiles_h_12_SPARSE_DATA
#define ProjectW_Source_ProjectW_Projectiles_h_12_RPC_WRAPPERS
#define ProjectW_Source_ProjectW_Projectiles_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define ProjectW_Source_ProjectW_Projectiles_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAProjectiles(); \
	friend struct Z_Construct_UClass_AProjectiles_Statics; \
public: \
	DECLARE_CLASS(AProjectiles, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectW"), NO_API) \
	DECLARE_SERIALIZER(AProjectiles)


#define ProjectW_Source_ProjectW_Projectiles_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAProjectiles(); \
	friend struct Z_Construct_UClass_AProjectiles_Statics; \
public: \
	DECLARE_CLASS(AProjectiles, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectW"), NO_API) \
	DECLARE_SERIALIZER(AProjectiles)


#define ProjectW_Source_ProjectW_Projectiles_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AProjectiles(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AProjectiles) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AProjectiles); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProjectiles); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AProjectiles(AProjectiles&&); \
	NO_API AProjectiles(const AProjectiles&); \
public:


#define ProjectW_Source_ProjectW_Projectiles_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AProjectiles(AProjectiles&&); \
	NO_API AProjectiles(const AProjectiles&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AProjectiles); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProjectiles); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AProjectiles)


#define ProjectW_Source_ProjectW_Projectiles_h_12_PRIVATE_PROPERTY_OFFSET
#define ProjectW_Source_ProjectW_Projectiles_h_9_PROLOG
#define ProjectW_Source_ProjectW_Projectiles_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ProjectW_Source_ProjectW_Projectiles_h_12_PRIVATE_PROPERTY_OFFSET \
	ProjectW_Source_ProjectW_Projectiles_h_12_SPARSE_DATA \
	ProjectW_Source_ProjectW_Projectiles_h_12_RPC_WRAPPERS \
	ProjectW_Source_ProjectW_Projectiles_h_12_INCLASS \
	ProjectW_Source_ProjectW_Projectiles_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ProjectW_Source_ProjectW_Projectiles_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ProjectW_Source_ProjectW_Projectiles_h_12_PRIVATE_PROPERTY_OFFSET \
	ProjectW_Source_ProjectW_Projectiles_h_12_SPARSE_DATA \
	ProjectW_Source_ProjectW_Projectiles_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	ProjectW_Source_ProjectW_Projectiles_h_12_INCLASS_NO_PURE_DECLS \
	ProjectW_Source_ProjectW_Projectiles_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECTW_API UClass* StaticClass<class AProjectiles>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ProjectW_Source_ProjectW_Projectiles_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
