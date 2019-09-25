#include "Resources.h"
#include "Debug.h"

namespace mge
{
	std::map<std::string, sf::Texture*>		Resources::loadedTextures;
	std::map<std::string, sf::Font*>		Resources::loadedFonts;
	std::map<std::string, sf::SoundBuffer*>	Resources::loadedSounds;


	bool Resources::loadTexture(std::string name, std::string path)
	{
		if (loadedTextures.count(name) > 0)
		{
			Debug::logWarning("Multiple textures found with the name: " + name + " and path: " + path);
			return false;
		}

		sf::Texture* texture = new sf::Texture();
		if (!texture->loadFromFile(path))
			Debug::logError("Texture with with the name: " + name + " and path: " + path + " could not found.");

		loadedTextures[name] = texture;
		return true;
	}
	bool Resources::unloadTexture(std::string name)
	{
		if (loadedTextures.count(name) > 0)
		{
			delete loadedTextures[name];
			loadedTextures.erase(name);
			return true;
		}
		Debug::logWarning("Texture with with the name: " + name + " could not found.");
		return false;
	}
	sf::Texture* Resources::getTexture(std::string name)
	{
		if (loadedTextures.count(name) > 0)
			return loadedTextures[name];

		Debug::logError("Texture with the name: " + name + " could not found");
		return new sf::Texture();
	}
	sf::Sprite* Resources::createSpriteFromTexture(std::string name)
	{
		if (loadedTextures.count(name) > 0)
			return new sf::Sprite(*loadedTextures[name]);

		Debug::logError("Texture with name: " + name + " could not found for creating sprite.");
		return new sf::Sprite();
	}
	sf::Sprite* Resources::createSpriteFromTexture(std::string name, IntRect spriteFrame)
	{
		if (loadedTextures.count(name) > 0)
			return new sf::Sprite(*loadedTextures[name], spriteFrame);

		Debug::logError("Texture with name: " + name + " could not found for creating sprite.");
		return new sf::Sprite();
	}

	bool Resources::loadFont(std::string name, std::string path)
	{
		if (loadedFonts.count(name) > 0)
		{
			Debug::logWarning("Multiple fonts found with the name: " + name + " and path: " + path);
			return false;
		}

		sf::Font* font = new sf::Font();
		if (!font->loadFromFile(path))
			Debug::logError("Font with with the name: " + name + " and path: " + path + " could not found.");
		
		loadedFonts[name] = font;
		return true;
	}
	bool Resources::unloadFont(std::string name)
	{
		if (loadedFonts.count(name) > 0)
		{
			delete loadedFonts[name];
			loadedFonts.erase(name);
			return true;
		}
		Debug::logWarning("Font with with the name: " + name + " could not found.");
		return false;
	}
	sf::Font* Resources::getFont(std::string name)
	{
		if (loadedFonts.count(name) > 0)
			return loadedFonts[name];

		Debug::logError("Texture with the name: " + name + " could not found");
		return new sf::Font();
	}

	bool Resources::loadSound(std::string name, std::string path)
	{
		if (loadedSounds.count(name) > 0)
		{
			Debug::logWarning("Multiple sounds found with the name: " + name + " and path: " + path);
			return false;
		}

		sf::SoundBuffer* sound = new sf::SoundBuffer();
		if (!sound->loadFromFile(path))
			Debug::logError("Sound with with the name: " + name + " and path: " + path + " could not found.");

		loadedSounds[name] = sound;
		return true;
	}
	bool Resources::unloadSound(std::string name)
	{
		if (loadedSounds.count(name) > 0)
		{
			delete loadedSounds[name];
			loadedSounds.erase(name);
			return true;
		}
		Debug::logWarning("Sound with with the name: " + name + " could not found.");
		return false;
	}
	sf::SoundBuffer* Resources::getSound(std::string name)
	{
		if (loadedSounds.count(name) > 0)
			return loadedSounds[name];

		Debug::logError("Sound with the name: " + name + " could not found");
		return new sf::SoundBuffer();
	}

}