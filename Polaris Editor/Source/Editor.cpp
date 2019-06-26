#include "Core/pch.h"

#include "Core/Window.h"

#include "Core/Renderer.h"

#include "Core/Shaders/BasicShader.h"

#include "Core/Drawables/Mesh.h"

const std::array<BasicVertex, 3> vertices =
{
	BasicVertex { DirectX::XMFLOAT3( 0.5f, -0.5f, 0.0f) },
	BasicVertex { DirectX::XMFLOAT3(-0.5f, -0.5f, 0.0f) },
	BasicVertex { DirectX::XMFLOAT3(-0.5f,  0.5f, 0.0f) }
};
const std::array<unsigned short, 6> indices =
{
	0, 1, 2,
	2, 3, 0
};

class Editor
{
public:
	Editor()
		: m_Window(800, 600, "Polaris Editor", false)
		, m_Mesh(vertices, indices)
	{
		m_Mesh.Bind();
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

	Mesh m_Mesh;

private:
	void Update()
	{
		m_Window.Update();
	}
	void Render()
	{
		Renderer::Draw(m_Mesh);
	}
};

int main()
{
	Editor editor;
	editor.Run();

	return 0;
}