// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BioCrowdsUE/src/RegionBox.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRegionBox() {}
// Cross Module References
	BIOCROWDSUE_API UClass* Z_Construct_UClass_ARegionBox_NoRegister();
	BIOCROWDSUE_API UClass* Z_Construct_UClass_ARegionBox();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_BioCrowdsUE();
// End Cross Module References
	void ARegionBox::StaticRegisterNativesARegionBox()
	{
	}
	UClass* Z_Construct_UClass_ARegionBox_NoRegister()
	{
		return ARegionBox::StaticClass();
	}
	struct Z_Construct_UClass_ARegionBox_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_percent_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_percent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_numAgents_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_numAgents;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_activities_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_activities_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_activities;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ARegionBox_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_BioCrowdsUE,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARegionBox_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "src/RegionBox.h" },
		{ "ModuleRelativePath", "src/RegionBox.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARegionBox_Statics::NewProp_percent_MetaData[] = {
		{ "Category", "SetUp" },
		{ "ModuleRelativePath", "src/RegionBox.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ARegionBox_Statics::NewProp_percent = { "percent", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ARegionBox, percent), METADATA_PARAMS(Z_Construct_UClass_ARegionBox_Statics::NewProp_percent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ARegionBox_Statics::NewProp_percent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARegionBox_Statics::NewProp_numAgents_MetaData[] = {
		{ "Category", "SetUp" },
		{ "ModuleRelativePath", "src/RegionBox.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ARegionBox_Statics::NewProp_numAgents = { "numAgents", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ARegionBox, numAgents), METADATA_PARAMS(Z_Construct_UClass_ARegionBox_Statics::NewProp_numAgents_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ARegionBox_Statics::NewProp_numAgents_MetaData)) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_ARegionBox_Statics::NewProp_activities_Inner = { "activities", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARegionBox_Statics::NewProp_activities_MetaData[] = {
		{ "Category", "SetUp" },
		{ "ModuleRelativePath", "src/RegionBox.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ARegionBox_Statics::NewProp_activities = { "activities", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ARegionBox, activities), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_ARegionBox_Statics::NewProp_activities_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ARegionBox_Statics::NewProp_activities_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ARegionBox_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARegionBox_Statics::NewProp_percent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARegionBox_Statics::NewProp_numAgents,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARegionBox_Statics::NewProp_activities_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARegionBox_Statics::NewProp_activities,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ARegionBox_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ARegionBox>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ARegionBox_Statics::ClassParams = {
		&ARegionBox::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ARegionBox_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ARegionBox_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ARegionBox_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ARegionBox_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ARegionBox()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ARegionBox_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ARegionBox, 3375785287);
	template<> BIOCROWDSUE_API UClass* StaticClass<ARegionBox>()
	{
		return ARegionBox::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ARegionBox(Z_Construct_UClass_ARegionBox, &ARegionBox::StaticClass, TEXT("/Script/BioCrowdsUE"), TEXT("ARegionBox"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ARegionBox);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
