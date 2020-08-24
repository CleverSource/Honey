#include "hnpch.h"
#include "Honey/Core/Input.h"

#ifdef HN_PLATFORM_WINDOWS
	#include "Platform/Windows/WindowsInput.h"
#endif

namespace Honey {

	Scope<Input> Input::s_Instance = Input::Create();

	Scope<Input> Input::Create()
	{
	#ifdef HN_PLATFORM_WINDOWS
		return CreateScope<WindowsInput>();
	#else
		HN_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
	#endif
	}

}