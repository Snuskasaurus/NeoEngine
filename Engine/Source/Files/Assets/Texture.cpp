#include "stdafx.h"
#include "../../Includes/Assets/Texture.h"

#include "SFML/Graphics/Texture.hpp"

using namespace neo;

Texture::~Texture()
{
	if (m_sfmlTexture) delete(m_sfmlTexture);
}

Texture* Texture::CreateFromFile(const std::string& _string)
{
	neo::Texture* newTexture = new neo::Texture();
	if (newTexture == nullptr) return nullptr;
	newTexture->m_sfmlTexture = new sf::Texture();
	if (newTexture->m_sfmlTexture == nullptr)
	{
		delete newTexture;
		return nullptr;
	}
	if (newTexture->m_sfmlTexture->loadFromFile(_string))
	{
		delete newTexture;
		return nullptr;
	}
	newTexture->m_sfmlTexture->setSmooth(false);
	newTexture->m_nbUse = 1;
	return newTexture;
}
