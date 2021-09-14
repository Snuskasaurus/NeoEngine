#include "../../Includes/Core/Game.h"

#include "../../Includes/Core/Screen.h"
#include "../../Includes/Core/Physic.h"
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

void Game::Load(Scene& _scene)
{
	Instance()->m_isRunning = true;
	Settings::LoadFromFile();
	Screen::Load();
	//Physic::Load();
	//Audio::Load();
	//Time::Load();
	SceneManager::Load(_scene);
}

void Game::Run()
{
	static Game* game = Instance();

	sf::RenderWindow* window = Screen::GetWindow();
	while (game->m_isRunning == true)
	{
		// Events
		sf::Event event;
		while (window->pollEvent(event))
		{
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

}

void Game::Exit()
{
	Instance()->m_isRunning = false;
	//Physic::Exit();
	//Audio::Exit();
	//Time::Exit();
	SceneManager::Exit();
}
