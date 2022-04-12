#include "CopperPCH.h"
#include "Application.h"

#include "Copper/Events/ApplicationEvent.h"
#include "Copper/Core/Log.h"

#include <GLFW/glfw3.h>

namespace CopperEngine
{

#define BIND_EVENT_FUNC(x) std::bind(&Application::x, this, std::placeholders::_1)
    Application::Application()
    {
        m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FUNC(OnEvent));
    }

	Application::~Application()
	{
	}

    void Application::Run()
    {
		while (m_Running)
		{
			glClearColor(0.17, 0.17, 0.18, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
    }

	void Application::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FUNC(OnWindowClose));

		COPPER_LOG_CORE_TRACE("{0}", event);
	}

	bool Application::OnWindowClose(WindowCloseEvent& event)
	{
		m_Running = false;
		return true;
	}
}