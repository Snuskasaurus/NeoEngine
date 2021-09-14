#include "../../Includes/Core/Screen.h"

#include "../../Includes/Core/Settings.h"

using namespace neo;

Screen* neo::Screen::Instance()
{
	static Screen screen;
	return &screen;
}

void neo::Screen::Load()
{
	sf::Vector2u resolution = (sf::Vector2u)Settings::GetResolution();
	Instance()->m_window = new sf::RenderWindow(sf::VideoMode(resolution.x, resolution.y), 32U);
}
