// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Lego : ModuleRules
{
	public Lego(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
