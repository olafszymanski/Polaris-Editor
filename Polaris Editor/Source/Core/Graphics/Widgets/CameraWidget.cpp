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
	float* positionPointers[3] { &position.x, &position.y, &position.z };

	ImGui::DragFloat3("XYZ", *positionPointers, 1.0f, -100.0f, 100.0f, "%.01f");

	if (ImGui::Button("Reset##0")) m_Camera.SetPosition({ 0.0f, 0.0f, 0.0f });
	else m_Camera.SetPosition(position);

	ImGui::Text("Rotation");

	DirectX::SimpleMath::Vector2 rotation = m_Camera.GetRotation();

	ImGui::DragFloat("Yaw", &rotation.x, 1.0f, -180.0f, 180.0f, "%.01f");
	ImGui::DragFloat("Pitch", &rotation.y, 1.0f, -90.0f, 90.0f, "%.01f");

	if (ImGui::Button("Reset##1")) m_Camera.SetRotation({ 0.0f, 0.0f });
	else m_Camera.SetRotation(rotation);

	ImGui::End();
}