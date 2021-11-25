#include "stdafx.h"
#include "../../Includes/Core/AssetManager.h"
#include "../../Includes/Assets/Texture.h"

using namespace neo;

Texture* neo::AssetManager::AddTexture(const std::string& _name)
{
	// The sprite already exist
	if (Instance()->m_textures[_name])
	{
		Instance()->m_textures[_name]->AddUse();
		return Instance()->m_textures[_name];
	}

	// Create a new sprite
	Texture* newTexture = Texture::CreateFromFile(_name);
	if (newTexture) Instance()->m_textures[_name] = newTexture;

	return newTexture;
}

void neo::AssetManager::VerifyUnusedAssets()
{
}

AssetManager* neo::AssetManager::Instance()
{
	static AssetManager assetManager;
	return &assetManager;
}
