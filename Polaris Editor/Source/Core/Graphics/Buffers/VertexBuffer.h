#pragma once

#include "../../Types/Vertex.h"

class VertexBuffer
{
public:
	template<unsigned int N>
	VertexBuffer(const std::array<Vertex, N>& vertices, unsigned int stride = sizeof(Vertex), unsigned int offset = 0);
	VertexBuffer(const std::vector<Vertex>& vertices, unsigned int stride = sizeof(Vertex), unsigned int offset = 0);
	~VertexBuffer() = default;

	VertexBuffer(const VertexBuffer& other);
	VertexBuffer& operator=(const VertexBuffer& other);

	void Bind(unsigned int slot = 0) const;

private:
	Microsoft::WRL::ComPtr<ID3D11Buffer> m_Buffer;

	unsigned int m_Stride, m_Offset;
};

#include "VertexBuffer.ipp"