#include "pch.h"

#include "Light.h"

Light::Light()
	: m_Type(LightType::NONE), m_TypePadding(0.0f, 0.0f)
	, m_Intensity(0.0f)
	, m_Ambient(0.0f, 0.0f, 0.0f, 0.0f), m_Diffuse(0.0f, 0.0f, 0.0f, 0.0f), m_Specular(0.0f, 0.0f, 0.0f, 0.0f)
{
}
Light::Light(const LightType& type, const DirectX::SimpleMath::Vector4& ambient, const DirectX::SimpleMath::Vector4& diffuse, const DirectX::SimpleMath::Vector4& specular, float intensity)
	: m_Type(type), m_TypePadding(0.0f, 0.0f)
	, m_Intensity(intensity)
	, m_Ambient(ambient), m_Diffuse(diffuse), m_Specular(specular)
{
}
Light::Light(const LightType& type, const DirectX::SimpleMath::Vector3& color, float intensity)
	: m_Type(type), m_TypePadding(0.0f, 0.0f)
	, m_Intensity(intensity)
	, m_Ambient(color.x, color.y, color.z, 1.0f), m_Diffuse(color.x, color.y, color.z, 1.0f), m_Specular(color.x, color.y, color.z, 1.0f) {
}

Light::Light(const Light& other)
	: m_Type(other.m_Type), m_TypePadding(other.m_TypePadding)
	, m_Intensity(other.m_Intensity)
	, m_Ambient(other.m_Ambient), m_Diffuse(other.m_Diffuse), m_Specular(other.m_Specular)
{
}
Light& Light::operator=(const Light& other)
{
	if (this != &other)
	{
		m_Type = other.m_Type;
		m_TypePadding = other.m_TypePadding;

		m_Intensity = other.m_Intensity;

		m_Ambient = other.m_Ambient;
		m_Diffuse = other.m_Diffuse;
		m_Specular = other.m_Specular;
	}

	return *this;
}