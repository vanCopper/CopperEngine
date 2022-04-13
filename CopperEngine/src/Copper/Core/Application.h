#pragma once

#include "Core.h"
#include "Window.h"
#include "Copper/Events/Event.h"
#include "Copper/Events/ApplicationEvent.h"
#include "Copper/Core/LayerStack.h"

namespace CopperEngine
{
    class COPPER_API Application
    {
    public:
        Application();
        virtual ~Application();
        void Run();
        void OnEvent(Event& event);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

    private:
        std::unique_ptr<Window> m_Window;
        LayerStack m_LayerStack;
        bool m_Running = true;

        bool OnWindowClose(WindowCloseEvent& event);
    };

    //To be defined in CLINET.
    Application* CreateApplication();
}

