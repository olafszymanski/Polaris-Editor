#include "pch.h"

#include "DirectionalLight.h"

#include "../Managers/LightManager.h"

DirectionalLight::DirectionalLight(const DirectX::SimpleMath::Vector3& direction, const DirectX::SimpleMath::Vector4& ambient, const DirectX::SimpleMath::Vector4& diffuse, const DirectX::SimpleMath::Vector4& specular, float intensity)
	: Light(ambient, diffuse, specular, intensity)
	, m_Direction(direction), m_DirectionPadding(0.0f)
{
	m_ID = LightManager::AddDirectionalLight(*this);
}
DirectionalLight::DirectionalLight(const DirectX::SimpleMath::Vector3& direction, const DirectX::SimpleMath::Vector3& color, float intensity)
	: Light(color, intensity)
	, m_Direction(direction), m_DirectionPadding(0.0f) 
{
	m_ID = LightManager::AddDirectionalLight(*this);
}
DirectionalLight::~DirectionalLight()
{
	LightManager::RemoveDirectionalLight(m_ID);
}