#include "pch.h"
#include "PointLight.h"

PointLight::PointLight()
	: Light(LightType::NONE, { 0.0f, 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f, 0.0f }, 0.0f)
	, m_Position(0.0f, 0.0f, 0.0f), m_PositionPadding(0.0f)
	, m_Attenuation(0.0f, 0.0f, 0.0f), m_AttenuationPadding(0.0f) 
{
}
PointLight::PointLight(const DirectX::SimpleMath::Vector3& position, const DirectX::SimpleMath::Vector3& attenuation, const DirectX::SimpleMath::Vector4& ambient, const DirectX::SimpleMath::Vector4& diffuse, const DirectX::SimpleMath::Vector4& specular, float intensity)
	: Light(LightType::POINT, ambient, diffuse, specular, intensity)
	, m_Position(position), m_PositionPadding(0.0f)
	, m_Attenuation(attenuation), m_AttenuationPadding(0.0f)
{
}
PointLight::PointLight(const DirectX::SimpleMath::Vector3& position, const DirectX::SimpleMath::Vector3& attenuation, const DirectX::SimpleMath::Vector3& color, float intensity)
	: Light(LightType::POINT, color, intensity)
	, m_Position(position), m_PositionPadding(0.0f)
	, m_Attenuation(attenuation), m_AttenuationPadding(0.0f) 
{
}

PointLight::PointLight(const PointLight& other)
	: Light(other.m_Type, other.m_Ambient, other.m_Diffuse, other.m_Specular, other.m_Intensity)
	, m_Position(other.m_Position), m_PositionPadding(other.m_PositionPadding)
	, m_Attenuation(other.m_Attenuation), m_AttenuationPadding(other.m_AttenuationPadding)
{
}
PointLight&	PointLight::operator=(const PointLight& other)
{
	if (this != &other)
	{
		m_Type = other.m_Type;
		m_TypePadding = other.m_TypePadding;

		m_Intensity = other.m_Intensity;

		m_Ambient = other.m_Ambient;
		m_Diffuse = other.m_Diffuse;
		m_Specular = other.m_Specular;

		m_Position = other.m_Position;
		m_PositionPadding = other.m_PositionPadding;

		m_Attenuation = other.m_Attenuation;
		m_AttenuationPadding = other.m_AttenuationPadding;
	}

	return *this;
}