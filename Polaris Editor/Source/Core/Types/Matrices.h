#pragma once

#include "pch.h"

struct Matrices
{
	DirectX::SimpleMath::Matrix World;
	DirectX::SimpleMath::Matrix WorldInverseTranspose;
	DirectX::SimpleMath::Matrix WorldViewProjection;

	Matrices()
		: World(DirectX::SimpleMath::Matrix::Identity), WorldInverseTranspose(DirectX::SimpleMath::Matrix::Identity), WorldViewProjection(DirectX::SimpleMath::Matrix::Identity)
	{
	}
	Matrices(const DirectX::SimpleMath::Matrix& world, const DirectX::SimpleMath::Matrix& worldInverseTranspose, const DirectX::SimpleMath::Matrix& worldViewProjection)
		: World(world), WorldInverseTranspose(worldInverseTranspose), WorldViewProjection(worldViewProjection)
	{
	}
};