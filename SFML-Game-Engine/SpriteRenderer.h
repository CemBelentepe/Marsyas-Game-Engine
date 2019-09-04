#pragma once
#include "SFML/Graphics.hpp"
#include "Math.h"

namespace mge
{
	class SpriteRenderer
	{
	private:
		sf::String textureName;
		IntRect textureRect;

		Vector2f pos;
		Vector2f scale;
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
		void setTexture(sf::String textureName, IntRect textureRect);
		void setTexureRect(IntRect textureRect);

		void setPosition(Vector2f pos) { this->pos = pos; }
		void setScale(Vector2f scale) { this->scale = scale; }
		void setRotation(float rotation) { this->rotation = rotation; }

		sf::FloatRect getGlobalBounds();

		void resetSprite();
	};
}

