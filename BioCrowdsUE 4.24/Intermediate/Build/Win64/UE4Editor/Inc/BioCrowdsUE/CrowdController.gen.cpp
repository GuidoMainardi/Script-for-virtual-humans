// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BioCrowdsUE/src/CrowdController.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCrowdController() {}
// Cross Module References
	BIOCROWDSUE_API UClass* Z_Construct_UClass_ACrowdController_NoRegister();
	BIOCROWDSUE_API UClass* Z_Construct_UClass_ACrowdController();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_BioCrowdsUE();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
// End Cross Module References
	void ACrowdController::StaticRegisterNativesACrowdController()
	{
	}
	UClass* Z_Construct_UClass_ACrowdController_NoRegister()
	{
		return ACrowdController::StaticClass();
	}
	struct Z_Construct_UClass_ACrowdController_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WidgetBPRef_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_WidgetBPRef;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_duration_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_duration;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_agentR_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_agentR;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_agentV_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_agentV;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_numAgents_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_numAgents;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_numSamples_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_numSamples;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACrowdController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_BioCrowdsUE,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACrowdController_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "src/CrowdController.h" },
		{ "ModuleRelativePath", "src/CrowdController.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACrowdController_Statics::NewProp_WidgetBPRef_MetaData[] = {
		{ "Category", "Widget" },
		{ "ModuleRelativePath", "src/CrowdController.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_ACrowdController_Statics::NewProp_WidgetBPRef = { "WidgetBPRef", nullptr, (EPropertyFlags)0x0014000000000005, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACrowdController, WidgetBPRef), Z_Construct_UClass_UUserWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_ACrowdController_Statics::NewProp_WidgetBPRef_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACrowdController_Statics::NewProp_WidgetBPRef_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACrowdController_Statics::NewProp_duration_MetaData[] = {
		{ "Category", "Behavior" },
		{ "ModuleRelativePath", "src/CrowdController.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ACrowdController_Statics::NewProp_duration = { "duration", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACrowdController, duration), METADATA_PARAMS(Z_Construct_UClass_ACrowdController_Statics::NewProp_duration_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACrowdController_Statics::NewProp_duration_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACrowdController_Statics::NewProp_agentR_MetaData[] = {
		{ "Category", "SetUp" },
		{ "ModuleRelativePath", "src/CrowdController.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ACrowdController_Statics::NewProp_agentR = { "agentR", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACrowdController, agentR), METADATA_PARAMS(Z_Construct_UClass_ACrowdController_Statics::NewProp_agentR_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACrowdController_Statics::NewProp_agentR_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACrowdController_Statics::NewProp_agentV_MetaData[] = {
		{ "Category", "SetUp" },
		{ "Comment", "// set numAgents\n" },
		{ "ModuleRelativePath", "src/CrowdController.h" },
		{ "ToolTip", "set numAgents" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ACrowdController_Statics::NewProp_agentV = { "agentV", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACrowdController, agentV), METADATA_PARAMS(Z_Construct_UClass_ACrowdController_Statics::NewProp_agentV_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACrowdController_Statics::NewProp_agentV_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACrowdController_Statics::NewProp_numAgents_MetaData[] = {
		{ "Category", "SetUp" },
		{ "ModuleRelativePath", "src/CrowdController.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ACrowdController_Statics::NewProp_numAgents = { "numAgents", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACrowdController, numAgents), METADATA_PARAMS(Z_Construct_UClass_ACrowdController_Statics::NewProp_numAgents_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACrowdController_Statics::NewProp_numAgents_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACrowdController_Statics::NewProp_numSamples_MetaData[] = {
		{ "Category", "SetUp" },
		{ "Comment", "//TArray<AAIController*> aic; //faster than getting controller each time? make sure matches up\n" },
		{ "ModuleRelativePath", "src/CrowdController.h" },
		{ "ToolTip", "TArray<AAIController*> aic; faster than getting controller each time? make sure matches up" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ACrowdController_Statics::NewProp_numSamples = { "numSamples", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACrowdController, numSamples), METADATA_PARAMS(Z_Construct_UClass_ACrowdController_Statics::NewProp_numSamples_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACrowdController_Statics::NewProp_numSamples_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACrowdController_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACrowdController_Statics::NewProp_WidgetBPRef,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACrowdController_Statics::NewProp_duration,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACrowdController_Statics::NewProp_agentR,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACrowdController_Statics::NewProp_agentV,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACrowdController_Statics::NewProp_numAgents,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACrowdController_Statics::NewProp_numSamples,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACrowdController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACrowdController>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ACrowdController_Statics::ClassParams = {
		&ACrowdController::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ACrowdController_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ACrowdController_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ACrowdController_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ACrowdController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACrowdController()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ACrowdController_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ACrowdController, 1793718582);
	template<> BIOCROWDSUE_API UClass* StaticClass<ACrowdController>()
	{
		return ACrowdController::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACrowdController(Z_Construct_UClass_ACrowdController, &ACrowdController::StaticClass, TEXT("/Script/BioCrowdsUE"), TEXT("ACrowdController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACrowdController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
