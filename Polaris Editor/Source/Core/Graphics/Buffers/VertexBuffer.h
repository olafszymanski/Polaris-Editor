#pragma once

#include "../../Structures/Structures.h"

class VertexBuffer
{
public:
	template<unsigned int N>
	VertexBuffer(const std::array<VertexStructure, N>& vertices, unsigned int stride = sizeof(VertexStructure), unsigned int offset = 0);
	VertexBuffer(const std::vector<VertexStructure>& vertices, unsigned int stride = sizeof(VertexStructure), unsigned int offset = 0);
	~VertexBuffer() = default;

	VertexBuffer(const VertexBuffer& other);
	VertexBuffer& operator=(const VertexBuffer& other);

	void Bind(unsigned int slot = 0) const;

private:
	Microsoft::WRL::ComPtr<ID3D11Buffer> m_Buffer;

	unsigned int m_Stride, m_Offset;
};

#include "VertexBuffer.ipp"