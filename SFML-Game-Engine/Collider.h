#pragma once
#include "Component.h"
#include "Math.h"
#include <vector>

namespace mge
{
	class GameObject;

	class Collider :public Component
	{
	public:
		GameObject* gameObject;
		std::vector<GameObject*> lastColliders;
		std::vector<GameObject*> frameColliders;

		Collider(GameObject* gameObject) :Component(gameObject)
		{
			this->gameObject = gameObject;
			this->lastColliders = std::vector<GameObject*>();
			this->frameColliders = std::vector<GameObject*>();
		}

		void colliderUpdate(GameObject* collider);
		void update() override;
		virtual bool intersects(Collider* collider);
	};

	class AABBCollider :public Collider
	{
	public:
		GameObject* gameObject;
		FloatRect boundingBox;
		AABBCollider(GameObject* gameObject);

		void start() override;
		void update() override;
		bool intersects(Collider* collider) override;
	};
}
