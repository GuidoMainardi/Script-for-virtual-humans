// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BioCrowdsUE/src/MarkerVis.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMarkerVis() {}
// Cross Module References
	BIOCROWDSUE_API UClass* Z_Construct_UClass_AMarkerVis_NoRegister();
	BIOCROWDSUE_API UClass* Z_Construct_UClass_AMarkerVis();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_BioCrowdsUE();
// End Cross Module References
	void AMarkerVis::StaticRegisterNativesAMarkerVis()
	{
	}
	UClass* Z_Construct_UClass_AMarkerVis_NoRegister()
	{
		return AMarkerVis::StaticClass();
	}
	struct Z_Construct_UClass_AMarkerVis_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMarkerVis_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_BioCrowdsUE,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMarkerVis_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "src/MarkerVis.h" },
		{ "ModuleRelativePath", "src/MarkerVis.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMarkerVis_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMarkerVis>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMarkerVis_Statics::ClassParams = {
		&AMarkerVis::StaticClass,
		"Engine",
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
		METADATA_PARAMS(Z_Construct_UClass_AMarkerVis_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMarkerVis_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMarkerVis()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMarkerVis_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMarkerVis, 2621405376);
	template<> BIOCROWDSUE_API UClass* StaticClass<AMarkerVis>()
	{
		return AMarkerVis::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMarkerVis(Z_Construct_UClass_AMarkerVis, &AMarkerVis::StaticClass, TEXT("/Script/BioCrowdsUE"), TEXT("AMarkerVis"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMarkerVis);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
