#include "Resources.h"
#include "Debug.h"

namespace mge
{
	std::map<std::string, sf::Texture*> Resources::loadedTextures;

	bool Resources::loadTexture(std::string name, std::string path)
	{
		if (loadedTextures.count(name) > 0)
		{
			Debug::logWarning("Multiple textures found with the name: " + name + " and path: " + path);
			return false;
		}
		sf::Texture* texture = new sf::Texture;
		if (!texture->loadFromFile(path))
		{
			Debug::logError("Texture with with the name: " + name + " and path: " + path + " could not found.");
		}
		loadedTextures[name] = texture;
		return true;
	}

	bool Resources::unloadTexture(std::string name)
	{
		return loadedTextures.erase(name);
	}

	sf::Texture Resources::getTexture(std::string name)
	{
		if (loadedTextures.count(name) > 0)
			return *loadedTextures[name];

		Debug::logError("Texture with the name: " + name + " could not found");
		return sf::Texture();
	}

	sf::Sprite* Resources::createSpriteFromTexture(std::string name)
	{
		if (loadedTextures.count(name) > 0)
		{
			return new sf::Sprite(*loadedTextures[name]);
		}
		Debug::logError("Texture with name: " + name + " could not found for creating sprite.");
		return new sf::Sprite();
	}

	sf::Sprite* Resources::createSpriteFromTexture(std::string name, IntRect spriteFrame)
	{
		if (loadedTextures.count(name) > 0)
		{
			return new sf::Sprite(*loadedTextures[name], spriteFrame);
		}
		Debug::logError("Texture with name: " + name + " could not found for creating sprite.");
		return new sf::Sprite();
	}
}