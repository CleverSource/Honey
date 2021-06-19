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
		virtual void OnEvent(Event& e) override;

		void Begin();
		void End();

		void BlockEvents(bool block) { m_BlockEvents = block; }

		void SetDarkThemeColors();
	private:
		bool m_BlockEvents = true;
	};

}
