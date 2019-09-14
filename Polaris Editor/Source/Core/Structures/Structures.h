#pragma once

#include "pch.h"

#include "Graphics/Managers/LightManager.h"

struct VertexStructure
{
	DirectX::SimpleMath::Vector3 Position;
	DirectX::SimpleMath::Vector2 TextureCoordinate;
	DirectX::SimpleMath::Vector3 Normal;

	VertexStructure()
		: Position(0.0f, 0.0f, 0.0f), TextureCoordinate(0.0f, 0.0f), Normal(0.0f, 0.0f, 0.0f)
	{
	}
	VertexStructure(const DirectX::SimpleMath::Vector3& position, const DirectX::SimpleMath::Vector2& textureCoordinate, const DirectX::SimpleMath::Vector3& normal)
		: Position(position), TextureCoordinate(textureCoordinate), Normal(normal)
	{
	}
};

struct MatricesStructure
{
	DirectX::SimpleMath::Matrix World;
	DirectX::SimpleMath::Matrix WorldInverseTranspose;
	DirectX::SimpleMath::Matrix WorldViewProjection;

	MatricesStructure()
		: World(DirectX::SimpleMath::Matrix::Identity), WorldInverseTranspose(DirectX::SimpleMath::Matrix::Identity), WorldViewProjection(DirectX::SimpleMath::Matrix::Identity)
	{
	}
	MatricesStructure(const DirectX::SimpleMath::Matrix& world, const DirectX::SimpleMath::Matrix& worldInverseTranspose, const DirectX::SimpleMath::Matrix& worldViewProjection)
		: World(world), WorldInverseTranspose(worldInverseTranspose), WorldViewProjection(worldViewProjection)
	{
	}
};

struct LightStructure
{
	float Intensity;
	DirectX::SimpleMath::Vector3 IntensityPadding;

	DirectX::SimpleMath::Vector4 Ambient;
	DirectX::SimpleMath::Vector4 Diffuse;
	DirectX::SimpleMath::Vector4 Specular;

	LightStructure()
		: Intensity(0.0f), IntensityPadding(0.0f, 0.0f, 0.0f)
		, Ambient(0.0f, 0.0f, 0.0f, 0.0f), Diffuse(0.0f, 0.0f, 0.0f, 0.0f), Specular(0.0f, 0.0f, 0.0f, 0.0f)
	{
	}
	LightStructure(float intensity, const DirectX::SimpleMath::Vector4& ambient, const DirectX::SimpleMath::Vector4& diffuse, const DirectX::SimpleMath::Vector4& specular)
		: Intensity(intensity), IntensityPadding(0.0f, 0.0f, 0.0f)
		, Ambient(ambient), Diffuse(diffuse), Specular(specular)
	{
	}
};

struct DirectionalLightStructure : public LightStructure
{
	DirectX::SimpleMath::Vector3 Direction;
	float DirectionPadding;

	DirectionalLightStructure()
		: LightStructure()
		, Direction(0.0f, 0.0f, 0.0f), DirectionPadding(0.0f)
	{
	}
	DirectionalLightStructure(float intensity, const DirectX::SimpleMath::Vector4& ambient, const DirectX::SimpleMath::Vector4& diffuse, const DirectX::SimpleMath::Vector4& specular, const DirectX::SimpleMath::Vector3& direction)
		: LightStructure(intensity, ambient, diffuse, specular)
		, Direction(direction), DirectionPadding(0.0f)
	{
	}
};

struct PointLightStructure : public LightStructure
{
	DirectX::SimpleMath::Vector3 Position;
	float PositionPadding;

	DirectX::SimpleMath::Vector3 Attenuation;
	float AttenuationPadding;

	PointLightStructure()
		: LightStructure()
		, Position(0.0f, 0.0f, 0.0f), PositionPadding(0.0f)
		, Attenuation(0.0f, 0.0f, 0.0f), AttenuationPadding(0.0f)
	{
	}
	PointLightStructure(float intensity, const DirectX::SimpleMath::Vector4& ambient, const DirectX::SimpleMath::Vector4& diffuse, const DirectX::SimpleMath::Vector4& specular, const DirectX::SimpleMath::Vector3& position, const DirectX::SimpleMath::Vector3& attenuation)
		: LightStructure(intensity, ambient, diffuse, specular)
		, Position(position), PositionPadding(0.0f)
		, Attenuation(attenuation), AttenuationPadding(0.0f)
	{
	}
};

struct SpotLightStructure : public LightStructure
{
	DirectX::SimpleMath::Vector3 Position;
	float CutOff;

