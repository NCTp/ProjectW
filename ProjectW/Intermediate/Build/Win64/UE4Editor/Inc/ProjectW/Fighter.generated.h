// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PROJECTW_Fighter_generated_h
#error "Fighter.generated.h already included, missing '#pragma once' in Fighter.h"
#endif
#define PROJECTW_Fighter_generated_h

#define ProjectW_Source_ProjectW_Fighter_h_12_SPARSE_DATA
#define ProjectW_Source_ProjectW_Fighter_h_12_RPC_WRAPPERS
#define ProjectW_Source_ProjectW_Fighter_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define ProjectW_Source_ProjectW_Fighter_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFighter(); \
	friend struct Z_Construct_UClass_AFighter_Statics; \
public: \
	DECLARE_CLASS(AFighter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectW"), NO_API) \
	DECLARE_SERIALIZER(AFighter)


#define ProjectW_Source_ProjectW_Fighter_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAFighter(); \
	friend struct Z_Construct_UClass_AFighter_Statics; \
public: \
	DECLARE_CLASS(AFighter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectW"), NO_API) \
	DECLARE_SERIALIZER(AFighter)


#define ProjectW_Source_ProjectW_Fighter_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AFighter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFighter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFighter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFighter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFighter(AFighter&&); \
	NO_API AFighter(const AFighter&); \
public:


#define ProjectW_Source_ProjectW_Fighter_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFighter(AFighter&&); \
	NO_API AFighter(const AFighter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFighter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFighter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFighter)


#define ProjectW_Source_ProjectW_Fighter_h_12_PRIVATE_PROPERTY_OFFSET
#define ProjectW_Source_ProjectW_Fighter_h_9_PROLOG
#define ProjectW_Source_ProjectW_Fighter_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ProjectW_Source_ProjectW_Fighter_h_12_PRIVATE_PROPERTY_OFFSET \
	ProjectW_Source_ProjectW_Fighter_h_12_SPARSE_DATA \
	ProjectW_Source_ProjectW_Fighter_h_12_RPC_WRAPPERS \
	ProjectW_Source_ProjectW_Fighter_h_12_INCLASS \
	ProjectW_Source_ProjectW_Fighter_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ProjectW_Source_ProjectW_Fighter_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ProjectW_Source_ProjectW_Fighter_h_12_PRIVATE_PROPERTY_OFFSET \
	ProjectW_Source_ProjectW_Fighter_h_12_SPARSE_DATA \
	ProjectW_Source_ProjectW_Fighter_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	ProjectW_Source_ProjectW_Fighter_h_12_INCLASS_NO_PURE_DECLS \
	ProjectW_Source_ProjectW_Fighter_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECTW_API UClass* StaticClass<class AFighter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ProjectW_Source_ProjectW_Fighter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
