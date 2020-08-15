#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Honey {

	class HONEY_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define HN_CORE_TRACE(...)    ::Honey::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HN_CORE_INFO(...)     ::Honey::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HN_CORE_WARN(...)     ::Honey::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HN_CORE_ERROR(...)    ::Honey::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HN_CORE_FATAL(...)    ::Honey::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define HN_TRACE(...)         ::Honey::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HN_INFO(...)          ::Honey::Log::GetClientLogger()->info(__VA_ARGS__)
#define HN_WARN(...)          ::Honey::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HN_ERROR(...)         ::Honey::Log::GetClientLogger()->error(__VA_ARGS__)
#define HN_FATAL(...)         ::Honey::Log::GetClientLogger()->critical(__VA_ARGS__)