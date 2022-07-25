// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PROJECTW_StarWitch_generated_h
#error "StarWitch.generated.h already included, missing '#pragma once' in StarWitch.h"
#endif
#define PROJECTW_StarWitch_generated_h

#define ProjectW_Source_ProjectW_StarWitch_h_25_SPARSE_DATA
#define ProjectW_Source_ProjectW_StarWitch_h_25_RPC_WRAPPERS
#define ProjectW_Source_ProjectW_StarWitch_h_25_RPC_WRAPPERS_NO_PURE_DECLS
#define ProjectW_Source_ProjectW_StarWitch_h_25_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAStarWitch(); \
	friend struct Z_Construct_UClass_AStarWitch_Statics; \
public: \
	DECLARE_CLASS(AStarWitch, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectW"), NO_API) \
	DECLARE_SERIALIZER(AStarWitch)


#define ProjectW_Source_ProjectW_StarWitch_h_25_INCLASS \
private: \
	static void StaticRegisterNativesAStarWitch(); \
	friend struct Z_Construct_UClass_AStarWitch_Statics; \
public: \
	DECLARE_CLASS(AStarWitch, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectW"), NO_API) \
	DECLARE_SERIALIZER(AStarWitch)


#define ProjectW_Source_ProjectW_StarWitch_h_25_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AStarWitch(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AStarWitch) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AStarWitch); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AStarWitch); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AStarWitch(AStarWitch&&); \
	NO_API AStarWitch(const AStarWitch&); \
public:


#define ProjectW_Source_ProjectW_StarWitch_h_25_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AStarWitch(AStarWitch&&); \
	NO_API AStarWitch(const AStarWitch&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AStarWitch); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AStarWitch); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AStarWitch)


#define ProjectW_Source_ProjectW_StarWitch_h_25_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__FlipbookComponent() { return STRUCT_OFFSET(AStarWitch, FlipbookComponent); }


#define ProjectW_Source_ProjectW_StarWitch_h_22_PROLOG
#define ProjectW_Source_ProjectW_StarWitch_h_25_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ProjectW_Source_ProjectW_StarWitch_h_25_PRIVATE_PROPERTY_OFFSET \
	ProjectW_Source_ProjectW_StarWitch_h_25_SPARSE_DATA \
	ProjectW_Source_ProjectW_StarWitch_h_25_RPC_WRAPPERS \
	ProjectW_Source_ProjectW_StarWitch_h_25_INCLASS \
	ProjectW_Source_ProjectW_StarWitch_h_25_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ProjectW_Source_ProjectW_StarWitch_h_25_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ProjectW_Source_ProjectW_StarWitch_h_25_PRIVATE_PROPERTY_OFFSET \
	ProjectW_Source_ProjectW_StarWitch_h_25_SPARSE_DATA \
	ProjectW_Source_ProjectW_StarWitch_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
	ProjectW_Source_ProjectW_StarWitch_h_25_INCLASS_NO_PURE_DECLS \
	ProjectW_Source_ProjectW_StarWitch_h_25_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECTW_API UClass* StaticClass<class AStarWitch>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ProjectW_Source_ProjectW_StarWitch_h


#define FOREACH_ENUM_EACTORSTATE(op) \
	op(EActorState::StarWitchState_Idle) \
	op(EActorState::StarWitchState_Walking) \
	op(EActorState::StarWitchState_Attack_01) \
	op(EActorState::StarWitchState_Attack_02) \
	op(EActorState::StarWitchState_Attack_03) \
	op(EActorState::StarWitchState_CounterReady) \
	op(EActorState::StarWitchState_Dead) 

enum class EActorState : uint8;
template<> PROJECTW_API UEnum* StaticEnum<EActorState>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
