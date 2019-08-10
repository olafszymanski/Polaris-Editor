#pragma once

#include "../Lights/DirectionalLight.h"
#include "../Lights/PointLight.h"
#include "../Lights/SpotLight.h"

#include "../../Logger.h"

class LightManager
{
public:
	static void AddDirectionalLight(const DirectionalLight& light, const std::string& name);
	static void AddPointLight(const PointLight& light, const std::string& name);
	static void AddSpotLight(const SpotLight& light, const std::string& name);

	static void AddDirectionalLight(const std::shared_ptr<DirectionalLight>& light, const std::string& name);
	static void AddPointLight(const std::shared_ptr<PointLight>& light, const std::string& name);
	static void AddSpotLight(const std::shared_ptr<SpotLight>& light, const std::string& name);

	static void RemoveDirectionalLight(const std::string& name);
	static void RemovePointLight(const std::string& name);
	static void RemoveSpotLight(const std::string& name);

	// Getters
	inline static const std::array<DirectionalLight, MAX_DIRECTIONAL_LIGHTS> GetDirectionalLights() 
	{ 
		std::array<DirectionalLight, MAX_DIRECTIONAL_LIGHTS> lights { };

		for (unsigned int i = 0; i < MAX_DIRECTIONAL_LIGHTS; ++i)
		{
			if (s_DirectionalLights[i].first) lights[i] = *s_DirectionalLights[i].first.get();
		}

		return lights;
	}
	inline static const std::array<PointLight, MAX_POINT_LIGHTS> GetPointLights() 
	{ 
		std::array<PointLight, MAX_POINT_LIGHTS> lights { };

		for (unsigned int i = 0; i < MAX_POINT_LIGHTS; ++i)
		{
			if (s_PointLights[i].first) lights[i] = *s_PointLights[i].first.get();
		}

		return lights;
	}
	inline static const std::array<SpotLight, MAX_SPOT_LIGHTS> GetSpotLights() 
	{ 
		std::array<SpotLight, MAX_SPOT_LIGHTS> lights { };

		for (unsigned int i = 0; i < MAX_SPOT_LIGHTS; ++i)
		{
			if (s_SpotLights[i].first) lights[i] = *s_SpotLights[i].first.get();
		}

		return lights;
	}

	inline static std::shared_ptr<DirectionalLight>& GetDirectionalLight(const std::string& name) 
	{ 
		if (!name.empty())
		{
			for (unsigned int i = 0; i < MAX_DIRECTIONAL_LIGHTS; ++i)
			{
				if (name == s_DirectionalLights[i].second) return s_DirectionalLights[i].first;
			}
		}

		POLARIS_ASSERT(false, "Failed to find a DirectionalLight with the name of '" + name + "'!");
	}
	inline static std::shared_ptr<PointLight>& GetPointLight(const std::string& name)
	{
		if (!name.empty())
		{
			for (unsigned int i = 0; i < MAX_POINT_LIGHTS; ++i)
			{
				if (name == s_PointLights[i].second) return s_PointLights[i].first;
			}
		}

		POLARIS_ASSERT(false, "Failed to find a PointLight with the name of '" + name + "'!");
	}
	inline static std::shared_ptr<SpotLight>& GetSpotLight(const std::string& name)
	{
		if (!name.empty())
		{
			for (unsigned int i = 0; i < MAX_SPOT_LIGHTS; ++i)
			{
				if (name == s_SpotLights[i].second) return s_SpotLights[i].first;
			}
		}

		POLARIS_ASSERT(false, "Failed to find a SpotLight with the name of '" + name + "'!");
	}

