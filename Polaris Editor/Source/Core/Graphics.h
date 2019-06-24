#pragma once

class Window;

class Graphics
{
public:
	inline static Microsoft::WRL::ComPtr<ID3D11Device>& GetDevice() { return s_Device; }
	inline static Microsoft::WRL::ComPtr<ID3D11DeviceContext>& GetDeviceContext() { return s_DeviceContext; }

	inline static Microsoft::WRL::ComPtr<IDXGISwapChain>& GetSwapChain() { return s_SwapChain; }

	inline static Microsoft::WRL::ComPtr<ID3D11RenderTargetView>& GetRenderTargetView() { return s_RenderTargetView; }
	inline static Microsoft::WRL::ComPtr<ID3D11DepthStencilView>& GetDepthStencilView() { return s_DepthStencilView; }

protected:
	Graphics() = default;
	~Graphics() = default;

	void Initialize(Window& window);

private:
	static bool s_Multisampling;
	static unsigned int s_SampleCount, s_MultisamplingQuality;

	static Microsoft::WRL::ComPtr<ID3D11Device> s_Device;
	static Microsoft::WRL::ComPtr<ID3D11DeviceContext> s_DeviceContext;

	static Microsoft::WRL::ComPtr<IDXGISwapChain> s_SwapChain;

	static Microsoft::WRL::ComPtr<ID3D11RenderTargetView> s_RenderTargetView;
	static Microsoft::WRL::ComPtr<ID3D11DepthStencilView> s_DepthStencilView;

	static Microsoft::WRL::ComPtr<ID3D11RasterizerState> s_RasterizerState;

private:
	void CreateDevice();

	void CreateSwapChain(Window& window);

	void CreateRenderTargetView();
	void CreateDepthStencilView(Window& window);

	void CreateViewport(Window& window);

	void CreateRasterizerState();
};