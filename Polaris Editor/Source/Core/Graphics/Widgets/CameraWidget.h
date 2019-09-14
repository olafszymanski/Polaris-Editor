#pragma once

#include "Widget.h"

#include "../Cameras/Camera.h"

class CameraWidget : public Widget
{
public:
	CameraWidget(Camera& camera);
	~CameraWidget() = default;

private:
	Camera& m_Camera;

private:
	virtual void DrawImGui() override;
};