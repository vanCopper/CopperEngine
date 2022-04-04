#pragma once

#include "Core.h"

namespace CopperEngine
{
    class COPPER_API Application
    {
    public:
        void Run();
    };

    //To be defined in CLINET.
    Application* CreateApplication();
}

