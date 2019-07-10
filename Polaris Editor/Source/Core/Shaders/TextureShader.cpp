#include "pch.h"

#include "TextureShader.h"

#include "../Logger.h"

#include "../Types/BasicVertex.h"

const std::array<D3D11_INPUT_ELEMENT_DESC, 2> INPUT_ELEMENTS =
{
	D3D11_INPUT_ELEMENT_DESC { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, offsetof(BasicVertex, Position), D3D11_INPUT_PER_VERTEX_DATA, 0 },
	D3D11_INPUT_ELEMENT_DESC { "TEXTURE_COORDINATE", 0, DXGI_FORMAT_R32G32_FLOAT, 0, offsetof(BasicVertex, TextureCoordinate), D3D11_INPUT_PER_VERTEX_DATA, 0 },
};

TextureShader::TextureShader()
	: m_VertexShader(nullptr), m_PixelShader(nullptr)
	, m_InputLayout(nullptr)
	, m_WorldViewProjection(), m_WorldViewProjectionBuffer(m_WorldViewProjection)
{
	Microsoft::WRL::ComPtr<ID3D10Blob> shaderBlob = nullptr;

	POLARIS_DX_ASSERT(D3DReadFileToBlob(m_PixelShaderSource, shaderBlob.GetAddressOf()), "Failed to load TexturePixelShader.cso!");
	POLARIS_DX_ASSERT(Graphics::GetDevice()->CreatePixelShader(shaderBlob->GetBufferPointer(), shaderBlob->GetBufferSize(), nullptr, m_PixelShader.GetAddressOf()), "Failed to create ID3D11PixelShader for BasicShader!");

	POLARIS_DX_ASSERT(D3DReadFileToBlob(m_VertexShaderSource, shaderBlob.GetAddressOf()), "Failed to load TextureVertexShader.cso!");
	POLARIS_DX_ASSERT(Graphics::GetDevice()->CreateVertexShader(shaderBlob->GetBufferPointer(), shaderBlob->GetBufferSize(), nullptr, m_VertexShader.GetAddressOf()), "Failed to create ID3D11VertexShader for BasicShader!");

	POLARIS_DX_ASSERT(Graphics::GetDevice()->CreateInputLayout(INPUT_ELEMENTS.data(), INPUT_ELEMENTS.size(), shaderBlob->GetBufferPointer(), shaderBlob->GetBufferSize(), m_InputLayout.GetAddressOf()), "Failed to create ID3D11InputLayout for BasicShader!");

	Graphics::GetDeviceContext()->IASetInputLayout(m_InputLayout.Get());

	Graphics::GetDeviceContext()->VSSetShader(m_VertexShader.Get(), nullptr, 0);
	Graphics::GetDeviceContext()->PSSetShader(m_PixelShader.Get(), nullptr, 0);

	m_WorldViewProjectionBuffer.BindVertex();
}

void TextureShader::UpdateWorldViewProjection(const WorldViewProjection& worldViewProjection)
{
	m_WorldViewProjection = worldViewProjection;
	m_WorldViewProjectionBuffer.Update(m_WorldViewProjection);
}