#pragma once

#include "pch.h"

struct BasicVertex
{
	DirectX::SimpleMath::Vector3 Position;
	DirectX::SimpleMath::Vector2 TextureCoordinate;

	BasicVertex()
		: Position(0.0f, 0.0f, 0.0f), TextureCoordinate(0.0f, 0.0f)
	{
	}
	BasicVertex(const DirectX::SimpleMath::Vector3& position)
		: Position(position), TextureCoordinate(0.0f, 0.0f)
	{
	}
	BasicVertex(const DirectX::SimpleMath::Vector3& position, const DirectX::SimpleMath::Vector2& textureCoordinate)
		: Position(position), TextureCoordinate(textureCoordinate)
	{
	}
};