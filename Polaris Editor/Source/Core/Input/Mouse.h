#pragma once

class Window;

enum class MouseButton
{
	RIGHT, LEFT, MIDDLE, X1, X2
};

class Mouse
{
public:
	static bool IsButtonPressed(MouseButton button);
	static bool IsButtonReleased(MouseButton button);
	static bool IsButtonHeld(MouseButton button);
	static bool IsButtonUp(MouseButton button);

	static bool IsScrolling();

	static int GetScrollWheelValue();

	static bool IsVisible() { return s_Mouse->IsVisible(); }
	static void SetVisible(bool visible) { s_Mouse->SetVisible(visible); }

	static bool IsRelative() { return s_Mouse->GetState().positionMode == DirectX::Mouse::MODE_RELATIVE ? true : false; }
	static void SetRelative() { s_Mouse->SetMode(DirectX::Mouse::MODE_RELATIVE); }
	static bool IsAbsolute() { return s_Mouse->GetState().positionMode == DirectX::Mouse::MODE_ABSOLUTE ? true : false; }
	static void SetAbsolute() { s_Mouse->SetMode(DirectX::Mouse::MODE_ABSOLUTE); }

	static DirectX::XMUINT2 GetPosition()
	{
		DirectX::Mouse::State state = s_Mouse->GetState();
		return DirectX::XMUINT2(state.x, state.y);
	}

protected:
	Mouse() = default;
	~Mouse() = default;

	void SetWindow(Window& window);

	void HandleInput(UINT message, WPARAM wParam, LPARAM lParam);

	void Update();

private:
	static std::unique_ptr<DirectX::Mouse> s_Mouse;
	static std::unique_ptr<DirectX::Mouse::ButtonStateTracker> s_StateTracker;
};