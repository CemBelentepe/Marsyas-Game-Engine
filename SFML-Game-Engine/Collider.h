#pragma once
#include "SFML/Graphics.hpp"
#include "Component.h"

namespace mge
{
	class GameObject;

	class Collider :public Component
	{
	public:
		GameObject* gameObject;
		GameObject* lastCollider;
		Collider(GameObject* gameObject) :Component(gameObject)
		{
			this->gameObject = gameObject;
			this->lastCollider = nullptr;
		}

		void onColliderStay(GameObject* collider) override;
		virtual bool intersects(Collider* collider);
	};

	class BoxCollider :public Collider
	{
	public:
		GameObject* gameObject;
		sf::FloatRect boundingBox;
		BoxCollider(GameObject* gameObject) : Collider(gameObject)
		{
			this->gameObject = gameObject;
		}

		void update() override;
		bool intersects(Collider* collider) override;
	};
}
