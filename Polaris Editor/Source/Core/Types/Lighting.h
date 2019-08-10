#pragma once

#include "../Graphics/Managers/LightManager.h"

struct Lighting
{
	std::array<DirectionalLight, MAX_DIRECTIONAL_LIGHTS> DirectionalLights;
	std::array<PointLight, MAX_POINT_LIGHTS> PointLights;
	std::array<SpotLight, MAX_SPOT_LIGHTS> SpotLights;

	DirectX::SimpleMath::Vector3 CameraPosition;
	float CameraPositionPadding;

	Lighting()
		: DirectionalLights({ }), PointLights({ }), SpotLights({ })
		, CameraPosition(0.0f, 0.0f, 0.0f), CameraPositionPadding(0.0f)
	{
	}
	Lighting(const DirectX::SimpleMath::Vector3& cameraPosition)
		: DirectionalLights(LightManager::GetDirectionalLights()), PointLights(LightManager::GetPointLights()), SpotLights(LightManager::GetSpotLights())
		, CameraPosition(cameraPosition), CameraPositionPadding(0.0f)
	{
	}
};