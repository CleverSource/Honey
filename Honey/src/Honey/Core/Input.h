#pragma once

#include "Honey/Core/Base.h"
#include "Honey/Core/KeyCodes.h"
#include "Honey/Core/MouseCodes.h"

namespace Honey {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};

}