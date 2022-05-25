#include "CopperEngine.h"
#include "Copper/Core/EntryPoint.h"

using Layer = Copper::Layer;
using ImGuiLayer = Copper::ImGuiLayer;

class ExampleLayer : public Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		if (Copper::Input::IsKeyPressed(Copper::Key::Tab))
		{
			COPPER_LOG_TRACE("Tab key is pressed (poll).");
		}
	}

	void OnEvent(Copper::Event& event) override
	{
		if (event.GetEventType() == Copper::EventType::KeyPressed)
		{
			Copper::KeyPressedEvent& targetEvent = (Copper::KeyPressedEvent&)event;

			if (targetEvent.GetKeyCode() == Copper::Key::Tab)
			{
				COPPER_LOG_TRACE("Tab key is pressed (event).");
				COPPER_LOG_TRACE("{0}", (char)targetEvent.GetKeyCode());
			}
		}
	}
};


class Sandbox : public Copper::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new ImGuiLayer());
	}
};

Copper::Application* Copper::CreateApplication()
{
    COPPER_LOG_CORE_TRACE("Copper Engine Core Log.");
    COPPER_LOG_WARN("Client Log.");

    return new Sandbox();
}

