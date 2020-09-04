#pragma once

#include <glm/glm.hpp>

#include "Honey/Core/KeyCodes.h"
#include "Honey/Core/MouseCodes.h"

namespace Honey {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};

}
