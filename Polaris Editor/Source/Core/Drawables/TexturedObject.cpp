#include "pch.h"

#include "TexturedObject.h"

TexturedObject::TexturedObject(const Mesh& mesh, const Texture& texture, const DirectX::XMFLOAT3& position, const DirectX::XMFLOAT3& rotation, const DirectX::XMFLOAT3& scale)
	: Object(mesh, position, rotation, scale), m_Texture(texture)
	, m_UpdateTexture(false)
{
}

TexturedObject::TexturedObject(const TexturedObject& other)
	: Object(other), m_Texture(other.m_Texture)
	, m_UpdateTexture(other.m_UpdateTexture)
{
}
TexturedObject& TexturedObject::operator=(const TexturedObject& other)
{
	if (this != &other)
	{
		m_Mesh = other.m_Mesh;

		m_Position = other.m_Position;
		m_Rotation = other.m_Rotation;
		m_Scale = other.m_Scale;

		m_Matrix = other.m_Matrix;

		m_Texture = other.m_Texture;
	
		m_UpdateTexture = other.m_UpdateTexture;
	}

	return *this;
}

void TexturedObject::Bind() const
{
	m_Texture.Bind();
	m_Mesh.Bind();
}

void TexturedObject::Update()
{
	m_Matrix = DirectX::XMMatrixTranspose(DirectX::XMMatrixTranslation(m_Position.x, m_Position.y, m_Position.z) * DirectX::XMMatrixRotationRollPitchYaw(m_Rotation.x, m_Rotation.y, m_Rotation.z) * DirectX::XMMatrixScaling(m_Scale.x, m_Scale.y, m_Scale.z));
	
	if (m_UpdateTexture)
	{
		m_Texture.Bind();
	
		m_UpdateTexture = false;
	}
}