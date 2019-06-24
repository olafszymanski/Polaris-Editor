#include "../Logger.h"

template<typename T, unsigned int N>
VertexBuffer::VertexBuffer(const std::array<T, N>& vertices, unsigned int stride, unsigned int offset)
	: m_Buffer(nullptr)
	, m_Stride(stride), m_Offset(offset)
{
	D3D11_BUFFER_DESC bufferDesc = { };
	bufferDesc.ByteWidth = sizeof(T) * N;
	bufferDesc.Usage = D3D11_USAGE_DEFAULT;
	bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bufferDesc.CPUAccessFlags = 0;
	bufferDesc.MiscFlags = 0;
	bufferDesc.StructureByteStride = m_Stride;

	D3D11_SUBRESOURCE_DATA subresourceData = { };
	subresourceData.pSysMem = vertices.data();
	subresourceData.SysMemPitch = 0;
	subresourceData.SysMemSlicePitch = 0;

	POLARIS_DX_ASSERT(Graphics::GetDevice()->CreateBuffer(&bufferDesc, &subresourceData, m_Buffer.GetAddressOf()), "Failed to create ID3D11Buffer for VertexBuffer!");
}
template<typename T>
VertexBuffer::VertexBuffer(const std::vector<T>& vertices, unsigned int stride, unsigned int offset)
	: m_Buffer(nullptr)
	, m_Stride(stride), m_Offset(offset)
{
	D3D11_BUFFER_DESC bufferDesc = { };
	bufferDesc.ByteWidth = sizeof(T) * vertices.size();
	bufferDesc.Usage = D3D11_USAGE_DEFAULT;
	bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bufferDesc.CPUAccessFlags = 0;
	bufferDesc.MiscFlags = 0;
	bufferDesc.StructureByteStride = m_Stride;

	D3D11_SUBRESOURCE_DATA subresourceData = { };
	subresourceData.pSysMem = vertices.data();
	subresourceData.SysMemPitch = 0;
	subresourceData.SysMemSlicePitch = 0;

	POLARIS_DX_ASSERT(Graphics::GetDevice()->CreateBuffer(&bufferDesc, &subresourceData, m_Buffer.GetAddressOf()), "Failed to create ID3D11Buffer for VertexBuffer!");
}