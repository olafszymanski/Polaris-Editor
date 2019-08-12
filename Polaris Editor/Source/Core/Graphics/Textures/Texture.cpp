#include "pch.h"

#include "Texture.h"

#include "../Graphics.h"

#include "../Managers/ResourceManager.h"

#include <DDSTextureLoader.h>
#include <WICTextureLoader.h>

#include "../../../Utils/StringHelper.h"

#include "../../Logger.h"

Texture::Texture(const std::string& filePath)
	: m_ShaderTextureView(nullptr)
{
	if (ResourceManager::TextureExists(filePath)) *this = ResourceManager::GetTexture(filePath);
	else
	{
		Microsoft::WRL::ComPtr<ID3D11Resource> texture = nullptr;

		if (StringHelper::GetFileExtension(filePath) == ".dds") { POLARIS_DX_ASSERT(DirectX::CreateWICTextureFromFile(Graphics::GetDevice().Get(), std::wstring(filePath.begin(), filePath.end()).c_str(), texture.GetAddressOf(), m_ShaderTextureView.GetAddressOf()), "Failed to load '" + filePath + "'!"); }
		else POLARIS_DX_ASSERT(DirectX::CreateWICTextureFromFile(Graphics::GetDevice().Get(), std::wstring(filePath.begin(), filePath.end()).c_str(), texture.GetAddressOf(), m_ShaderTextureView.GetAddressOf()), "Failed to load '" + filePath + "'!");

		ResourceManager::AddTexture(*this, filePath);
	}
}
Texture::Texture(unsigned int width, unsigned int height, const DirectX::SimpleMath::Vector4& color)
	: m_ShaderTextureView(nullptr)
{
	Microsoft::WRL::ComPtr<ID3D11Texture2D> texture = nullptr;

	D3D11_TEXTURE2D_DESC textureDesc { };
	textureDesc.Width = width;
	textureDesc.Height = height;
	textureDesc.MipLevels = 1;
	textureDesc.ArraySize = 1;
	textureDesc.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
	textureDesc.SampleDesc.Count = 1;
	textureDesc.SampleDesc.Quality = 0;
	textureDesc.Usage = D3D11_USAGE_DEFAULT;
	textureDesc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
	textureDesc.CPUAccessFlags = 0;
	textureDesc.MiscFlags = 0;

	D3D11_SUBRESOURCE_DATA subresourceData { };
	subresourceData.pSysMem = &color;
	subresourceData.SysMemPitch = width * sizeof(float);
	subresourceData.SysMemSlicePitch = 0;

	POLARIS_DX_ASSERT(Graphics::GetDevice()->CreateTexture2D(&textureDesc, &subresourceData, texture.GetAddressOf()), "Failed to create ID3D11Texture2D!");

	POLARIS_DX_ASSERT(Graphics::GetDevice()->CreateShaderResourceView(texture.Get(), nullptr, m_ShaderTextureView.GetAddressOf()), "Failed to create ID3D11ShaderResourceView!");
}
Texture::Texture(unsigned int size, const uint8_t* data)
	: m_ShaderTextureView(nullptr)
{
	Microsoft::WRL::ComPtr<ID3D11Resource> texture = nullptr;

	POLARIS_DX_ASSERT(DirectX::CreateWICTextureFromMemory(Graphics::GetDevice().Get(), data, size, texture.GetAddressOf(), m_ShaderTextureView.GetAddressOf()), "Failed to load embedded texture!");
}

Texture::Texture(const Texture& other)
	: m_ShaderTextureView(other.m_ShaderTextureView)
{
}
Texture& Texture::operator=(const Texture& other)
{
	if (this != &other) m_ShaderTextureView = other.m_ShaderTextureView;

	return *this;
}

void Texture::Bind(unsigned int slot) const
{
	Graphics::GetDeviceContext()->PSSetShaderResources(slot, 1, m_ShaderTextureView.GetAddressOf());
}