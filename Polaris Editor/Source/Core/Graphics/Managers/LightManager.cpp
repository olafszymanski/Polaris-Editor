#include "pch.h"

#include "LightManager.h"

std::array<std::pair<std::shared_ptr<DirectionalLight>, std::string>, MAX_DIRECTIONAL_LIGHTS> LightManager::s_DirectionalLights;
std::array<std::pair<std::shared_ptr<PointLight>, std::string>, MAX_POINT_LIGHTS> LightManager::s_PointLights;
std::array<std::pair<std::shared_ptr<SpotLight>, std::string>, MAX_SPOT_LIGHTS> LightManager::s_SpotLights;

void LightManager::AddDirectionalLight(const DirectionalLight& light, const std::string& name)
{
	POLARIS_WARNING(name.empty(), "DirectionalLight's name cannot be empty!");
	POLARIS_WARNING(IsNameUsed(s_DirectionalLights, name), "DirectionalLight with the same name already exists!");

	bool space = true;

	for (unsigned int i = 0; i < MAX_DIRECTIONAL_LIGHTS; ++i)
	{
		if (s_DirectionalLights[i].second.empty())
		{
			s_DirectionalLights[i] = std::make_pair(std::make_shared<DirectionalLight>(light), name);

			return;
		}
		else space = false;
	}

	POLARIS_WARNING(!space, "You're trying to add too many directional lights!");
}
void LightManager::AddPointLight(const PointLight& light, const std::string& name)
{
	POLARIS_WARNING(name.empty(), "PointLight's name cannot be empty!");
	POLARIS_WARNING(IsNameUsed(s_PointLights, name), "PointLight with the name of '" + name + "' already exists!");

	bool space = true;

	for (unsigned int i = 0; i < MAX_POINT_LIGHTS; ++i)
	{
		if (s_PointLights[i].second.empty())
		{
			s_PointLights[i] = std::make_pair(std::make_shared<PointLight>(light), name);

			return;
		}
		else space = false;
	}

	POLARIS_WARNING(!space, "You're trying to add too many point lights!");
}
void LightManager::AddSpotLight(const SpotLight& light, const std::string& name)
{
	POLARIS_WARNING(name.empty(), "SpotLight's name cannot be empty!");
	POLARIS_WARNING(IsNameUsed(s_SpotLights, name), "SpotLight with the name of '" + name + "' already exists!");

	bool space = true;

	for (unsigned int i = 0; i < MAX_SPOT_LIGHTS; ++i)
	{
		if (s_PointLights[i].second.empty())
		{
			s_SpotLights[i] = std::make_pair(std::make_shared<SpotLight>(light), name);

			return;
		}
		else space = false;
	}

	POLARIS_WARNING(!space, "You're trying to add too many spot lights!");
}

void LightManager::AddDirectionalLight(const std::shared_ptr<DirectionalLight>& light, const std::string& name)
{
	POLARIS_WARNING(name.empty(), "DirectionalLight's name cannot be empty!");
	POLARIS_WARNING(IsNameUsed(s_DirectionalLights, name), "DirectionalLight with the same name already exists!");

	bool space = true;

	for (unsigned int i = 0; i < MAX_DIRECTIONAL_LIGHTS; ++i)
	{
		if (s_DirectionalLights[i].second.empty())
		{
			s_DirectionalLights[i] = std::make_pair(light, name);

			return;
		}
		else space = false;
	}

	POLARIS_WARNING(!space, "You're trying to add too many directional lights!");
}
void LightManager::AddPointLight(const std::shared_ptr<PointLight>& light, const std::string& name)
{
	POLARIS_WARNING(name.empty(), "PointLight's name cannot be empty!");
	POLARIS_WARNING(IsNameUsed(s_PointLights, name), "PointLight with the name of '" + name + "' already exists!");

	bool space = true;

	for (unsigned int i = 0; i < MAX_POINT_LIGHTS; ++i)
	{
		if (s_PointLights[i].second.empty())
		{
			s_PointLights[i] = std::make_pair(light, name);

			return;
		}
		else space = false;
	}

	POLARIS_WARNING(!space, "You're trying to add too many point lights!");
}
void LightManager::AddSpotLight(const std::shared_ptr<SpotLight>& light, const std::string& name)
{
	POLARIS_WARNING(name.empty(), "SpotLight's name cannot be empty!");
	POLARIS_WARNING(IsNameUsed(s_SpotLights, name), "SpotLight with the name of '" + name + "' already exists!");

	bool space = true;

	for (unsigned int i = 0; i < MAX_SPOT_LIGHTS; ++i)
	{
		if (s_PointLights[i].second.empty())
		{
			s_SpotLights[i] = std::make_pair(light, name);

			return;
		}
		else space = false;
	}

	POLARIS_WARNING(!space, "You're trying to add too many spot lights!");
}

void LightManager::RemoveDirectionalLight(const std::string& name)
{
	POLARIS_WARNING(name.empty(), "DirectionalLight's name cannot be empty!");

	bool found = false;

	for (unsigned int i = 0; i < MAX_DIRECTIONAL_LIGHTS; ++i)
	{
		if (name == s_DirectionalLights[i].second)
		{
			s_DirectionalLights[i] = std::make_pair(std::make_shared<DirectionalLight>(), "");

			found = true;
		}

		if (found) break;
	}

	POLARIS_WARNING(!found, "Failed to find a DirectionalLight with the name of '" + name + "'!");
	
}
void LightManager::RemovePointLight(const std::string& name)
{
	POLARIS_WARNING(name.empty(), "PointLight's name cannot be empty!");

	bool found = false;
	
	for (unsigned int i = 0; i < MAX_POINT_LIGHTS; ++i)
	{
		if (name == s_PointLights[i].second)
		{
			s_PointLights[i] = std::make_pair(std::make_shared<PointLight>(), "");

			found = true;
		}

		if (found) break;
	}

	POLARIS_WARNING(!found, "Failed to find a PointLight with the name of '" + name + "'!");
}
void LightManager::RemoveSpotLight(const std::string& name)
{
	POLARIS_WARNING(name.empty(), "SpotLight's name cannot be empty!");

	bool found = false;

	for (unsigned int i = 0; i < MAX_SPOT_LIGHTS; ++i)
	{
		if (name == s_PointLights[i].second)
		{
			s_SpotLights[i] = std::make_pair(std::make_shared<SpotLight>(), "");

			found = true;
		}

		if (found) break;
	}

	POLARIS_WARNING(!found, "Failed to find a SpotLight with the name of '" + name + "'!");
}