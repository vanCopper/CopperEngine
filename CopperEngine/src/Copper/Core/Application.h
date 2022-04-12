#pragma once

#include "Core.h"
#include "Window.h"
#include "Copper/Events/Event.h"
#include "Copper/Events/ApplicationEvent.h"

namespace CopperEngine
{
    class COPPER_API Application
    {
    public:
        Application();
        virtual ~Application();
        void Run();
        void OnEvent(Event& event);

    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;

        bool OnWindowClose(WindowCloseEvent& event);
    };

    //To be defined in CLINET.
    Application* CreateApplication();
}

