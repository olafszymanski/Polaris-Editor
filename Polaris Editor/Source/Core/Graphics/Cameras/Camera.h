#pragma once

class Window;

class Camera
{
public:
	Camera(const Window& window, const DirectX::SimpleMath::Vector3& position = { 0.0f, 0.0f, 0.0f }, const DirectX::SimpleMath::Vector2& rotation = { 0.0f, 0.0f }, float fieldOfView = DirectX::XM_PIDIV4, float nearPlane = 0.1f, float farPlane = 100.0f);
	virtual ~Camera() = default;

	Camera(const Camera& other);
	Camera& operator=(const Camera& other);

	virtual void Update(float deltaTime);

	// Getters
	inline const DirectX::SimpleMath::Vector3& GetPosition() const { return m_Position; }
	inline const DirectX::SimpleMath::Vector2& GetRotation() const { return m_Rotation; }
	inline const DirectX::SimpleMath::Vector3& GetForward() const { return m_Forward; }
	inline const DirectX::SimpleMath::Vector3& GetUp() const { return m_Up; }

	inline const float& GetFieldOfView() const { return m_FieldOfView; }
	inline const float& GetNearPlane() const { return m_NearPlane; }
	inline const float& GetFarPlane() const { return m_FarPlane; }

	inline const DirectX::SimpleMath::Matrix& GetMatrix() const { return m_Matrix; }

	// Setters
	inline void SetPosition(const DirectX::SimpleMath::Vector3& position) 
	{ 
		m_Position = position;
		
		m_UpdateViewMatrix = true;
	}
	inline void SetRotation(const DirectX::SimpleMath::Vector2& rotation)
	{
		m_Rotation = rotation;
		m_LastRotation = m_Rotation;

		m_UpdateViewMatrix = true;
	}
	inline void SetForward(const DirectX::SimpleMath::Vector3& forward)
	{
		m_Forward = forward;

		m_UpdateViewMatrix = true;
	}
	inline void SetUp(const DirectX::SimpleMath::Vector3& up)
	{
		m_Up = up;

		m_UpdateViewMatrix = true;
	}

	inline void SetFieldOfView(float fieldOfView) 
	{ 
		m_FieldOfView = fieldOfView;

		m_UpdateProjectionMatrix = true;
	}
	inline void SetNearPlane(float nearPlane)
	{ 
		m_NearPlane = nearPlane;

		m_UpdateProjectionMatrix = true;
	}
	inline void SetFarPlane(float farPlane)
	{ 
		m_FarPlane = farPlane;

		m_UpdateProjectionMatrix = true;
	}

protected:
	const Window* m_Window;

	DirectX::SimpleMath::Vector3 m_Position, m_Forward, m_Up;
	DirectX::SimpleMath::Vector2 m_Rotation, m_LastRotation;

	float m_FieldOfView, m_NearPlane, m_FarPlane;

	DirectX::SimpleMath::Matrix m_ViewMatrix, m_ProjectionMatrix, m_Matrix;
	bool m_UpdateViewMatrix, m_UpdateProjectionMatrix;
};