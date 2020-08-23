#pragma once
#include "Honey/Core/Core.h"

#ifdef HN_PLATFORM_WINDOWS

extern Honey::Application* Honey::CreateApplication();

int main(int argc, char** argv)
{
	Honey::Log::Init();

	HN_PROFILE_BEGIN_SESSION("Startup", "HoneyProfile-Startup.json");
	auto app = Honey::CreateApplication();
	HN_PROFILE_END_SESSION();

	HN_PROFILE_BEGIN_SESSION("Runtime", "HoneyProfile-Runtime.json");
	app->Run();
	HN_PROFILE_END_SESSION();

	HN_PROFILE_BEGIN_SESSION("Startup", "HoneyProfile-Shutdown.json");
	delete app;
	HN_PROFILE_END_SESSION();
}

#endif