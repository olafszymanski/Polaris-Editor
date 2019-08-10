#pragma once

#include "pch.h"

struct Vertex
{
	DirectX::SimpleMath::Vector3 Position;
	DirectX::SimpleMath::Vector2 TextureCoordinate;
	DirectX::SimpleMath::Vector3 Normal;

	Vertex()
		: Position(0.0f, 0.0f, 0.0f), TextureCoordinate(0.0f, 0.0f), Normal(0.0f, 0.0f, 0.0f)
	{
	}
	Vertex(const DirectX::SimpleMath::Vector3& position, const DirectX::SimpleMath::Vector2& textureCoordinate, const DirectX::SimpleMath::Vector3& normal)
		: Position(position), TextureCoordinate(textureCoordinate), Normal(normal)
	{
	}
};