#pragma once

#include "Runtime/Core/Core.h"

namespace Copper
{
	class COPPER_API CopperEngine
	{
	public:
		void Initialize();
		void StartEngine();
		void ShutDownEngine();
	private:
		void GameTick();
		void RendererTick();
	};
}
