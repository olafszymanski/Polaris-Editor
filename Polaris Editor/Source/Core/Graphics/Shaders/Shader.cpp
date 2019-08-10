#include "pch.h"

#include "Shader.h"

#include "../Graphics.h"

Shader::Shader()
	: m_SamplerState(nullptr)
	, m_MatricesBuffer({ }), m_LightingBuffer({ }), m_MaterialBuffer({ })
{
	D3D11_SAMPLER_DESC samplerDesc { };
	samplerDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
	samplerDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;

	POLARIS_DX_ASSERT(Graphics::GetDevice()->CreateSamplerState(&samplerDesc, m_SamplerState.GetAddressOf()), "Failed to create ID3D11SamplerState!");
}

void Shader::UpdateLighting(const Lighting& lighting)
{
	m_LightingBuffer.Update(lighting);
}
void Shader::UpdateMatrices(const Matrices& matrices)
{
	m_MatricesBuffer.Update(matrices);
}
void Shader::UpdateMaterial(const Material& material)
{
	m_MaterialBuffer.Update(material);
}