// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SiberiaSecret/Public/PlayerCharacter/CppHUD.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCppHUD() {}
// Cross Module References
	SIBERIASECRET_API UClass* Z_Construct_UClass_ACppHUD_NoRegister();
	SIBERIASECRET_API UClass* Z_Construct_UClass_ACppHUD();
	ENGINE_API UClass* Z_Construct_UClass_AHUD();
	UPackage* Z_Construct_UPackage__Script_SiberiaSecret();
// End Cross Module References
	void ACppHUD::StaticRegisterNativesACppHUD()
	{
	}
	UClass* Z_Construct_UClass_ACppHUD_NoRegister()
	{
		return ACppHUD::StaticClass();
	}
	struct Z_Construct_UClass_ACppHUD_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACppHUD_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AHUD,
		(UObject* (*)())Z_Construct_UPackage__Script_SiberiaSecret,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACppHUD_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Rendering Actor Input Replication" },
		{ "IncludePath", "PlayerCharacter/CppHUD.h" },
		{ "ModuleRelativePath", "Public/PlayerCharacter/CppHUD.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACppHUD_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACppHUD>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ACppHUD_Statics::ClassParams = {
		&ACppHUD::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_ACppHUD_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ACppHUD_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACppHUD()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ACppHUD_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ACppHUD, 1999353185);
	template<> SIBERIASECRET_API UClass* StaticClass<ACppHUD>()
	{
		return ACppHUD::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACppHUD(Z_Construct_UClass_ACppHUD, &ACppHUD::StaticClass, TEXT("/Script/SiberiaSecret"), TEXT("ACppHUD"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACppHUD);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
