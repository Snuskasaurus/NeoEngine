#pragma once
#include "../Export.h"

#include "../Core/Vector2D.h"

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#define SPRITE_DATA_FOLDER_PATH "Data/Sprites/"
#define SPRITE_EXTENSION ".png"

#define DF_SIZE 1.0f
#define DF_ANGLE 0.0f
#define DF_X_ORIGIN 0.5f
#define DF_Y_ORIGIN 0.5f

namespace neo
{
	class NEOENGINE_API SpriteRenderer
	{
	public:
		SpriteRenderer();
		SpriteRenderer(std::string const& _filename, float _xOrigin = DF_X_ORIGIN, float _yOrigin = DF_Y_ORIGIN);
		~SpriteRenderer();

		void SetTexture(std::string const& _filename, float _xOrigin = DF_X_ORIGIN, float _yOrigin = DF_Y_ORIGIN);
		void SetOrigin(float _xOrigin = DF_X_ORIGIN, float _yOrigin = DF_Y_ORIGIN);
		void Draw(sf::Vector2f _position, float _size = DF_SIZE, float _angle = DF_ANGLE, float _opacity = 1.0f);
		void Draw(Vector2D _position = Vector2D::Zero, float _size = DF_SIZE, float _angle = DF_ANGLE, float _opacity = 1.0f);

	private:
		sf::Texture* m_texture = nullptr;
		sf::Sprite* m_sprite = nullptr;
	};
}