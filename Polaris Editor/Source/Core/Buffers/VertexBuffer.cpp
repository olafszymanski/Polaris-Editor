#include "../pch.h"

#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(const VertexBuffer& other)
{
	m_Buffer = other.m_Buffer;

	m_Stride = other.m_Stride;
	m_Offset = other.m_Offset;
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

void VertexBuffer::Bind(unsigned int slot)
{
	Graphics::GetDeviceContext()->IASetVertexBuffers(slot, 1, m_Buffer.GetAddressOf(), &m_Stride, &m_Offset);
}