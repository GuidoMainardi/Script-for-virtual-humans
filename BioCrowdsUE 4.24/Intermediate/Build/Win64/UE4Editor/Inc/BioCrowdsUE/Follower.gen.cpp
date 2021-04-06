// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BioCrowdsUE/src/Follower.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFollower() {}
// Cross Module References
	BIOCROWDSUE_API UClass* Z_Construct_UClass_AFollower_NoRegister();
	BIOCROWDSUE_API UClass* Z_Construct_UClass_AFollower();
	BIOCROWDSUE_API UClass* Z_Construct_UClass_AAgent();
	UPackage* Z_Construct_UPackage__Script_BioCrowdsUE();
// End Cross Module References
	void AFollower::StaticRegisterNativesAFollower()
	{
	}
	UClass* Z_Construct_UClass_AFollower_NoRegister()
	{
		return AFollower::StaticClass();
	}
	struct Z_Construct_UClass_AFollower_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFollower_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AAgent,
		(UObject* (*)())Z_Construct_UPackage__Script_BioCrowdsUE,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFollower_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "src/Follower.h" },
		{ "ModuleRelativePath", "src/Follower.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFollower_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFollower>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AFollower_Statics::ClassParams = {
		&AFollower::StaticClass,
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
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AFollower_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AFollower_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AFollower()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AFollower_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AFollower, 1116494449);
	template<> BIOCROWDSUE_API UClass* StaticClass<AFollower>()
	{
		return AFollower::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AFollower(Z_Construct_UClass_AFollower, &AFollower::StaticClass, TEXT("/Script/BioCrowdsUE"), TEXT("AFollower"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFollower);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
