#include "CopperEngine.h"
#include "Copper/Core/EntryPoint.h"

class ExampleLayer : public CopperEngine::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		COPPER_LOG_INFO("ExampleLayer::Update");
	}

	void OnEvent(CopperEngine::Event& event) override
	{
		COPPER_LOG_TRACE("{0}", event);
	}
};


class Sandbox : public CopperEngine::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}
};

CopperEngine::Application* CopperEngine::CreateApplication()
{
    COPPER_LOG_CORE_TRACE("Copper Engine Core Log.");
    COPPER_LOG_WARN("Client Log.");

    return new Sandbox();
}

