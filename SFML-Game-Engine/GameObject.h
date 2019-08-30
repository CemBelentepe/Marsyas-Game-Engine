#pragma once
#include "SFML/Graphics.hpp"
#include "Component.h"
#include "Resources.h"
#include "SpriteRenderer.h"

namespace mge
{
	class GameObject
	{
	private:
		mge::SpriteRenderer renderer;

		void initVariables();
		void updateComponents();

	public:
		sf::String name;
		sf::Vector2f pos;
		sf::Vector2f scale;
		float rotation;

		std::vector<Component*> components;

		GameObject(sf::String name, sf::Vector2f pos = sf::Vector2f(0, 0));
		GameObject(sf::String name, sf::String textureName, sf::Vector2f pos = sf::Vector2f(0, 0));
		GameObject(sf::String name, sf::String textureName, sf::IntRect textureRect, sf::Vector2f pos = sf::Vector2f(0, 0));
		
		template <class T>
		void addComponenet();
		
		void init();
		virtual void update();
		virtual void render(sf::RenderWindow* window);
	};
}
