#include "pch.h"

#include "PointLight.h"

#include "../Managers/LightManager.h"

PointLight::PointLight(const DirectX::SimpleMath::Vector3& position, const DirectX::SimpleMath::Vector3& attenuation, const DirectX::SimpleMath::Vector4& ambient, const DirectX::SimpleMath::Vector4& diffuse, const DirectX::SimpleMath::Vector4& specular, float intensity)
	: Light(ambient, diffuse, specular, intensity)
	, m_Position(position), m_PositionPadding(0.0f)
	, m_Attenuation(attenuation), m_AttenuationPadding(0.0f)
{
	m_ID = LightManager::AddPointLight(*this);
}
PointLight::PointLight(const DirectX::SimpleMath::Vector3& position, const DirectX::SimpleMath::Vector3& attenuation, const DirectX::SimpleMath::Vector3& color, float intensity)
	: Light(color, intensity)
	, m_Position(position), m_PositionPadding(0.0f)
	, m_Attenuation(attenuation), m_AttenuationPadding(0.0f) 
{
	m_ID = LightManager::AddPointLight(*this);
}
PointLight::~PointLight()
{
	LightManager::RemovePointLight(m_ID);
}