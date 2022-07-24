#pragma once

#include "Core.h"
#include "Window.h"
#include "Runtime/Events/Event.h"
#include "Runtime/Events/ApplicationEvent.h"
#include "Runtime/Core/LayerStack.h"

namespace Copper
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

        Window& GetWindow() { return *m_Window; }

        static Application& Get() { return *s_Instance; }

    private:
        std::unique_ptr<Window> m_Window;
        LayerStack m_LayerStack;
        bool m_Running = true;

        bool OnWindowClose(WindowCloseEvent& event);

    private:
        static Application* s_Instance;
    };

    //To be defined in CLINET.
    Application* CreateApplication();
}

