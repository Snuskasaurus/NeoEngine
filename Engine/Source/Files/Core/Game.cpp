#include "../../Includes/Core/Game.h"

#include "../../Includes/Systems/Scene.h"
#include "../../Includes/Core/Screen.h"
#include "../../Includes/Core/Audio.h"
#include "../../Includes/Core/Time.h"
#include "../../Includes/Core/SceneManager.h"
#include "../../Includes/Core/Settings.h"

using namespace neo;

Game* Game::Instance()
{
	static Game game;
	return &game;
}

void Game::Run(Scene& _scene)
{
	const static Game* game = Instance();

	Instance()->m_isRunning = true;
	Settings::LoadFromFile();
	Screen::Load();
	//Physic::Load();
	//Audio::Load();
	//Time::Load();
	SceneManager::Load(_scene);

	sf::RenderWindow* window = Screen::GetRenderWindow();
	if (nullptr == window) return;
	while (game->m_isRunning == true)
	{
		// Events
		sf::Event event;
		while (game->m_isRunning && window->pollEvent(event))
		{
			SceneManager::DispatchEvents(event);
			if (event.type == sf::Event::Closed) Exit();
		}

		// Update
		//if (game->m_isRunning == true) Physic::Update();
		//if (game->m_isRunning == true) Audio::Update();
		//if (game->m_isRunning == true) Time::Update();
		if (game->m_isRunning == true) SceneManager::Update();

		// Draw 
		window->clear();
		if (game->m_isRunning == true) SceneManager::Draw();
		window->display();
	}
	
	//Physic::Exit();
	//Audio::Exit();
	//Time::Exit();
	SceneManager::Exit();
	Screen::Exit();
}