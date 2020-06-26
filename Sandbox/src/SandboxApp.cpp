#include <Hazel.h>

#include <glm/mat2x2.hpp>

class ExampleLayer : public Hazel::Layer
{
public:
	ExampleLayer()
		: Layer("example")
	{
	}

	~ExampleLayer() override {}

	void OnUpdate() override
	{
		glm::mat2x2 m(1);
		int a = m.length();
	}

	void OnEvent(Hazel::Event& e) override
	{
		if (e.GetEventType() == Hazel::EventType::KeyPressed)
		{
			Hazel::KeyPressedEvent& kpe = (Hazel::KeyPressedEvent&)e;
			HZ_TRACE("{0}", (char)kpe.GetKeyCode());
		}
	}
};

class Sandbox : public Hazel::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushLayer(new Hazel::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};


Hazel::Application* Hazel::CreateApplication()
{
	return new Sandbox();
}