#include "../../Includes/Core/Screen.h"

#include "../../Includes/Core/Settings.h"
#include <SFML/Graphics.hpp>

using namespace neo;

Screen* Screen::Instance()
{
	static Screen screen;
	return &screen;
}


void neo::Screen::Load()
{
	Vector2D resolution = Settings::GetResolution();
	Instance()->m_window = new sf::RenderWindow(sf::VideoMode((unsigned int)resolution.x, (unsigned int)resolution.y), 32U);
}

void neo::Screen::Exit()
{
	if (Instance()->m_window) delete Instance()->m_window;
}
