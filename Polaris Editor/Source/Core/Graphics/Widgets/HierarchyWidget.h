#pragma once

#include "Widget.h"

#include "../Scenes/Scene.h"

#include "InspectorWidget.h"

class HierarchyWidget : public Widget
{
public:
	HierarchyWidget(Scene& scene, InspectorWidget& inspectorWidget);
	~HierarchyWidget() = default;

private:
	Scene& m_Scene;

	InspectorWidget& m_InspectorWidget;

private:
	virtual void DrawImGui() override;
};