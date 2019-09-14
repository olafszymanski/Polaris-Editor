#pragma once

#include "../Utils/NonCopyable.h"

class Widget : public NonCopyable
{
public:
	Widget();
	virtual ~Widget() = default;

	void Draw();

	void Show();
	void Hide();

protected:
	virtual void DrawImGui() = 0;

private:
	bool m_Draw;
};