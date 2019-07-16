#pragma once

#include "../../Types/BasicVertex.h"

struct BasicVertex;

class VertexBuffer
{
public:
	template<unsigned int N>
	VertexBuffer(const std::array<BasicVertex, N>& vertices, unsigned int stride = sizeof(BasicVertex), unsigned int offset = 0);
	VertexBuffer(const std::vector<BasicVertex>& vertices, unsigned int stride = sizeof(BasicVertex), unsigned int offset = 0);
	~VertexBuffer() = default;

	VertexBuffer(const VertexBuffer& other);
	VertexBuffer& operator=(const VertexBuffer& other);

	void Bind(unsigned int slot = 0) const;

private:
	Microsoft::WRL::ComPtr<ID3D11Buffer> m_Buffer;

	unsigned int m_Stride, m_Offset;
};

#include "VertexBuffer.ipp"