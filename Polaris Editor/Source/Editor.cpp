#include "pch.h"

#include "Core/Graphics/Window.h"

#include "Core/Graphics/Renderer.h"

#include "Core/Graphics/Drawables/Object.h"

#include "Core/Graphics/Cameras/Camera.h"

#include "Core/Timer.h"

class Editor
{
public:
	Editor()
		: m_Window(800, 600, "Polaris Editor", false)
		, m_Nanosuit({ "Resources/Models/Nanosuit/nanosuit.obj" }, { 0.0f, 0.0f, 0.0f }, { DirectX::XM_PI, 0.0f, 0.0f })
		, m_Camera(m_Window, { 0.0f, 0.0f, -3.0f }), m_CameraSpeed(4.0f)
	{
		m_Renderer.PushObject(m_Nanosuit);
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

	Object m_Nanosuit;

	Camera m_Camera;
	float m_CameraSpeed;

private:
	void HandleInput()
	{
		if (Keyboard::IsKeyDown(DirectX::Keyboard::W)) m_Camera.SetPosition({ m_Camera.GetPosition().x, m_Camera.GetPosition().y, m_Camera.GetPosition().z + m_CameraSpeed * Timer::GetDeltaTime() });
		if (Keyboard::IsKeyDown(DirectX::Keyboard::S)) m_Camera.SetPosition({ m_Camera.GetPosition().x, m_Camera.GetPosition().y, m_Camera.GetPosition().z - m_CameraSpeed * Timer::GetDeltaTime() });
		if (Keyboard::IsKeyDown(DirectX::Keyboard::A)) m_Camera.SetPosition({ m_Camera.GetPosition().x + m_CameraSpeed * Timer::GetDeltaTime(), m_Camera.GetPosition().y, m_Camera.GetPosition().z });
		if (Keyboard::IsKeyDown(DirectX::Keyboard::D)) m_Camera.SetPosition({ m_Camera.GetPosition().x - m_CameraSpeed * Timer::GetDeltaTime(), m_Camera.GetPosition().y, m_Camera.GetPosition().z });
		if (Keyboard::IsKeyDown(DirectX::Keyboard::X)) m_Camera.SetPosition({ m_Camera.GetPosition().x, m_Camera.GetPosition().y + m_CameraSpeed * Timer::GetDeltaTime(), m_Camera.GetPosition().z });
		if (Keyboard::IsKeyDown(DirectX::Keyboard::Z)) m_Camera.SetPosition({ m_Camera.GetPosition().x, m_Camera.GetPosition().y - m_CameraSpeed * Timer::GetDeltaTime(), m_Camera.GetPosition().z });
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