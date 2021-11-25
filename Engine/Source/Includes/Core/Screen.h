#pragma once
#include "../Export.h"

namespace sf
{
	class RenderWindow;
}

namespace neo
{
	class NEOENGINE_API Screen
	{
		friend class Game; // Game is the only class needing the "Load" method
	public:
		static sf::RenderWindow* GetRenderWindow() { return Instance()->m_window; };
	private:
		Screen() = default;
		~Screen() = default;
		static Screen* Instance();
		static void Load();
		static void Exit();
	private:
		sf::RenderWindow* m_window;
	};
}

