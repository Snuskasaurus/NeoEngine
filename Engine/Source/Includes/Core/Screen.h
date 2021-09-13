#pragma once
#include "../Export.h"

#include <SFML/Graphics.hpp>

namespace neo
{
	class NEOENGINE_API Screen
	{

	public:
		static Screen* Instance();
		static sf::RenderWindow* GetWindow() { return Instance()->m_window; };

	private:
		sf::RenderWindow* m_window;
	};
}

