#pragma once

#ifdef HN_PLATFORM_WINDOWS
	#ifdef HN_BUILD_DLL
		#define HONEY_API __declspec(dllexport)
	#else
		#define HONEY_API __declspec(dllimport)
	#endif
#else
	#error Honey only supports Windows!
#endif

#define BIT(x) (1 << x)