#pragma once

#include "Honey.h"

class Sandbox2D : public Honey::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Honey::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Honey::Event& e) override;
private:
	Honey::OrthographicCameraController m_CameraController;

	// Temp
	Honey::Ref<Honey::VertexArray> m_SquareVA;
	Honey::Ref<Honey::Shader> m_FlatColorShader;
	Honey::Ref<Honey::Framebuffer> m_Framebuffer;

	Honey::Ref<Honey::Texture2D> m_CheckerboardTexture;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};