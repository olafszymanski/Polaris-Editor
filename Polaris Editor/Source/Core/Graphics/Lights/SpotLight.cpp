#include "pch.h"

#include "SpotLight.h"

SpotLight::SpotLight()
	: Light(LightType::NONE, { 0.0f, 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f, 0.0f }, 0.0f)
	, m_Position(0.0f, 0.0f, 0.0f)
	, m_CutOff(0.0f)
	, m_Direction(0.0f, 0.0f, 0.0f), m_DirectionPadding(0.0f)
	, m_Attenuation(0.0f, 0.0f, 0.0f), m_AttenuationPadding(0.0f)
{
}
SpotLight::SpotLight(const DirectX::SimpleMath::Vector3& position, float cutOff, const DirectX::SimpleMath::Vector3& direction, const DirectX::SimpleMath::Vector3& attenuation, const DirectX::SimpleMath::Vector4& ambient, const DirectX::SimpleMath::Vector4& diffuse, const DirectX::SimpleMath::Vector4& specular, float intensity)
	: Light(LightType::SPOT, ambient, diffuse, specular, intensity)
	, m_Position(position)
	, m_CutOff(cutOff)
	, m_Direction(direction), m_DirectionPadding(0.0f)
	, m_Attenuation(attenuation), m_AttenuationPadding(0.0f)
{
}
SpotLight::SpotLight(const DirectX::SimpleMath::Vector3& position, float cutOff, const DirectX::SimpleMath::Vector3& direction, const DirectX::SimpleMath::Vector3& attenuation, const DirectX::SimpleMath::Vector3& color, float intensity)
	: Light(LightType::SPOT, color, intensity)
	, m_Position(position)
	, m_CutOff(cutOff)
	, m_Direction(direction), m_DirectionPadding(0.0f)
	, m_Attenuation(attenuation), m_AttenuationPadding(0.0f) 
{
}

SpotLight::SpotLight(const SpotLight& other)
	: Light(other.m_Type, other.m_Ambient, other.m_Diffuse, other.m_Specular, other.m_Intensity)
	, m_Position(other.m_Position)
	, m_CutOff(other.m_CutOff)
	, m_Direction(other.m_Direction), m_DirectionPadding(other.m_DirectionPadding)
	, m_Attenuation(other.m_Attenuation), m_AttenuationPadding(other.m_AttenuationPadding) 
{
}
SpotLight& SpotLight::operator=(const SpotLight& other)
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

		m_CutOff = other.m_CutOff;

		m_Direction = other.m_Direction;
		m_DirectionPadding = other.m_DirectionPadding;

		m_Attenuation = other.m_Attenuation;
		m_AttenuationPadding = other.m_AttenuationPadding;
	}

	return *this;
}