#include "pch.h"

#include "Camera.h"

#include "../Window.h"

Camera::Camera(const Window& window, const DirectX::SimpleMath::Vector3& position, const DirectX::SimpleMath::Vector2& rotation, float fieldOfView, float nearPlane, float farPlane)
	: m_Window(&window)
	, m_Position(position), m_Rotation(rotation), m_LastRotation(m_Rotation), m_Forward(0.0f, 0.0f, -1.0f), m_Up(0.0f, 1.0f, 0.0f)
	, m_FieldOfView(fieldOfView), m_NearPlane(nearPlane), m_FarPlane(farPlane)
	, m_ViewMatrix(DirectX::SimpleMath::Matrix::CreateLookAt(m_Position, m_Position + m_Forward, m_Up)), m_ProjectionMatrix(DirectX::SimpleMath::Matrix::CreatePerspectiveFieldOfView(m_FieldOfView, static_cast<float>(m_Window->GetWidth()) / static_cast<float>(m_Window->GetHeight()), m_NearPlane, m_FarPlane)), m_Matrix(m_ViewMatrix * m_ProjectionMatrix)
	, m_UpdateViewMatrix(false), m_UpdateProjectionMatrix(false)
{
}

Camera::Camera(const Camera& other)
	: m_Window(other.m_Window)
	, m_Position(other.m_Position), m_Rotation(other.m_Rotation), m_LastRotation(other.m_Rotation), m_Forward(other.m_Forward), m_Up(other.m_Up)
	, m_FieldOfView(other.m_FieldOfView), m_NearPlane(other.m_NearPlane), m_FarPlane(other.m_FarPlane)
	, m_ViewMatrix(other.m_ViewMatrix), m_ProjectionMatrix(other.m_ProjectionMatrix), m_Matrix(other.m_Matrix)
	, m_UpdateViewMatrix(other.m_UpdateViewMatrix), m_UpdateProjectionMatrix(other.m_UpdateProjectionMatrix)
{
}
Camera& Camera::operator=(const Camera& other)
{
	if (this != &other)
	{
		m_Window = other.m_Window;

		m_Position = other.m_Position;
		m_Rotation = other.m_Rotation;
		m_LastRotation = other.m_LastRotation;
		m_Forward = other.m_Forward;
		m_Up = other.m_Up;

		m_FieldOfView = other.m_FieldOfView;
		m_NearPlane = other.m_NearPlane;
		m_FarPlane = other.m_FarPlane;

		m_ViewMatrix = other.m_ViewMatrix;
		m_ProjectionMatrix = other.m_ProjectionMatrix;
		m_Matrix = other.m_Matrix;

		m_UpdateViewMatrix = other.m_UpdateViewMatrix;
		m_UpdateProjectionMatrix = other.m_UpdateProjectionMatrix;
	}

	return *this;
}

void Camera::Update(float deltaTime)
{
	if (m_UpdateViewMatrix)
	{
		m_Forward.x = cos(DirectX::XMConvertToRadians(m_Rotation.x)) * cos(DirectX::XMConvertToRadians(m_Rotation.y));
		m_Forward.y = sin(DirectX::XMConvertToRadians(m_Rotation.y));
		m_Forward.z = sin(DirectX::XMConvertToRadians(m_Rotation.x)) * cos(DirectX::XMConvertToRadians(m_Rotation.y));

		m_Forward.Normalize();

		m_ViewMatrix = DirectX::SimpleMath::Matrix::CreateLookAt(m_Position, m_Position + m_Forward, m_Up);

		m_Matrix = m_ViewMatrix * m_ProjectionMatrix;

		m_UpdateViewMatrix = false;
	}

	if (m_UpdateProjectionMatrix)
	{
		m_ProjectionMatrix = DirectX::SimpleMath::Matrix::CreatePerspectiveFieldOfView(m_FieldOfView, static_cast<float>(m_Window->GetWidth()) / static_cast<float>(m_Window->GetHeight()), m_NearPlane, m_FarPlane);

		m_Matrix = m_ViewMatrix * m_ProjectionMatrix;

		m_UpdateProjectionMatrix = false;
	}
}