#include "../pch.h"

#include "IndexBuffer.h"

IndexBuffer::IndexBuffer(const std::vector<unsigned short>& indices)
	: m_Buffer(nullptr)
	, m_Format(DXGI_FORMAT_R16_UINT)
{
	D3D11_BUFFER_DESC bufferDesc = { };
	bufferDesc.ByteWidth = sizeof(unsigned short) * indices.size();
	bufferDesc.Usage = D3D11_USAGE_IMMUTABLE;
	bufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	bufferDesc.CPUAccessFlags = 0;
	bufferDesc.MiscFlags = 0;
	bufferDesc.StructureByteStride = 0;

	D3D11_SUBRESOURCE_DATA subresourceData = { };
	subresourceData.pSysMem = indices.data();
	subresourceData.SysMemPitch = 0;
	subresourceData.SysMemSlicePitch = 0;

	POLARIS_DX_ASSERT(Graphics::GetDevice()->CreateBuffer(&bufferDesc, &subresourceData, m_Buffer.GetAddressOf()), "Failed to create ID3D11Buffer for IndexBuffer!");
}
IndexBuffer::IndexBuffer(const std::vector<unsigned int>& indices)
	: m_Buffer(nullptr) 
	, m_Format(DXGI_FORMAT_R32_UINT)
{
	D3D11_BUFFER_DESC bufferDesc = { };
	bufferDesc.ByteWidth = sizeof(unsigned int) * indices.size();
	bufferDesc.Usage = D3D11_USAGE_IMMUTABLE;
	bufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	bufferDesc.CPUAccessFlags = 0;
	bufferDesc.MiscFlags = 0;
	bufferDesc.StructureByteStride = 0;

	D3D11_SUBRESOURCE_DATA subresourceData = { };
	subresourceData.pSysMem = indices.data();
	subresourceData.SysMemPitch = 0;
	subresourceData.SysMemSlicePitch = 0;

	POLARIS_DX_ASSERT(Graphics::GetDevice()->CreateBuffer(&bufferDesc, &subresourceData, m_Buffer.GetAddressOf()), "Failed to create ID3D11Buffer for IndexBuffer!");
}

IndexBuffer::IndexBuffer(const IndexBuffer& other)
	: m_Buffer(other.m_Buffer)
	, m_Format(other.m_Format)
{
}
IndexBuffer& IndexBuffer::operator=(const IndexBuffer& other)
{
	if (this != &other)
	{
		m_Buffer = other.m_Buffer;

		m_Format = other.m_Format;
	}

	return *this;
}

void IndexBuffer::Bind() const
{
	Graphics::GetDeviceContext()->IASetIndexBuffer(m_Buffer.Get(), m_Format, 0);
}