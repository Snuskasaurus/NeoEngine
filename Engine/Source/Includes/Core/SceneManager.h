#pragma once
#include "../Export.h"

#include "../Systems/Scene.h"


namespace sf
{
	class Event;
}

namespace neo
{
	class Scene;

	class NEOENGINE_API SceneManager
	{
		friend class Game; // Game is the only class needing the "Update, "Draw", "Exit" methods
	public:
		static void Load(Scene& _scene);
	private:
		static SceneManager* Instance();
		static void Update();
		static void Draw();
		static void Exit();
		static void DispatchEvents(const sf::Event& _event);
		Scene* m_currentScene = nullptr;
	};
}

