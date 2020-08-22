#pragma once

#include <memory>

#ifdef HN_PLATFORM_WINDOWS
#if HN_DYNAMIC_LINK
	#ifdef HN_BUILD_DLL
		#define HONEY_API __declspec(dllexport)
	#else
		#define HONEY_API __declspec(dllimport)
	#endif
#else
	#define HONEY_API
#endif
#else
	#error Honey only supports Windows!
#endif

#ifdef HN_DEBUG
	#define HN_ENABLE_ASSERTS
#endif

#ifdef HN_ENABLE_ASSERTS
	#define HN_ASSERT(x, ...) { if(!(x)) { HN_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define HN_CORE_ASSERT(x, ...) { if(!(x)) { HN_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define HN_ASSERT(x, ...)
	#define HN_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define HN_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace Honey {

	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T>
	using Ref = std::shared_ptr<T>;

}