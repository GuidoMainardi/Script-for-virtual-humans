// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef NEWDEMO_DemoController_generated_h
#error "DemoController.generated.h already included, missing '#pragma once' in DemoController.h"
#endif
#define NEWDEMO_DemoController_generated_h

#define NewDemo_Source_NewDemo_DemoController_h_15_SPARSE_DATA
#define NewDemo_Source_NewDemo_DemoController_h_15_RPC_WRAPPERS
#define NewDemo_Source_NewDemo_DemoController_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define NewDemo_Source_NewDemo_DemoController_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesADemoController(); \
	friend struct Z_Construct_UClass_ADemoController_Statics; \
public: \
	DECLARE_CLASS(ADemoController, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/NewDemo"), NO_API) \
	DECLARE_SERIALIZER(ADemoController)


#define NewDemo_Source_NewDemo_DemoController_h_15_INCLASS \
private: \
	static void StaticRegisterNativesADemoController(); \
	friend struct Z_Construct_UClass_ADemoController_Statics; \
public: \
	DECLARE_CLASS(ADemoController, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/NewDemo"), NO_API) \
	DECLARE_SERIALIZER(ADemoController)


#define NewDemo_Source_NewDemo_DemoController_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ADemoController(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ADemoController) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADemoController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADemoController); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ADemoController(ADemoController&&); \
	NO_API ADemoController(const ADemoController&); \
public:


#define NewDemo_Source_NewDemo_DemoController_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ADemoController(ADemoController&&); \
	NO_API ADemoController(const ADemoController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADemoController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADemoController); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ADemoController)


#define NewDemo_Source_NewDemo_DemoController_h_15_PRIVATE_PROPERTY_OFFSET
#define NewDemo_Source_NewDemo_DemoController_h_12_PROLOG
#define NewDemo_Source_NewDemo_DemoController_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	NewDemo_Source_NewDemo_DemoController_h_15_PRIVATE_PROPERTY_OFFSET \
	NewDemo_Source_NewDemo_DemoController_h_15_SPARSE_DATA \
	NewDemo_Source_NewDemo_DemoController_h_15_RPC_WRAPPERS \
	NewDemo_Source_NewDemo_DemoController_h_15_INCLASS \
	NewDemo_Source_NewDemo_DemoController_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define NewDemo_Source_NewDemo_DemoController_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	NewDemo_Source_NewDemo_DemoController_h_15_PRIVATE_PROPERTY_OFFSET \
	NewDemo_Source_NewDemo_DemoController_h_15_SPARSE_DATA \
	NewDemo_Source_NewDemo_DemoController_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	NewDemo_Source_NewDemo_DemoController_h_15_INCLASS_NO_PURE_DECLS \
	NewDemo_Source_NewDemo_DemoController_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> NEWDEMO_API UClass* StaticClass<class ADemoController>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID NewDemo_Source_NewDemo_DemoController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
