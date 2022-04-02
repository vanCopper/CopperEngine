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

#define BIT(x)  (1 << x)