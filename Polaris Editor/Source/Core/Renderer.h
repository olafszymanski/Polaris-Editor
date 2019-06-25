#pragma once

#include "Graphics.h"

class Renderer
{
public:
	static void ClearScreen();

	static void Draw(unsigned int indexCount);

	static void Present();

private:
	Renderer() = default;
	~Renderer() = default;
};