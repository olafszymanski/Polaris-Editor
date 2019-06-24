#pragma once

#include "../Graphics.h"

class VertexBuffer : protected Graphics
{
public:
	template<typename T, unsigned int N>
	VertexBuffer(const std::array<T, N>& vertices, unsigned int stride = sizeof(T), unsigned int offset = 0);
	template<typename T>
	VertexBuffer(const std::vector<T>& vertices, unsigned int stride = sizeof(T), unsigned int offset = 0);
	~VertexBuffer() = default;

	VertexBuffer(const VertexBuffer& other);
	VertexBuffer& operator=(const VertexBuffer& other);

	void Bind(unsigned int slot = 0);

private:
	Microsoft::WRL::ComPtr<ID3D11Buffer> m_Buffer;

	unsigned int m_Stride, m_Offset;
};

#include "VertexBuffer.ipp"