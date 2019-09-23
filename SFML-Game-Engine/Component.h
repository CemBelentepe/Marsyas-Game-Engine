#pragma once

namespace mge
{
	class GameObject;

	class Component
	{
	private:
		bool enabled = true;
	public:
		GameObject* gameObject;
		Component(GameObject* gameObject):gameObject(gameObject){}
		virtual ~Component() {}

		virtual void start() {}
		virtual void update() {}
		virtual void onColliderEnter(GameObject& collider) {}
		virtual void onColliderStay(GameObject& collider) {}
		virtual void onColliderLeave(GameObject& collider){}

		virtual bool isActive() { return this->enabled; }
		virtual void setActive(bool active) { this->enabled = active; }
	};
}
