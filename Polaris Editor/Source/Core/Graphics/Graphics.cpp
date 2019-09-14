#include "pch.h"

#include "Graphics.h"

#include "Window.h"

#include "Logger.h"

bool Graphics::s_Multisampling = true;
unsigned int Graphics::s_SampleCount = 8;
unsigned int Graphics::s_MultisamplingQuality = 0;

Microsoft::WRL::ComPtr<ID3D11Device> Graphics::s_Device = nullptr;
Microsoft::WRL::ComPtr<ID3D11DeviceContext> Graphics::s_DeviceContext = nullptr;

Microsoft::WRL::ComPtr<IDXGISwapChain> Graphics::s_SwapChain = nullptr;

Microsoft::WRL::ComPtr<ID3D11RenderTargetView> Graphics::s_RenderTargetView = nullptr;
Microsoft::WRL::ComPtr<ID3D11DepthStencilView> Graphics::s_DepthStencilView = nullptr;

Microsoft::WRL::ComPtr<ID3D11RasterizerState> Graphics::s_RasterizerState = nullptr;

void Graphics::Initialize(const Window& window)
{
	CreateDevice();

	CreateSwapChain(window);

	CreateRenderTargetView();
	CreateDepthStencilView(window);

	CreateViewport(window);

	CreateRasterizerState();
}

void Graphics::CreateDevice()
{
	int flags = 0;
#ifdef _DEBUG
	flags = D3D11_CREATE_DEVICE_DEBUG;
#endif

	const D3D_FEATURE_LEVEL FEATURE_LEVEL = D3D_FEATURE_LEVEL_11_0;

	POLARIS_DX_ASSERT(D3D11CreateDevice(nullptr, D3D_DRIVER_TYPE_HARDWARE, NULL, flags, &FEATURE_LEVEL, 1, D3D11_SDK_VERSION, s_Device.GetAddressOf(), nullptr, s_DeviceContext.GetAddressOf()), "Failed to create ID3D11Device!");

	if (s_Multisampling)
	{
		POLARIS_DX_ASSERT(s_Device->CheckMultisampleQualityLevels(DXGI_FORMAT_B8G8R8A8_UNORM, s_SampleCount, &s_MultisamplingQuality), "Failed to check multisampling quality!");

	if (s_MultisamplingQuality > 0) s_MultisamplingQuality -= 1;
	}
}

void Graphics::CreateSwapChain(const Window& window)
{
	Microsoft::WRL::ComPtr<IDXGIDevice> dxgiDevice = nullptr;
	POLARIS_DX_ASSERT(s_Device->QueryInterface(__uuidof(IDXGIDevice), reinterpret_cast<void**>(dxgiDevice.GetAddressOf())), "Failed to create IDXGIDevice!");

	Microsoft::WRL::ComPtr<IDXGIAdapter> dxgiAdapter = nullptr;
	POLARIS_DX_ASSERT(dxgiDevice->GetAdapter(dxgiAdapter.GetAddressOf()), "Failed to create IDXGIAdapter!");

	Microsoft::WRL::ComPtr<IDXGIFactory> dxgiFactory = nullptr;
	POLARIS_DX_ASSERT(dxgiAdapter->GetParent(__uuidof(IDXGIFactory), reinterpret_cast<void**>(dxgiFactory.GetAddressOf())), "Failed to create IDXGIFactory!");

	RECT clientRect;
	GetClientRect(window.GetHandle(), &clientRect);

	DXGI_SWAP_CHAIN_DESC swapChainDesc { };
	swapChainDesc.BufferDesc.Width = clientRect.right;
	swapChainDesc.BufferDesc.Height = clientRect.bottom;
	swapChainDesc.BufferDesc.RefreshRate.Numerator = 60;
	swapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
	swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapChainDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	swapChainDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	if (s_Multisampling)
	{
		swapChainDesc.SampleDesc.Count = s_SampleCount;
		swapChainDesc.SampleDesc.Quality = s_MultisamplingQuality;
	}
	else
	{
		swapChainDesc.SampleDesc.Count = 1;
		swapChainDesc.SampleDesc.Quality = 0;
	}
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.BufferCount = 1;
	swapChainDesc.OutputWindow = window.GetHandle();
	swapChainDesc.Windowed = true;
	swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	swapChainDesc.Flags = 0;

	POLARIS_DX_ASSERT(dxgiFactory->CreateSwapChain(s_Device.Get(), &swapChainDesc, s_SwapChain.GetAddressOf()), "Failed to create IDXGISwapChain!");
}

