#pragma once

#include "../Lights/DirectionalLight.h"
#include "../Lights/PointLight.h"
#include "../Lights/SpotLight.h"

class LightManager
{
public:
	static unsigned int AddDirectionalLight(DirectionalLight& directionalLight);
	static void RemoveDirectionalLight(unsigned int ID);
	static unsigned int AddPointLight(PointLight& pointLight);
	static void RemovePointLight(unsigned int ID);
	static unsigned int AddSpotLight(SpotLight& spotLight);
	static void RemoveSpotLight(unsigned int ID);

	// Getters
	inline static std::unordered_map<unsigned int, DirectionalLight*>& GetDirectionalLights() { return s_DirectionalLights; }
	inline static std::unordered_map<unsigned int, PointLight*>& GetPointLights() { return s_PointLights; }
	inline static std::unordered_map<unsigned int, SpotLight*>& GetSpotLights() { return s_SpotLights; }

private:
	static std::unordered_map<unsigned int, DirectionalLight*> s_DirectionalLights;
	static unsigned int s_CurrentDirectionalLightID;
	static std::unordered_map<unsigned int, PointLight*> s_PointLights;
	static unsigned int s_CurrentPointLightID;
	static std::unordered_map<unsigned int, SpotLight*> s_SpotLights;
	static unsigned int s_CurrentSpotLightID;

private:
	LightManager() = default;
	~LightManager() = default;
};