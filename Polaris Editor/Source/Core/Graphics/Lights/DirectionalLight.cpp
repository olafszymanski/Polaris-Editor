#include "pch.h"

#include "DirectionalLight.h"

DirectionalLight::DirectionalLight()
	: Light(LightType::NONE, { 0.0f, 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f, 0.0f }, 0.0f)
	, m_Direction(0.0f, 0.0f, 0.0f), m_DirectionPadding(0.0f)
{
}
DirectionalLight::DirectionalLight(const DirectX::SimpleMath::Vector3& direction, const DirectX::SimpleMath::Vector4& ambient, const DirectX::SimpleMath::Vector4& diffuse, const DirectX::SimpleMath::Vector4& specular, float intensity)
	: Light(LightType::DIRECTIONAL, ambient, diffuse, specular, intensity)
	, m_Direction(direction), m_DirectionPadding(0.0f)
{
}
DirectionalLight::DirectionalLight(const DirectX::SimpleMath::Vector3& direction, const DirectX::SimpleMath::Vector3& color, float intensity)
	: Light(LightType::DIRECTIONAL, color, intensity)
	, m_Direction(direction), m_DirectionPadding(0.0f) {
}

DirectionalLight::DirectionalLight(const DirectionalLight& other)
	: Light(other.m_Type, other.m_Ambient, other.m_Diffuse, other.m_Specular, other.m_Intensity)
	, m_Direction(other.m_Direction), m_DirectionPadding(other.m_DirectionPadding)
{
}
DirectionalLight& DirectionalLight::operator=(const DirectionalLight& other)
{
	if (this != &other)
	{
		m_Type = other.m_Type;
		m_TypePadding = other.m_TypePadding;

		m_Intensity = other.m_Intensity;

		m_Ambient = other.m_Ambient;
		m_Diffuse = other.m_Diffuse;
		m_Specular = other.m_Specular;

		m_Direction = other.m_Direction;
		m_DirectionPadding = other.m_DirectionPadding;
	}

	return *this;
}