#include "pch.h"

#include "Object.h"

Object::Object(const Model& model, const DirectX::SimpleMath::Vector3& position, const DirectX::SimpleMath::Vector3& rotation, const DirectX::SimpleMath::Vector3& scale)
	: m_Model(model)
	, m_Position(position), m_Rotation(rotation), m_Scale(scale)
	, m_Matrix(DirectX::SimpleMath::Matrix::CreateScale(m_Scale.x, m_Scale.y, m_Scale.z) * DirectX::SimpleMath::Matrix::CreateFromYawPitchRoll(m_Rotation.x, m_Rotation.y, m_Rotation.z) * DirectX::SimpleMath::Matrix::CreateTranslation(m_Position.x, m_Position.y, m_Position.z))
	, m_UpdateMatrix(false)
{
}

Object::Object(const Object& other)
	: m_Model(other.m_Model)
	, m_Position(other.m_Position), m_Rotation(other.m_Rotation), m_Scale(other.m_Scale)
	, m_Matrix(other.m_Matrix)
	, m_UpdateMatrix(other.m_UpdateMatrix)
{
}
Object& Object::operator=(const Object& other)
{
	if (this != &other)
	{
		m_Model = other.m_Model;

		m_Position = other.m_Position;
		m_Rotation = other.m_Rotation;
		m_Scale = other.m_Scale;

		m_Matrix = other.m_Matrix;

		m_UpdateMatrix = other.m_UpdateMatrix;
	}

	return *this;
}

void Object::Bind(unsigned int index) const
{
	m_Model.GetMeshes()[index]->Bind();
}

void Object::UpdateMatrix()
{
	if (m_UpdateMatrix)
	{
		m_Matrix = DirectX::SimpleMath::Matrix::CreateScale(m_Scale.x, m_Scale.y, m_Scale.z) * DirectX::SimpleMath::Matrix::CreateFromYawPitchRoll(m_Rotation.x, m_Rotation.y, m_Rotation.z) * DirectX::SimpleMath::Matrix::CreateTranslation(m_Position.x, m_Position.y, m_Position.z);

		m_UpdateMatrix = false;
	}
}
void Object::UpdateMesh(unsigned int index)
{
	m_Model.GetMeshes()[index]->Update();
}