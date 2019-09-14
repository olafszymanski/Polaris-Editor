#include "pch.h"

#include "Widget.h"

#include "../Managers/WidgetManager.h"

Widget::Widget()
	: m_ID(0)
	, m_Draw(true)
{
	m_ID = WidgetManager::AddWidget(*this);
}
Widget::~Widget()
{
	WidgetManager::RemoveWidget(m_ID);
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