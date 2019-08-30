#pragma once
#include "SFML/Graphics.hpp"
#include "SpriteRenderer.h"
#include "Collider.h"
#include "Scene.h"
#include "Debug.h"
#include "Component.h"

namespace mge
{

	class GameObject
	{
	private:
		void initVariables();
		void updateComponents();

	public:
		mge::SpriteRenderer renderer;
		mge::Scene* scene;
		sf::String name;
		sf::Vector2f pos;
		sf::Vector2f scale;
		float rotation;

		std::vector<Component*> components;

		GameObject(sf::String name, sf::Vector2f pos = sf::Vector2f(0, 0), Scene* scene = nullptr);
		GameObject(sf::String name, sf::String textureName, sf::Vector2f pos = sf::Vector2f(0, 0), Scene* scene = nullptr);
		GameObject(sf::String name, sf::String textureName, sf::IntRect textureRect, sf::Vector2f pos = sf::Vector2f(0, 0), Scene* scene = nullptr);
		
		template <class T>
		void addComponenet()
		{
			bool contains = false;
			for (auto comp : components)
			{
				T* x = dynamic_cast<T*>(comp);
				if (x)
				{
					contains = true;
					break;
				}
			}

			if (!contains)
			{
				Component* component = new T(this);
				this->components.push_back(component);

				Collider* collider = dynamic_cast<Collider*>(component);
				if (collider)
				{
					this->scene->addCollider(collider);
				}
			}
			else
				Debug::logWarning("Gameobject contains the same component already.");
		}
		
		void init(Scene* scene);
		virtual void update();
		virtual void render(sf::RenderWindow* window);
	};
}
