#include "pch.h"

#include "LightManager.h"

#include "../../Logger.h"

std::unordered_map<unsigned int, DirectionalLight*> LightManager::s_DirectionalLights { };
unsigned int LightManager::s_CurrentDirectionalLightID = 0;
std::unordered_map<unsigned int, PointLight*> LightManager::s_PointLights { };
unsigned int LightManager::s_CurrentPointLightID = 0;
std::unordered_map<unsigned int, SpotLight*> LightManager::s_SpotLights { };
unsigned int LightManager::s_CurrentSpotLightID = 0;

unsigned int LightManager::AddDirectionalLight(DirectionalLight& directionalLight)
{
	POLARIS_WARNING(s_CurrentDirectionalLightID > MAX_DIRECTIONAL_LIGHTS - 1, "You're trying to create too many DirectionalLights!");

	s_DirectionalLights[s_CurrentDirectionalLightID] = &directionalLight;

	s_CurrentDirectionalLightID += 1;

	return s_CurrentDirectionalLightID - 1;
}
void LightManager::RemoveDirectionalLight(unsigned int ID)
{
	s_DirectionalLights[ID] = nullptr;
}
unsigned int LightManager::AddPointLight(PointLight& pointLight)
{
	POLARIS_WARNING(s_CurrentPointLightID > MAX_POINT_LIGHTS - 1, "You're trying to create too many PointLights!");

	s_PointLights[s_CurrentPointLightID] = &pointLight;

	s_CurrentPointLightID += 1;

	return s_CurrentPointLightID - 1;
}
void LightManager::RemovePointLight(unsigned int ID)
{
	s_SpotLights[ID] = nullptr;
}
unsigned int LightManager::AddSpotLight(SpotLight& spotLight)
{
	POLARIS_WARNING(s_CurrentSpotLightID > MAX_SPOT_LIGHTS - 1, "You're trying to create too many SpotLight!");

	s_SpotLights[s_CurrentSpotLightID] = &spotLight;

	s_CurrentSpotLightID += 1;

	return s_CurrentSpotLightID - 1;
}
void LightManager::RemoveSpotLight(unsigned int ID)
{
	s_PointLights[ID] = nullptr;
}