#include "../pch.h"

#include "BasicShader.h"

#include "../Logger.h"

const std::array<D3D11_INPUT_ELEMENT_DESC, 1> INPUT_ELEMENTS =
{
	D3D11_INPUT_ELEMENT_DESC { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, offsetof(BasicVertex, Position), D3D11_INPUT_PER_VERTEX_DATA, 0 },
};

BasicShader::BasicShader()
	: m_VertexShader(nullptr), m_PixelShader(nullptr)
	, m_InputLayout(nullptr)
{
	Microsoft::WRL::ComPtr<ID3D10Blob> shaderBlob = nullptr;

	POLARIS_DX_ASSERT(D3DReadFileToBlob(m_PixelShaderSource, shaderBlob.GetAddressOf()), "Failed to load BasicPixelShader.cso!");
	POLARIS_DX_ASSERT(Graphics::GetDevice()->CreatePixelShader(shaderBlob->GetBufferPointer(), shaderBlob->GetBufferSize(), nullptr, m_PixelShader.GetAddressOf()), "Failed to create ID3D11PixelShader for BasicShader!");

	POLARIS_DX_ASSERT(D3DReadFileToBlob(m_VertexShaderSource, shaderBlob.GetAddressOf()), "Failed to load BasicVertexShader.cso!");
	POLARIS_DX_ASSERT(Graphics::GetDevice()->CreateVertexShader(shaderBlob->GetBufferPointer(), shaderBlob->GetBufferSize(), nullptr, m_VertexShader.GetAddressOf()), "Failed to create ID3D11VertexShader for BasicShader!");

	POLARIS_DX_ASSERT(Graphics::GetDevice()->CreateInputLayout(INPUT_ELEMENTS.data(), INPUT_ELEMENTS.size(), shaderBlob->GetBufferPointer(), shaderBlob->GetBufferSize(), m_InputLayout.GetAddressOf()), "Failed to create ID3D11InputLayout for BasicShader!");

	Graphics::GetDeviceContext()->IASetInputLayout(m_InputLayout.Get());

	Graphics::GetDeviceContext()->VSSetShader(m_VertexShader.Get(), nullptr, 0);
	Graphics::GetDeviceContext()->PSSetShader(m_PixelShader.Get(), nullptr, 0);
}