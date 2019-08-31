#include "Collider.h"
#include "GameObject.h"

void mge::Collider::onColliderStay(GameObject* collider)
{
	for (auto comp : this->gameObject->components)
	{
		if (!dynamic_cast<Collider*>(comp))
		{
			comp->onColliderStay(collider);
			if (collider != this->lastCollider)
			{
				if (collider != nullptr) comp->onColliderEnter(collider);
				else comp->onColliderLeave(collider);
			}
			this->lastCollider = collider;
		}
	}
}

bool mge::Collider::intersects(Collider* collider)
{
	Debug::logError("Collider is just an interface not an actual collider");
	return false;
}

void mge::BoxCollider::update()
{
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
