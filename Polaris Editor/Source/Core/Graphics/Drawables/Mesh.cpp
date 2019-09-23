#include "pch.h"

#include "Mesh.h"

Mesh::Mesh(const std::vector<VertexStructure>& vertices, const std::vector<unsigned short>& indices, const MaterialStructure& material, const Texture& diffuseTexture, const Texture& specularTexture, const std::string& name)
	: m_VertexBuffer(vertices), m_IndexBuffer(indices)
	, m_IndexCount(indices.size())
	, m_Material(material)
	, m_DiffuseTexture(diffuseTexture), m_SpecularTexture(specularTexture)
	, m_UpdateDiffuseTexture(false), m_UpdateSpecularTexture(false)
	, m_Name(name)
{
}
Mesh::Mesh(const std::vector<VertexStructure>& vertices, const std::vector<unsigned int>& indices, const MaterialStructure& material, const Texture& diffuseTexture, const Texture& specularTexture, const std::string& name)
	: m_VertexBuffer(vertices), m_IndexBuffer(indices)
	, m_IndexCount(indices.size())
	, m_Material(material)
	, m_DiffuseTexture(diffuseTexture), m_SpecularTexture(specularTexture)
	, m_UpdateDiffuseTexture(false), m_UpdateSpecularTexture(false)
	, m_Name(name)
{
}

Mesh::Mesh(const Mesh& other)
	: m_VertexBuffer(other.m_VertexBuffer), m_IndexBuffer(other.m_IndexBuffer)
	, m_IndexCount(other.m_IndexCount)
	, m_Material(other.m_Material)
	, m_DiffuseTexture(other.m_DiffuseTexture), m_SpecularTexture(other.m_SpecularTexture)
	, m_UpdateDiffuseTexture(other.m_UpdateDiffuseTexture), m_UpdateSpecularTexture(other.m_UpdateSpecularTexture)
	, m_Name(other.m_Name)
{
}
Mesh& Mesh::operator=(const Mesh& other)
{
	if (this != &other)
	{
		m_VertexBuffer = other.m_VertexBuffer;
		m_IndexBuffer = other.m_IndexBuffer;

		m_IndexCount = other.m_IndexCount;
	
		m_Material = other.m_Material;

		m_DiffuseTexture = other.m_DiffuseTexture;
		m_SpecularTexture = other.m_SpecularTexture;

		m_UpdateDiffuseTexture = other.m_UpdateDiffuseTexture;
		m_UpdateDiffuseTexture = other.m_UpdateSpecularTexture;

		m_Name = other.m_Name;
	}

	return *this;
}

void Mesh::Bind() const
{
	m_VertexBuffer.Bind();
	m_IndexBuffer.Bind();
	
	m_DiffuseTexture.Bind(0);
	m_SpecularTexture.Bind(1);
}

void Mesh::Update()
{
	if (m_UpdateDiffuseTexture)
	{
		m_DiffuseTexture.Bind(0);

		m_UpdateDiffuseTexture = false;
	}
	if (m_UpdateSpecularTexture)
	{
		m_SpecularTexture.Bind(1);
	
		m_UpdateSpecularTexture = false;
	}
}