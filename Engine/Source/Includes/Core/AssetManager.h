#pragma once
#include "../Export.h"
#include <string>

namespace neo
{
	class Texture;

	class AssetManager
	{
	public:
		static Texture* AddTexture(const std::string& _name);
		static void VerifyUnusedAssets();
	private:
		static AssetManager* Instance();
		AssetManager() = default;
		~AssetManager() = default;
		std::map<std::string, neo::Texture*> m_textures;
	};

}