// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SiberiaSecret/Public/PlayerCharacter/CppGamemode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCppGamemode() {}
// Cross Module References
	SIBERIASECRET_API UClass* Z_Construct_UClass_ACppGamemode_NoRegister();
	SIBERIASECRET_API UClass* Z_Construct_UClass_ACppGamemode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_SiberiaSecret();
// End Cross Module References
	void ACppGamemode::StaticRegisterNativesACppGamemode()
	{
	}
	UClass* Z_Construct_UClass_ACppGamemode_NoRegister()
	{
		return ACppGamemode::StaticClass();
	}
	struct Z_Construct_UClass_ACppGamemode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACppGamemode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_SiberiaSecret,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACppGamemode_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "PlayerCharacter/CppGamemode.h" },
		{ "ModuleRelativePath", "Public/PlayerCharacter/CppGamemode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACppGamemode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACppGamemode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ACppGamemode_Statics::ClassParams = {
		&ACppGamemode::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_ACppGamemode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ACppGamemode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACppGamemode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ACppGamemode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ACppGamemode, 236192096);
	template<> SIBERIASECRET_API UClass* StaticClass<ACppGamemode>()
	{
		return ACppGamemode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACppGamemode(Z_Construct_UClass_ACppGamemode, &ACppGamemode::StaticClass, TEXT("/Script/SiberiaSecret"), TEXT("ACppGamemode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACppGamemode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
