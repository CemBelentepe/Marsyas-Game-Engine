#include "Component.h"

using namespace mge;

Component::Component(GameObject* gameObject)
{
	this->gameObject = gameObject;
}

Component::~Component()
{
}

void Component::update()
{
}
