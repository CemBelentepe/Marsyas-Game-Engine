#pragma once
#include <SFML/Graphics.hpp>

namespace mge
{
	class UIGameObject;
	class Renderer;

	class UIComponent
	{
	private:
		bool enabled = true;
	public:
		UIGameObject* gameObject;
		Renderer* renderer;

		UIComponent(UIGameObject* gameObject) :gameObject(gameObject)
		{
			this->renderer = nullptr;
		}
		virtual ~UIComponent()
		{
			delete renderer;
		}

		virtual void start() {}
		virtual void update() {}
		virtual void render(sf::RenderWindow& window) {}
		virtual void onColliderEnter(UIGameObject& collider) {}
		virtual void onColliderStay(UIGameObject& collider) {}
		virtual void onColliderLeave(UIGameObject& collider) {}

		virtual bool isActive() { return this->enabled; }
		virtual void setActive(bool active) { this->enabled = active; }
	};
}
