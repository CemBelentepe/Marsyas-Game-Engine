#pragma once
#include "Debug.h"
#include "Math.h"
#include <vector>

namespace mge
{
	class Scene;
	class Component;
	class Renderer;

	class GameObject
	{
	private:
		std::vector<Component*> newComponents;
		std::vector<Component*> removedComponents;
	protected:
		bool enabled = true;

		void initVariables();
		void updateComponents();
	public:
		Renderer* renderer;
		Scene* scene;
		sf::String name;
		Vector2f pos;
		Vector2f scale;
		float rotation;

		std::vector<Component*> components;

		GameObject(sf::String name, Vector2f pos = Vector2f(0, 0));
		GameObject(sf::String name, sf::String textureName, Vector2f pos = Vector2f(0, 0));
		GameObject(sf::String name, sf::String textureName, IntRect textureRect, Vector2f pos = Vector2f(0, 0));
		virtual ~GameObject();

		template <class T>
		void addComponent()
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
				this->newComponents.push_back(component);
			}
			else
				Debug::logWarning("Gameobject contains the same component already.");
		}

		template <class T>
		T* getComponent()
		{
			for (auto comp : components)
			{
				T* component = dynamic_cast<T*>(comp);
				if (component) return component;
			}
			for (auto comp : newComponents)
			{
				T* component = dynamic_cast<T*>(comp);
				if (component) return component;
			}
			return nullptr;
		}

		template <class T>
		bool removeComponent()
		{
			for (auto comp : components)
			{
				T* x = static_cast<T*>(comp);
				if (x)
				{
					removedComponents.push_back(x);
					return true;
				}
			}

			return false;
		}

		virtual void init(Scene* scene);
		virtual void update();
		virtual void render(sf::RenderWindow* window);

		virtual void setActive(bool active);
		virtual bool isActive() { return this->enabled; }
	};
}
