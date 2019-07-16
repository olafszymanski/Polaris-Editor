#pragma once

#include "Shader.h"

class BasicShader : public Shader
{
public:
	BasicShader();
	~BasicShader() = default;

	virtual void Bind() const override;

private:
	const wchar_t* m_VertexShaderSource = L"Resources/Shaders/Compiled/BasicVertexShader.cso";
	const wchar_t* m_PixelShaderSource = L"Resources/Shaders/Compiled/BasicPixelShader.cso";

	Microsoft::WRL::ComPtr<ID3D11VertexShader> m_VertexShader;
	Microsoft::WRL::ComPtr<ID3D11PixelShader> m_PixelShader;

	Microsoft::WRL::ComPtr<ID3D11InputLayout> m_InputLayout;
};