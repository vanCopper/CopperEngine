#include "Application.h"

#include "Copper/Events/ApplicationEvent.h"
#include "Copper/Core/Log.h"

namespace CopperEngine
{
    void Application::Run()
    {
        WindowResizeEvent WResizeEvent(1280, 720);
        COPPER_LOG_TRACE(WResizeEvent);

        while (true)
        {
            //TODO:
        }
    }
}