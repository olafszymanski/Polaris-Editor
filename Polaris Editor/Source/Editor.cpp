#include "pch.h"

#include "Core/Graphics/Window.h"

#include "Core/Graphics/Renderers/Renderer.h"
#include "Core/Graphics/Renderers/WidgetRenderer.h"

#include "Core/Graphics/Cameras/FreeCamera.h"

#include "Core/Graphics/Scenes/Scene.h"

#include "Core/Timer.h"

#include "Core/Graphics/Widgets/CameraWidget.h"
#include "Core/Graphics/Widgets/InfoWidget.h"
#include "Core/Graphics/Widgets/SettingsWidget.h"
#include "Core/Graphics/Widgets/InspectorWidget.h"
#include "Core/Graphics/Widgets/HierarchyWidget.h"

class Editor
{
public:
	Editor()
		: m_Window(1280, 760, "Polaris Editor", true)
		, m_DirectionalLight({ 0.0f, 0.0f, -1.0f }, { 1.0f, 1.0f, 1.0f })
		, m_Camera(m_Window, { 0.0f, 10.0f, 5.0f })
		, m_Scene(m_Camera)
		, m_CameraWidget(m_Camera), m_InfoWidget(m_Window), m_SettingsWidget(m_Window), m_HierarchyWidget(m_Scene, m_InspectorWidget)
	{
	}
	~Editor()
	{
	}

	void Run()
	{	
		while (m_Window.IsOpen())
		{
			Timer::Tick();

			Update(Timer::GetDeltaTime());
			Render();
		}
	}

private:
	Window m_Window;

	Renderer m_Renderer;
	WidgetRenderer m_WidgetRenderer;

	DirectionalLight m_DirectionalLight;

	FreeCamera m_Camera;

	Scene m_Scene;

	CameraWidget m_CameraWidget;
	InfoWidget m_InfoWidget;
	SettingsWidget m_SettingsWidget;
	InspectorWidget m_InspectorWidget;
	HierarchyWidget m_HierarchyWidget;

private:
	void Update(float deltaTime)
	{
		m_Window.Update();

		m_Camera.Update(deltaTime);
	}
	void Render()
	{
		m_Renderer.ClearScreen();

		m_Renderer.Draw(m_Scene);
		m_WidgetRenderer.Draw(m_Window);

		m_Renderer.Present();
	}
};

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	Editor editor;
	editor.Run();

	return 0;
}