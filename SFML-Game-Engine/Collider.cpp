#include "Collider.h"
#include "GameObject.h"
#include "Debug.h"
#include "SpriteRenderer.h"
#include <algorithm>

namespace mge
{
	void Collider::colliderUpdate(GameObject* collider)
	{
		if (collider != nullptr)
			this->frameColliders.push_back(collider);
	}

	void Collider::update()
	{
		for (GameObject* collider : frameColliders)
		{
			for (auto comp : this->gameObject->components)
			{
				comp->onColliderStay(collider);

				if (std::find(lastColliders.begin(), lastColliders.end(), collider) == lastColliders.end())
				{
					comp->onColliderEnter(collider);
				}

			}
		}

		for (GameObject* collider : lastColliders)
		{
			for (auto comp : this->gameObject->components)
			{
				comp->onColliderStay(collider);

				if (std::find(frameColliders.begin(), frameColliders.end(), collider) == frameColliders.end())
				{
					comp->onColliderLeave(collider);
				}

			}
		}

		this->lastColliders.clear();
		for (GameObject* x : frameColliders)
		{
			this->lastColliders.push_back(x);
		}
		this->frameColliders.clear();
	}

	bool Collider::intersects(Collider* collider)
	{
		Debug::logError("Collider is just an interface not an actual collider");
		return false;
	}

	AABBCollider::AABBCollider(GameObject* gameObject) : Collider(gameObject)
	{
		this->gameObject = gameObject;
		this->boundingBox = gameObject->renderer->getBoundingBox();
	}

	void AABBCollider::start()
	{
		this->boundingBox = gameObject->renderer->getBoundingBox();
	}

	void AABBCollider::update()
	{
		Collider::update();
		this->boundingBox = gameObject->renderer->getBoundingBox();
	}

	bool AABBCollider::intersects(Collider* collider)
	{
		// Check type, then do calculations
		AABBCollider* boxCollider = dynamic_cast<AABBCollider*>(collider);
		if (boxCollider)
		{
			return this->boundingBox.intersects(boxCollider->boundingBox);
		}
		else
		{
			Debug::logError("Collider type is unknown.");
			return false;
		}
	}
}