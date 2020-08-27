#include <Honey.h>
#include <Honey/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Honey {

	class HoneyEditor : public Application
	{
	public:
		HoneyEditor()
			: Application("Honey Editor")
		{
			PushLayer(new EditorLayer());
		}

		~HoneyEditor()
		{
		}
	};

	Application* CreateApplication()
	{
		return new HoneyEditor();
	}

}