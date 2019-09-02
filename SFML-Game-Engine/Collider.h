#pragma once
#include <vector>
#include "SFML/Graphics.hpp"
#include "Component.h"

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
