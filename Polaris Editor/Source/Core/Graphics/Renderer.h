#pragma once

class Drawable;

class Camera;

#include "Shaders/BasicShader.h"
#include "Shaders/TextureShader.h"

#include "Drawables/Object.h"
#include "Drawables/TexturedObject.h"

class Renderer
{
public:
	Renderer();
	~Renderer() = default;

	void ClearScreen();

	void PushDrawable(const Drawable& drawable);
	template<unsigned int N>
	void PushDrawables(const std::array<Drawable*, N>& drawables);
	void PushDrawables(const std::vector<Drawable*>& drawables);

	void Draw(Camera& camera);

	void Present();

private:
	BasicShader m_BasicShader;
	TextureShader m_TextureShader;

	std::vector<Object*> m_Objects;
	std::vector<TexturedObject*> m_TexturedObjects;
};

#include "Renderer.ipp"