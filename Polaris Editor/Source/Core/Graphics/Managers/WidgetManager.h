#pragma once

#include "../Widgets/Widget.h"

class WidgetManager
{
public:
	static void AddWidget(Widget& widget);
	inline static std::vector<Widget*>& GetWidgets() { return s_Widgets; }

private:
	static std::vector<Widget*> s_Widgets;

private:
	WidgetManager() = default;
	~WidgetManager() = default;
};