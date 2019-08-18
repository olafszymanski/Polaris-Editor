#include "pch.h"

#include "Core/Graphics/Window.h"

#include "Core/Graphics/Renderer.h"

#include "Core/Graphics/Drawables/Object.h"

#include "Core/Graphics/Cameras/FreeCamera.h"

#include "Core/Graphics/Managers/LightManager.h"

#include "Core/Timer.h"

class Editor
{
public:
	Editor()
		: m_Window(1280, 760, "Polaris Editor", false)
		, m_Nanosuit({ "Resources/Models/Nanosuit/nanosuit.obj" })
		, m_Camera(m_Window, { 0.0f, 10.0f, 5.0f })
	{
		m_Renderer.PushObject(m_Nanosuit);

		LightManager::AddDirectionalLight({ { 0.0f, 0.0f, -1.0f } }, "DirectionalLight");
		LightManager::AddPointLight({ { 0.0f, 15.0f, 7.5f }, { 1.0f, 0.09f, 0.032f }, { 0.0f, 1.0f, 0.0f } }, "PointLight");
		LightManager::AddSpotLight({ { 0.0f, 10.0f, 7.5f }, 0.89f, { 0.0f, 0.0f, -1.0f }, { 1.0f, 0.09f, 0.032f }, { 0.0f, 0.0f, 1.0f } }, "SpotLight");
	}
	~Editor()
	{
	}

	void Run()
	{	
		while (m_Window.IsOpen())
		{
			Timer::Tick();

			float deltaTime = Timer::GetDeltaTime();

			m_Renderer.ClearScreen();

			Update(deltaTime);
			Render();

			m_Renderer.Present();
		}
	}

private:
	Window m_Window;

	Renderer m_Renderer;

	Object m_Nanosuit;

	FreeCamera m_Camera;

private:
	void Update(float deltaTime)
	{
		m_Window.Update();

		m_Camera.Update(deltaTime);

		m_Nanosuit.Update();
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