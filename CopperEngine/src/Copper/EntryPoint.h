#pragma once

#ifdef COPPER_PLATFORM_WINDOWS

    extern CopperEngine::Application* CopperEngine::CreateApplication();

    int main(int argc, char** argv)
    {
        //Init Logger
        CopperEngine::Log::Init();

        auto app = CopperEngine::CreateApplication();
        app->Run();
        delete app;
    }

#endif
