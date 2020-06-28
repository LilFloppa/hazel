#include <Hazel.h>
#include "imgui/imgui.h"

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
	}

	void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
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
	}

	~Sandbox()
	{

	}
};


Hazel::Application* Hazel::CreateApplication()
{
	return new Sandbox();
}