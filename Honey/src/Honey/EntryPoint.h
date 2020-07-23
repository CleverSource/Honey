#pragma once

#ifdef HN_PLATFORM_WINDOWS

extern Honey::Application* Honey::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Honey::CreateApplication();
	app->Run();
	delete app;
}

#endif