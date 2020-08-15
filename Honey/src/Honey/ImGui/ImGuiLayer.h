#pragma once

#include "Honey/Layer.h"

#include "Honey/Events/ApplicationEvent.h"
#include "Honey/Events/KeyEvent.h"
#include "Honey/Events/MouseEvent.h"

namespace Honey {

	class HONEY_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};

}