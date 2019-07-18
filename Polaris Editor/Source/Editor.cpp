#include "pch.h"

#include "Core/Graphics/Window.h"

#include "Core/Graphics/Renderer.h"

#include "Core/Graphics/Shaders/TextureShader.h"

#include "Core/Graphics/Drawables/TexturedObject.h"

#include "Core/Graphics/Cameras/Camera.h"

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
		, m_Camera(m_Window, { 0.0f, 0.0f, -3.0f }), m_CameraSpeed(4.0f), m_CameraRotationSpeed(DirectX::XM_PI / 2)
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

			HandleInput();
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

	Camera m_Camera;
	float m_CameraSpeed, m_CameraRotationSpeed;

private:
	void HandleInput()
	{
		if (Keyboard::IsKeyDown(DirectX::Keyboard::W)) m_Camera.SetPosition({ m_Camera.GetPosition().x, m_Camera.GetPosition().y, m_Camera.GetPosition().z + m_CameraSpeed * Timer::GetDeltaTime() });
		if (Keyboard::IsKeyDown(DirectX::Keyboard::S)) m_Camera.SetPosition({ m_Camera.GetPosition().x, m_Camera.GetPosition().y, m_Camera.GetPosition().z - m_CameraSpeed * Timer::GetDeltaTime() });
		if (Keyboard::IsKeyDown(DirectX::Keyboard::A)) m_Camera.SetPosition({ m_Camera.GetPosition().x + m_CameraSpeed * Timer::GetDeltaTime(), m_Camera.GetPosition().y, m_Camera.GetPosition().z });
		if (Keyboard::IsKeyDown(DirectX::Keyboard::D)) m_Camera.SetPosition({ m_Camera.GetPosition().x - m_CameraSpeed * Timer::GetDeltaTime(), m_Camera.GetPosition().y, m_Camera.GetPosition().z });
		if (Keyboard::IsKeyDown(DirectX::Keyboard::Z)) m_Camera.SetPosition({ m_Camera.GetPosition().x, m_Camera.GetPosition().y + m_CameraSpeed * Timer::GetDeltaTime(), m_Camera.GetPosition().z });
		if (Keyboard::IsKeyDown(DirectX::Keyboard::X)) m_Camera.SetPosition({ m_Camera.GetPosition().x, m_Camera.GetPosition().y - m_CameraSpeed * Timer::GetDeltaTime(), m_Camera.GetPosition().z });

		if (Keyboard::IsKeyDown(DirectX::Keyboard::Q)) m_Camera.SetRotation({ m_Camera.GetRotation().x - m_CameraRotationSpeed * Timer::GetDeltaTime(), m_Camera.GetRotation().y, m_Camera.GetRotation().z });
		if (Keyboard::IsKeyDown(DirectX::Keyboard::E)) m_Camera.SetRotation({ m_Camera.GetRotation().x + m_CameraRotationSpeed * Timer::GetDeltaTime(), m_Camera.GetRotation().y, m_Camera.GetRotation().z });
	}
	void Update()
	{
		m_Window.Update();
	}
	void Render()
	{
		m_Renderer.Draw(m_Camera);
	}
};

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	Editor editor;
	editor.Run();

	return 0;
}