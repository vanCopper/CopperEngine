#pragma once

#ifdef COPPER_PLATFORM_WINDOWS

    extern Copper::Application* Copper::CreateApplication();

    int main(int argc, char** argv)
    {
        //Init Logger
        Copper::Log::Init();

        auto app = Copper::CreateApplication();
        app->Run();
        delete app;
    }

#endif
