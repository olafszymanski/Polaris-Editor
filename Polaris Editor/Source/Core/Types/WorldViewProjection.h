#pragma once

#include "pch.h"

struct WorldViewProjection
{
	DirectX::SimpleMath::Matrix Matrix;

	WorldViewProjection()
		: Matrix(DirectX::SimpleMath::Matrix::Identity)
	{
	}
	WorldViewProjection(const DirectX::SimpleMath::Matrix& matrix)
		: Matrix(matrix)
	{
	}
};