#pragma once
#include "Honey/Core/Base.h"
#include "Honey/Core/Application.h"

#ifdef HN_PLATFORM_WINDOWS

extern Honey::Application* Honey::CreateApplication(ApplicationCommandLineArgs args);

int main(int argc, char** argv)
{
	Honey::Log::Init();

	HN_PROFILE_BEGIN_SESSION("Startup", "HoneyProfile-Startup.json");
	auto app = Honey::CreateApplication({ argc, argv });
	HN_PROFILE_END_SESSION();

	HN_PROFILE_BEGIN_SESSION("Runtime", "HoneyProfile-Runtime.json");
	app->Run();
	HN_PROFILE_END_SESSION();

	HN_PROFILE_BEGIN_SESSION("Shutdown", "HoneyProfile-Shutdown.json");
	delete app;
	HN_PROFILE_END_SESSION();
}

#endif
