// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BioCrowdsUE/src/FIleReader.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFIleReader() {}
// Cross Module References
	BIOCROWDSUE_API UClass* Z_Construct_UClass_UFIleReader_NoRegister();
	BIOCROWDSUE_API UClass* Z_Construct_UClass_UFIleReader();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_BioCrowdsUE();
// End Cross Module References
	DEFINE_FUNCTION(UFIleReader::execSaveTxt)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_SaveTextB);
		P_GET_PROPERTY(FStrProperty,Z_Param_FileNameB);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UFIleReader::SaveTxt(Z_Param_SaveTextB,Z_Param_FileNameB);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFIleReader::execLoadTxt)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_FileNameA);
		P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_SaveTextA);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UFIleReader::LoadTxt(Z_Param_FileNameA,Z_Param_Out_SaveTextA);
		P_NATIVE_END;
	}
	void UFIleReader::StaticRegisterNativesUFIleReader()
	{
		UClass* Class = UFIleReader::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "LoadTxt", &UFIleReader::execLoadTxt },
			{ "SaveTxt", &UFIleReader::execSaveTxt },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UFIleReader_LoadTxt_Statics
	{
		struct FIleReader_eventLoadTxt_Parms
		{
			FString FileNameA;
			FString SaveTextA;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_FileNameA;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_SaveTextA;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFIleReader_LoadTxt_Statics::NewProp_FileNameA = { "FileNameA", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FIleReader_eventLoadTxt_Parms, FileNameA), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFIleReader_LoadTxt_Statics::NewProp_SaveTextA = { "SaveTextA", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FIleReader_eventLoadTxt_Parms, SaveTextA), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UFIleReader_LoadTxt_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((FIleReader_eventLoadTxt_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UFIleReader_LoadTxt_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FIleReader_eventLoadTxt_Parms), &Z_Construct_UFunction_UFIleReader_LoadTxt_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFIleReader_LoadTxt_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFIleReader_LoadTxt_Statics::NewProp_FileNameA,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFIleReader_LoadTxt_Statics::NewProp_SaveTextA,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFIleReader_LoadTxt_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFIleReader_LoadTxt_Statics::Function_MetaDataParams[] = {
		{ "Category", "Custom" },
		{ "Keywords", "LoadTxt" },
		{ "ModuleRelativePath", "src/FIleReader.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFIleReader_LoadTxt_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFIleReader, nullptr, "LoadTxt", nullptr, nullptr, sizeof(FIleReader_eventLoadTxt_Parms), Z_Construct_UFunction_UFIleReader_LoadTxt_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFIleReader_LoadTxt_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFIleReader_LoadTxt_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFIleReader_LoadTxt_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFIleReader_LoadTxt()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFIleReader_LoadTxt_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFIleReader_SaveTxt_Statics
	{
		struct FIleReader_eventSaveTxt_Parms
		{
			FString SaveTextB;
			FString FileNameB;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_SaveTextB;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_FileNameB;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFIleReader_SaveTxt_Statics::NewProp_SaveTextB = { "SaveTextB", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FIleReader_eventSaveTxt_Parms, SaveTextB), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFIleReader_SaveTxt_Statics::NewProp_FileNameB = { "FileNameB", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FIleReader_eventSaveTxt_Parms, FileNameB), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UFIleReader_SaveTxt_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((FIleReader_eventSaveTxt_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UFIleReader_SaveTxt_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FIleReader_eventSaveTxt_Parms), &Z_Construct_UFunction_UFIleReader_SaveTxt_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFIleReader_SaveTxt_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFIleReader_SaveTxt_Statics::NewProp_SaveTextB,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFIleReader_SaveTxt_Statics::NewProp_FileNameB,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFIleReader_SaveTxt_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFIleReader_SaveTxt_Statics::Function_MetaDataParams[] = {
		{ "Category", "Custom" },
		{ "Keywords", "SaveTxt" },
		{ "ModuleRelativePath", "src/FIleReader.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFIleReader_SaveTxt_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFIleReader, nullptr, "SaveTxt", nullptr, nullptr, sizeof(FIleReader_eventSaveTxt_Parms), Z_Construct_UFunction_UFIleReader_SaveTxt_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFIleReader_SaveTxt_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFIleReader_SaveTxt_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFIleReader_SaveTxt_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFIleReader_SaveTxt()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFIleReader_SaveTxt_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UFIleReader_NoRegister()
	{
		return UFIleReader::StaticClass();
	}
	struct Z_Construct_UClass_UFIleReader_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UFIleReader_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_BioCrowdsUE,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UFIleReader_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UFIleReader_LoadTxt, "LoadTxt" }, // 3994611418
		{ &Z_Construct_UFunction_UFIleReader_SaveTxt, "SaveTxt" }, // 4183144328
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFIleReader_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n *\n */" },
		{ "IncludePath", "src/FIleReader.h" },
		{ "ModuleRelativePath", "src/FIleReader.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UFIleReader_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UFIleReader>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UFIleReader_Statics::ClassParams = {
		&UFIleReader::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x000000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UFIleReader_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UFIleReader_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UFIleReader()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UFIleReader_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UFIleReader, 1796876007);
	template<> BIOCROWDSUE_API UClass* StaticClass<UFIleReader>()
	{
		return UFIleReader::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UFIleReader(Z_Construct_UClass_UFIleReader, &UFIleReader::StaticClass, TEXT("/Script/BioCrowdsUE"), TEXT("UFIleReader"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UFIleReader);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
