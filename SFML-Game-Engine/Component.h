#pragma once

namespace mge
{
	class GameObject;

	class Component
	{
	public:
		GameObject* gameObject;
		Component(GameObject* gameObject);
		virtual ~Component();

		virtual void update();
		virtual void onColliderEnter(GameObject* collider) {}
		virtual void onColliderStay(GameObject* collider) {}
		virtual void onColliderLeave(GameObject* collider) {}
	};
}
