#include "../../Includes/Components/SpriteRenderer.h"

#include <iostream>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "../../Includes/Core/Screen.h"
#include "../../Includes/Assets/Texture.h"
#include "Includes/Core/AssetManager.h"

using namespace neo;

SpriteRenderer::SpriteRenderer()
{
	m_sprite = new sf::Sprite();
}

SpriteRenderer::~SpriteRenderer()
{
	if (nullptr != m_sprite) delete m_sprite;
	m_texture->RemoveUse();
}

void SpriteRenderer::SetTexture(std::string const& _filename, float _xOrigin, float _yOrigin)
{
	if (nullptr == m_sprite) return;
	if (m_texture)
	{
		m_texture->RemoveUse();
		m_texture = nullptr;
	}
	else m_texture = AssetManager::AddTexture(SPRITE_DATA_FOLDER_PATH + _filename + SPRITE_EXTENSION);
	if (nullptr == m_texture) return;
	sf::Texture* texture = m_texture->GetSFMLTexture();
	if (nullptr == texture) return;
	m_sprite->setTexture(*texture);
	SetOrigin(_xOrigin, _yOrigin);
}

void SpriteRenderer::SetOrigin(float _xOrigin, float _yOrigin)
{
	if (nullptr == m_sprite) return;
	if (nullptr == m_texture) return;
	sf::Texture* texture = m_texture->GetSFMLTexture();
	if (nullptr == texture) return;

	_xOrigin = Math::Clamp(_xOrigin, 0.0f, 1.0f);
	_yOrigin = Math::Clamp(_yOrigin, 0.0f, 1.0f);

	Vector2D origin;
	Vector2D textureSize = Vector2D((float)texture->getSize().x, (float)texture->getSize().y);
	origin.x = (float)textureSize.x * _xOrigin;
	origin.y = (float)textureSize.y * _yOrigin;
	m_sprite->setOrigin(sf::Vector2f(origin.x, origin.y));
}

void neo::SpriteRenderer::Draw(Vector2D _position, float _size, float _angle, float _opacity)
{
	if (nullptr == m_sprite) return;
	static sf::RenderWindow* window = Screen::GetRenderWindow();
	m_sprite->setPosition(sf::Vector2f(_position.x, _position.y));
	m_sprite->setScale(sf::Vector2f(_size, _size));
	m_sprite->setRotation(_angle);
	m_sprite->setColor(sf::Color((sf::Uint8)255, (sf::Uint8)255, (sf::Uint8)255, (sf::Uint8)(_opacity * 255.0f)));
	window->draw(*m_sprite);
}
