#include <Honey.h>

class Sandbox : public Honey::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

Honey::Application* Honey::CreateApplication()
{
	return new Sandbox();
}