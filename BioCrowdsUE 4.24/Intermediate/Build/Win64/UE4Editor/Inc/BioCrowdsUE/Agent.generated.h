// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
struct FKey;
#ifdef BIOCROWDSUE_Agent_generated_h
#error "Agent.generated.h already included, missing '#pragma once' in Agent.h"
#endif
#define BIOCROWDSUE_Agent_generated_h

#define BioCrowdsUE_4_24_Source_BioCrowdsUE_src_Agent_h_25_SPARSE_DATA
#define BioCrowdsUE_4_24_Source_BioCrowdsUE_src_Agent_h_25_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(exectoggleGoal); \
	DECLARE_FUNCTION(execOnSelected);


#define BioCrowdsUE_4_24_Source_BioCrowdsUE_src_Agent_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(exectoggleGoal); \
	DECLARE_FUNCTION(execOnSelected);


#define BioCrowdsUE_4_24_Source_BioCrowdsUE_src_Agent_h_25_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAAgent(); \
	friend struct Z_Construct_UClass_AAgent_Statics; \
public: \
	DECLARE_CLASS(AAgent, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BioCrowdsUE"), NO_API) \
	DECLARE_SERIALIZER(AAgent)


#define BioCrowdsUE_4_24_Source_BioCrowdsUE_src_Agent_h_25_INCLASS \
private: \
	static void StaticRegisterNativesAAgent(); \
	friend struct Z_Construct_UClass_AAgent_Statics; \
public: \
	DECLARE_CLASS(AAgent, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BioCrowdsUE"), NO_API) \
	DECLARE_SERIALIZER(AAgent)


#define BioCrowdsUE_4_24_Source_BioCrowdsUE_src_Agent_h_25_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AAgent(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AAgent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AAgent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AAgent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AAgent(AAgent&&); \
	NO_API AAgent(const AAgent&); \
public:


#define BioCrowdsUE_4_24_Source_BioCrowdsUE_src_Agent_h_25_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AAgent(AAgent&&); \
	NO_API AAgent(const AAgent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AAgent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AAgent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AAgent)


#define BioCrowdsUE_4_24_Source_BioCrowdsUE_src_Agent_h_25_PRIVATE_PROPERTY_OFFSET
#define BioCrowdsUE_4_24_Source_BioCrowdsUE_src_Agent_h_22_PROLOG
#define BioCrowdsUE_4_24_Source_BioCrowdsUE_src_Agent_h_25_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BioCrowdsUE_4_24_Source_BioCrowdsUE_src_Agent_h_25_PRIVATE_PROPERTY_OFFSET \
	BioCrowdsUE_4_24_Source_BioCrowdsUE_src_Agent_h_25_SPARSE_DATA \
	BioCrowdsUE_4_24_Source_BioCrowdsUE_src_Agent_h_25_RPC_WRAPPERS \
	BioCrowdsUE_4_24_Source_BioCrowdsUE_src_Agent_h_25_INCLASS \
	BioCrowdsUE_4_24_Source_BioCrowdsUE_src_Agent_h_25_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define BioCrowdsUE_4_24_Source_BioCrowdsUE_src_Agent_h_25_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BioCrowdsUE_4_24_Source_BioCrowdsUE_src_Agent_h_25_PRIVATE_PROPERTY_OFFSET \
	BioCrowdsUE_4_24_Source_BioCrowdsUE_src_Agent_h_25_SPARSE_DATA \
	BioCrowdsUE_4_24_Source_BioCrowdsUE_src_Agent_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
	BioCrowdsUE_4_24_Source_BioCrowdsUE_src_Agent_h_25_INCLASS_NO_PURE_DECLS \
	BioCrowdsUE_4_24_Source_BioCrowdsUE_src_Agent_h_25_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BIOCROWDSUE_API UClass* StaticClass<class AAgent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID BioCrowdsUE_4_24_Source_BioCrowdsUE_src_Agent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
