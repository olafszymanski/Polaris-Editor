#pragma once

#include "Widget.h"

#include "../Window.h"

class InfoWidget : public Widget
{
public:
	InfoWidget(const Window& window);
	~InfoWidget() = default;

private:
	const Window& m_Window;

private:
	virtual void DrawImGui() override;
};