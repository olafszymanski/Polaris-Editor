#include "pch.h"

struct BasicVertex
{
	DirectX::XMFLOAT3 Position;

	BasicVertex()
		: Position({ 0.0f, 0.0f, 0.0f })
	{
	}
	BasicVertex(const DirectX::XMFLOAT3& position)
		: Position(position)
	{
	}
};