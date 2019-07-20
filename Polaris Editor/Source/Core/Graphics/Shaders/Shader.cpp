#include "pch.h"

#include "Shader.h"

#include "../Graphics.h"

Shader::Shader()
	: m_SamplerState(nullptr)
	, m_WorldViewProjection(), m_WorldViewProjectionBuffer(m_WorldViewProjection)
{
	D3D11_SAMPLER_DESC samplerDesc { };
	samplerDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
	samplerDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;

	POLARIS_DX_ASSERT(Graphics::GetDevice()->CreateSamplerState(&samplerDesc, m_SamplerState.GetAddressOf()), "Failed to create ID3D11SamplerState!");
}

void Shader::UpdateWorldViewProjection(const WorldViewProjection& worldViewProjection)
{
	m_WorldViewProjection = worldViewProjection;
	m_WorldViewProjectionBuffer.Update(m_WorldViewProjection);
}