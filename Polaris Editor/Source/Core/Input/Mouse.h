#pragma once

class Window;

enum class MouseButton
{
	RIGHT, LEFT, MIDDLE, X1, X2
};

struct MousePosition
{
	int X, Y;
};

class Mouse
{
public:
	static bool IsButtonPressed(MouseButton button);
	static bool IsButtonReleased(MouseButton button);
	static bool IsButtonHeld(MouseButton button);
	static bool IsButtonUp(MouseButton button);

	inline static bool IsScrolling()
	{
		int scrollWheelValue = GetScrollWheelValue();

		s_Mouse->ResetScrollWheelValue();

		return scrollWheelValue != 0;
	}
	inline static int GetScrollWheelValue() { return s_State.scrollWheelValue; }

	inline static bool IsVisible() { return s_Mouse->IsVisible(); }
	inline static bool IsRelative() { return s_State.positionMode == DirectX::Mouse::MODE_RELATIVE ? true : false; }
	inline static bool IsAbsolute() { return s_State.positionMode == DirectX::Mouse::MODE_ABSOLUTE ? true : false; }
	
	inline static void SetVisible(bool visible) { s_Mouse->SetVisible(visible); }
	inline static void SetRelative() { s_Mouse->SetMode(DirectX::Mouse::MODE_RELATIVE); }
	inline static void SetAbsolute() { s_Mouse->SetMode(DirectX::Mouse::MODE_ABSOLUTE); }

	inline static MousePosition GetPosition() { return { s_State.x, s_State.y }; }

protected:
	Mouse() = default;
	~Mouse() = default;

	static void SetWindow(const Window& window);

	static void HandleInput(UINT message, WPARAM wParam, LPARAM lParam);

	static void Update();

private:
	static std::unique_ptr<DirectX::Mouse> s_Mouse;
	static DirectX::Mouse::State s_State;
	static std::unique_ptr<DirectX::Mouse::ButtonStateTracker> s_StateTracker;
};