#pragma once
#include "../Export.h"

#include "../Systems/Scene.h"

namespace neo
{
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
		Scene* m_currentScene = nullptr;
	};
}

