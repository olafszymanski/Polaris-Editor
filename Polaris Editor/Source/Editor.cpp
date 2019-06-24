#include "Core/pch.h"

#include "Core/Window.h"

#include "Core/Renderer.h"

#include "Core/Shaders/BasicShader.h"

class Editor
{
public:
	Editor()
		: m_Window(800, 600, "Polaris Editor", false)
	{
		
	}
	~Editor()
	{

	}

	void Run()
	{
		while (m_Window.IsOpen())
		{
			Renderer::ClearScreen();

			Update();
			Render();

			Renderer::Present();
		}
	}

private:
	Window m_Window;

	BasicShader m_BasicShader;

private:
	void Update()
	{
		m_Window.Update();
	}
	void Render()
	{

	}
};

int main()
{
	Editor editor;
	editor.Run();

	return 0;
}