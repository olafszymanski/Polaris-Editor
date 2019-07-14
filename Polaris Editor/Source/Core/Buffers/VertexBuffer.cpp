#include "pch.h"

#include "VertexBuffer.h"

#include "../Graphics.h"

VertexBuffer::VertexBuffer(const std::vector<BasicVertex>& vertices, unsigned int stride, unsigned int offset)
	: m_Buffer(nullptr)
	, m_Stride(stride), m_Offset(offset)
{
	D3D11_BUFFER_DESC bufferDesc { };
	bufferDesc.ByteWidth = sizeof(BasicVertex) * vertices.size();
	bufferDesc.Usage = D3D11_USAGE_DEFAULT;
	bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bufferDesc.CPUAccessFlags = 0;
	bufferDesc.MiscFlags = 0;
	bufferDesc.StructureByteStride = m_Stride;

	D3D11_SUBRESOURCE_DATA subresourceData { };
	subresourceData.pSysMem = vertices.data();
	subresourceData.SysMemPitch = 0;
	subresourceData.SysMemSlicePitch = 0;

	POLARIS_DX_ASSERT(Graphics::GetDevice()->CreateBuffer(&bufferDesc, &subresourceData, m_Buffer.GetAddressOf()), "Failed to create ID3D11Buffer for VertexBuffer!");
}

VertexBuffer::VertexBuffer(const VertexBuffer& other)
	: m_Buffer(other.m_Buffer)
	, m_Stride(other.m_Stride), m_Offset(other.m_Offset)
{
}
VertexBuffer& VertexBuffer::operator=(const VertexBuffer& other)
{
	if (this != &other)
	{
		m_Buffer = other.m_Buffer;

		m_Stride = other.m_Stride;
		m_Offset = other.m_Offset;
	}

	return *this;
}

void VertexBuffer::Bind(unsigned int slot) const
{
	Graphics::GetDeviceContext()->IASetVertexBuffers(slot, 1, m_Buffer.GetAddressOf(), &m_Stride, &m_Offset);
}