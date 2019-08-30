#pragma once
#include "SFML/Graphics.hpp"
#include "Component.h"

namespace mge
{
	class GameObject
	{
	private:
		void initVariables();
		void updateComponents();
	public:
		sf::Sprite* sprite;
		sf::Vector2f pos;
		sf::Vector2f scale;
		float rotation;

		std::vector<Component*> components;

		GameObject(sf::Texture* texture, sf::Vector2f pos);
		GameObject(sf::Texture* texture, sf::Vector2f pos, sf::IntRect textureRect);

		template <class T>
		void addComponenet();

		virtual void update();
		virtual void render(sf::RenderWindow* window);
	};

	template<class T>
	inline void GameObject::addComponenet()
	{
		Component* component = new T(this);
		this->components.push_back(component);
	}
}
