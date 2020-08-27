#pragma once

#include "Honey/Core/Base.h"

#include "Honey/Core/Window.h"
#include "Honey/Core/LayerStack.h"
#include "Honey/Events/Event.h"
#include "Honey/Events/ApplicationEvent.h"

#include "Honey/Core/Timestep.h"

#include "Honey/ImGui/ImGuiLayer.h"

int main(int argc, char** argv);

namespace Honey {

	class Application
	{
	public:
		Application();
		virtual ~Application();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		Window& GetWindow() { return *m_Window; }

		void Close();

		static Application& Get() { return *s_Instance; }
	private:
		void Run();
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
		friend int ::main(int argc, char** argv);
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}