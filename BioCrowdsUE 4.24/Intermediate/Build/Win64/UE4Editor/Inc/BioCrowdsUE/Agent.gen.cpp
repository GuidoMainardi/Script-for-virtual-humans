// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BioCrowdsUE/src/Agent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAgent() {}
// Cross Module References
	BIOCROWDSUE_API UClass* Z_Construct_UClass_AAgent_NoRegister();
	BIOCROWDSUE_API UClass* Z_Construct_UClass_AAgent();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_BioCrowdsUE();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	INPUTCORE_API UScriptStruct* Z_Construct_UScriptStruct_FKey();
	UMG_API UClass* Z_Construct_UClass_UButton_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(AAgent::exectoggleGoal)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->toggleGoal();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AAgent::execOnSelected)
	{
		P_GET_OBJECT(AActor,Z_Param_TouchedActor);
		P_GET_STRUCT(FKey,Z_Param_ButtonPressed);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnSelected(Z_Param_TouchedActor,Z_Param_ButtonPressed);
		P_NATIVE_END;
	}
	void AAgent::StaticRegisterNativesAAgent()
	{
		UClass* Class = AAgent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnSelected", &AAgent::execOnSelected },
			{ "toggleGoal", &AAgent::exectoggleGoal },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AAgent_OnSelected_Statics
	{
		struct Agent_eventOnSelected_Parms
		{
			AActor* TouchedActor;
			FKey ButtonPressed;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_TouchedActor;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ButtonPressed;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AAgent_OnSelected_Statics::NewProp_TouchedActor = { "TouchedActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Agent_eventOnSelected_Parms, TouchedActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AAgent_OnSelected_Statics::NewProp_ButtonPressed = { "ButtonPressed", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Agent_eventOnSelected_Parms, ButtonPressed), Z_Construct_UScriptStruct_FKey, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AAgent_OnSelected_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AAgent_OnSelected_Statics::NewProp_TouchedActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AAgent_OnSelected_Statics::NewProp_ButtonPressed,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AAgent_OnSelected_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "src/Agent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AAgent_OnSelected_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AAgent, nullptr, "OnSelected", nullptr, nullptr, sizeof(Agent_eventOnSelected_Parms), Z_Construct_UFunction_AAgent_OnSelected_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AAgent_OnSelected_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AAgent_OnSelected_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AAgent_OnSelected_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AAgent_OnSelected()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AAgent_OnSelected_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AAgent_toggleGoal_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AAgent_toggleGoal_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "src/Agent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AAgent_toggleGoal_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AAgent, nullptr, "toggleGoal", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AAgent_toggleGoal_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AAgent_toggleGoal_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AAgent_toggleGoal()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AAgent_toggleGoal_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AAgent_NoRegister()
	{
		return AAgent::StaticClass();
	}
	struct Z_Construct_UClass_AAgent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ticks_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_ticks;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_duration_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_duration;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ShowGoal_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ShowGoal;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AAgent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_BioCrowdsUE,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AAgent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AAgent_OnSelected, "OnSelected" }, // 3324652593
		{ &Z_Construct_UFunction_AAgent_toggleGoal, "toggleGoal" }, // 1045758645
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAgent_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "src/Agent.h" },
		{ "ModuleRelativePath", "src/Agent.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAgent_Statics::NewProp_ticks_MetaData[] = {
		{ "Category", "Behavior" },
		{ "ModuleRelativePath", "src/Agent.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AAgent_Statics::NewProp_ticks = { "ticks", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAgent, ticks), METADATA_PARAMS(Z_Construct_UClass_AAgent_Statics::NewProp_ticks_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAgent_Statics::NewProp_ticks_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAgent_Statics::NewProp_duration_MetaData[] = {
		{ "Category", "Behavior" },
		{ "ModuleRelativePath", "src/Agent.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AAgent_Statics::NewProp_duration = { "duration", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAgent, duration), METADATA_PARAMS(Z_Construct_UClass_AAgent_Statics::NewProp_duration_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAgent_Statics::NewProp_duration_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAgent_Statics::NewProp_ShowGoal_MetaData[] = {
		{ "AgentMenu", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "src/Agent.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAgent_Statics::NewProp_ShowGoal = { "ShowGoal", nullptr, (EPropertyFlags)0x0010000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAgent, ShowGoal), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AAgent_Statics::NewProp_ShowGoal_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAgent_Statics::NewProp_ShowGoal_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AAgent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAgent_Statics::NewProp_ticks,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAgent_Statics::NewProp_duration,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAgent_Statics::NewProp_ShowGoal,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AAgent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AAgent>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AAgent_Statics::ClassParams = {
		&AAgent::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AAgent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AAgent_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AAgent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AAgent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AAgent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AAgent_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AAgent, 2077435288);
	template<> BIOCROWDSUE_API UClass* StaticClass<AAgent>()
	{
		return AAgent::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AAgent(Z_Construct_UClass_AAgent, &AAgent::StaticClass, TEXT("/Script/BioCrowdsUE"), TEXT("AAgent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AAgent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
