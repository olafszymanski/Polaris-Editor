#pragma once

#include "Light.h"

class SpotLight : public Light
{
public:
	SpotLight(const DirectX::SimpleMath::Vector3& position, float cutOff, const DirectX::SimpleMath::Vector3& direction, const DirectX::SimpleMath::Vector3& attenuation, const DirectX::SimpleMath::Vector4& ambient = { 1.0f, 1.0f, 1.0f, 1.0f }, const DirectX::SimpleMath::Vector4& diffuse = { 1.0f, 1.0f, 1.0f, 1.0f }, const DirectX::SimpleMath::Vector4& specular = { 1.0f, 1.0f, 1.0f, 1.0f }, float intensity = 1.0f);
	SpotLight(const DirectX::SimpleMath::Vector3& position, float cutOff, const DirectX::SimpleMath::Vector3& direction, const DirectX::SimpleMath::Vector3& attenuation, const DirectX::SimpleMath::Vector3& color, float intensity = 1.0f);
	~SpotLight();

	// Getters
	inline const DirectX::SimpleMath::Vector3& GetPosition() const { return m_Position; }
	inline const float& GetCutOff() const { return m_CutOff; }

	inline const DirectX::SimpleMath::Vector3& GetDirection() { return m_Direction; }

	inline const DirectX::SimpleMath::Vector3& GetAttenuation() const { return m_Attenuation; }

	// Setters
	inline void SetPosition(const DirectX::SimpleMath::Vector3& position) { m_Position = position; }
	inline void SetCutOff(float cutOff) { m_CutOff = cutOff; }

	inline void SetDirection(const DirectX::SimpleMath::Vector3& direction) { m_Direction = direction; }

	inline void SetAttenuation(const DirectX::SimpleMath::Vector3& attenuation) { m_Attenuation = attenuation; }

private:
	DirectX::SimpleMath::Vector3 m_Position;

	float m_CutOff;

	DirectX::SimpleMath::Vector3 m_Direction;
	float m_DirectionPadding;

	DirectX::SimpleMath::Vector3 m_Attenuation;
	float m_AttenuationPadding;
};