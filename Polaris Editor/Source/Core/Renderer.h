#pragma once

class Drawable;

class Renderer
{
public:
	static void ClearScreen();

	static void Draw(const Drawable& drawable);

	static void Present();

private:
	Renderer() = default;
	~Renderer() = default;
};