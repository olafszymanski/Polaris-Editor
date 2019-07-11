#pragma once

class Drawable
{
public:
	Drawable() = default;
	~Drawable() = default;

	// Getters
	virtual unsigned int GetIndexCount() const = 0;

	virtual DirectX::SimpleMath::Matrix GetMatrix() const = 0;
};