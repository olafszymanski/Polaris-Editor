#pragma once

#include "Graphics.h"

class Window : protected Graphics
{
public:
	Window(unsigned int width, unsigned int height, const std::string& title, bool resizable);
	~Window();

	Window(const Window& other);
	void operator=(const Window& other);

	void Update();

	void Close();

	// Getters
	unsigned int GetWidth() const { return m_Width; }
	unsigned int GetHeight() const { return m_Height; }
	std::string GetTitle() const { return m_Title; }
	bool IsResizable() const { return m_Width; }

	HWND GetHandle() const { return m_Handle; }

	bool IsOpen() const { return m_Open; }

private:
	unsigned int m_Width, m_Height;
	std::string m_Title;
	bool m_Resizable;

	HINSTANCE m_Instance;
	HWND m_Handle;

	MSG m_Message;

	bool m_Open;

private:
	static LRESULT CALLBACK WindowProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
	static LRESULT CALLBACK WindowProcAdapter(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);

	LRESULT CALLBACK HandleEvents(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
};