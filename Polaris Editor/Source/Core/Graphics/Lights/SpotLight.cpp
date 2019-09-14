#include "pch.h"

#include "SpotLight.h"

#include "../Managers/LightManager.h"

SpotLight::SpotLight(const DirectX::SimpleMath::Vector3& position, float cutOff, const DirectX::SimpleMath::Vector3& direction, const DirectX::SimpleMath::Vector3& attenuation, const DirectX::SimpleMath::Vector4& ambient, const DirectX::SimpleMath::Vector4& diffuse, const DirectX::SimpleMath::Vector4& specular, float intensity)
	: Light(ambient, diffuse, specular, intensity)
	, m_Position(position)
	, m_CutOff(cutOff)
	, m_Direction(direction), m_DirectionPadding(0.0f)
	, m_Attenuation(attenuation), m_AttenuationPadding(0.0f)
{
	m_ID = LightManager::AddSpotLight(*this);
}
SpotLight::SpotLight(const DirectX::SimpleMath::Vector3& position, float cutOff, const DirectX::SimpleMath::Vector3& direction, const DirectX::SimpleMath::Vector3& attenuation, const DirectX::SimpleMath::Vector3& color, float intensity)
	: Light(color, intensity)
	, m_Position(position)
	, m_CutOff(cutOff)
	, m_Direction(direction), m_DirectionPadding(0.0f)
	, m_Attenuation(attenuation), m_AttenuationPadding(0.0f) 
{
	m_ID = LightManager::AddSpotLight(*this);
}
SpotLight::~SpotLight()
{
	LightManager::RemoveSpotLight(m_ID);
}