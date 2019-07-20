#include "pch.h"

#include "Renderer.h"

#include "Graphics/Graphics.h"

#include "Cameras/Camera.h"

#include <DirectXColors.h>

Renderer::Renderer()
	: m_BasicShader()
	, m_Objects({ })
{
	m_BasicShader.Bind();
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

	for (auto& object : m_Objects)
	{
		object->UpdateMatrix();

		m_BasicShader.UpdateWorldViewProjection((object->GetMatrix() * camera.GetMatrix()).Transpose());

		for (unsigned int i = 0; i < object->GetModel().GetMeshes().size(); ++i)
		{
			object->Bind(i);

			object->UpdateMesh(i);

			Graphics::GetDeviceContext()->DrawIndexed(object->GetModel().GetMeshes()[i]->GetIndexCount(), 0, 0);
		}
	}
}

void Renderer::Present()
{
	Graphics::GetSwapChain()->Present(1, 0);
}