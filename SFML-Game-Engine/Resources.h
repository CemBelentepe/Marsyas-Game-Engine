#pragma once
#include "Math.h"
#include <map>
#include <SFML/Audio.hpp>

namespace mge
{
	class Resources
	{
	private:
		static std::map<std::string, sf::Texture*> loadedTextures;
		static std::map<std::string, sf::Font*> loadedFonts;
		static std::map<std::string, sf::SoundBuffer*> loadedSounds;
	public:
		// Texture
		static bool loadTexture(std::string name, std::string path);
		static bool unloadTexture(std::string name);
		static sf::Texture* getTexture(std::string name);
		static sf::Sprite* createSpriteFromTexture(std::string name);
		static sf::Sprite* createSpriteFromTexture(std::string name, IntRect spriteFrame);
		
		//Font
		static bool loadFont(std::string name, std::string path);
		static bool unloadFont(std::string name);
		static sf::Font* getFont(std::string name);

		// Audio
		static bool loadSound(std::string name, std::string path);
		static bool unloadSound(std::string name);
		static sf::SoundBuffer* getSound(std::string name);
	};
}
