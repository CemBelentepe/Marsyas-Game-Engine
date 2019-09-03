#include "GameObject.h"
#include "Component.h"
#include "Scene.h"
#include "Collider.h"

using namespace mge;

void GameObject::initVariables()
{
	this->name = "GameObject";
	this->pos = sf::Vector2f(0, 0);
	this->scale = sf::Vector2f(1, 1);
	this->rotation = 0;
}

void GameObject::updateComponents()
{
	// Adds the new components to the all components vector then
	// Starts the components even if they are enabled or not!
	for (auto c : newComponents)
	{
		components.push_back(c);
		c->start();

		Collider* collider = dynamic_cast<Collider*>(c);
		if (collider)
		{
			this->scene->addCollider(collider);
		}
	}
	newComponents.clear();

	// Updates all of the components (newly added too), if they are enabled
	for (auto c : components)
	{
		if (c->isActive())
			c->update();
	}
}

GameObject::GameObject(sf::String name, sf::Vector2f pos)
{
	this->initVariables();
	this->name = name;
	this->renderer.setTexture("default");
	this->renderer.setPosition(pos);
}

mge::GameObject::GameObject(sf::String name, sf::String textureName, sf::Vector2f pos)
{
	this->initVariables();
	this->name = name;
	this->renderer.setTexture(textureName);
	this->pos = pos;
}

mge::GameObject::GameObject(sf::String name, sf::String textureName, sf::IntRect textureRect, sf::Vector2f pos)
{
	this->initVariables();
	this->name = name;
	this->renderer.setTexture(textureName, textureRect);
	this->pos = pos;
}

mge::GameObject::~GameObject()
{
	for (auto comp : components)
	{
		delete comp;
	}

}

void mge::GameObject::init(Scene* scene)
{
	this->scene = scene;
	this->renderer.setActive(true);
}

void GameObject::update()
{
	this->updateComponents();
	this->renderer.setPosition(this->pos);
	this->renderer.setScale(this->scale);
	this->renderer.setRotation(this->rotation);
}

void GameObject::render(sf::RenderWindow* window)
{
	this->renderer.render(window);
}

void mge::GameObject::setActive(bool active)
{
	this->enabled = active;
}
