#include "pch.h"

#include "Texture.h"

#include "../Graphics.h"

#include "../../Logger.h"

Texture::Texture(const std::string& filePath)
	: m_ShaderTextureView(nullptr), m_SamplerState(nullptr)
{
	Microsoft::WRL::ComPtr<ID3D11Resource> texture = nullptr;
	POLARIS_DX_ASSERT(DirectX::CreateWICTextureFromFile(Graphics::GetDevice().Get(), std::wstring(filePath.begin(), filePath.end()).c_str(), texture.GetAddressOf(), m_ShaderTextureView.GetAddressOf()), "Failed to load '" + filePath + "'!");

	D3D11_SAMPLER_DESC samplerDesc { };
	samplerDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
	samplerDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;

	POLARIS_DX_ASSERT(Graphics::GetDevice()->CreateSamplerState(&samplerDesc, m_SamplerState.GetAddressOf()), "Failed to create ID3D11SamplerState!");
}

Texture::Texture(const Texture& other)
	: m_ShaderTextureView(other.m_ShaderTextureView), m_SamplerState(other.m_SamplerState)
{
}
Texture& Texture::operator=(const Texture& other)
{
	if (this != &other)
	{
		m_ShaderTextureView = other.m_ShaderTextureView;
		m_SamplerState = other.m_SamplerState;
	}

	return *this;
}

void Texture::Bind(unsigned int slot) const
{
	Graphics::GetDeviceContext()->PSSetShaderResources(slot, 1, m_ShaderTextureView.GetAddressOf());
	Graphics::GetDeviceContext()->PSSetSamplers(slot, 1, m_SamplerState.GetAddressOf());
}