#pragma once
#include "Hazel/Core.h"
#include "Hazel/Window.h"

namespace Hazel
{
	class HAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};


	// To be defined by client
	Application* CreateApplication();
}