#pragma once

#include "../../../Utils/NonCopyable.h"

class Window;

class Camera
{
public:
	Camera(const Window& window, const DirectX::SimpleMath::Vector3& position = { 0.0f, 0.0f, 0.0f }, const DirectX::SimpleMath::Vector3& rotation = { 0.0f, 0.0f, 0.0f }, float fieldOfView = DirectX::XM_PIDIV4, float nearPlane = 0.1f, float farPlane = 100.0f);
	~Camera() = default;

	Camera(const Camera& other);
	Camera& operator=(const Camera& other);

	virtual void Update();

	// Getters
	inline const DirectX::SimpleMath::Vector3& GetPosition() const { return m_Position; }
	inline const DirectX::SimpleMath::Vector3& GetRotation() const { return m_Rotation; }

	inline DirectX::SimpleMath::Matrix GetMatrix() const { return m_Matrix; }

	// Setters
	inline void SetPosition(const DirectX::SimpleMath::Vector3& position) 
	{ 
		m_Position = position; 
		
		m_UpdateMatrices = true;
	}
	inline void SetRotation(const DirectX::SimpleMath::Vector3& rotation) 
	{ 
		m_Rotation = rotation; 
	
		m_UpdateMatrices = true;
	}

protected:
	DirectX::SimpleMath::Vector3 m_Position, m_Rotation;

	DirectX::SimpleMath::Matrix m_ViewMatrix, m_ProjectionMatrix, m_Matrix;

private:
	bool m_UpdateMatrices;
};