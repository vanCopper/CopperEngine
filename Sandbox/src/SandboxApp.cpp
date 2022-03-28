#include <CopperEngine.h>

class Sandbox : public CopperEngine::Application
{

};

CopperEngine::Application* CopperEngine::CreateApplication()
{
    return new Sandbox();
}