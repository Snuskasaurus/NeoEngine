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
	m_rootsEntities.push_back(&entity);
}

bool neo::Scene::DettachEntity(Entity& entity)
{
	for (Entity* entity : m_rootsEntities)
	{

	}
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