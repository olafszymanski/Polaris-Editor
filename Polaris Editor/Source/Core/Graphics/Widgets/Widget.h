#pragma once

#include "../Utils/NonCopyable.h"

class Widget : public NonCopyable
{
public:
	Widget();
	virtual ~Widget();

	void Draw();

	void Show();
	void Hide();

protected:
	virtual void DrawImGui() = 0;

private:
	unsigned int m_ID;
	
	bool m_Draw;
};