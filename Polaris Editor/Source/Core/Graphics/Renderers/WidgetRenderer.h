#pragma once

class Window;

class WidgetRenderer
{
public:
	WidgetRenderer() = default;
	~WidgetRenderer() = default;

	void Draw(const Window& window);
};