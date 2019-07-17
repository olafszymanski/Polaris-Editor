#include "pch.h"

#include "Renderer.h"

#include "Graphics/Graphics.h"

#include "Drawables/Drawable.h"

#include "Cameras/Camera.h"

Renderer::Renderer()
	: m_BasicShader(), m_TextureShader()
	, m_Objects({ }), m_TexturedObjects({ }) 
{
}

void Renderer::ClearScreen()
{
	Graphics::GetDeviceContext()->ClearRenderTargetView(Graphics::GetRenderTargetView().Get(), DirectX::Colors::Black);
	Graphics::GetDeviceContext()->ClearDepthStencilView(Graphics::GetDepthStencilView().Get(), D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 1);
}

void Renderer::PushDrawable(const Drawable& drawable)
{
	if (dynamic_cast<TexturedObject*>(const_cast<Drawable*>(&drawable))) m_TexturedObjects.push_back(static_cast<TexturedObject*>(const_cast<Drawable*>(&drawable)));
	else m_Objects.push_back(static_cast<Object*>(const_cast<Drawable*>(&drawable)));
}
void Renderer::PushDrawables(const std::vector<Drawable*>& drawables)
{
	for (auto& drawable : drawables)
	{
		if (dynamic_cast<TexturedObject*>(drawable)) m_TexturedObjects.push_back(static_cast<TexturedObject*>(drawable));
		else m_Objects.push_back(static_cast<Object*>(drawable));
	}
}

void Renderer::Draw(Camera& camera)
{
	camera.Update();

	for (auto& drawable : m_Objects)
	{
		drawable->Bind();
		
		m_BasicShader.Bind();
	
		drawable->Update();

		m_BasicShader.UpdateWorldViewProjection((drawable->GetMatrix() * camera.GetMatrix()).Transpose());

		Graphics::GetDeviceContext()->DrawIndexed(drawable->GetIndexCount(), 0, 0);
	}

	for (auto& drawable : m_TexturedObjects)
	{
		drawable->Bind();

		m_TextureShader.Bind();

		drawable->Update();

		m_TextureShader.UpdateWorldViewProjection((drawable->GetMatrix() * camera.GetMatrix()).Transpose());

		Graphics::GetDeviceContext()->DrawIndexed(drawable->GetIndexCount(), 0, 0);
	}
}

void Renderer::Present()
{
	Graphics::GetSwapChain()->Present(1, 0);
}