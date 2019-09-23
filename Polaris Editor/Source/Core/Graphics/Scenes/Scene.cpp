#include "pch.h"

#include "Scene.h"

#include "../Drawables/Object.h"

Scene::Scene(Camera& camera)
	: m_Camera(camera)
	, m_Objects({ }), m_CurrentID(0)
{
}
Scene::~Scene()
{
	for (auto& object : m_Objects)
	{
		delete object.second;
	}
}

Scene::Scene(const Scene& other)
	: m_Camera(other.m_Camera)
	, m_Objects(other.m_Objects), m_CurrentID(other.m_CurrentID)
{
}
Scene& Scene::operator=(const Scene& other)
{
	if (this != &other)
	{
		m_Camera = other.m_Camera;

		m_Objects = other.m_Objects;
		m_CurrentID = other.m_CurrentID;
	}

	return *this;
}

void Scene::AddObject(Object* object)
{
	for (unsigned int i = 0; i < m_Objects.size(); ++i)
	{
		if (m_Objects[i] != nullptr && object->GetModel().GetName() == m_Objects[i]->GetModel().GetName()) object->GetModel().SetName(std::string(object->GetModel().GetName() + std::to_string(i)));
	}

	object->SetScene(*this);
	m_Objects[m_CurrentID] = object;

	object->SetID(m_CurrentID);

	m_CurrentID += 1;
}
void Scene::RemoveObject(unsigned int ID)
{
	delete m_Objects[ID];
	m_Objects[ID] = nullptr;
}