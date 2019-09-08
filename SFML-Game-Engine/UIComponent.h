#pragma once

class sf::RenderWindow;

namespace mge
{
	class GameObject;
	class Renderer;

	class UIComponent
	{
	private:
		bool enabled = true;
	public:
		GameObject* gameObject;
		Renderer* renderer;

		UIComponent(GameObject* gameObject) :gameObject(gameObject)
		{
			this->renderer = nullptr;
		}
		virtual ~UIComponent()
		{
			delete renderer;
		}

		virtual void start() {}
		virtual void update() {}
		virtual void render(sf::RenderWindow* window) {}
		virtual void onColliderEnter(GameObject* collider) {}
		virtual void onColliderStay(GameObject* collider) {}
		virtual void onColliderLeave(GameObject* collider) {}

		virtual bool isActive() { return this->enabled; }
		virtual void setActive(bool active) { this->enabled = active; }
	};
}
