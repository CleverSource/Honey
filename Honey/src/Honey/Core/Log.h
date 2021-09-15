#pragma once

#include "glm/gtx/string_cast.hpp"

#include "Honey/Core/Base.h"

// This ignores all warnings raised inside External headers
#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)

namespace Honey {

	class Log
	{
	public:
		static void Init();

		static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};

}

template<typename OStream, glm::length_t L, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, const glm::vec<L, T, Q>& vector)
{
	return os << glm::to_string(vector);
}

template<typename OStream, glm::length_t C, glm::length_t R, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, const glm::mat<C, R, T, Q>& matrix)
{
	return os << glm::to_string(matrix);
}

template<typename OStream, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, glm::qua<T, Q> quaternion)
{
	return os << glm::to_string(quaternion);
}

// Core log macros
#define HN_CORE_TRACE(...)    ::Honey::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HN_CORE_INFO(...)     ::Honey::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HN_CORE_WARN(...)     ::Honey::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HN_CORE_ERROR(...)    ::Honey::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HN_CORE_CRITICAL(...) ::Honey::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define HN_TRACE(...)         ::Honey::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HN_INFO(...)          ::Honey::Log::GetClientLogger()->info(__VA_ARGS__)
#define HN_WARN(...)          ::Honey::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HN_ERROR(...)         ::Honey::Log::GetClientLogger()->error(__VA_ARGS__)
#define HN_CRITICAL(...)      ::Honey::Log::GetClientLogger()->critical(__VA_ARGS__)
