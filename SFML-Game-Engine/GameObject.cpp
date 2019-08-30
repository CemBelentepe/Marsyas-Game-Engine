#include "GameObject.h"

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
	for (size_t i = 0; i < components.size(); i++)
	{
		components.at(i)->update();
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

void mge::GameObject::init()
{
	this->render.
}

void GameObject::update()
{
	this->sprite->setPosition(this->pos);
	this->sprite->setScale(this->scale);
	this->sprite->setRotation(this->rotation);
	this->updateComponents();
}

void GameObject::render(sf::RenderWindow* window)
{
	this->renderer.render(window);
}

template<class T>
void GameObject::addComponenet()
{
	Component* component = new T(this);
	this->components.push_back(component);
}