#pragma once

#include "Widget.h"

#include "../Window.h"

class SettingsWidget : public Widget
{
public:
	SettingsWidget(const Window& window);
	~SettingsWidget() = default;

private:
	const Window& m_Window;

private:
	virtual void DrawImGui() override;

	void SetDarkStyle();
	void SetLightStyle();
	void SetClassicStyle();
};