#include <Honey.h>

class ExampleLayer : public Honey::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		if (Honey::Input::IsKeyPressed(HN_KEY_TAB))
			HN_TRACE("Tab key is pressed (poll)!");
	}

	void OnEvent(Honey::Event& event) override
	{
		if (event.GetEventType() == Honey::EventType::KeyPressed)
		{
			Honey::KeyPressedEvent& e = (Honey::KeyPressedEvent&)event;
			if (e.GetKeyCode() == HN_KEY_TAB)
				HN_TRACE("Tab key is pressed (event)!");
			HN_TRACE("{0}", (char)e.GetKeyCode());
		}
	}

};

class Sandbox : public Honey::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Honey::ImGuiLayer());
	}

	~Sandbox()
	{

	}

};

Honey::Application* Honey::CreateApplication()
{
	return new Sandbox();
}