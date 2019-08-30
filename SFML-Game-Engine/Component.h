#pragma once

namespace mge
{
	class GameObject;

	class Component
	{
	protected:
		GameObject* gameObject;
	public:
		Component(GameObject* gameObject);
		virtual ~Component();

		virtual void update();
	};
}
