#pragma once
#include "SFML/Graphics.hpp"
#include "Renderer.h"
#include "Math.h"

namespace mge
{
	class SpriteRenderer : public Renderer
	{
	private:
		sf::String textureName;
		IntRect textureRect;

	public:
		sf::Sprite* sprite;

		SpriteRenderer(sf::String textureName);
		SpriteRenderer(sf::String textureName, IntRect textureRect);
		~SpriteRenderer();

		void render(sf::RenderWindow* window) override;

		void setActive(bool isActive) override;

		void setTexture(sf::String textureName);
		void setTexture(sf::String textureName, IntRect textureRect);
		void setTexureRect(IntRect textureRect);

		sf::FloatRect getGlobalBounds();

		void resetSprite();

		Vector2f getSize() override;
		FloatRect getBoundingBox() override;
	};
}

