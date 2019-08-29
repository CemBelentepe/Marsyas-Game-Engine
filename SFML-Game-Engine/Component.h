#pragma once

class GameObject;

class Component
{
private:
	GameObject* gameObject;
public:
	Component(GameObject* gameObject);
	virtual ~Component();

	void update();
};

