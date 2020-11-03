// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef NEWDEMO_Cubo_generated_h
#error "Cubo.generated.h already included, missing '#pragma once' in Cubo.h"
#endif
#define NEWDEMO_Cubo_generated_h

#define NewDemo_Source_NewDemo_Cubo_h_12_SPARSE_DATA
#define NewDemo_Source_NewDemo_Cubo_h_12_RPC_WRAPPERS
#define NewDemo_Source_NewDemo_Cubo_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define NewDemo_Source_NewDemo_Cubo_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACubo(); \
	friend struct Z_Construct_UClass_ACubo_Statics; \
public: \
	DECLARE_CLASS(ACubo, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/NewDemo"), NO_API) \
	DECLARE_SERIALIZER(ACubo)


#define NewDemo_Source_NewDemo_Cubo_h_12_INCLASS \
private: \
	static void StaticRegisterNativesACubo(); \
	friend struct Z_Construct_UClass_ACubo_Statics; \
public: \
	DECLARE_CLASS(ACubo, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/NewDemo"), NO_API) \
	DECLARE_SERIALIZER(ACubo)


#define NewDemo_Source_NewDemo_Cubo_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ACubo(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ACubo) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACubo); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACubo); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACubo(ACubo&&); \
	NO_API ACubo(const ACubo&); \
public:


#define NewDemo_Source_NewDemo_Cubo_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACubo(ACubo&&); \
	NO_API ACubo(const ACubo&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACubo); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACubo); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACubo)


#define NewDemo_Source_NewDemo_Cubo_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__RootScene() { return STRUCT_OFFSET(ACubo, RootScene); } \
	FORCEINLINE static uint32 __PPO__Mesh() { return STRUCT_OFFSET(ACubo, Mesh); }


#define NewDemo_Source_NewDemo_Cubo_h_9_PROLOG
#define NewDemo_Source_NewDemo_Cubo_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	NewDemo_Source_NewDemo_Cubo_h_12_PRIVATE_PROPERTY_OFFSET \
	NewDemo_Source_NewDemo_Cubo_h_12_SPARSE_DATA \
	NewDemo_Source_NewDemo_Cubo_h_12_RPC_WRAPPERS \
	NewDemo_Source_NewDemo_Cubo_h_12_INCLASS \
	NewDemo_Source_NewDemo_Cubo_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define NewDemo_Source_NewDemo_Cubo_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	NewDemo_Source_NewDemo_Cubo_h_12_PRIVATE_PROPERTY_OFFSET \
	NewDemo_Source_NewDemo_Cubo_h_12_SPARSE_DATA \
	NewDemo_Source_NewDemo_Cubo_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	NewDemo_Source_NewDemo_Cubo_h_12_INCLASS_NO_PURE_DECLS \
	NewDemo_Source_NewDemo_Cubo_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> NEWDEMO_API UClass* StaticClass<class ACubo>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID NewDemo_Source_NewDemo_Cubo_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
