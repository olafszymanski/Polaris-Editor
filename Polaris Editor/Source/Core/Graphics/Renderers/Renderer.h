#pragma once

class Scene;

#include "../Shaders/PhongShader.h"

class Renderer
{
public:
	Renderer();
	~Renderer() = default;

	void ClearScreen();

	void Draw(Scene& scene);

	void Present();

private:
	PhongShader m_PhongShader;
};