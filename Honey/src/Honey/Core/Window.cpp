#include "hnpch.h"
#include "Honey/Core/Window.h"

#ifdef HN_PLATFORM_WINDOWS
	#include "Platform/Windows/WindowsWindow.h"
#endif

namespace Honey {

	Scope<Window> Window::Create(const WindowProps& props)
	{
	#ifdef HN_PLATFORM_WINDOWS
		return CreateScope<WindowsWindow>(props);
	#else
		HN_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
	#endif
	}

}