#include "Core/pch.h"

#include "Core/Window.h"

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
			Update();
			Render();
		}
	}

private:
	Window m_Window;

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