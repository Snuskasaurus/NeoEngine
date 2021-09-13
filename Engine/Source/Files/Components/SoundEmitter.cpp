#include "../../Includes/Components/SoundEmitter.h"

using namespace neo;

#include "../../Includes/Core/Sound.h"
#include "../../Includes/Core/Random.h"

SoundEmitter::~SoundEmitter()
{
	for (sf::SoundBuffer* buffer : m_buffers)
	{
		if (nullptr != buffer) delete buffer;
	}
}

void SoundEmitter::AddNewBuffer(std::string _filename)
{
	sf::SoundBuffer* newBuffer = new sf::SoundBuffer();
	if (nullptr == newBuffer) return;

	bool succes = newBuffer->loadFromFile(SOUND_DATA_FOLDER_PATH + _filename + SOUND_EXTENSION);
	if (false == succes)
	{
		delete newBuffer;
		return;
	}

	m_buffers.push_back(newBuffer);
}

void SoundEmitter::Play()
{
	if (m_buffers.size() == 0) return;

	int index = 0;
	if (Type::IS_RANDOM == m_type) index = Random::Range(0, (int)m_buffers.size() - 1);
	sf::Sound* newSound = new sf::Sound(*m_buffers[index]);
	if (nullptr == newSound) return;
	newSound->setVolume(TEMP_VOLUME);
	newSound->play();
	Sound::Add(newSound);
}