	// Setters
	inline static void SetDirectionalLight(const DirectionalLight& light, const std::string& name) 
	{ 
		POLARIS_WARNING(name.empty(), "DirectionalLight's name cannot be empty!");

		bool found = false;

		for (unsigned int i = 0; i < MAX_DIRECTIONAL_LIGHTS; ++i)
		{
			if (name == s_DirectionalLights[i].second)
			{
				s_DirectionalLights[i].first = std::make_shared<DirectionalLight>(light);

				found = true;
			}

			if (found) break;
		}

		POLARIS_WARNING(!found, "Failed to find a DirectionalLight with the name of '" + name + "'!");
	}
	inline static void SetPointLight(const PointLight& light, const std::string& name)
	{
		POLARIS_WARNING(name.empty(), "PointLights's name cannot be empty!");

		bool found = false;

		for (unsigned int i = 0; i < MAX_POINT_LIGHTS; ++i)
		{
			if (name == s_PointLights[i].second)
			{
				s_PointLights[i].first = std::make_shared<PointLight>(light);

				found = true;
			}

			if (found) break;
		}
		
		POLARIS_WARNING(!found, "Failed to find a PointLight with the name of '" + name + "'!");
	}
	inline static void SetSpotLight(const SpotLight& light, const std::string& name)
	{
		POLARIS_WARNING(name.empty(), "SpotLight's name cannot be empty!");

		bool found = false;

		for (unsigned int i = 0; i < MAX_SPOT_LIGHTS; ++i)
		{
			if (name == s_SpotLights[i].second)
			{
				s_SpotLights[i].first = std::make_shared<SpotLight>(light);

				found = true;
			}

			if (found) break;
		}

		POLARIS_WARNING(!found, "Failed to find a SpotLight with the name of '" + name + "'!");
	}

	inline static void SetDirectionalLight(const std::shared_ptr<DirectionalLight>& light, const std::string& name)
	{
		POLARIS_WARNING(name.empty(), "DirectionalLight's name cannot be empty!");

		bool found = false;

		for (unsigned int i = 0; i < MAX_DIRECTIONAL_LIGHTS; ++i)
		{
			if (name == s_DirectionalLights[i].second)
			{
				s_DirectionalLights[i].first = light;

				found = true;
			}

			if (found) break;
		}

		POLARIS_WARNING(!found, "Failed to find a DirectionalLight with the name of '" + name + "'!");
	}
	inline static void SetPointLight(const std::shared_ptr<PointLight>& light, const std::string& name)
	{
		POLARIS_WARNING(name.empty(), "PointLights's name cannot be empty!");

		bool found = false;

		for (unsigned int i = 0; i < MAX_POINT_LIGHTS; ++i)
		{
			if (name == s_PointLights[i].second)
			{
				s_PointLights[i].first = light;

				found = true;
			}

			if (found) break;
		}

		POLARIS_WARNING(!found, "Failed to find a PointLight with the name of '" + name + "'!");
	}
	inline static void SetSpotLight(const std::shared_ptr<SpotLight>& light, const std::string& name)
	{
		POLARIS_WARNING(name.empty(), "SpotLight's name cannot be empty!");

		bool found = false;

		for (unsigned int i = 0; i < MAX_SPOT_LIGHTS; ++i)
		{
			if (name == s_SpotLights[i].second)
			{
				s_SpotLights[i].first = light;

				found = true;
			}

			if (found) break;
		}

		POLARIS_WARNING(!found, "Failed to find a SpotLight with the name of '" + name + "'!");
	}

private:
	static std::array<std::pair<std::shared_ptr<DirectionalLight>, std::string>, MAX_DIRECTIONAL_LIGHTS> s_DirectionalLights;
	static std::array<std::pair<std::shared_ptr<PointLight>, std::string>, MAX_POINT_LIGHTS> s_PointLights;
	static std::array<std::pair<std::shared_ptr<SpotLight>, std::string>, MAX_SPOT_LIGHTS> s_SpotLights;

private:
	LightManager() = default;
	~LightManager() = default;

	template<typename T, unsigned int N>
	static bool IsNameUsed(const std::array<std::pair<T, std::string>, N>& lights, const std::string& name);
};

#include "LightManager.ipp"