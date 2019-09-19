#pragma once

class Window;

class Graphics
{
public:
	// Getters
	inline static const bool& IsMultisampling() { return s_Multisampling; }
	inline static const bool& IsVerticalSync() { return s_VerticalSync; }
	inline static const unsigned int& GetSampleCount() { return s_SampleCount; }
	inline static const unsigned int& GetMultisamplingQuality() { return s_MultisamplingQuality; }

	inline static Microsoft::WRL::ComPtr<ID3D11Device>& GetDevice() { return s_Device; }
	inline static Microsoft::WRL::ComPtr<ID3D11DeviceContext>& GetDeviceContext() { return s_DeviceContext; }

	inline static Microsoft::WRL::ComPtr<IDXGISwapChain>& GetSwapChain() { return s_SwapChain; }

	inline static Microsoft::WRL::ComPtr<ID3D11RenderTargetView>& GetRenderTargetView() { return s_RenderTargetView; }
	inline static Microsoft::WRL::ComPtr<ID3D11DepthStencilView>& GetDepthStencilView() { return s_DepthStencilView; }

	inline static const DirectX::SimpleMath::Vector4& GetClearColor() { return s_ClearColor; }

	// Setter
	inline static void SetVerticalSync(bool verticalSync) { s_VerticalSync = verticalSync; }

	inline static void SetClearColor(const DirectX::SimpleMath::Vector4& clearColor) { s_ClearColor = clearColor; }

protected:
	Graphics() = default;
	~Graphics() = default;

	static void Initialize(const Window& window);

	static void Resize(const Window& window);

private:
	static bool s_Multisampling, s_VerticalSync;
	static unsigned int s_SampleCount, s_MultisamplingQuality;

	static Microsoft::WRL::ComPtr<ID3D11Device> s_Device;
	static Microsoft::WRL::ComPtr<ID3D11DeviceContext> s_DeviceContext;

	static Microsoft::WRL::ComPtr<IDXGISwapChain> s_SwapChain;

	static Microsoft::WRL::ComPtr<ID3D11RenderTargetView> s_RenderTargetView;
	static Microsoft::WRL::ComPtr<ID3D11DepthStencilView> s_DepthStencilView;

	static Microsoft::WRL::ComPtr<ID3D11RasterizerState> s_RasterizerState;

	static DirectX::SimpleMath::Vector4 s_ClearColor;

private:
	static void CreateDevice();

	static void CreateSwapChain(const Window& window);

	static void CreateRenderTargetView();
	static void CreateDepthStencilView(const Window& window);

	static void CreateViewport(const Window& window);

	static void CreateRasterizerState();
};