#pragma once

#ifdef COPPER_PLATFORM_WINDOWS
    extern CopperEngine::Application* CopperEngine::CreateApplication();

    int main(int argc, char** argv)
    {
        printf("Copper Engine\n");
        auto app = CopperEngine::CreateApplication();
        app->Run();
        delete app;
    }
#endif
