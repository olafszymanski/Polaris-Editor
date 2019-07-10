#pragma once

#include "Shader.h"

class TextureShader : public Shader
{
public:
	TextureShader();
	~TextureShader() = default;

	virtual void Bind() const;

private:
	const wchar_t* m_VertexShaderSource = L"Resources/Shaders/Compiled/TextureVertexShader.cso";
	const wchar_t* m_PixelShaderSource = L"Resources/Shaders/Compiled/TexturePixelShader.cso";

	Microsoft::WRL::ComPtr<ID3D11VertexShader> m_VertexShader;
	Microsoft::WRL::ComPtr<ID3D11PixelShader> m_PixelShader;

	Microsoft::WRL::ComPtr<ID3D11InputLayout> m_InputLayout;
};