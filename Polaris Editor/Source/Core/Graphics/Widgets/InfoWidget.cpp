#include "pch.h"

#include "InfoWidget.h"

#include "../../Timer.h"

InfoWidget::InfoWidget(const Window& window)
	: m_Window(window)
{
}

void InfoWidget::DrawImGui()
{
	ImGui::Begin("Info");

	if (ImGui::TreeNode("Window"))
	{
		ImGui::TextWrapped("Width: ");
		ImGui::SameLine();
		ImGui::TextWrapped(std::to_string(m_Window.GetWidth()).c_str());

		ImGui::TextWrapped("Height: ");
		ImGui::SameLine();
		ImGui::TextWrapped(std::to_string(m_Window.GetHeight()).c_str());

		ImGui::TreePop();
	}
	if (ImGui::TreeNode("Performance"))
	{
		ImGui::TextWrapped("Delta time: ");
		ImGui::SameLine();
		ImGui::TextWrapped(std::to_string(Timer::GetDeltaTime()).c_str());

		ImGui::TextWrapped("FPS: ");
		ImGui::SameLine();
		ImGui::TextWrapped(std::to_string(Timer::GetFramesPerSecond()).c_str());

		ImGui::TreePop();
	}

	ImGui::End();
}