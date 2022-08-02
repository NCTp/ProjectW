// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PROJECTW_NightWitch_generated_h
#error "NightWitch.generated.h already included, missing '#pragma once' in NightWitch.h"
#endif
#define PROJECTW_NightWitch_generated_h

#define ProjectW_Source_ProjectW_NightWitch_h_25_SPARSE_DATA
#define ProjectW_Source_ProjectW_NightWitch_h_25_RPC_WRAPPERS
#define ProjectW_Source_ProjectW_NightWitch_h_25_RPC_WRAPPERS_NO_PURE_DECLS
#define ProjectW_Source_ProjectW_NightWitch_h_25_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesANightWitch(); \
	friend struct Z_Construct_UClass_ANightWitch_Statics; \
public: \
	DECLARE_CLASS(ANightWitch, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectW"), NO_API) \
	DECLARE_SERIALIZER(ANightWitch)


#define ProjectW_Source_ProjectW_NightWitch_h_25_INCLASS \
private: \
	static void StaticRegisterNativesANightWitch(); \
	friend struct Z_Construct_UClass_ANightWitch_Statics; \
public: \
	DECLARE_CLASS(ANightWitch, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectW"), NO_API) \
	DECLARE_SERIALIZER(ANightWitch)


#define ProjectW_Source_ProjectW_NightWitch_h_25_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ANightWitch(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ANightWitch) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ANightWitch); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ANightWitch); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ANightWitch(ANightWitch&&); \
	NO_API ANightWitch(const ANightWitch&); \
public:


#define ProjectW_Source_ProjectW_NightWitch_h_25_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ANightWitch(ANightWitch&&); \
	NO_API ANightWitch(const ANightWitch&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ANightWitch); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ANightWitch); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ANightWitch)


#define ProjectW_Source_ProjectW_NightWitch_h_25_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__NightWitchFlipbook() { return STRUCT_OFFSET(ANightWitch, NightWitchFlipbook); } \
	FORCEINLINE static uint32 __PPO__CapsuleCollision() { return STRUCT_OFFSET(ANightWitch, CapsuleCollision); } \
	FORCEINLINE static uint32 __PPO__Arrow() { return STRUCT_OFFSET(ANightWitch, Arrow); } \
	FORCEINLINE static uint32 __PPO__Movement() { return STRUCT_OFFSET(ANightWitch, Movement); } \
	FORCEINLINE static uint32 __PPO__ActiveState() { return STRUCT_OFFSET(ANightWitch, ActiveState); }


#define ProjectW_Source_ProjectW_NightWitch_h_22_PROLOG
#define ProjectW_Source_ProjectW_NightWitch_h_25_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ProjectW_Source_ProjectW_NightWitch_h_25_PRIVATE_PROPERTY_OFFSET \
	ProjectW_Source_ProjectW_NightWitch_h_25_SPARSE_DATA \
	ProjectW_Source_ProjectW_NightWitch_h_25_RPC_WRAPPERS \
	ProjectW_Source_ProjectW_NightWitch_h_25_INCLASS \
	ProjectW_Source_ProjectW_NightWitch_h_25_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ProjectW_Source_ProjectW_NightWitch_h_25_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ProjectW_Source_ProjectW_NightWitch_h_25_PRIVATE_PROPERTY_OFFSET \
	ProjectW_Source_ProjectW_NightWitch_h_25_SPARSE_DATA \
	ProjectW_Source_ProjectW_NightWitch_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
	ProjectW_Source_ProjectW_NightWitch_h_25_INCLASS_NO_PURE_DECLS \
	ProjectW_Source_ProjectW_NightWitch_h_25_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECTW_API UClass* StaticClass<class ANightWitch>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ProjectW_Source_ProjectW_NightWitch_h


#define FOREACH_ENUM_ESTATE(op) \
	op(EState::DEFAULT) \
	op(EState::IDLE) \
	op(EState::CHASE) \
	op(EState::TELEPORT) \
	op(EState::ATTACK) \
	op(EState::STUMBLE) \
	op(EState::TAUNT) \
	op(EState::DEAD) 

enum class EState : uint8;
template<> PROJECTW_API UEnum* StaticEnum<EState>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
