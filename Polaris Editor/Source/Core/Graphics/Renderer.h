#pragma once

class Camera;

#include "Shaders/PhongShader.h"

#include "Drawables/Object.h"

class Renderer
{
public:
	Renderer();
	~Renderer() = default;

	void ClearScreen();

	void PushObject(Object& object);
	template<unsigned int N>
	void PushObjects(const std::array<Object*, N>& objects);
	void PushObjects(const std::vector<Object*>& objects);

	void Draw(const Camera& camera);

	void Present();

private:
	PhongShader m_PhongShader;

	std::vector<Object*> m_Objects;
};

#include "Renderer.ipp"