#include "Sandbox2D.h"
#include <imgui/imgui.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
{
}

void Sandbox2D::OnAttach()
{
	HZ_PROFILE_FUNCTION();

	m_CheckerboardTexture = Hazel::Texture2D::Create("assets/textures/Checkerboard.png");
	m_SpriteSheet = Hazel::Texture2D::Create("assets/textures/SpriteSheet.png");
	m_Stairs = Hazel::SubTexture2D::CreateFromCoords(m_SpriteSheet, { 7, 6 }, { 64, 64 });
	m_Barrel = Hazel::SubTexture2D::CreateFromCoords(m_SpriteSheet, { 8, 2 }, { 64, 64 });

}

void Sandbox2D::OnDetach()
{
	HZ_PROFILE_FUNCTION();
}

void Sandbox2D::OnUpdate(Hazel::Timestep ts)
{
	HZ_PROFILE_FUNCTION();

	static int i = 0;
	i++;

	if (i > 10)
	{
		fps = 1.0 / ts;
		i = 0;
	}

	// Update
	m_CameraController.OnUpdate(ts);

	// Render
	Hazel::Renderer2D::ResetStats();
	{
		HZ_PROFILE_SCOPE("Renderer Prep");

		Hazel::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Hazel::RenderCommand::Clear();
	}

	{
		static float rotation = 0.0f;
		rotation += ts * 50.0f;

		HZ_PROFILE_SCOPE("Renderer Draw");
		Hazel::Renderer2D::BeginScene(m_CameraController.GetCamera());
		Hazel::Renderer2D::DrawQuad({ -2.0f, 0.0f, 0.0f }, { 1.0f, 1.0f }, m_Stairs);
		Hazel::Renderer2D::DrawQuad({ -2.0f, 0.0f, 1.0f }, { 1.0f, 1.0f }, m_Barrel);
		Hazel::Renderer2D::EndScene();

		Hazel::Renderer2D::BeginScene(m_CameraController.GetCamera());
		for (float y = -10.0f; y < 10.0f; y += 0.5f)
		{
			for (float x = -10.0f; x < 10.0f; x += 0.5f)
			{
				glm::vec4 color = { (x + 5.0f) / 10.0f, 0.4f, (y + 5.0f) / 10.0f, 1.0f };
				Hazel::Renderer2D::DrawQuad({ x, y, -0.1f }, { 0.45f, 0.45f }, color);
			}
		}
		Hazel::Renderer2D::EndScene();
	}
}

void Sandbox2D::OnImGuiRender()
{
	HZ_PROFILE_FUNCTION();

   
	ImGui::Begin("Settings");

	auto stats = Hazel::Renderer2D::GetStats();
	ImGui::Text("Renderer2D Stats:");
	ImGui::Text("Draw Calls: %d", stats.DrawCalls);
	ImGui::Text("Quads: %d", stats.QuadCount);
	ImGui::Text("Vertices: %d", stats.GetTotalVertexCount());
	ImGui::Text("Indices: %d", stats.GetTotalIndexCount());
	ImGui::Text("FPS: %f", fps);

	ImGui::End();
}

void Sandbox2D::OnEvent(Hazel::Event& e)
{
	m_CameraController.OnEvent(e);
}