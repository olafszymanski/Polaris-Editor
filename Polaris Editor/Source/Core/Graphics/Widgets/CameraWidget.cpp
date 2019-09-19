#include "pch.h"

#include "CameraWidget.h"

CameraWidget::CameraWidget(Camera& camera)
	: m_Camera(camera)
{
}

void CameraWidget::DrawImGui()
{
	ImGui::Begin("Camera");

	ImGui::Text("Position");

	DirectX::SimpleMath::Vector3 position = m_Camera.GetPosition();

	ImGui::SliderFloat("X", &position.x, -100.0f, 100.0f, "%.01f");
	ImGui::SliderFloat("Y", &position.y, -100.0f, 100.0f, "%.01f");
	ImGui::SliderFloat("Z", &position.z, -100.0f, 100.0f, "%.01f");

	if (ImGui::Button("Reset")) m_Camera.SetPosition({ 0.0f, 0.0f, 0.0f });
	else m_Camera.SetPosition(position);

	ImGui::Text("Rotation");

	DirectX::SimpleMath::Vector2 rotation = m_Camera.GetRotation();

	ImGui::SliderFloat("Yaw", &rotation.x, -360.0f, 360.0f, "%.01f");
	ImGui::SliderFloat("Pitch", &rotation.y, -80.0f, 80.0f, "%.01f");

	if (ImGui::Button("Reset")) m_Camera.SetRotation({ 0.0f, 0.0f });
	else m_Camera.SetRotation(rotation);

	ImGui::End();
}