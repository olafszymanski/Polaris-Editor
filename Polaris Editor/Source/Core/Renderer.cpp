#include "pch.h"

#include "Renderer.h"

void Renderer::ClearScreen()
{
	Graphics::GetDeviceContext()->ClearRenderTargetView(Graphics::GetRenderTargetView().Get(), DirectX::Colors::Black);
	Graphics::GetDeviceContext()->ClearDepthStencilView(Graphics::GetDepthStencilView().Get(), D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 1);
}

void Renderer::Present()
{
	Graphics::GetSwapChain()->Present(1, 0);
}