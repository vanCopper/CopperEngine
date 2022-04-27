#include "CopperEngine.h"
#include "Copper/Core/EntryPoint.h"

using Layer = CopperEngine::Layer;
using ImGuiLayer = CopperEngine::ImGuiLayer;

class ExampleLayer : public Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		if (CopperEngine::Input::IsKeyPressed(CopperEngine::Key::Tab))
		{
			COPPER_LOG_TRACE("Tab key is pressed (poll).");
		}
	}

	void OnEvent(CopperEngine::Event& event) override
	{
		if (event.GetEventType() == CopperEngine::EventType::KeyPressed)
		{
			CopperEngine::KeyPressedEvent& targetEvent = (CopperEngine::KeyPressedEvent&)event;

			if (targetEvent.GetKeyCode() == CopperEngine::Key::Tab)
			{
				COPPER_LOG_TRACE("Tab key is pressed (event).");
				COPPER_LOG_TRACE("{0}", (char)targetEvent.GetKeyCode());
			}
		}
	}
};


class Sandbox : public CopperEngine::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new ImGuiLayer());
	}
};

CopperEngine::Application* CopperEngine::CreateApplication()
{
    COPPER_LOG_CORE_TRACE("Copper Engine Core Log.");
    COPPER_LOG_WARN("Client Log.");

    return new Sandbox();
}

