#pragma once

class Keyboard
{
public:
	static bool IsKeyPressed(DirectX::Keyboard::Keys key);
	static bool IsKeyReleased(DirectX::Keyboard::Keys key);
	
	static bool IsKeyDown(DirectX::Keyboard::Keys key);
	static bool IsKeyUp(DirectX::Keyboard::Keys key);

protected:
	Keyboard() = default;
	~Keyboard() = default;

	void HandleInput(UINT message, WPARAM wParam, LPARAM lParam);

	void Update();

private:
	static std::unique_ptr<DirectX::Keyboard> s_Keyboard;
	static std::unique_ptr<DirectX::Keyboard::KeyboardStateTracker> s_StateTracker;
};