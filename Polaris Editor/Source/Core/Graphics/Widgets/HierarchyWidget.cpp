#include "pch.h"

#include "HierarchyWidget.h"

#include "../Drawables/Object.h"

#include "../../../Vendor/PortableFileDialogs/portable-file-dialogs.h"

HierarchyWidget::HierarchyWidget(Scene& scene, InspectorWidget& inspectorWidget)
	: m_Scene(scene)
	, m_InspectorWidget(inspectorWidget)
{
}

void HierarchyWidget::DrawImGui()
{
	ImGui::Begin("Hierarchy");

	if (ImGui::IsWindowHovered() && ImGui::IsMouseClicked(1)) ImGui::OpenPopup("SceneMenu");

	if (ImGui::BeginPopupContextItem("SceneMenu"))
	{
		if (ImGui::Button("Create an object"))
		{
			ImGui::CloseCurrentPopup();

			pfd::settings::verbose(false);

			pfd::open_file file = pfd::open_file("Select model file", DEFAULT_PATH, { "3D Files", "*.fbx *.dae *.blend *.3ds *.obj" }, false);

			for (auto& name : file.result())
			{
				Object* object = new Object({ name });

				m_Scene.AddObject(object);
			}
		}

		ImGui::EndPopup();
	}

	if (ImGui::TreeNode("Objects"))
	{
		for (auto& object : m_Scene.GetObjects())
		{
			if (object.second != nullptr)
			{
				const std::string& name = object.second->GetModel().GetName();

				if (ImGui::Selectable(name.c_str()))
				{
					Object* currentObject = m_InspectorWidget.GetCurrentObject();

					if (currentObject && currentObject->GetModel().GetName() != name) m_InspectorWidget.SetCurrentMesh(nullptr);

					m_InspectorWidget.SetCurrentObject(object.second);
				}
			}
		}

		ImGui::TreePop();
	}

	ImGui::End();
}