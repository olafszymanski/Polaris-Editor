#pragma once

class Drawable
{
public:
	Drawable() = default;
	~Drawable() = default;

	// Getter
	virtual unsigned int GetIndexCount() const = 0;
};