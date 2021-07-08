#include <Honey.h>
#include <Honey/Core/EntryPoint.h>

#include "Sandbox2D.h"
#include "ExampleLayer.h"

class Sandbox : public Honey::Application
{
public:
	Sandbox(Honey::ApplicationCommandLineArgs args)
	{
		// PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	}

	~Sandbox()
	{
	}
};

Honey::Application* Honey::CreateApplication(Honey::ApplicationCommandLineArgs args)
{
	return new Sandbox(args);
}
