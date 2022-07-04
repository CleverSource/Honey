#include <Honey.h>
#include <Honey/Core/EntryPoint.h>

#include "Sandbox2D.h"
#include "ExampleLayer.h"

class Sandbox : public Honey::Application
{
public:
	Sandbox(const Honey::ApplicationSpecification& specification)
		: Honey::Application(specification)
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
	ApplicationSpecification spec;
	spec.Name = "Sandbox";
	spec.WorkingDirectory = "../Honeynut";
	spec.CommandLineArgs = args;

	return new Sandbox(spec);
}
