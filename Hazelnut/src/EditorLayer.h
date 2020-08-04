#pragma once

#include "Hazel.h"

namespace Hazel
{
	class EditorLayer : public Layer
	{
	public:
		EditorLayer();
		virtual ~EditorLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		void OnUpdate(Timestep ts) override;
		virtual void OnImGuiRender() override;
		void OnEvent(Event& e) override;
	private:
		OrthographicCameraController m_CameraController;

		Ref<Texture2D> m_CheckerboardTexture;
		Ref<Texture2D> m_SpriteSheet;
		Ref<SubTexture2D> m_Stairs, m_Barrel;

		Ref<Framebuffer> m_Framebuffer;

		glm::vec2 m_ViewportSize = { 0.0f, 0.0f };
		glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
		float fps = 0.0f;
	};
}