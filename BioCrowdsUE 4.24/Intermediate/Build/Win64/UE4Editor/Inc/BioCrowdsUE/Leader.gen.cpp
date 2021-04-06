// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BioCrowdsUE/src/Leader.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLeader() {}
// Cross Module References
	BIOCROWDSUE_API UEnum* Z_Construct_UEnum_BioCrowdsUE_EForm();
	UPackage* Z_Construct_UPackage__Script_BioCrowdsUE();
	BIOCROWDSUE_API UClass* Z_Construct_UClass_ALeader_NoRegister();
	BIOCROWDSUE_API UClass* Z_Construct_UClass_ALeader();
	BIOCROWDSUE_API UClass* Z_Construct_UClass_AAgent();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
// End Cross Module References
	static UEnum* EForm_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_BioCrowdsUE_EForm, Z_Construct_UPackage__Script_BioCrowdsUE(), TEXT("EForm"));
		}
		return Singleton;
	}
	template<> BIOCROWDSUE_API UEnum* StaticEnum<EForm>()
	{
		return EForm_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EForm(EForm_StaticEnum, TEXT("/Script/BioCrowdsUE"), TEXT("EForm"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_BioCrowdsUE_EForm_Hash() { return 471914912U; }
	UEnum* Z_Construct_UEnum_BioCrowdsUE_EForm()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_BioCrowdsUE();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EForm"), 0, Get_Z_Construct_UEnum_BioCrowdsUE_EForm_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EForm::EF_CLUMP", (int64)EForm::EF_CLUMP },
				{ "EForm::EF_CLUMPLINE", (int64)EForm::EF_CLUMPLINE },
				{ "EForm::EF_LINE", (int64)EForm::EF_LINE },
				{ "EForm::EF_RANDLINE", (int64)EForm::EF_RANDLINE },
				{ "EForm::EF_WIDELINE", (int64)EForm::EF_WIDELINE },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "Comment", "/**\n * \n */" },
				{ "EF_CLUMP.Comment", "/**\n * \n */" },
				{ "EF_CLUMP.DisplayName", "Clump" },
				{ "EF_CLUMP.Name", "EForm::EF_CLUMP" },
				{ "EF_CLUMPLINE.Comment", "/**\n * \n */" },
				{ "EF_CLUMPLINE.DisplayName", "ClumpLine" },
				{ "EF_CLUMPLINE.Name", "EForm::EF_CLUMPLINE" },
				{ "EF_LINE.Comment", "/**\n * \n */" },
				{ "EF_LINE.DisplayName", "Line" },
				{ "EF_LINE.Name", "EForm::EF_LINE" },
				{ "EF_RANDLINE.Comment", "/**\n * \n */" },
				{ "EF_RANDLINE.DisplayName", "RandLine" },
				{ "EF_RANDLINE.Name", "EForm::EF_RANDLINE" },
				{ "EF_WIDELINE.Comment", "/**\n * \n */" },
				{ "EF_WIDELINE.DisplayName", "WideLine" },
				{ "EF_WIDELINE.Name", "EForm::EF_WIDELINE" },
				{ "ModuleRelativePath", "src/Leader.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_BioCrowdsUE,
				nullptr,
				"EForm",
				"EForm",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	void ALeader::StaticRegisterNativesALeader()
	{
	}
	UClass* Z_Construct_UClass_ALeader_NoRegister()
	{
		return ALeader::StaticClass();
	}
	struct Z_Construct_UClass_ALeader_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_numFollowers_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_numFollowers;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_formation_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_formation_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_formation;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_points_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_points_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_points;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ALeader_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AAgent,
		(UObject* (*)())Z_Construct_UPackage__Script_BioCrowdsUE,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALeader_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "src/Leader.h" },
		{ "ModuleRelativePath", "src/Leader.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALeader_Statics::NewProp_numFollowers_MetaData[] = {
		{ "Category", "Followers" },
		{ "ModuleRelativePath", "src/Leader.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ALeader_Statics::NewProp_numFollowers = { "numFollowers", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ALeader, numFollowers), METADATA_PARAMS(Z_Construct_UClass_ALeader_Statics::NewProp_numFollowers_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ALeader_Statics::NewProp_numFollowers_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_ALeader_Statics::NewProp_formation_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALeader_Statics::NewProp_formation_MetaData[] = {
		{ "Category", "Followers" },
		{ "ModuleRelativePath", "src/Leader.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_ALeader_Statics::NewProp_formation = { "formation", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ALeader, formation), Z_Construct_UEnum_BioCrowdsUE_EForm, METADATA_PARAMS(Z_Construct_UClass_ALeader_Statics::NewProp_formation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ALeader_Statics::NewProp_formation_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_ALeader_Statics::NewProp_points_Inner = { "points", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALeader_Statics::NewProp_points_MetaData[] = {
		{ "Category", "SetUp" },
		{ "ModuleRelativePath", "src/Leader.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ALeader_Statics::NewProp_points = { "points", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ALeader, points), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_ALeader_Statics::NewProp_points_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ALeader_Statics::NewProp_points_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ALeader_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALeader_Statics::NewProp_numFollowers,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALeader_Statics::NewProp_formation_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALeader_Statics::NewProp_formation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALeader_Statics::NewProp_points_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALeader_Statics::NewProp_points,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ALeader_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ALeader>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ALeader_Statics::ClassParams = {
		&ALeader::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ALeader_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ALeader_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ALeader_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ALeader_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ALeader()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ALeader_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ALeader, 1671404744);
	template<> BIOCROWDSUE_API UClass* StaticClass<ALeader>()
	{
		return ALeader::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ALeader(Z_Construct_UClass_ALeader, &ALeader::StaticClass, TEXT("/Script/BioCrowdsUE"), TEXT("ALeader"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ALeader);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
