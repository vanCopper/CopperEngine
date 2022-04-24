#pragma once

#ifdef COPPER_PLATFORM_WINDOWS
    #ifdef COPPER_BUILD_DLL
        #define COPPER_API __declspec(dllexport)
    #else
        #define COPPER_API __declspec(dllimport)
    #endif // COPPER_BUILD_DLL
#else
    #error CopperEngine only supports Windows!
#endif // COPPER_PLATFORM_WINDOWS

#ifdef COPPER_DEBUG
    #define COPPER_ENABLE_ASSERTS 
#endif // COPPER_DEBUG


#ifdef COPPER_ENABLE_ASSERTS
    #define COPPER_ASSERT(x, ...) { if(!(x)) { COPPER_LOG_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();} }
    #define COPPER_CORE_ASSERT(x, ...) { if(!(x)) { COPPER_LOG_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
    #define COPPER_CORE_ASSERT(...)
    #define COPPER_ASSERT(...)
#endif

#define BIT(x)  (1 << x)

#define COPPER_BIND_EVENT_FUNC(func) std::bind(&func, this, std::placeholders::_1)

