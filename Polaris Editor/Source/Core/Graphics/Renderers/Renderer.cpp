#include "pch.h"

#include "Renderer.h"

#include "../Graphics.h"

#include "../Scenes/Scene.h"

#include "../Drawables/Object.h"

Renderer::Renderer()
	: m_PhongShader()
{
	m_PhongShader.Bind();
}

void Renderer::ClearScreen()
{
	Graphics::GetDeviceContext()->OMSetRenderTargets(1, Graphics::GetRenderTargetView().GetAddressOf(), Graphics::GetDepthStencilView().Get());

	const DirectX::SimpleMath::Vector4& clearColor = Graphics::GetClearColor();
	float realClearColor[4] { clearColor.x, clearColor.y, clearColor.z, clearColor.w };

	Graphics::GetDeviceContext()->ClearRenderTargetView(Graphics::GetRenderTargetView().Get(), realClearColor);
	Graphics::GetDeviceContext()->ClearDepthStencilView(Graphics::GetDepthStencilView().Get(), D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 1);
}

void Renderer::Draw(Scene& scene)
{
	m_PhongShader.UpdateLighting({ scene.GetCamera().GetPosition() });

	for (auto& object : scene.GetObjects())
	{
		if (object.second != nullptr)
		{
			object.second->Update();

			m_PhongShader.UpdateMatrices({ object.second->GetMatrix().Transpose(), object.second->GetMatrix().Invert().Transpose(), (object.second->GetMatrix() * scene.GetCamera().GetMatrix()).Transpose() });

			for (auto& mesh : object.second->GetModel().GetMeshes())
			{
				mesh->Bind();

				m_PhongShader.UpdateMaterial(mesh->GetMaterial());

				mesh->Update();

				Graphics::GetDeviceContext()->DrawIndexed(mesh->GetIndexCount(), 0, 0);
			}
		}
	}
}

void Renderer::Present()
{
	Graphics::GetSwapChain()->Present(Graphics::IsVerticalSync() ? 1 : 0, 0);
}