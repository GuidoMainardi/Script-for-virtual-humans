// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BioCrowdsUE/src/Senario.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSenario() {}
// Cross Module References
	BIOCROWDSUE_API UClass* Z_Construct_UClass_USenario_NoRegister();
	BIOCROWDSUE_API UClass* Z_Construct_UClass_USenario();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_BioCrowdsUE();
// End Cross Module References
	void USenario::StaticRegisterNativesUSenario()
	{
	}
	UClass* Z_Construct_UClass_USenario_NoRegister()
	{
		return USenario::StaticClass();
	}
	struct Z_Construct_UClass_USenario_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USenario_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_BioCrowdsUE,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USenario_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "src/Senario.h" },
		{ "ModuleRelativePath", "src/Senario.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USenario_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USenario>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USenario_Statics::ClassParams = {
		&USenario::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_USenario_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USenario_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USenario()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USenario_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USenario, 4184706155);
	template<> BIOCROWDSUE_API UClass* StaticClass<USenario>()
	{
		return USenario::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USenario(Z_Construct_UClass_USenario, &USenario::StaticClass, TEXT("/Script/BioCrowdsUE"), TEXT("USenario"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USenario);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
