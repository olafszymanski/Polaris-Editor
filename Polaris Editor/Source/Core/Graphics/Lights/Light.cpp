#include "pch.h"

#include "Light.h"

Light::Light(const DirectX::SimpleMath::Vector4& ambient, const DirectX::SimpleMath::Vector4& diffuse, const DirectX::SimpleMath::Vector4& specular, float intensity)
	: m_ID(0)
	, m_Intensity(intensity), m_IntensityPadding(0.0f)
	, m_Ambient(ambient), m_Diffuse(diffuse), m_Specular(specular)
{
}
Light::Light(const DirectX::SimpleMath::Vector3& color, float intensity)
	: m_ID(0)
	, m_Intensity(intensity), m_IntensityPadding(0.0f)
	, m_Ambient(color.x, color.y, color.z, 1.0f), m_Diffuse(color.x, color.y, color.z, 1.0f), m_Specular(color.x, color.y, color.z, 1.0f)
{
}