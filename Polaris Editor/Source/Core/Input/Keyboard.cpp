#include "../pch.h"

#include "Keyboard.h"

std::unique_ptr<DirectX::Keyboard> Keyboard::s_Keyboard = std::make_unique<DirectX::Keyboard>();
std::unique_ptr<DirectX::Keyboard::KeyboardStateTracker> Keyboard::s_StateTracker = std::make_unique<DirectX::Keyboard::KeyboardStateTracker>();

bool Keyboard::IsKeyPressed(DirectX::Keyboard::Keys key)
{
	return s_StateTracker->IsKeyPressed(key);
}
bool Keyboard::IsKeyReleased(DirectX::Keyboard::Keys key)
{
	return s_StateTracker->IsKeyReleased(key);
}

bool Keyboard::IsKeyDown(DirectX::Keyboard::Keys key)
{
	return s_Keyboard->GetState().IsKeyDown(key);
}
bool Keyboard::IsKeyUp(DirectX::Keyboard::Keys key)
{
	return s_Keyboard->GetState().IsKeyUp(key);
}

void Keyboard::HandleInput(UINT message, WPARAM wParam, LPARAM lParam)
{
	s_Keyboard->ProcessMessage(message, wParam, lParam);
}

void Keyboard::Update()
{
	s_StateTracker->Update(s_Keyboard->GetState());
}