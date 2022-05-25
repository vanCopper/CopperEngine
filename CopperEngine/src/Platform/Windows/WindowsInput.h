#pragma once

#include "Copper/Core/Input.h"

namespace Copper
{
	class WindowsInput : public Input
	{

	protected:
		virtual bool IsKeyPressedImpl(int keycode) override;


		virtual bool IsMouseButtonPressedImpl(int button) override;


		virtual std::pair<float, float> GetMousePositionImpl() override;


		virtual float GetMouseXImpl() override;


		virtual float GetMouseYImpl() override;

	};
}
