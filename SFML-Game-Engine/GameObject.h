#pragma once
#include "Debug.h"
#include "Camera.h"
#include "Math.h"
#include <vector>

namespace mge
{
	class Layer;
	class Component;
	class Renderer;

	class GameObject
	{
	private:
		std::vector<Component*> addedComponents;
		std::vector<Component*> removedComponents;
	protected:
		bool enabled = true;

		void initVariables();
		void updateComponents();
	public:
		Renderer* renderer;
		Layer* layer;
		sf::String name;
		Vector2f pos;
		Vector2f scale;
		float rotation;

		std::vector<Component*> components;

		GameObject(const sf::String& name, const Vector2f& pos = Vector2f(0, 0));
		GameObject(const sf::String& name, const sf::String& textureName, const Vector2f& pos = Vector2f(0, 0));
		GameObject(const sf::String& name, const sf::String& textureName, const IntRect& textureRect, const Vector2f& pos = Vector2f(0, 0));
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
				this->addedComponents.push_back(component);
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
			for (auto comp : addedComponents)
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

		virtual void init(Layer* layer);
		virtual void update();
		virtual void render(sf::RenderWindow& window, Camera& camera);

		virtual void setActive(bool active);
		virtual bool isActive() { return this->enabled; }
	};
}
