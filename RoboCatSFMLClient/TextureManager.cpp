#include "RoboCatClientPCH.hpp"
//texturemanager? and rerndermanager? for adding a map texture

std::unique_ptr< TextureManager >		TextureManager::sInstance;

void TextureManager::StaticInit()
{
	sInstance.reset(new TextureManager());
}

TextureManager::TextureManager()
{
	//Initial "cat" "mouse" and "yarn" textures that are wizards, books, and fireballs in order
	CacheTexture("cat", "../Assets/cat.png");
	CacheTexture("mouse", "../Assets/mouse.png");
	CacheTexture("yarn", "../Assets/yarn.png");
	//Other textures added later
	CacheTexture("floor", "../Assets/floor.png");
}

TexturePtr	TextureManager::GetTexture(const string& inTextureName)
{
	return mNameToTextureMap[inTextureName];
}

bool TextureManager::CacheTexture(string inTextureName, const char* inFileName)
{
	TexturePtr newTexture(new sf::Texture());
	if (!newTexture->loadFromFile(inFileName))
	{
		return false;
	}

	mNameToTextureMap[inTextureName] = newTexture;

	return true;

}
