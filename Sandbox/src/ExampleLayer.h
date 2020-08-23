#pragma once

#include "Honey.h"

class ExampleLayer : public Honey::Layer
{
public:
	ExampleLayer();
	virtual ~ExampleLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Honey::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Honey::Event& e) override;
private:
	Honey::ShaderLibrary m_ShaderLibrary;
	Honey::Ref<Honey::Shader> m_Shader;
	Honey::Ref<Honey::VertexArray> m_VertexArray;

	Honey::Ref<Honey::Shader> m_FlatColorShader;
	Honey::Ref<Honey::VertexArray> m_SquareVA;

	Honey::Ref<Honey::Texture2D> m_Texture, m_CleverLogoTexture;

	Honey::OrthographicCameraController m_CameraController;
	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};