template<unsigned int N>
IndexBuffer::IndexBuffer(const std::array<unsigned short, N>& indices)
	: m_Buffer(nullptr)
	, m_Format(DXGI_FORMAT_R16_UINT)
{
	D3D11_BUFFER_DESC bufferDesc = { };
	bufferDesc.ByteWidth = sizeof(unsigned short) * N;
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
template<unsigned int N>
IndexBuffer::IndexBuffer(const std::array<unsigned int, N>& indices)
	: m_Buffer(nullptr)
	, m_Format(DXGI_FORMAT_R32_FLOAT)
{
	D3D11_BUFFER_DESC bufferDesc = { };
	bufferDesc.ByteWidth = sizeof(unsigned int) * N;
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