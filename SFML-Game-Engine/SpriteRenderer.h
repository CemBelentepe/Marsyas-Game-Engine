#pragma once
#include "SFML/Graphics.hpp"

namespace mge
{
	class SpriteRenderer
	{
	private:
		sf::String textureName;
		sf::IntRect textureRect;

		sf::Vector2f pos;
		sf::Vector2f scale;
		float rotation;

		bool enabled = true;

	public:
		sf::Sprite* sprite;

		SpriteRenderer();
		~SpriteRenderer();

		void render(sf::RenderWindow* window);

		void setActive(bool isActive);
		bool isActive() { return this->enabled; }

		void setTexture(sf::String textureName);
		void setTexture(sf::String textureName, sf::IntRect textureRect);
		void setTexureRect(sf::IntRect textureRect);

		void setPosition(sf::Vector2f pos) { this->pos = pos; }
		void setScale(sf::Vector2f scale) { this->scale = scale; }
		void setRotation(float rotation) { this->rotation = rotation; }

		sf::FloatRect getGlobalBounds();

		void resetSprite();
	};
}

