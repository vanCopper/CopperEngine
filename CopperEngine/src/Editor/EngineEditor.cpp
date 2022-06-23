#include "CopperPCH.h"
#include "Runtime/Core/Core.h"
#include "Runtime/Core/Log.h"
#include "Editor/ImGui/ImGuiLayer.h"
#include <glad/glad.h>

#include "EngineEditor.h"

namespace Copper
{

#define BIND_EVENT_FUNC(x) std::bind(&EngineEditor::x, this, std::placeholders::_1)

	EngineEditor* EngineEditor::s_Instance = nullptr;

	EngineEditor::EngineEditor()
	{
		COPPER_CORE_ASSERT(!s_Instance, "EngineEditor already exists!");

		s_Instance = this;
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FUNC(OnEvent));
	}

	void EngineEditor::Initialize(CopperEngine* Engine)
	{
		m_EditorUILayer = std::shared_ptr<ImGuiLayer>(new ImGuiLayer());
	}

	void EngineEditor::Start()
	{
		//m_LayerStack.PushOverlay(m_EditorUILayer.get());
		m_EditorUILayer->OnAttach();
	}

	void EngineEditor::ShutDown()
	{

	}

	void EngineEditor::Run()
	{
		while (m_Running)
		{
			glClearColor(0.17f, 0.17f, 0.18f, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			if (m_EditorUILayer)
			{
				m_EditorUILayer->OnUpdate();
			}
			
			m_Window->OnUpdate();
		}
	}

	void EngineEditor::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FUNC(OnWindowClose));

		if (m_EditorUILayer)
		{
			m_EditorUILayer->OnEvent(event);
		}

		//for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		//{
		//	(*--it)->OnEvent(event);
		//	if (event.Handled)
		//	{
		//		break;
		//	}
		//}
	}

	void EngineEditor::Tick()
	{

	}

	bool EngineEditor::OnWindowClose(WindowCloseEvent& event)
	{
		m_Running = false;
		return true;
	}
}

