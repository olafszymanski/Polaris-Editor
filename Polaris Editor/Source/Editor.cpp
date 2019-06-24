#include "Core/pch.h"

#include "Core/Window.h"

#include "Core/Renderer.h"

#include "Core/Shaders/BasicShader.h"

#include "Core/Buffers/VertexBuffer.h"

const std::array<BasicVertex, 3> vertices =
{
	BasicVertex { DirectX::XMFLOAT3( 0.5f, -0.5f, 0.0f) },
	BasicVertex { DirectX::XMFLOAT3(-0.5f, -0.5f, 0.0f) },
	BasicVertex { DirectX::XMFLOAT3(-0.5f,  0.5f, 0.0f) }
};

class Editor
{
public:
	Editor()
		: m_Window(800, 600, "Polaris Editor", false)
		, m_VertexBuffer(vertices)
	{
		m_VertexBuffer.Bind();
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

	VertexBuffer m_VertexBuffer;

private:
	void Update()
	{
		m_Window.Update();
	}
	void Render()
	{
		Renderer::Draw(vertices.size());
	}
};

int main()
{
	Editor editor;
	editor.Run();

	return 0;
}