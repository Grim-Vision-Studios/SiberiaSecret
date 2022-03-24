// Copyright Epic Game, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MH_GrappleHook : ModuleRules
{
    public MH_GrappleHook(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { 
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "HeadMountedDisplay"
        });
    }
}