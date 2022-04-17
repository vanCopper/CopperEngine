#pragma once

#include "COpper/Core/Layer.h"

namespace CopperEngine
{
	class COPPER_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach() override;
		void OnDetach() override;

		void OnUpdate() override;
		void OnEvent(Event& event) override;

	private:

		float m_Time = 0.0f;
	};
}