#include "Core/pch.h"

#include "Core/Window.h"

#include "Core/Renderer.h"

#include "Core/Shaders/BasicShader.h"

#include "Core/Drawables/Object.h"

const std::array<BasicVertex, 4> vertices =
{
	BasicVertex { DirectX::XMFLOAT3( 0.5f, -0.5f, 0.0f) },
	BasicVertex { DirectX::XMFLOAT3(-0.5f, -0.5f, 0.0f) },
	BasicVertex { DirectX::XMFLOAT3(-0.5f,  0.5f, 0.0f) },
	BasicVertex { DirectX::XMFLOAT3( 0.5f,  0.5f, 0.0f) }
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
		, m_Object({ vertices, indices }, { 0.0f, 0.0f, 0.0f })
	{
		m_Object.Bind();
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

	Object m_Object;

private:
	void Update()
	{
		m_Window.Update();

		if (Keyboard::IsKeyDown(DirectX::Keyboard::Keys::A)) m_Object.SetPosition({ m_Object.GetPosition().x - 0.025f, m_Object.GetPosition().y, m_Object.GetPosition().z });
		if (Keyboard::IsKeyDown(DirectX::Keyboard::Keys::D)) m_Object.SetPosition({ m_Object.GetPosition().x + 0.025f, m_Object.GetPosition().y, m_Object.GetPosition().z });
		if (Keyboard::IsKeyDown(DirectX::Keyboard::Keys::W)) m_Object.SetPosition({ m_Object.GetPosition().x, m_Object.GetPosition().y + 0.025f, m_Object.GetPosition().z });
		if (Keyboard::IsKeyDown(DirectX::Keyboard::Keys::S)) m_Object.SetPosition({ m_Object.GetPosition().x, m_Object.GetPosition().y - 0.025f, m_Object.GetPosition().z });

		m_Object.Update();

		m_BasicShader.UpdateWorldViewProjection({ m_Object.GetMatrix() });
	}
	void Render()
	{
		Renderer::Draw(m_Object);
	}
};

int main()
{
	Editor editor;
	editor.Run();

	return 0;
}