#include "pch.h"

#include "InspectorWidget.h"

#include "../Drawables/Object.h"

#include "../Scenes/Scene.h"

#include "../../../Vendor/PortableFileDialogs/portable-file-dialogs.h"

#include "../../../Utils/StringHelper.h"

InspectorWidget::InspectorWidget()
	: m_CurrentMesh(nullptr), m_CurrentObject(nullptr)
{
}

void InspectorWidget::DrawImGui()
{
	ImGui::Begin("Inspector");

	if (m_CurrentObject)
	{
		ImGui::Text(std::string("Inspecting " + m_CurrentObject->GetModel().GetName()).c_str());

		ImGui::Spacing();
		ImGui::Separator();
		ImGui::Spacing();

		ImGui::Text("Position");

		DirectX::SimpleMath::Vector3 position = m_CurrentObject->GetPosition();
		float* positionPointers[3] { &position.x, &position.y, &position.z };

		ImGui::DragFloat3("XYZ##0", *positionPointers, 1.0f, -100.0f, 100.0f, "%.01f");

		if (ImGui::Button("Reset##0")) m_CurrentObject->SetPosition({ 0.0f, 0.0f, 0.0f });
		else m_CurrentObject->SetPosition(position);

		ImGui::Text("Rotation");

		DirectX::SimpleMath::Vector3 rotation = m_CurrentObject->GetRotation();
		float* rotationPoiners[3] { &rotation.x, &rotation.y, &rotation.z };

		ImGui::DragFloat3("XYZ##1", *rotationPoiners, 1.0f, 0.0f, 360.0f, "%.01f");

		if (ImGui::Button("Reset##1")) m_CurrentObject->SetRotation({ 0.0f, 0.0f, 0.0f });
		else m_CurrentObject->SetRotation(rotation);

		ImGui::Text("Scale");

		DirectX::SimpleMath::Vector3 scale = m_CurrentObject->GetScale();

		static bool allAxis = false;

		if (allAxis)
		{
			ImGui::DragFloat("XYZ##2", &scale.x, 1.0f, 0.05f, 100.0f, "%.01f");

			scale.y = scale.z = scale.x;
		}
		else
		{
			float* scalePointers[3] { &scale.x, &scale.y, &scale.z };

			ImGui::DragFloat3("XYZ##2", *scalePointers, 1.0f, 0.05f, 100.0f, "%.01f");
		}

		if (ImGui::Button("Reset##2")) m_CurrentObject->SetScale({ 1.0f, 1.0f, 1.0f });
		else m_CurrentObject->SetScale(scale);

		ImGui::SameLine();
		ImGui::Checkbox("All axis", &allAxis);

		ImGui::Spacing();
		ImGui::Separator();
		ImGui::Spacing();

		if (ImGui::TreeNode("Meshes"))
		{
			for (auto& mesh : m_CurrentObject->GetModel().GetMeshes())
			{
				if (ImGui::Selectable(mesh->GetName().c_str())) m_CurrentMesh = mesh.get();
			}

			ImGui::TreePop();
		}

		ImGui::Spacing();
		ImGui::Separator();
		ImGui::Spacing();

		if (m_CurrentMesh)
		{
			if (ImGui::TreeNode(std::string(m_CurrentMesh->GetName() + " Material").c_str()))
			{
				if (ImGui::TreeNode("Diffuse texture"))
				{
					ImGui::Text(std::string("Name: " + StringHelper::GetFileName(m_CurrentMesh->GetDiffuseTexture().GetFilePath())).c_str());

					if (ImGui::ImageButton(static_cast<void*>(m_CurrentMesh->GetDiffuseTexture().GetShaderTextureView().Get()), ImVec2(128, 128)))
					{
						pfd::settings::verbose(false);

						pfd::open_file file = pfd::open_file("Select texture file", DEFAULT_PATH, { "2D Images", "*.png *.jpg *.jpeg *.dds *.svg" }, false);

						for (auto& name : file.result())
						{
							m_CurrentMesh->SetDiffuseTexture({ name });
						}
					}

					ImGui::TreePop();
				}
				if (ImGui::TreeNode("Specular texture"))
				{
					ImGui::Text(std::string("Name: " + StringHelper::GetFileName(m_CurrentMesh->GetSpecularTexture().GetFilePath())).c_str());

					if (ImGui::ImageButton(static_cast<void*>(m_CurrentMesh->GetSpecularTexture().GetShaderTextureView().Get()), ImVec2(128, 128)))
					{
						pfd::settings::verbose(false);

						pfd::open_file file = pfd::open_file("Select texture file", DEFAULT_PATH, { "2D Images", "*.png *.jpg *.jpeg *.dds *.svg" }, false);

						for (auto& name : file.result())
						{
							m_CurrentMesh->SetSpecularTexture({ name });
						}
					}

					ImGui::TreePop();
				}
				if (ImGui::TreeNode("Color"))
				{
					bool valueChanged = false;

					DirectX::SimpleMath::Vector4 selectedMeshAmbient = m_CurrentMesh->GetMaterial().Ambient;
					float ambientColor[3] { selectedMeshAmbient.x, selectedMeshAmbient.y, selectedMeshAmbient.z };
					if (ImGui::ColorEdit3("Ambient", ambientColor)) valueChanged = true;

					DirectX::SimpleMath::Vector4 selectedMeshDiffuse = m_CurrentMesh->GetMaterial().Diffuse;
					float diffuseColor[3] { selectedMeshDiffuse.x, selectedMeshDiffuse.y, selectedMeshDiffuse.z };
					if (ImGui::ColorEdit3("Diffuse", diffuseColor)) valueChanged = true;

					DirectX::SimpleMath::Vector4 selectedMeshSpecular = m_CurrentMesh->GetMaterial().Specular;
					float specularColor[3] { selectedMeshSpecular.x, selectedMeshSpecular.y, selectedMeshSpecular.z };
					if (ImGui::ColorEdit3("Specular", specularColor)) valueChanged = true;

					static float shininess = selectedMeshSpecular.w;
					if (ImGui::DragFloat("Shininess", &shininess, 1.0f, 1.0f, 256.0f)) valueChanged = true;

					if (valueChanged) m_CurrentMesh->SetMaterial({ { ambientColor[0], ambientColor[1], ambientColor[2], selectedMeshAmbient.w } , { diffuseColor[0], diffuseColor[1], diffuseColor[2], selectedMeshDiffuse.z }, { specularColor[0], specularColor[1], specularColor[2], shininess } });

					if (ImGui::Button("Apply to whole object"))
					{
						for (auto& mesh : m_CurrentObject->GetModel().GetMeshes())
						{
							mesh->SetMaterial({ { ambientColor[0], ambientColor[1], ambientColor[2], selectedMeshAmbient.z } , { diffuseColor[0], diffuseColor[1], diffuseColor[2], selectedMeshDiffuse.z }, { specularColor[0], specularColor[1], specularColor[2], shininess } });
						}
					}

					ImGui::TreePop();
				}

				ImGui::TreePop();
			}
		}
		else ImGui::Text("Select a mesh");

		ImGui::Spacing();
		ImGui::Separator();
		ImGui::Spacing();

		if (ImGui::Button("Change name")) ImGui::OpenPopup("ChangeName");	
		ImGui::SameLine();
		if (ImGui::Button("Remove"))
		{
			m_CurrentObject->GetScene().RemoveObject(m_CurrentObject->GetID());
		
			m_CurrentMesh = nullptr;
			m_CurrentObject = nullptr;
		}

		if (ImGui::BeginPopupContextItem("ChangeName"))
		{
			static char name[32] = "";
			ImGui::InputTextWithHint("", "Name...", name, IM_ARRAYSIZE(name));
			ImGui::SameLine();
			if (ImGui::Button("Change"))
			{
				m_CurrentObject->GetModel().SetName(name);

				ImGui::CloseCurrentPopup();
			}

			ImGui::EndPopup();
		}
	}
	else ImGui::Text("Select an object");

	ImGui::End();
}