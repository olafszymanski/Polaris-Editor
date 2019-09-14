#include "pch.h"

#include "WidgetManager.h"

std::unordered_map<unsigned int, Widget*> WidgetManager::s_Widgets { };
unsigned int WidgetManager::s_CurrentID = 0;

unsigned int WidgetManager::AddWidget(Widget& widget)
{
	s_Widgets[s_CurrentID] = &widget;

	s_CurrentID += 1;

	return s_CurrentID - 1;
}
void WidgetManager::RemoveWidget(unsigned int ID)
{
	s_Widgets[ID] = nullptr;
}