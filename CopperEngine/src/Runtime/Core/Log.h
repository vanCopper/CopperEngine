#pragma once

//#include "memory.h"
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Copper
{
    class COPPER_API Log
    {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return CoreLogger;}
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return ClientLogger;}

    private:
        static std::shared_ptr<spdlog::logger> CoreLogger;
        static std::shared_ptr<spdlog::logger> ClientLogger;
    };
}

//core log for engine.
#define COPPER_LOG_CORE_TRACE(...)          ::Copper::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define COPPER_LOG_CORE_INFO(...)           ::Copper::Log::GetCoreLogger()->info(__VA_ARGS__)
#define COPPER_LOG_CORE_WARN(...)           ::Copper::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define COPPER_LOG_CORE_ERROR(...)          ::Copper::Log::GetCoreLogger()->error(__VA_ARGS__)
#define COPPER_LOG_CORE_FATAL(...)          ::Copper::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//log for clients.
#define COPPER_LOG_INFO(...)           ::Copper::Log::GetClientLogger()->info(__VA_ARGS__)
#define COPPER_LOG_TRACE(...)          ::Copper::Log::GetClientLogger()->trace(__VA_ARGS__)
#define COPPER_LOG_WARN(...)           ::Copper::Log::GetClientLogger()->warn(__VA_ARGS__)
#define COPPER_LOG_ERROR(...)          ::Copper::Log::GetClientLogger()->error(__VA_ARGS__)
#define COPPER_LOG_FATAL(...)          ::Copper::Log::GetClientLogger()->fatal(__VA_ARGS__)
