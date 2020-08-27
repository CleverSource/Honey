#include <Honey.h>
#include <Honey/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Honey {

	class Honeynut : public Application
	{
	public:
		Honeynut()
			: Application("Honeynut")
		{
			PushLayer(new EditorLayer());
		}

		~Honeynut()
		{
		}
	};

	Application* CreateApplication()
	{
		return new Honeynut();
	}

}