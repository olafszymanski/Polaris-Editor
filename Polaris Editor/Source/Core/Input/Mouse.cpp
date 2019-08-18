#include "pch.h"

#include "Mouse.h"

#include "../Graphics/Window.h"

std::unique_ptr<DirectX::Mouse> Mouse::s_Mouse = std::make_unique<DirectX::Mouse>();
DirectX::Mouse::State Mouse::s_State;
std::unique_ptr<DirectX::Mouse::ButtonStateTracker> Mouse::s_StateTracker = std::make_unique<DirectX::Mouse::ButtonStateTracker>();

bool Mouse::IsButtonPressed(MouseButton button)
{
	switch (button)
	{
	case MouseButton::RIGHT:
		return s_StateTracker->rightButton == DirectX::Mouse::ButtonStateTracker::PRESSED ? true : false;
		break;

	case MouseButton::LEFT:
		return s_StateTracker->leftButton == DirectX::Mouse::ButtonStateTracker::PRESSED ? true : false;
		break;

	case MouseButton::MIDDLE:
		return s_StateTracker->middleButton == DirectX::Mouse::ButtonStateTracker::PRESSED ? true : false;
		break;

	case MouseButton::X1:
		return s_StateTracker->xButton1 == DirectX::Mouse::ButtonStateTracker::PRESSED ? true : false;
		break;

	case MouseButton::X2:
		return s_StateTracker->xButton2 == DirectX::Mouse::ButtonStateTracker::PRESSED ? true : false;
		break;

	default:
		return false;
	}
}
bool Mouse::IsButtonReleased(MouseButton button)
{
	switch (button)
	{
	case MouseButton::RIGHT:
		return s_StateTracker->rightButton == DirectX::Mouse::ButtonStateTracker::RELEASED ? true : false;
		break;

	case MouseButton::LEFT:
		return s_StateTracker->leftButton == DirectX::Mouse::ButtonStateTracker::RELEASED ? true : false;
		break;

	case MouseButton::MIDDLE:
		return s_StateTracker->middleButton == DirectX::Mouse::ButtonStateTracker::RELEASED ? true : false;
		break;

	case MouseButton::X1:
		return s_StateTracker->xButton1 == DirectX::Mouse::ButtonStateTracker::RELEASED ? true : false;
		break;

	case MouseButton::X2:
		return s_StateTracker->xButton2 == DirectX::Mouse::ButtonStateTracker::RELEASED ? true : false;
		break;

	default:
		return false;
	}
}
bool Mouse::IsButtonHeld(MouseButton button)
{
	switch (button)
	{
	case MouseButton::RIGHT:
		return s_StateTracker->rightButton == DirectX::Mouse::ButtonStateTracker::HELD ? true : false;
		break;

	case MouseButton::LEFT:
		return s_StateTracker->leftButton == DirectX::Mouse::ButtonStateTracker::HELD ? true : false;
		break;

	case MouseButton::MIDDLE:
		return s_StateTracker->middleButton == DirectX::Mouse::ButtonStateTracker::HELD ? true : false;
		break;

	case MouseButton::X1:
		return s_StateTracker->xButton1 == DirectX::Mouse::ButtonStateTracker::HELD ? true : false;
		break;

	case MouseButton::X2:
		return s_StateTracker->xButton2 == DirectX::Mouse::ButtonStateTracker::HELD ? true : false;
		break;

	default:
		return false;
	}
}
bool Mouse::IsButtonUp(MouseButton button)
{
	switch (button)
	{
	case MouseButton::RIGHT:
		return s_StateTracker->rightButton == DirectX::Mouse::ButtonStateTracker::UP ? true : false;
		break;

	case MouseButton::LEFT:
		return s_StateTracker->leftButton == DirectX::Mouse::ButtonStateTracker::UP ? true : false;
		break;

	case MouseButton::MIDDLE:
		return s_StateTracker->middleButton == DirectX::Mouse::ButtonStateTracker::UP ? true : false;
		break;

	case MouseButton::X1:
		return s_StateTracker->xButton1 == DirectX::Mouse::ButtonStateTracker::UP ? true : false;
		break;

	case MouseButton::X2:
		return s_StateTracker->xButton2 == DirectX::Mouse::ButtonStateTracker::UP ? true : false;
		break;

	default:
		return false;
	}
}

void Mouse::SetWindow(const Window& window)
{
	s_Mouse->SetWindow(window.GetHandle());
}

void Mouse::HandleInput(UINT message, WPARAM wParam, LPARAM lParam)
{
	s_Mouse->ProcessMessage(message, wParam, lParam);
}

void Mouse::Update()
{
	s_State = s_Mouse->GetState();
	s_StateTracker->Update(s_State);
}