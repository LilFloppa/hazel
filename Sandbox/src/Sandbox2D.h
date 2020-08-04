#pragma once

#include "Hazel.h"

class Sandbox2D : public Hazel::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Hazel::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Hazel::Event& e) override;
private:
	Hazel::OrthographicCameraController m_CameraController;

	Hazel::Ref<Hazel::Texture2D> m_CheckerboardTexture;
	Hazel::Ref<Hazel::Texture2D> m_SpriteSheet;
	Hazel::Ref<Hazel::SubTexture2D> m_Stairs, m_Barrel;

	float fps = 0.0f;

	float angle = 0.0f;
	float length = 1.0f;
	float thickness = 1.0f;
};