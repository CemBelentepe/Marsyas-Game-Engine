#include "GameObject.h"
#include "Component.h"
#include "Scene.h"

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
	this->renderer.setPosition(this->pos);
	this->renderer.setScale(this->scale);
	this->renderer.setRotation(this->rotation);
	this->updateComponents();
}

void GameObject::render(sf::RenderWindow* window)
{
	this->renderer.render(window);
}