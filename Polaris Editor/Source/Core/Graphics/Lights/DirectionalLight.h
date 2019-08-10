#pragma once

#include "Light.h"

class DirectionalLight : public Light
{
public:
	DirectionalLight();
	DirectionalLight(const DirectX::SimpleMath::Vector3& direction, const DirectX::SimpleMath::Vector4& ambient = { 1.0f, 1.0f, 1.0f, 1.0f }, const DirectX::SimpleMath::Vector4& diffuse = { 1.0f, 1.0f, 1.0f, 1.0f }, const DirectX::SimpleMath::Vector4& specular = { 1.0f, 1.0f, 1.0f, 1.0f }, float intensity = 1.0f);
	DirectionalLight(const DirectX::SimpleMath::Vector3& direction, const DirectX::SimpleMath::Vector3& color, float intensity = 1.0f);
	~DirectionalLight() = default;

	DirectionalLight(const DirectionalLight& other);
	DirectionalLight& operator=(const DirectionalLight& other);

	// Getter
	inline const DirectX::SimpleMath::Vector3& GetDirection() const { return m_Direction; }

	// Setter
	inline void SetDirection(const DirectX::SimpleMath::Vector3& direction) { m_Direction = direction; }

private:
	DirectX::SimpleMath::Vector3 m_Direction;
	float m_DirectionPadding;
};