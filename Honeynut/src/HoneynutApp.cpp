#include <Honey.h>
#include <Honey/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Honey {

	class Honeynut : public Application
	{
	public:
		Honeynut(ApplicationSpecification spec)
			: Application(spec)
		{
			PushLayer(new EditorLayer());
		}

		~Honeynut()
		{
		}
	};

	Application* CreateApplication(ApplicationCommandLineArgs args)
	{
		ApplicationSpecification spec;
		spec.Name = "Honeynut";
		spec.CommandLineArgs = args;

		return new Honeynut(spec);
	}

}
