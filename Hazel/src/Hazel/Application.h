#pragma once
#include "Hazel/Core.h"
#include "Hazel/Window.h"
#include "Hazel/Events/Event.h"
#include "Hazel/Events/ApplicationEvent.h"
#include "Hazel/LayerStack.h"
#include "Hazel/Layer.h"
#include "Hazel/ImGui/ImGuiLayer.h"

#include "Hazel/Renderer/Buffer.h"
#include "Hazel/Renderer/Shader.h"

namespace Hazel
{
	class Application
	{
	public:
		Application();
		virtual ~Application();

		void OnEvent(Event& e);
		void Run();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		LayerStack m_LayerStack;
		bool m_Running = true;


		unsigned int m_VertexArray;
		std::unique_ptr<Shader> m_Shader;
		std::unique_ptr<VertexBuffer> m_VertexBuffer;
		std::unique_ptr<IndexBuffer> m_IndexBuffer;

	private:
		static Application* s_Instance;
	};


	// To be defined by client
	Application* CreateApplication();
}