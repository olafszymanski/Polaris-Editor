#include "pch.h"

#include "FreeCamera.h"

#include "../../Input/Keyboard.h"
#include "../../Input/Mouse.h"

FreeCamera::FreeCamera(const Window& window, const DirectX::SimpleMath::Vector3& position, const DirectX::SimpleMath::Vector2& rotation, float fieldOfView, float nearPlane, float farPlane, float movementSpeed, float rotationSpeed)
	: Camera(window, position, rotation, fieldOfView, nearPlane, farPlane)
	, m_UseLastRotation(false)
	, m_MovementSpeed(movementSpeed), m_RotationSpeed(rotationSpeed)
{
}

FreeCamera::FreeCamera(const FreeCamera& other)
	: Camera(*other.m_Window, other.m_Position, other.m_Rotation, other.m_FieldOfView, other.m_NearPlane, other.m_FarPlane)
	, m_UseLastRotation(other.m_UseLastRotation)
	, m_MovementSpeed(other.m_MovementSpeed), m_RotationSpeed(other.m_RotationSpeed)
{
}
FreeCamera& FreeCamera::operator=(const FreeCamera& other)
{
	if (this != &other)
	{
		m_Window = other.m_Window;

		m_Position = other.m_Position;
		m_Rotation = other.m_Rotation;
		m_LastRotation = other.m_LastRotation;
		m_Forward = other.m_Forward;
		m_Up = other.m_Up;

		m_UseLastRotation = other.m_UseLastRotation;

		m_FieldOfView = other.m_FieldOfView;
		m_NearPlane = other.m_NearPlane;
		m_FarPlane = other.m_FarPlane;

		m_ViewMatrix = other.m_ViewMatrix;
		m_ProjectionMatrix = other.m_ProjectionMatrix;
		m_Matrix = other.m_Matrix;

		m_UpdateViewMatrix = other.m_UpdateViewMatrix;
		m_UpdateProjectionMatrix = other.m_UpdateProjectionMatrix;

		m_MovementSpeed = other.m_MovementSpeed;
		m_RotationSpeed = other.m_RotationSpeed;
	}

	return *this;
}

void FreeCamera::Update(float deltaTime)
{
	if (Mouse::IsButtonHeld(MouseButton::RIGHT))
	{
		if (Keyboard::IsKeyDown(DirectX::Keyboard::W)) m_Position += m_MovementSpeed * m_Forward * deltaTime;
		if (Keyboard::IsKeyDown(DirectX::Keyboard::S)) m_Position -= m_MovementSpeed * m_Forward * deltaTime;
		if (Keyboard::IsKeyDown(DirectX::Keyboard::A))
		{
			DirectX::SimpleMath::Vector3 right(0.0f, 0.0f, 0.0f);
			m_Forward.Cross(m_Up).Normalize(right);

			m_Position -= m_MovementSpeed * right * deltaTime;
		}
		if (Keyboard::IsKeyDown(DirectX::Keyboard::D))
		{
			DirectX::SimpleMath::Vector3 right(0.0f, 0.0f, 0.0f);
			m_Forward.Cross(m_Up).Normalize(right);

			m_Position += m_MovementSpeed * right * deltaTime;
		}
		if (Keyboard::IsKeyDown(DirectX::Keyboard::Space)) m_Position += m_MovementSpeed * m_Up * deltaTime;
		if (Keyboard::IsKeyDown(DirectX::Keyboard::LeftControl)) m_Position -= m_MovementSpeed * m_Up * deltaTime;

		if (Mouse::IsAbsolute()) Mouse::SetRelative();

		if (m_UseLastRotation)
		{
			m_Rotation = m_LastRotation;

			m_UseLastRotation = false;
		}
		else
		{
			MousePosition position = Mouse::GetPosition();

			m_Rotation.x += position.X * m_RotationSpeed * deltaTime;
			m_Rotation.y -= position.Y * m_RotationSpeed * deltaTime;

			if (m_Rotation.x > 360.0f || m_Rotation.x < -360.0f) m_Rotation.x = 0.0f;

			if (m_Rotation.y > 80.0f) m_Rotation.y = 80.0f;
			else if (m_Rotation.y < -80.0f) m_Rotation.y = -80.0f;
		}

		m_LastRotation = m_Rotation;

		m_UpdateViewMatrix = true;
	}
	else
	{
		if (Mouse::IsRelative()) Mouse::SetAbsolute();

		m_UseLastRotation = true;
	}

	Camera::Update(deltaTime);
}