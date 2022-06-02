#pragma once

#include "Runtime/Core/Core.h"
#include "Runtime/Engine.h"

namespace Copper
{
	class COPPER_API EngineEditor
	{
	public:
		void Initialize(CopperEngine* Engine);
		
		void Start();
		void ShutDown();

	private:
		void Tick();
	};
}