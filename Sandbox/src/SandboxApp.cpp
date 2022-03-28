#include <CopperEngine.h>

class Sandbox : public CopperEngine::Application
{

};

CopperEngine::Application* CopperEngine::CreateApplication()
{
    COPPER_LOG_CORE_TRACE("Copper Engine Core Log.");
    COPPER_LOG_WARN("Client Log.");
    return new Sandbox();
}