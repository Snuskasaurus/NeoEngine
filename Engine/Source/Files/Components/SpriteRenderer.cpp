#include "../../Includes/Components/SpriteRenderer.h"

#include "../../Includes/Core/Screen.h"

using namespace neo;

SpriteRenderer::SpriteRenderer()
{
	m_texture = new sf::Texture();
	if (nullptr == m_texture) { std::cout << "Failed to allocate memory for a texture." << std::endl; }

	m_sprite = new sf::Sprite();
	if (nullptr == m_sprite)
	{ 
		delete m_texture;
		m_texture = nullptr;
		std::cout << "Failed to allocate memory for a sprite." << std::endl;
	}
}

SpriteRenderer::SpriteRenderer(std::string const& _filename, float _xOrigin, float _yOrigin)
{
	m_texture = new sf::Texture();
	if (nullptr == m_texture) { std::cout << "Failed to allocate memory for a texture." << std::endl; }

	bool succes = m_texture->loadFromFile(SPRITE_DATA_FOLDER_PATH + _filename + SPRITE_EXTENSION);
	if (false == succes) 
	{
		delete m_texture;
		return;
	}

	m_sprite = new sf::Sprite(*m_texture);
	if (nullptr == m_sprite)
	{
		delete m_texture;
		m_texture = nullptr;
		std::cout << "Failed to allocate memory for a sprite." << std::endl;
	}

	SetOrigin(_xOrigin, _yOrigin);
}

SpriteRenderer::~SpriteRenderer()
{
	if (nullptr != m_texture) delete m_texture;
	if (nullptr != m_sprite) delete m_sprite;
}

void SpriteRenderer::SetTexture(std::string const& _filename, float _xOrigin, float _yOrigin)
{
	if (nullptr == m_texture) return;
	if (nullptr == m_sprite) return;

	m_texture->loadFromFile(SPRITE_DATA_FOLDER_PATH + _filename + SPRITE_EXTENSION);
	m_texture->setSmooth(false);
	m_sprite->setTexture(*m_texture);
	SetOrigin(_xOrigin, _yOrigin);
}

void SpriteRenderer::SetOrigin(float _xOrigin, float _yOrigin)
{
	if (nullptr == m_sprite) return;

	_xOrigin = Math::Clamp(_xOrigin, 0.0f, 1.0f);
	_yOrigin = Math::Clamp(_yOrigin, 0.0f, 1.0f);

	sf::Vector2f origin;
	sf::Vector2u textureSize = m_texture->getSize();
	origin.x = (float)textureSize.x * _xOrigin;
	origin.y = (float)textureSize.y * _yOrigin;
	m_sprite->setOrigin(origin);
}

void SpriteRenderer::Draw(Vector2D _position, float _size, float _angle, float _opacity)
{
	Draw(_position.ToSFML(), _size, _angle, _opacity);
}

void SpriteRenderer::Draw(sf::Vector2f _position, float _size, float _angle, float _opacity)
{
	if (nullptr == m_sprite) return;
	static sf::RenderWindow& window = Screen::GetWindow();
	m_sprite->setPosition(_position);
	m_sprite->setScale(sf::Vector2f(_size, _size));
	m_sprite->setRotation(_angle);
	m_sprite->setColor(sf::Color((sf::Uint8)255, (sf::Uint8)255, (sf::Uint8)255, (sf::Uint8)(_opacity * 255.0f)));
	window.draw(*m_sprite);
}
