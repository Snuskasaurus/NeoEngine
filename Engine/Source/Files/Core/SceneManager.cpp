#include "../../Includes/Core/SceneManager.h"

#include "../../Includes/Core/SceneManager.h"
#include "../../Includes/Core/Screen.h"
#include "../../Includes/Core/Time.h"
#include "../../Includes/Core/Physic.h"
#include "../../Includes/Core/Audio.h"

using namespace neo;

SceneManager* SceneManager::Instance()
{
	static SceneManager sceneManager;
	return &sceneManager;
}

void neo::SceneManager::Load(Scene& _scene)
{
	SceneManager* instance = Instance();

	if (nullptr == instance->m_currentScene)
	{
		instance->m_currentScene = &_scene;
		instance->m_currentScene->Load();
	}
}

void SceneManager::Update()
{
	SceneManager* instance = Instance();
	instance->m_currentScene->Update();
}

void SceneManager::Draw()
{
	SceneManager* instance = Instance();
	instance->m_currentScene->Draw();
}

void SceneManager::Exit()
{
	SceneManager* instance = Instance();
	instance->m_currentScene->Exit();
}
