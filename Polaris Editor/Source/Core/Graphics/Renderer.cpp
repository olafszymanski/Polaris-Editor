#include "pch.h"

#include "Renderer.h"

#include "Graphics/Graphics.h"

#include "Cameras/Camera.h"

#include <DirectXColors.h>

Renderer::Renderer()
	: m_PhongShader()
	, m_Objects({ })
{
	m_PhongShader.Bind();
}

void Renderer::ClearScreen()
{
	Graphics::GetDeviceContext()->ClearRenderTargetView(Graphics::GetRenderTargetView().Get(), DirectX::Colors::Black);
	Graphics::GetDeviceContext()->ClearDepthStencilView(Graphics::GetDepthStencilView().Get(), D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 1);
}

void Renderer::PushObject(Object& object)
{
	m_Objects.push_back(&object);
}
void Renderer::PushObjects(const std::vector<Object*>& objects)
{
	for (auto& object : objects)
	{
		m_Objects.push_back(object);
	}
}

void Renderer::Draw(Camera& camera)
{
	camera.Update();

	m_PhongShader.UpdateLighting({ camera.GetPosition() });

	for (auto& object : m_Objects)
	{
		object->Update();

		m_PhongShader.UpdateMatrices({ object->GetMatrix(), object->GetMatrix().Invert(), (object->GetMatrix() * camera.GetMatrix()).Transpose() });

		for (unsigned int i = 0; i < object->GetModel().GetMeshes().size(); ++i)
		{
			object->GetModel().GetMeshes()[i]->Bind();

			m_PhongShader.UpdateMaterial(object->GetModel().GetMeshes()[i]->GetMaterial());

			object->GetModel().GetMeshes()[i]->Update();

			Graphics::GetDeviceContext()->DrawIndexed(object->GetModel().GetMeshes()[i]->GetIndexCount(), 0, 0);
		}
	}
}

void Renderer::Present()
{
	Graphics::GetSwapChain()->Present(1, 0);
}