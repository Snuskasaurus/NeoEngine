#pragma once
#include "../Export.h"
#include <string>

namespace sf
{
	class Texture;
}

namespace neo
{
	class NEOENGINE_API Texture
	{
	public:
		static Texture* CreateFromFile(const std::string& _string);
		int AddUse() { return m_nbUse++; };
		int RemoveUse() { return m_nbUse--; };
		sf::Texture* GetSFMLTexture()const { return m_sfmlTexture; }
	private:
		Texture() = default;
		~Texture();
		sf::Texture* m_sfmlTexture = nullptr;
		int m_nbUse = 0;
	};
}

