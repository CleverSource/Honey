#pragma once

#include "Honey/Core/Layer.h"

#include "Honey/Events/ApplicationEvent.h"
#include "Honey/Events/KeyEvent.h"
#include "Honey/Events/MouseEvent.h"

namespace Honey {

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};

}