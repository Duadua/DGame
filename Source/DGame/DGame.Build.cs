using UnrealBuildTool;

public class DGame : ModuleRules
{
	public DGame(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(
            new string[] {
                "Core",
                "CoreUObject",
                "Engine",
                "InputCore",
            });

        PrivateDependencyModuleNames.AddRange(
            new string[] {
                //"OnlineSubsystemNull",
            });

        PrivateIncludePaths.AddRange(
            new string[] {
                "DGame/Private",
                "DGame/Private/Level",
                "DGame/Private/Player",
                "DGame/Private/Player/Anim_Notify",
            }
        );

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}
