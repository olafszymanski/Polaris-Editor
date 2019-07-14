#pragma once

class Drawable
{
public:
	Drawable() = default;
	~Drawable() = default;

	virtual void Bind() const = 0;

	virtual void Update() = 0;

	// Getters
	virtual unsigned int GetIndexCount() const = 0;

	virtual DirectX::SimpleMath::Matrix GetMatrix() const = 0;
};