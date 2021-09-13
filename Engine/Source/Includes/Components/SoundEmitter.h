#pragma once

#include <vector>
#include <string>
#include <SFML/Audio.hpp>

#define TEMP_VOLUME 2.5f

#define SOUND_DATA_FOLDER_PATH "Data/Sounds/"
#define SOUND_EXTENSION ".wav"

namespace neo
{
	class NEOENGINE_API SoundEmitter
	{
	public:

		SoundEmitter() = default;
		~SoundEmitter();

		enum class Type
		{
			IS_RANDOM,
			IS_LINEAR,
		};

		void AddNewBuffer(std::string _filename);
		void Play();

	private:
		std::vector<sf::SoundBuffer*> m_buffers;
		sf::Sound* m_sound = nullptr;

		Type m_type;
		bool m_isRepeated = false;
	};
}
