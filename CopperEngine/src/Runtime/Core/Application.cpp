#include "CopperPCH.h"
#include "Application.h"

#include "Runtime/Events/ApplicationEvent.h"
#include "Runtime/Core/Log.h"

#include <glad/glad.h>

namespace Copper
{

#define BIND_EVENT_FUNC(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::s_Instance = nullptr;

    Application::Application()
    {
		COPPER_CORE_ASSERT(!s_Instance, "Application already exists!");

		s_Instance = this;
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
			glClearColor(0.17f, 0.17f, 0.18f, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack)
			{
				layer->OnUpdate();
			}

			m_Window->OnUpdate();
		}
    }

	void Application::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FUNC(OnWindowClose));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(event);
			if (event.Handled)
			{
				break;
			}
		}

		//COPPER_LOG_CORE_TRACE("{0}", event);
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

	bool Application::OnWindowClose(WindowCloseEvent& event)
	{
		m_Running = false;
		return true;
	}
}