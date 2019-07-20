#pragma once

class Drawable;

class Camera;

#include "Shaders/BasicShader.h"

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

	void Draw(Camera& camera);

	void Present();

private:
	BasicShader m_BasicShader;

	std::vector<Object*> m_Objects;
};

#include "Renderer.ipp"