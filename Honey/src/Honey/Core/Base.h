#pragma once

#include <memory>

#include "Honey/Core/PlatformDetection.h"

#ifdef HN_DEBUG
	#if defined(HN_PLATFORM_WINDOWS)
		#define HN_DEBUGBREAK() __debugbreak()
	#elif defined(HN_PLATFORM_LINUX)
		#include <signal.h>
		#define HN_DEBUGBREAK() raise(SIGTRAP)
	#else
		#error "Platform doesn't support debugbreak yet!"
	#endif
	#define HN_ENABLE_ASSERTS
#else
	#define HN_DEBUGBREAK()
#endif

// TODO: Make this macro able to take in no arguments except condition
#ifdef HN_ENABLE_ASSERTS
	#define HN_ASSERT(x, ...) { if(!(x)) { HN_ERROR("Assertion Failed: {0}", __VA_ARGS__); HN_DEBUGBREAK(); } }
	#define HN_CORE_ASSERT(x, ...) { if(!(x)) { HN_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); HN_DEBUGBREAK(); } }
#else
	#define HN_ASSERT(x, ...)
	#define HN_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define HN_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace Honey {

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}
