#pragma once

class Mesh;
class Object;

#include "Widget.h"

class InspectorWidget : public Widget
{
public:
	InspectorWidget();
	~InspectorWidget() = default;

	// Getter
	inline Object* GetCurrentObject() const { return m_CurrentObject; }

	// Setters
	inline void SetCurrentMesh(Mesh* currentMesh) { m_CurrentMesh = currentMesh; }
	inline void SetCurrentObject(Object* currentObject) { m_CurrentObject = currentObject; }

private:
	Mesh* m_CurrentMesh;
	Object* m_CurrentObject;

private:
	virtual void DrawImGui() override;
};