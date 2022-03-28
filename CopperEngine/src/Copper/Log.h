#pragma once

//#include "memory.h"
#include "Core.h"
#include "spdlog/spdlog.h"

namespace CopperEngine
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
#define COPPER_LOG_CORE_TRACE(...)          CopperEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define COPPER_LOG_CORE_INFO(...)           CopperEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define COPPER_LOG_CORE_WARN(...)           CopperEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define COPPER_LOG_CORE_ERROR(...)          CopperEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define COPPER_LOG_CORE_FATAL(...)          CopperEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//log for clients.
#define COPPER_LOG_INFO(...)           CopperEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define COPPER_LOG_TRACE(...)          CopperEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define COPPER_LOG_WARN(...)           CopperEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define COPPER_LOG_ERROR(...)          CopperEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define COPPER_LOG_FATAL(...)          CopperEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)
