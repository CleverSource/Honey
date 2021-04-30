#include <Honey.h>
#include <Honey/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Honey {

	class Honeynut : public Application
	{
	public:
		Honeynut(ApplicationCommandLineArgs args)
			: Application("Honeynut", args)
		{
			PushLayer(new EditorLayer());
		}

		~Honeynut()
		{
		}
	};

	Application* CreateApplication(ApplicationCommandLineArgs args)
	{
		return new Honeynut(args);
	}

}
