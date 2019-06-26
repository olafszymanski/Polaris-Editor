#include "../pch.h"

struct WorldViewProjection
{
	DirectX::XMMATRIX Matrix;

	WorldViewProjection()
		: Matrix(DirectX::XMMatrixIdentity())
	{
	}
	WorldViewProjection(const DirectX::XMMATRIX& matrix)
		: Matrix(matrix)
	{
	}
};