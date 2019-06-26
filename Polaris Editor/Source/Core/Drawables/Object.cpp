#include "../pch.h"

#include "Object.h"

Object::Object(Mesh mesh, const DirectX::XMFLOAT3& position, const DirectX::XMFLOAT3& rotation, const DirectX::XMFLOAT3& scale)
	: m_Mesh(mesh)
	, m_Position(position), m_Rotation(rotation), m_Scale(scale)
	, m_Matrix(DirectX::XMMatrixTranspose(DirectX::XMMatrixTranslation(m_Position.x, m_Position.y, m_Position.z) * DirectX::XMMatrixRotationRollPitchYaw(m_Rotation.x, m_Rotation.y, m_Rotation.z) * DirectX::XMMatrixScaling(m_Scale.x, m_Scale.y, m_Scale.z)))
{
}

Object::Object(const Object& other)
	: m_Mesh(other.m_Mesh)
	, m_Position(other.m_Position), m_Rotation(other.m_Rotation), m_Scale(other.m_Scale)
	, m_Matrix(other.m_Matrix)
{
}
Object& Object::operator=(const Object& other)
{
	if (this != &other)
	{
		m_Mesh = other.m_Mesh;

		m_Position = other.m_Position;
		m_Rotation = other.m_Rotation;
		m_Scale = other.m_Scale;

		m_Matrix = other.m_Matrix;
	}

	return *this;
}

void Object::Bind() const
{
	m_Mesh.Bind();
}

void Object::Update()
{
	m_Matrix = DirectX::XMMatrixTranspose(DirectX::XMMatrixTranslation(m_Position.x, m_Position.y, m_Position.z) * DirectX::XMMatrixRotationRollPitchYaw(m_Rotation.x, m_Rotation.y, m_Rotation.z) * DirectX::XMMatrixScaling(m_Scale.x, m_Scale.y, m_Scale.z));
}