#include "CopperPCH.h"
#include "Runtime/Core/Core.h"
#include "Runtime/Core/Log.h"
#include "EngineEditor.h"

namespace Copper
{

#define BIND_EVENT_FUNC(x) std::bind(&Application::x, this, std::placeholders::_1)

	EngineEditor* EngineEditor::s_Instance = nullptr;

	EngineEditor::EngineEditor()
	{
		COPPER_CORE_ASSERT(!s_Instance, "EngineEditor already exists!");
	}

	void EngineEditor::Initialize(CopperEngine* Engine)
	{

	}

	void EngineEditor::Start()
	{

	}

	void EngineEditor::ShutDown()
	{

	}

	void EngineEditor::Run()
	{

	}

	void EngineEditor::Tick()
	{

	}

	bool EngineEditor::OnWindowClose(WindowCloseEvent& event)
	{
		return false;
	}
}

