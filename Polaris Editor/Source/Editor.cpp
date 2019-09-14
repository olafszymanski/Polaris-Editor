#include "pch.h"

#include "Core/Graphics/Window.h"

#include "Core/Graphics/Renderers/Renderer.h"
#include "Core/Graphics/Renderers/WidgetRenderer.h"

#include "Core/Graphics/Drawables/Object.h"

#include "Core/Graphics/Cameras/FreeCamera.h"

#include "Core/Graphics/Managers/LightManager.h"

#include "Core/Timer.h"

#include "Core/Graphics/Widgets/CameraWidget.h"
#include "Core/Graphics/Widgets/InfoWidget.h"

class Editor
{
public:
	Editor()
		: m_Window(1280, 760, "Polaris Editor", false)
		, m_Nanosuit({ "Resources/Models/Nanosuit/nanosuit.obj" }, { 0.0f, 0.0f, 0.0f }, { DirectX::XM_PI, 0.0f, 0.0f })
		, m_Camera(m_Window, { 0.0f, 10.0f, 5.0f })
		, m_CameraWidget(m_Camera), m_InfoWidget(m_Window)
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

			Update(deltaTime);
			Render();
		}
	}

private:
	Window m_Window;

	Renderer m_Renderer;
	WidgetRenderer m_WidgetRenderer;

	Object m_Nanosuit;

	FreeCamera m_Camera;

	CameraWidget m_CameraWidget;
	InfoWidget m_InfoWidget;

private:
	void Update(float deltaTime)
	{
		m_Window.Update();

		m_Camera.Update(deltaTime);

		m_Nanosuit.Update();
	}
	void Render()
	{
		m_Renderer.ClearScreen();

		m_Renderer.Draw(m_Camera);
		m_WidgetRenderer.Draw();

		m_Renderer.Present();
	}
};

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	Editor editor;
	editor.Run();

	return 0;
}