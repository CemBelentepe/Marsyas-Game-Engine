#pragma once
#include "SFML/Graphics.hpp"

namespace mge
{
	class SpriteRenderer
	{
	private:
		sf::String textureName;
		sf::IntRect textureRect;
		bool isActive;

	public:
		sf::Sprite* sprite;

		SpriteRenderer();

		void render(sf::RenderWindow* window);

		void setActive(bool isActive);

		void setTexture(sf::String textureName);
		void setTexture(sf::String textureName, sf::IntRect textureRect);
		void setTexureRect(sf::IntRect textureRect);

		void setPosition(sf::Vector2f pos) { this->sprite->setPosition(pos); }

		void resetSprite();
	};
}

