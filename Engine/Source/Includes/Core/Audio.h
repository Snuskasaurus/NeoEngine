#pragma once
#include "../Export.h"
#include <vector>

namespace sf
{
	class Sound;
}

namespace neo
{
	class NEOENGINE_API Audio
	{
	public:
		static Audio* Instance();
		inline static void Add(sf::Sound* _sound) { Instance()->m_sounds.push_back(_sound); };

	private:
		std::vector<sf::Sound*> m_sounds;
	};
}
