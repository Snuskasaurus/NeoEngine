#pragma once
#include "../Export.h"

#include <SFML/Graphics.hpp>

namespace neo
{
	class NEOENGINE_API Screen
	{
		friend class Game; // Game is the only class needing the "Load" method
	public:
		static sf::RenderWindow* GetWindow() { return Instance()->m_window; };

	private:
		static Screen* Instance();
		static void Load();
		sf::RenderWindow* m_window;
	};
}

