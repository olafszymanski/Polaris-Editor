#include "pch.h"

struct BasicVertex
{
	DirectX::XMFLOAT3 Position;
	DirectX::XMFLOAT2 TextureCoordinate;

	BasicVertex()
		: Position({ 0.0f, 0.0f, 0.0f }), TextureCoordinate({ 0.0f, 0.0f })
	{
	}
	BasicVertex(const DirectX::XMFLOAT3& position)
		: Position(position), TextureCoordinate({ 0.0f, 0.0f })
	{
	}
	BasicVertex(const DirectX::XMFLOAT3& position, const DirectX::XMFLOAT2& textureCoordinate)
		: Position(position), TextureCoordinate(textureCoordinate)
	{
	}
};