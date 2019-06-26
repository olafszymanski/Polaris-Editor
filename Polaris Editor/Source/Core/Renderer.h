#pragma once

#include "Graphics.h"

class Drawable;

class Renderer
{
public:
	static void ClearScreen();

	static void Draw(Drawable& drawable);

	static void Present();

private:
	Renderer() = default;
	~Renderer() = default;
};