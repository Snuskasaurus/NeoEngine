#include "../../Includes/Systems/Scene.h"
#include "../../Includes/Systems/Entity.h"
#include "..\..\Includes\Systems\Scene.h"

using namespace neo;

neo::Scene::Scene()
{
	m_rootsEntities.reserve(RESERVE_VEC_ROOT_ENTITIES);
}

inline void neo::Scene::AttachEntity(Entity& entity)
{
	size_t size = m_rootsEntities.max_size();
	if (m_rootsEntities.size() >= size - 1)
	{
		m_rootsEntities.resize(size * 2);
	}
	m_rootsEntities.emplace_back(&entity);
}

bool neo::Scene::DetachEntity(Entity& entity)
{
	Entity* entityToDetach = &entity;
	for (size_t index = 0; index < m_rootsEntities.size(); index++)
	{
		if (m_rootsEntities[index] == entityToDetach)
		{
			m_rootsEntities.erase(m_rootsEntities.begin() + index);
			return true;
		}
	}
	return false;
}

void Scene::Load()
{
	for (Entity* entity : m_rootsEntities)
	{
		entity->Load();
	}
	OnLoad();
}

void Scene::Event()
{

}

void Scene::Update()
{
	for (Entity* entity : m_rootsEntities)
	{
		entity->Update();
	}
	OnUpdate();
}

void Scene::Draw()
{
	for (Entity* entity : m_rootsEntities)
	{
		entity->Draw();
	}
	OnDraw();
}

void Scene::Exit()
{
	for (Entity* entity : m_rootsEntities)
	{
		entity->Exit();
	}
	OnExit();
}