void Graphics::CreateRenderTargetView()
{
	Microsoft::WRL::ComPtr<ID3D11Texture2D> backBuffer = nullptr;
	s_SwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<void**>(backBuffer.GetAddressOf()));

	POLARIS_DX_ASSERT(s_Device->CreateRenderTargetView(backBuffer.Get(), nullptr, s_RenderTargetView.GetAddressOf()), "Failed to create IDXGIRenderTargetView!");
}
void Graphics::CreateDepthStencilView(const Window& window)
{
	Microsoft::WRL::ComPtr<ID3D11Texture2D> depthStencilBuffer = nullptr;

	RECT clientRect;
	GetClientRect(window.GetHandle(), &clientRect);

	D3D11_TEXTURE2D_DESC depthStencilBufferDesc { };
	depthStencilBufferDesc.Width = clientRect.right;
	depthStencilBufferDesc.Height = clientRect.bottom;
	depthStencilBufferDesc.MipLevels = 1;
	depthStencilBufferDesc.ArraySize = 1;
	depthStencilBufferDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
	if (s_Multisampling)
	{
		depthStencilBufferDesc.SampleDesc.Count = s_SampleCount;
		depthStencilBufferDesc.SampleDesc.Quality = s_MultisamplingQuality;
	}
	else
	{
		depthStencilBufferDesc.SampleDesc.Count = 1;
		depthStencilBufferDesc.SampleDesc.Quality = 0;
	}
	depthStencilBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	depthStencilBufferDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
	depthStencilBufferDesc.CPUAccessFlags = 0;
	depthStencilBufferDesc.MiscFlags = 0;

	POLARIS_DX_ASSERT(s_Device->CreateTexture2D(&depthStencilBufferDesc, nullptr, depthStencilBuffer.GetAddressOf()), "Failed to create depth stencil buffer!");

	POLARIS_DX_ASSERT(s_Device->CreateDepthStencilView(depthStencilBuffer.Get(), nullptr, s_DepthStencilView.GetAddressOf()), "Failed to create ID3D11DepthStencilView!");

	s_DeviceContext->OMSetRenderTargets(1, s_RenderTargetView.GetAddressOf(), s_DepthStencilView.Get());
}

void Graphics::CreateViewport(const Window& window)
{
	D3D11_VIEWPORT viewport { };
	viewport.TopLeftX = 0.0f;
	viewport.TopLeftY = 0.0f;
	viewport.Width = static_cast<float>(window.GetWidth());
	viewport.Height = static_cast<float>(window.GetHeight());
	viewport.MinDepth = 0.0f;
	viewport.MaxDepth = 1.0f;

	s_DeviceContext->RSSetViewports(1, &viewport);
}

void Graphics::CreateRasterizerState()
{
	D3D11_RASTERIZER_DESC rasterizerDesc { };
	rasterizerDesc.FillMode = D3D11_FILL_SOLID;
	rasterizerDesc.CullMode = D3D11_CULL_BACK;
	rasterizerDesc.FrontCounterClockwise = true;
	rasterizerDesc.DepthBias = 0;
	rasterizerDesc.DepthBiasClamp = 0.0f;
	rasterizerDesc.SlopeScaledDepthBias = 0.0f;
	rasterizerDesc.DepthClipEnable = true;
	rasterizerDesc.ScissorEnable = false;
	rasterizerDesc.MultisampleEnable = s_Multisampling;
	rasterizerDesc.AntialiasedLineEnable = false;

	POLARIS_DX_ASSERT(s_Device->CreateRasterizerState(&rasterizerDesc, s_RasterizerState.GetAddressOf()), "Failed to create ID3D11RasterizerState!");

	s_DeviceContext->RSSetState(s_RasterizerState.Get());

	s_DeviceContext->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
}