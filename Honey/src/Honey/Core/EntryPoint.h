#pragma once

#ifdef HN_PLATFORM_WINDOWS

extern Honey::Application* Honey::CreateApplication();

int main(int argc, char** argv)
{
	Honey::Log::Init();
	HN_CORE_WARN("Initialized Log!");
	int a = 5;
	HN_INFO("Hello! Var={0}", a);

	auto app = Honey::CreateApplication();
	app->Run();
	delete app;
}

#endif