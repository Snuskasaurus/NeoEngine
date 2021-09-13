#pragma once

namespace neo
{
	class NEOENGINE_API Sound
	{
	public:
		static Sound* Instance();
		inline static void Add(sf::Sound* _sound) { Instance()->m_sounds.push_back(_sound); };

	private:
		std::vector<sf::Sound*> m_sounds;
	};
}
