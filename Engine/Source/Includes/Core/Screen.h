#pragma once

namespace neo
{
	class Screen
	{

	public:
		static Screen* Instance();
		static sf::RenderWindow& GetWindow() { return Instance()->m_window; };

	private:
		sf::RenderWindow m_window;

	};
}

