// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BioCrowdsUE/BioCrowdsUEGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBioCrowdsUEGameModeBase() {}
// Cross Module References
	BIOCROWDSUE_API UClass* Z_Construct_UClass_ABioCrowdsUEGameModeBase_NoRegister();
	BIOCROWDSUE_API UClass* Z_Construct_UClass_ABioCrowdsUEGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_BioCrowdsUE();
// End Cross Module References
	void ABioCrowdsUEGameModeBase::StaticRegisterNativesABioCrowdsUEGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_ABioCrowdsUEGameModeBase_NoRegister()
	{
		return ABioCrowdsUEGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_ABioCrowdsUEGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABioCrowdsUEGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_BioCrowdsUE,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABioCrowdsUEGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "BioCrowdsUEGameModeBase.h" },
		{ "ModuleRelativePath", "BioCrowdsUEGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABioCrowdsUEGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABioCrowdsUEGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ABioCrowdsUEGameModeBase_Statics::ClassParams = {
		&ABioCrowdsUEGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_ABioCrowdsUEGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ABioCrowdsUEGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ABioCrowdsUEGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ABioCrowdsUEGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ABioCrowdsUEGameModeBase, 3122627777);
	template<> BIOCROWDSUE_API UClass* StaticClass<ABioCrowdsUEGameModeBase>()
	{
		return ABioCrowdsUEGameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABioCrowdsUEGameModeBase(Z_Construct_UClass_ABioCrowdsUEGameModeBase, &ABioCrowdsUEGameModeBase::StaticClass, TEXT("/Script/BioCrowdsUE"), TEXT("ABioCrowdsUEGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABioCrowdsUEGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
