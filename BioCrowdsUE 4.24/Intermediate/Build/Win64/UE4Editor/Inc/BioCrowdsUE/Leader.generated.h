// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef BIOCROWDSUE_Leader_generated_h
#error "Leader.generated.h already included, missing '#pragma once' in Leader.h"
#endif
#define BIOCROWDSUE_Leader_generated_h

#define BioCrowdsUE_4_24_Source_BioCrowdsUE_src_Leader_h_28_SPARSE_DATA
#define BioCrowdsUE_4_24_Source_BioCrowdsUE_src_Leader_h_28_RPC_WRAPPERS
#define BioCrowdsUE_4_24_Source_BioCrowdsUE_src_Leader_h_28_RPC_WRAPPERS_NO_PURE_DECLS
#define BioCrowdsUE_4_24_Source_BioCrowdsUE_src_Leader_h_28_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesALeader(); \
	friend struct Z_Construct_UClass_ALeader_Statics; \
public: \
	DECLARE_CLASS(ALeader, AAgent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BioCrowdsUE"), NO_API) \
	DECLARE_SERIALIZER(ALeader)


#define BioCrowdsUE_4_24_Source_BioCrowdsUE_src_Leader_h_28_INCLASS \
private: \
	static void StaticRegisterNativesALeader(); \
	friend struct Z_Construct_UClass_ALeader_Statics; \
public: \
	DECLARE_CLASS(ALeader, AAgent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BioCrowdsUE"), NO_API) \
	DECLARE_SERIALIZER(ALeader)


#define BioCrowdsUE_4_24_Source_BioCrowdsUE_src_Leader_h_28_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ALeader(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ALeader) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ALeader); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ALeader); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ALeader(ALeader&&); \
	NO_API ALeader(const ALeader&); \
public:


#define BioCrowdsUE_4_24_Source_BioCrowdsUE_src_Leader_h_28_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ALeader() { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ALeader(ALeader&&); \
	NO_API ALeader(const ALeader&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ALeader); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ALeader); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ALeader)


#define BioCrowdsUE_4_24_Source_BioCrowdsUE_src_Leader_h_28_PRIVATE_PROPERTY_OFFSET
#define BioCrowdsUE_4_24_Source_BioCrowdsUE_src_Leader_h_25_PROLOG
#define BioCrowdsUE_4_24_Source_BioCrowdsUE_src_Leader_h_28_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BioCrowdsUE_4_24_Source_BioCrowdsUE_src_Leader_h_28_PRIVATE_PROPERTY_OFFSET \
	BioCrowdsUE_4_24_Source_BioCrowdsUE_src_Leader_h_28_SPARSE_DATA \
	BioCrowdsUE_4_24_Source_BioCrowdsUE_src_Leader_h_28_RPC_WRAPPERS \
	BioCrowdsUE_4_24_Source_BioCrowdsUE_src_Leader_h_28_INCLASS \
	BioCrowdsUE_4_24_Source_BioCrowdsUE_src_Leader_h_28_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define BioCrowdsUE_4_24_Source_BioCrowdsUE_src_Leader_h_28_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BioCrowdsUE_4_24_Source_BioCrowdsUE_src_Leader_h_28_PRIVATE_PROPERTY_OFFSET \
	BioCrowdsUE_4_24_Source_BioCrowdsUE_src_Leader_h_28_SPARSE_DATA \
	BioCrowdsUE_4_24_Source_BioCrowdsUE_src_Leader_h_28_RPC_WRAPPERS_NO_PURE_DECLS \
	BioCrowdsUE_4_24_Source_BioCrowdsUE_src_Leader_h_28_INCLASS_NO_PURE_DECLS \
	BioCrowdsUE_4_24_Source_BioCrowdsUE_src_Leader_h_28_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BIOCROWDSUE_API UClass* StaticClass<class ALeader>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID BioCrowdsUE_4_24_Source_BioCrowdsUE_src_Leader_h


#define FOREACH_ENUM_EFORM(op) \
	op(EForm::EF_CLUMP) \
	op(EForm::EF_CLUMPLINE) \
	op(EForm::EF_LINE) \
	op(EForm::EF_RANDLINE) \
	op(EForm::EF_WIDELINE) 

enum class EForm : uint8;
template<> BIOCROWDSUE_API UEnum* StaticEnum<EForm>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
