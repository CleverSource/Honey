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
	HN_PROFILE_FUNCTION();

	m_CheckerboardTexture = Honey::Texture2D::Create("assets/textures/Checkerboard.png");
}

void Sandbox2D::OnDetach()
{
	HN_PROFILE_FUNCTION();
}

void Sandbox2D::OnUpdate(Honey::Timestep ts)
{
	HN_PROFILE_FUNCTION();

	// Update
	m_CameraController.OnUpdate(ts);

	// Render
	{
		HN_PROFILE_SCOPE("Renderer Prep");
		Honey::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Honey::RenderCommand::Clear();
	}

	{
		HN_PROFILE_SCOPE("Renderer Draw");
		Honey::Renderer2D::BeginScene(m_CameraController.GetCamera());
		Honey::Renderer2D::DrawRotatedQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, glm::radians(-45.0f), { 0.8f, 0.2f, 0.3f, 1.0f });
		Honey::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });
		Honey::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 10.0f, 10.0f }, m_CheckerboardTexture, 10.0f);
		Honey::Renderer2D::EndScene();
	}
}

void Sandbox2D::OnImGuiRender()
{
	HN_PROFILE_FUNCTION();

	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void Sandbox2D::OnEvent(Honey::Event& e)
{
	m_CameraController.OnEvent(e);
}