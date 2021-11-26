#include "../../Includes/Core/SceneManager.h"

#include "../../Includes/Systems/Scene.h"
#include "../../Includes/Core/SceneManager.h"
#include "../../Includes/Core/Screen.h"
#include "../../Includes/Core/Time.h"
#include "../../Includes/Core/Audio.h"
#include "../../Includes/Core/Input.h"

#include "SFML/Window/Event.hpp"

#include <iostream>

#pragma warning( disable : 26812 )

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

void neo::SceneManager::DispatchEvents(const sf::Event& _event)
{
	switch (_event.type)
	{
	case sf::Event::LostFocus:
	{
		Instance()->m_currentScene->OnLostFocus();
		break;
	}
	case sf::Event::GainedFocus:
	{
		Instance()->m_currentScene->OnGainedFocus();
		break;
	}
	case sf::Event::KeyPressed:
	{
		const Input::KeyCode keyCode = (Input::KeyCode)_event.key.code;
		Instance()->m_currentScene->OnKeyPressed(keyCode);
		break;
	}
	case sf::Event::KeyReleased:
	{
		const Input::KeyCode keyCode = (Input::KeyCode)_event.key.code;
		Instance()->m_currentScene->OnKeyReleased(keyCode);
		break;
	}
	case sf::Event::MouseWheelScrolled:
	{
		const float delta = _event.mouseWheelScroll.delta;
		Instance()->m_currentScene->OnMouseWheelScrolled(delta);
		break;
	}
	case sf::Event::MouseButtonPressed:
	{
		const Vector2D mousePosition = 
			Vector2D((float)_event.mouseButton.x, (float)_event.mouseButton.y);
		const Input::MouseCode mouseCode = (Input::MouseCode)_event.mouseButton.button;
		Instance()->m_currentScene->OnMouseButtonPressed(mouseCode, mousePosition);
		break;
	}
	case sf::Event::MouseButtonReleased:
	{
		const Vector2D mousePosition = 
			Vector2D((float)_event.mouseButton.x, (float)_event.mouseButton.y);
		const Input::MouseCode mouseCode = (Input::MouseCode)_event.mouseButton.button;
		Instance()->m_currentScene->OnMouseButtonReleased(mouseCode, mousePosition);
		break;
	}
	case sf::Event::MouseMoved:
	{
		const Vector2D mousePosition =
			Vector2D((float)_event.mouseMove.x, (float)_event.mouseMove.y);
		Instance()->m_currentScene->OnMouseMoved(mousePosition);
		break;
	}
	default:
		break;
	}
}
