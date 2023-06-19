#pragma once

#include "Honey/Core/PlatformDetection.h"

#include <memory>

#if defined(HN_PLATFORM_WINDOWS)
	#define HN_DEBUGBREAK() __debugbreak()
#elif defined(HN_PLATFORM_LINUX)
	#include <signal.h>
	#define HN_DEBUGBREAK() raise(SIGTRAP)
#else
	#error "Platform doesn't support debugbreak yet!"
#endif

#ifdef HN_DEBUG
	#define HN_ENABLE_ASSERTS
#endif

#ifndef HN_DIST
	#define HN_ENABLE_VERIFY
#endif

#define HN_EXPAND_MACRO(x) x
#define HN_STRINGIFY_MACRO(x) #x

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

#include "Honey/Core/Log.h"
#include "Honey/Core/Assert.h"
