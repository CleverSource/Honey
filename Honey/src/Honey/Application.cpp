#include "hnpch.h"
#include "Application.h"

#include "Honey/Events/ApplicationEvent.h"
#include "Honey/Log.h"

namespace Honey {

	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			HN_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			HN_TRACE(e);
		}

		while (true);
	}

}