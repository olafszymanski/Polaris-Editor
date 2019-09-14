#include "pch.h"

#include "WidgetRenderer.h"

#include "../Managers/WidgetManager.h"

#include "../Widgets/ImGui/imgui_impl_dx11.h"
#include "../Widgets/ImGui/imgui_impl_win32.h"

void WidgetRenderer::Draw()
{
	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	ImGuiViewport* viewport = ImGui::GetMainViewport();
	ImGui::SetNextWindowViewport(viewport->ID);
	ImGui::SetNextWindowBgAlpha(0.0f);

	static ImGuiWindowFlags windowFlags = ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;

	static bool open = true;

	ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
	ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
	ImGui::Begin("Polaris Editor", &open, windowFlags);
	ImGui::PopStyleVar(3);

	ImGuiID id = ImGui::GetID("Polaris Editor Dockspace");
	static ImGuiDockNodeFlags flags = ImGuiDockNodeFlags_PassthruCentralNode;
	ImGui::DockSpace(id, ImVec2(0.0f, 0.0f), flags);

	ImGui::End();

	for (auto& widget : WidgetManager::GetWidgets())
	{
		widget->Draw();
	}

	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

	ImGuiIO& io = ImGui::GetIO();
	if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
	{
		ImGui::UpdatePlatformWindows();
		ImGui::RenderPlatformWindowsDefault();
	}
}