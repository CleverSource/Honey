#pragma once

#include "Honey/Core/Base.h"
#include "Honey/Core/Log.h"

#ifdef HN_ENABLE_ASSERTS

	namespace Honey::Assert
	{
		// Returns the simple file name rather than full path
		constexpr const char* CurrentFileName(const char* path) {
			const char* file = path;
			while (*path)
			{
				if (*path == '/' || *path == '\\')
					file = ++path;
				else
					path++;
			}
			return file;
		}
	}

	// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
	// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
	#define HN_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { HN##type##ERROR(msg, __VA_ARGS__); HN_DEBUGBREAK(); } }
	#define HN_INTERNAL_ASSERT_WITH_MSG(type, check, ...) HN_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
	#define HN_INTERNAL_ASSERT_NO_MSG(type, check) HN_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", HN_STRINGIFY_MACRO(check), ::Honey::Assert::CurrentFileName(__FILE__), __LINE__)

	#define HN_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
	#define HN_INTERNAL_ASSERT_GET_MACRO(...) HN_EXPAND_MACRO( HN_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, HN_INTERNAL_ASSERT_WITH_MSG, HN_INTERNAL_ASSERT_NO_MSG) )

	// Currently accepts at least the condition and one additional parameter (the message) being optional
	#define HN_ASSERT(...) HN_EXPAND_MACRO( HN_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
	#define HN_CORE_ASSERT(...) HN_EXPAND_MACRO( HN_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
	#define HN_ASSERT(...)
	#define HN_CORE_ASSERT(...)
#endif