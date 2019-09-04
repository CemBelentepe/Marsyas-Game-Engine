#include "Component.h"

namespace mge
{
	Component::Component(GameObject* gameObject)
	{
		this->gameObject = gameObject;
	}

	Component::~Component()
	{
	}

	void mge::Component::start()
	{
	}

	void Component::update()
	{
	}
}