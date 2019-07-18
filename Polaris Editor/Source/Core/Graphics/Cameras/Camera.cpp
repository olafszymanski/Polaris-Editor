#include "pch.h"

#include "Camera.h"

#include "../Window.h"

Camera::Camera(const Window& window, const DirectX::SimpleMath::Vector3& position, const DirectX::SimpleMath::Vector3& rotation, float fieldOfView, float nearPlane, float farPlane)
	: m_Position(position), m_Rotation(rotation)
	, m_ViewMatrix(DirectX::SimpleMath::Matrix::CreateTranslation(m_Position) * DirectX::SimpleMath::Matrix::CreateFromYawPitchRoll(m_Rotation.x, m_Rotation.y, m_Rotation.z)), m_ProjectionMatrix(DirectX::SimpleMath::Matrix::CreatePerspectiveFieldOfView(fieldOfView, static_cast<float>(window.GetWidth()) / static_cast<float>(window.GetHeight()), nearPlane, farPlane)), m_Matrix(m_ViewMatrix * m_ProjectionMatrix)
	, m_UpdateMatrices(false)
{
}

Camera::Camera(const Camera& other)
	: m_Position(other.m_Position), m_Rotation(other.m_Rotation)
	, m_ViewMatrix(other.m_ViewMatrix), m_ProjectionMatrix(other.m_ProjectionMatrix), m_Matrix(other.m_Matrix)
	, m_UpdateMatrices(other.m_UpdateMatrices)
{
}
Camera& Camera::operator=(const Camera& other)
{
	if (this != &other)
	{
		m_Position = other.m_Position;
		m_Rotation = other.m_Rotation;

		m_ViewMatrix = other.m_ViewMatrix;
		m_ProjectionMatrix = other.m_ProjectionMatrix;
		m_Matrix = other.m_Matrix;

		m_UpdateMatrices = other.m_UpdateMatrices;
	}

	return *this;
}

void Camera::Update()
{
	if (m_UpdateMatrices)
	{
		m_ViewMatrix = DirectX::SimpleMath::Matrix::CreateFromYawPitchRoll(m_Rotation.x, m_Rotation.y, m_Rotation.z) * DirectX::SimpleMath::Matrix::CreateTranslation(m_Position);

		m_Matrix = m_ViewMatrix * m_ProjectionMatrix;

		m_UpdateMatrices = false;
	}
}