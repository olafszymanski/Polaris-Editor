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

Mesh::Mesh(const Mesh& other)
	: m_VertexBuffer(other.m_VertexBuffer), m_IndexBuffer(other.m_IndexBuffer)
	, m_IndexCount(other.m_IndexCount)
{
}
Mesh& Mesh::operator=(const Mesh& other)
{
	if (this != &other)
	{
		m_VertexBuffer = other.m_VertexBuffer;
		m_IndexBuffer = other.m_IndexBuffer;

		m_IndexCount = other.m_IndexCount;
	}

	return *this;
}

void Mesh::Bind() const
{
	m_VertexBuffer.Bind();
	m_IndexBuffer.Bind();
}