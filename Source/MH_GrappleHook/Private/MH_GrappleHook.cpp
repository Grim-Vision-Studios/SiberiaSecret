#include <MH_GrappleHook/Public/MH_GrappleHook.h>

#define LOCTEXT_NAMESPACE "MH_GrappleHookModule"

void FMH_GrappleHookModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FMH_GrappleHookModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FMH_GrappleHookModule, MH_GrappleHook)