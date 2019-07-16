#pragma once

#include "../Utils/NonCopyable.h"

#include "Graphics/Graphics.h"

#include "Input/Keyboard.h"
#include "Input/Mouse.h"

class Window : public NonCopyable, protected Graphics, Keyboard, Mouse
{
public:
	Window(unsigned int width, unsigned int height, const std::string& title, bool resizable);
	~Window();

	void Update();

	void Close();

	// Getters
	inline unsigned int GetWidth() const { return m_Width; }
	inline unsigned int GetHeight() const { return m_Height; }
	inline std::string GetTitle() const { return m_Title; }
	inline bool IsResizable() const { return m_Width; }

	inline HWND GetHandle() const { return m_Handle; }

	inline bool IsOpen() const { return m_Open; }

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