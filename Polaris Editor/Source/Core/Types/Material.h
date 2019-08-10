#pragma once

#include "pch.h"

struct Material
{
	DirectX::SimpleMath::Vector4 Ambient;
	DirectX::SimpleMath::Vector4 Diffuse;
	DirectX::SimpleMath::Vector4 Specular;

	Material()
		: Ambient(0.0f, 0.0f, 0.0f, 0.0f), Diffuse(0.0f, 0.0f, 0.0f, 0.0f), Specular(0.0f, 0.0f, 0.0f, 0.0f)
	{
	}
	Material(const DirectX::SimpleMath::Vector4& ambient, const DirectX::SimpleMath::Vector4& diffuse, const DirectX::SimpleMath::Vector4& specular)
		: Ambient(ambient), Diffuse(diffuse), Specular(specular)
	{
	}
	Material(const DirectX::SimpleMath::Vector3& color, float shininess)
		: Ambient(color.x / 10.0f, color.y / 10.0f, color.z / 10.0f, 1.0f), Diffuse(color.x, color.y, color.z, 1.0f), Specular(color.x, color.y, color.z, shininess)
	{
	}
};