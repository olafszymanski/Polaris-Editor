#pragma once

#include "Light.h"

class PointLight : public Light
{
public:
	PointLight(const DirectX::SimpleMath::Vector3& position, const DirectX::SimpleMath::Vector3& attenuation, const DirectX::SimpleMath::Vector4& ambient = { 1.0f, 1.0f, 1.0f, 1.0f }, const DirectX::SimpleMath::Vector4& diffuse = { 1.0f, 1.0f, 1.0f, 1.0f }, const DirectX::SimpleMath::Vector4& specular = { 1.0f, 1.0f, 1.0f, 1.0f }, float intensity = 1.0f);
	PointLight(const DirectX::SimpleMath::Vector3& position, const DirectX::SimpleMath::Vector3& attenuation, const DirectX::SimpleMath::Vector3& color, float intensity = 1.0f);
	~PointLight();

	// Getters
	inline const DirectX::SimpleMath::Vector3& GetPosition() const { return m_Position; }

	inline const DirectX::SimpleMath::Vector3& GetAttenuation() const { return m_Attenuation; }

	// Setters
	inline void SetPosition(const DirectX::SimpleMath::Vector3& position) { m_Position = position; }

	inline void SetAttenuation(const DirectX::SimpleMath::Vector3& attenuation) { m_Attenuation = attenuation; }

private:
	DirectX::SimpleMath::Vector3 m_Position;
	float m_PositionPadding;

	DirectX::SimpleMath::Vector3 m_Attenuation;
	float m_AttenuationPadding;
};