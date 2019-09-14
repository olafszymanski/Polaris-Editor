#pragma once

#include "../Widgets/Widget.h"

class WidgetManager
{
public:
	static unsigned int AddWidget(Widget& widget);
	static void RemoveWidget(unsigned int ID);

	// Getter
	inline static std::unordered_map<unsigned int, Widget*>& GetWidgets() { return s_Widgets; }

private:
	static std::unordered_map<unsigned int, Widget*> s_Widgets;
	static unsigned int s_CurrentID;

private:
	WidgetManager() = default;
	~WidgetManager() = default;
};