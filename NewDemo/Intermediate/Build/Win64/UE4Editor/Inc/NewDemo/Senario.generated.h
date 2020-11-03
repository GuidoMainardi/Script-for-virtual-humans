// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef NEWDEMO_Senario_generated_h
#error "Senario.generated.h already included, missing '#pragma once' in Senario.h"
#endif
#define NEWDEMO_Senario_generated_h

#define NewDemo_Source_NewDemo_Senario_h_15_SPARSE_DATA
#define NewDemo_Source_NewDemo_Senario_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSaveTxt); \
	DECLARE_FUNCTION(execLoadTxt);


#define NewDemo_Source_NewDemo_Senario_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSaveTxt); \
	DECLARE_FUNCTION(execLoadTxt);


#define NewDemo_Source_NewDemo_Senario_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSenario(); \
	friend struct Z_Construct_UClass_USenario_Statics; \
public: \
	DECLARE_CLASS(USenario, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/NewDemo"), NO_API) \
	DECLARE_SERIALIZER(USenario)


#define NewDemo_Source_NewDemo_Senario_h_15_INCLASS \
private: \
	static void StaticRegisterNativesUSenario(); \
	friend struct Z_Construct_UClass_USenario_Statics; \
public: \
	DECLARE_CLASS(USenario, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/NewDemo"), NO_API) \
	DECLARE_SERIALIZER(USenario)


#define NewDemo_Source_NewDemo_Senario_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USenario(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USenario) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USenario); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USenario); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USenario(USenario&&); \
	NO_API USenario(const USenario&); \
public:


#define NewDemo_Source_NewDemo_Senario_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USenario(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USenario(USenario&&); \
	NO_API USenario(const USenario&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USenario); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USenario); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USenario)


#define NewDemo_Source_NewDemo_Senario_h_15_PRIVATE_PROPERTY_OFFSET
#define NewDemo_Source_NewDemo_Senario_h_12_PROLOG
#define NewDemo_Source_NewDemo_Senario_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	NewDemo_Source_NewDemo_Senario_h_15_PRIVATE_PROPERTY_OFFSET \
	NewDemo_Source_NewDemo_Senario_h_15_SPARSE_DATA \
	NewDemo_Source_NewDemo_Senario_h_15_RPC_WRAPPERS \
	NewDemo_Source_NewDemo_Senario_h_15_INCLASS \
	NewDemo_Source_NewDemo_Senario_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define NewDemo_Source_NewDemo_Senario_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	NewDemo_Source_NewDemo_Senario_h_15_PRIVATE_PROPERTY_OFFSET \
	NewDemo_Source_NewDemo_Senario_h_15_SPARSE_DATA \
	NewDemo_Source_NewDemo_Senario_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	NewDemo_Source_NewDemo_Senario_h_15_INCLASS_NO_PURE_DECLS \
	NewDemo_Source_NewDemo_Senario_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> NEWDEMO_API UClass* StaticClass<class USenario>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID NewDemo_Source_NewDemo_Senario_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
