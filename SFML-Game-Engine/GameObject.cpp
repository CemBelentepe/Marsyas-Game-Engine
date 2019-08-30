#include "GameObject.h"

using namespace mge;

void GameObject::initVariables()
{
	this->sprite = new sf::Sprite();
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

GameObject::GameObject(sf::Texture* texture, sf::Vector2f pos)
{
	this->initVariables();
	this->sprite->setTexture(*texture);
	this->sprite->setPosition(pos);
}

GameObject::GameObject(sf::Texture* texture, sf::Vector2f pos, sf::IntRect textureRect)
{
	this->initVariables();
	this->sprite->setTexture(*texture);
	this->sprite->setPosition(pos);
	this->sprite->setTextureRect(textureRect);
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
	window->draw(*this->sprite);
}
