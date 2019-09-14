#include "pch.h"

#include "Widget.h"

#include "../Managers/WidgetManager.h"

Widget::Widget()
	: m_Draw(true)
{
	WidgetManager::AddWidget(*this);
}

void Widget::Draw()
{
	if (m_Draw) DrawImGui();
}

void Widget::Show()
{
	m_Draw = true;
}
void Widget::Hide()
{
	m_Draw = false;
}