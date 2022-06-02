#pragma once

#include "Runtime/Engine.h"
#include "Editor/EngineEditor.h"
#include "Runtime/Core/Application.h"
#include "Runtime/Core/Log.h"

#ifdef COPPER_PLATFORM_WINDOWS

    extern Copper::Application* Copper::CreateApplication();

    int main(int argc, char** argv)
    {
        Copper::CopperEngine* EngineRuntime = new Copper::CopperEngine();
        EngineRuntime->Initialize();
        EngineRuntime->StartEngine();

        Copper::EngineEditor* EngineEditor = new Copper::EngineEditor();
        EngineEditor->Initialize(EngineRuntime);
        EngineEditor->Start();
        //Init Logger
        Copper::Log::Init();


        EngineEditor->Run();
        /*auto app = Copper::CreateApplication();
        app->Run();*/

        EngineEditor->ShutDown();
        EngineRuntime->ShutDownEngine();

        delete EngineRuntime;
        delete EngineEditor;
        //delete app;
    }

#endif
