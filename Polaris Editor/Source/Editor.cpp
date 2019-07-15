#include "pch.h"

#include "Core/Window.h"

#include "Core/Renderer.h"

#include "Core/Shaders/TextureShader.h"

#include "Core/Drawables/TexturedObject.h"

#include "Core/Timer.h"

const std::array<BasicVertex, 4> vertices
{
	BasicVertex { DirectX::SimpleMath::Vector3( 0.5f, -0.5f, 0.0f), DirectX::SimpleMath::Vector2(1.0f, 0.0f) },
	BasicVertex { DirectX::SimpleMath::Vector3(-0.5f, -0.5f, 0.0f), DirectX::SimpleMath::Vector2(0.0f, 0.0f) },
	BasicVertex { DirectX::SimpleMath::Vector3(-0.5f,  0.5f, 0.0f), DirectX::SimpleMath::Vector2(0.0f, 1.0f) },
	BasicVertex { DirectX::SimpleMath::Vector3( 0.5f,  0.5f, 0.0f), DirectX::SimpleMath::Vector2(1.0f, 1.0f) }
};
const std::array<unsigned short, 6> indices
{
	0, 1, 2,
	2, 3, 0
};

class Editor
{
public:
	Editor()
		: m_Window(800, 600, "Polaris Editor", false)
		, m_Object({ vertices, indices }, { 1.0f, 0.0f, 0.0f }), m_TexturedObject({ vertices, indices }, { "Resources/Textures/Crate.jpg" }, { 0.0f, 0.0f, 0.0f })
	{
		m_Renderer.PushDrawables({ &m_TexturedObject, &m_Object });
	}
	~Editor()
	{

	}

	void Run()
	{	
		while (m_Window.IsOpen())
		{
			Timer::Tick();

			m_Renderer.ClearScreen();

			Update();
			Render();

			m_Renderer.Present();
		}
	}

private:
	Window m_Window;

	Renderer m_Renderer;

	Object m_Object;
	TexturedObject m_TexturedObject;

private:
	void Update()
	{
		m_Window.Update();
	}
	void Render()
	{
		m_Renderer.Draw();
	}
};

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	Editor editor;
	editor.Run();

	return 0;
}