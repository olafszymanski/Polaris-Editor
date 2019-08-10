#include "ConstantBuffer.h"
template<typename T>
ConstantBuffer<T>::ConstantBuffer(const T& data)
	: m_Buffer(nullptr)
{
	D3D11_BUFFER_DESC bufferDesc { };
	bufferDesc.ByteWidth = sizeof(data);
	bufferDesc.Usage = D3D11_USAGE_DEFAULT;
	bufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	bufferDesc.CPUAccessFlags = 0;
	bufferDesc.MiscFlags = 0;
	bufferDesc.StructureByteStride = 0;

	D3D11_SUBRESOURCE_DATA subresourceData { };
	subresourceData.pSysMem = &data;
	subresourceData.SysMemPitch = 0;
	subresourceData.SysMemSlicePitch = 0;

	POLARIS_DX_ASSERT(Graphics::GetDevice()->CreateBuffer(&bufferDesc, &subresourceData, m_Buffer.GetAddressOf()), "Failed to create ID3D11Buffer for ConstantBuffer!");
}

template<typename T>
ConstantBuffer<T>::ConstantBuffer(const ConstantBuffer<T>& other)
	: m_Buffer(other.m_Buffer)
{
}
template<typename T>
ConstantBuffer<T>& ConstantBuffer<T>::operator=(const ConstantBuffer<T>& other)
{
	if (this != &other) m_Buffer = other.m_Buffer;

	return *this;
}

template<typename T>
void ConstantBuffer<T>::BindVertex(unsigned int slot) const
{
	Graphics::GetDeviceContext()->VSSetConstantBuffers(slot, 1, m_Buffer.GetAddressOf());
}
template<typename T>
void ConstantBuffer<T>::BindHull(unsigned int slot) const
{
	Graphics::GetDeviceContext()->HSSetConstantBuffers(slot, 1, m_Buffer.GetAddressOf());
}
template<typename T>
void ConstantBuffer<T>::BindDomain(unsigned int slot) const
{
	Graphics::GetDeviceContext()->DSSetConstantBuffers(slot, 1, m_Buffer.GetAddressOf());
}
template<typename T>
void ConstantBuffer<T>::BindGeometry(unsigned int slot) const
{
	Graphics::GetDeviceContext()->GSSetConstantBuffers(slot, 1, m_Buffer.GetAddressOf());
}
template<typename T>
void ConstantBuffer<T>::BindPixel(unsigned int slot) const
{
	Graphics::GetDeviceContext()->PSSetConstantBuffers(slot, 1, m_Buffer.GetAddressOf());
}
template<typename T>
void ConstantBuffer<T>::BindCompute(unsigned int slot) const
{
	Graphics::GetDeviceContext()->CSSetConstantBuffers(slot, 1, m_Buffer.GetAddressOf());
}

template<typename T>
void ConstantBuffer<T>::Update(const T& data) const
{
	Graphics::GetDeviceContext()->UpdateSubresource(m_Buffer.Get(), 0, nullptr, &data, 0, 0);
}