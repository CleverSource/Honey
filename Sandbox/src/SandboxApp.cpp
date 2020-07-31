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
		HN_INFO("ExampleLayer::Update");
	}

	void OnEvent(Honey::Event& event) override
	{
		HN_TRACE("{0}", event);
	}

};

class Sandbox : public Honey::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}

};

Honey::Application* Honey::CreateApplication()
{
	return new Sandbox();
}