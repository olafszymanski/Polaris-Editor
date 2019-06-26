#pragma once

#include "Drawable.h"

struct BasicVertex;

#include "../Buffers/VertexBuffer.h"
#include "../Buffers/IndexBuffer.h"

class Mesh : public Drawable
{
public:
	template<unsigned int V_N, unsigned int I_N>
	Mesh(const std::array<BasicVertex, V_N>& vertices, const std::array<unsigned short, I_N>& indices);
	template<unsigned int V_N, unsigned int I_N>
	Mesh(const std::array<BasicVertex, V_N>& vertices, const std::array<unsigned int, I_N>& indices);
	template<unsigned int N>
	Mesh(const std::vector<BasicVertex>& vertices, const std::array<unsigned short, N>& indices);
	template<unsigned int N>
	Mesh(const std::vector<BasicVertex>& vertices, const std::array<unsigned int, N>& indices);
	Mesh(const std::vector<BasicVertex>& vertices, const std::vector<unsigned short>& indices);
	Mesh(const std::vector<BasicVertex>& vertices, const std::vector<unsigned int>& indices);
	~Mesh() = default;

	void Bind() const;

	// Getter
	virtual unsigned int GetIndexCount() const override { return m_IndexCount; }

private:
	VertexBuffer m_VertexBuffer;
	IndexBuffer m_IndexBuffer;

	unsigned int m_IndexCount;
};

#include "Mesh.ipp"