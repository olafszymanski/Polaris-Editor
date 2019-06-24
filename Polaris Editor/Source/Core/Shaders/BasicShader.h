#pragma once

#include "../../Utils/NonCopyable.h"

#include "../Graphics.h"

struct BasicVertex
{
	DirectX::XMFLOAT3 Position;
};

class BasicShader : public NonCopyable, protected Graphics
{
public:
	BasicShader();
	~BasicShader() = default;

private:
	const wchar_t* m_VertexShaderSource = L"Resources/Shaders/Compiled/BasicVertexShader.cso";
	const wchar_t* m_PixelShaderSource = L"Resources/Shaders/Compiled/BasicPixelShader.cso";

	Microsoft::WRL::ComPtr<ID3D11VertexShader> m_VertexShader;
	Microsoft::WRL::ComPtr<ID3D11PixelShader> m_PixelShader;

	Microsoft::WRL::ComPtr<ID3D11InputLayout> m_InputLayout;
};