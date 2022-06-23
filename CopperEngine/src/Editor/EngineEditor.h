#pragma once

#include "Runtime/Core/Core.h"
#include "Runtime/Engine.h"
#include "Runtime/Core/LayerStack.h"
#include "Runtime/Core/Window.h"
#include "Runtime/Events/Event.h"
#include "Runtime/Events/ApplicationEvent.h"

namespace Copper
{
	class COPPER_API EngineEditor
	{
	public:
		EngineEditor();

		void Initialize(CopperEngine* Engine);
		
		void Start();
		void ShutDown();
		void Run();
		void OnEvent(Event& event);

		Window& GetWindow() { return *m_Window; }

		static EngineEditor& Get() { return *s_Instance; }

	private:
		void Tick();
		bool OnWindowClose(WindowCloseEvent& event);

	private:
		std::unique_ptr<Window> m_Window;
		LayerStack m_LayerStack;
		bool m_Running = true;
		std::shared_ptr<Layer> m_EditorUILayer;

	private:
		static EngineEditor* s_Instance;
	};
}