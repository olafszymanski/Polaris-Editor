#include "../pch.h"

#include "Mesh.h"

Mesh::Mesh(const std::vector<BasicVertex>& vertices, const std::vector<unsigned short>& indices)
	: m_VertexBuffer(vertices), m_IndexBuffer(indices)
	, m_IndexCount(indices.size())
{
}
Mesh::Mesh(const std::vector<BasicVertex>& vertices, const std::vector<unsigned int>& indices)
	: m_VertexBuffer(vertices), m_IndexBuffer(indices)
	, m_IndexCount(indices.size())
{
}

void Mesh::Bind() const
{
	m_VertexBuffer.Bind();
	m_IndexBuffer.Bind();
}