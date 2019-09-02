#include "Collider.h"
#include "GameObject.h"
#include "Debug.h"
#include <algorithm>

void mge::Collider::colliderUpdate(GameObject* collider)
{
	if (collider != nullptr)
		this->frameColliders.push_back(collider);
}

void mge::Collider::update()
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

bool mge::Collider::intersects(Collider* collider)
{
	Debug::logError("Collider is just an interface not an actual collider");
	return false;
}

void mge::BoxCollider::update()
{
	Collider::update();
	boundingBox = this->gameObject->renderer.getGlobalBounds();
}

bool mge::BoxCollider::intersects(Collider* collider)
{
	// Check type, then do calculations
	// Use GPU later
	BoxCollider* boxCollider = dynamic_cast<BoxCollider*>(collider);
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
