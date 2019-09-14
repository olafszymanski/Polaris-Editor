#include "pch.h"

#include "WidgetManager.h"

std::vector<Widget*> WidgetManager::s_Widgets { };

void WidgetManager::AddWidget(Widget& widget)
{
	s_Widgets.push_back(&widget);
}