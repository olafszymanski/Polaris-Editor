#pragma once

#include "Camera.h"

class FreeCamera : public Camera
{
public:
	FreeCamera(const Window& window, const DirectX::SimpleMath::Vector3& position = { 0.0f, 0.0f, 0.0f }, const DirectX::SimpleMath::Vector2& rotation = { 0.0f, 0.0f }, float fieldOfView = DirectX::XM_PIDIV4, float nearPlane = 0.1f, float farPlane = 100.0f, float movementSpeed = 10.0f, float rotationSpeed = 10.0f);
	~FreeCamera() = default;

	FreeCamera(const FreeCamera& other);
	FreeCamera& operator=(const FreeCamera& other);

	virtual void Update(float deltaTime) override;

	// Getters
	inline const float& GetMovementSpeed() const { return m_MovementSpeed; }
	inline const float& GetRotationSpeed() const { return m_RotationSpeed; }

	// Setters
	inline void SetMovementSpeed(float movementSpeed) { m_MovementSpeed = movementSpeed; }
	inline void SetRotationSpeed(float rotationSpeed) { m_RotationSpeed = rotationSpeed; }

private:
	bool m_UseLastRotation;

	float m_MovementSpeed, m_RotationSpeed;
};