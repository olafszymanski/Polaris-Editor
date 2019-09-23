#pragma once

class Object;

#include "../Cameras/Camera.h"

class Scene
{
public:
	Scene(Camera& camera);
	~Scene();

	Scene(const Scene& other);
	Scene& operator=(const Scene& other);

	void AddObject(Object* object);
	void RemoveObject(unsigned int ID);

	// Getters
	inline const Camera& GetCamera() const { return m_Camera; }

	inline const std::unordered_map<unsigned int, Object*>& GetObjects() const { return m_Objects; }

private:
	Camera& m_Camera;

	std::unordered_map<unsigned int, Object*> m_Objects;
	unsigned int m_CurrentID;
};