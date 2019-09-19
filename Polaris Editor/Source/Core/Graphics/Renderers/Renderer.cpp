#include "pch.h"

#include "Renderer.h"

#include "../Graphics.h"

#include "../Cameras/Camera.h"

#include <DirectXColors.h>

Renderer::Renderer()
	: m_PhongShader()
	, m_Objects({ })
{
	m_PhongShader.Bind();
}

void Renderer::ClearScreen()
{
	Graphics::GetDeviceContext()->OMSetRenderTargets(1, Graphics::GetRenderTargetView().GetAddressOf(), Graphics::GetDepthStencilView().Get());

	const DirectX::SimpleMath::Vector4& clearColor = Graphics::GetClearColor();
	float realClearColor[4] = { clearColor.x, clearColor.y, clearColor.z, clearColor.w };

	Graphics::GetDeviceContext()->ClearRenderTargetView(Graphics::GetRenderTargetView().Get(), realClearColor);
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

void Renderer::Draw(const Camera& camera)
{
	m_PhongShader.UpdateLighting({ camera.GetPosition() });

	for (auto& object : m_Objects)
	{
		object->Update();

		m_PhongShader.UpdateMatrices({ object->GetMatrix().Transpose(), object->GetMatrix().Invert().Transpose(), (object->GetMatrix() * camera.GetMatrix()).Transpose() });

		for (auto& mesh : object->GetModel().GetMeshes())
		{
			mesh->Bind();

			m_PhongShader.UpdateMaterial(mesh->GetMaterial());

			mesh->Update();

			Graphics::GetDeviceContext()->DrawIndexed(mesh->GetIndexCount(), 0, 0);
		}
	}
}

void Renderer::Present()
{
	Graphics::GetSwapChain()->Present(Graphics::IsVerticalSync() ? 1 : 0, 0);
}