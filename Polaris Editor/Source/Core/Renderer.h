#pragma once

#include "Graphics.h"

class Renderer
{
public:
	static void ClearScreen();

	static void Draw(unsigned int vertexCount, unsigned int startPosition = 0);

	static void Present();

private:
	Renderer() = default;
	~Renderer() = default;
};