	DirectX::SimpleMath::Vector3 Direction;
	float DirectionPadding;

	DirectX::SimpleMath::Vector3 Attenuation;
	float AttenuationPadding;

	SpotLightStructure()
		: LightStructure()
		, Position(0.0f, 0.0f, 0.0f), CutOff(0.0f)
		, Direction(0.0f, 0.0f, 0.0f), DirectionPadding(0.0f)
		, Attenuation(0.0f, 0.0f, 0.0f), AttenuationPadding(0.0f)
	{
	}
	SpotLightStructure(float intensity, const DirectX::SimpleMath::Vector4& ambient, const DirectX::SimpleMath::Vector4& diffuse, const DirectX::SimpleMath::Vector4& specular, const DirectX::SimpleMath::Vector3& position, float cutOff, const DirectX::SimpleMath::Vector3& direction, const DirectX::SimpleMath::Vector3& attenuation)
		: LightStructure(intensity, ambient, diffuse, specular)
		, Position(position), CutOff(cutOff)
		, Direction(direction), DirectionPadding(0.0f)
		, Attenuation(attenuation), AttenuationPadding(0.0f)
	{
	}
};

struct LightingStructure
{
	std::array<DirectionalLightStructure, MAX_DIRECTIONAL_LIGHTS> DirectionalLights;
	std::array<PointLightStructure, MAX_POINT_LIGHTS> PointLights;
	std::array<SpotLightStructure, MAX_SPOT_LIGHTS> SpotLights;

	DirectX::SimpleMath::Vector3 CameraPosition;
	float CameraPositionPadding;

	LightingStructure()
		: DirectionalLights({ }), PointLights({ }), SpotLights({ })
		, CameraPosition(0.0f, 0.0f, 0.0f), CameraPositionPadding(0.0f)
	{
	}
	LightingStructure(const DirectX::SimpleMath::Vector3& cameraPosition)
		: CameraPosition(cameraPosition), CameraPositionPadding(0.0f)
	{
		auto directionalLights = LightManager::GetDirectionalLights();
		for (unsigned int i = 0; i < MAX_DIRECTIONAL_LIGHTS; ++i)
		{
			if (directionalLights[i] != nullptr) DirectionalLights[i] = DirectionalLightStructure(directionalLights[i]->GetIntensity(), directionalLights[i]->GetAmbient(), directionalLights[i]->GetDiffuse(), directionalLights[i]->GetSpecular(), directionalLights[i]->GetDirection());
		}

		auto pointLights = LightManager::GetPointLights();
		for (unsigned int i = 0; i < MAX_POINT_LIGHTS; ++i)
		{
			if (pointLights[i] != nullptr) PointLights[i] = PointLightStructure(pointLights[i]->GetIntensity(), pointLights[i]->GetAmbient(), pointLights[i]->GetDiffuse(), pointLights[i]->GetSpecular(), pointLights[i]->GetPosition(), pointLights[i]->GetAttenuation());
		}

		auto spotLights = LightManager::GetSpotLights();
		for (unsigned int i = 0; i < MAX_SPOT_LIGHTS; ++i)
		{
			if (spotLights[i] != nullptr) SpotLights[i] = SpotLightStructure(spotLights[i]->GetIntensity(), spotLights[i]->GetAmbient(), spotLights[i]->GetDiffuse(), spotLights[i]->GetSpecular(), spotLights[i]->GetPosition(), spotLights[i]->GetCutOff(), spotLights[i]->GetDirection(), spotLights[i]->GetAttenuation());
		}
	}
};

struct MaterialStructure
{
	DirectX::SimpleMath::Vector4 Ambient;
	DirectX::SimpleMath::Vector4 Diffuse;
	DirectX::SimpleMath::Vector4 Specular;

	MaterialStructure()
		: Ambient(0.0f, 0.0f, 0.0f, 0.0f), Diffuse(0.0f, 0.0f, 0.0f, 0.0f), Specular(0.0f, 0.0f, 0.0f, 0.0f)
	{
	}
	MaterialStructure(const DirectX::SimpleMath::Vector4& ambient, const DirectX::SimpleMath::Vector4& diffuse, const DirectX::SimpleMath::Vector4& specular)
		: Ambient(ambient), Diffuse(diffuse), Specular(specular)
	{
	}
	MaterialStructure(const DirectX::SimpleMath::Vector3& color, float shininess)
		: Ambient(color.x / 10.0f, color.y / 10.0f, color.z / 10.0f, 1.0f), Diffuse(color.x, color.y, color.z, 1.0f), Specular(color.x, color.y, color.z, shininess)
	{
	}
};