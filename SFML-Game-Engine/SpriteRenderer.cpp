#include "SpriteRenderer.h"
#include "Resources.h"

mge::SpriteRenderer::SpriteRenderer()
{
	this->textureName = "default";
	this->textureRect = sf::IntRect();
	this->isActive = false;
}

void mge::SpriteRenderer::render(sf::RenderWindow* window)
{
	window->draw(*this->sprite);
}

void mge::SpriteRenderer::setActive(bool isActive)
{
	this->isActive = isActive;

	if (isActive) this->resetSprite();
	else delete sprite;
}

void mge::SpriteRenderer::setTexture(sf::String textureName)
{
	this->textureName = textureName;
	sf::Vector2u textureRect = mge::Resources::getTexture(textureName).getSize();
	this->textureRect = sf::IntRect(0, 0, textureRect.x, textureRect.y);
}

void mge::SpriteRenderer::setTexture(sf::String textureName, sf::IntRect textureRect)
{
	this->textureName = textureName;
	this->textureRect = textureRect;
}

void mge::SpriteRenderer::setTexureRect(sf::IntRect textureRect)
{
	this->textureRect = textureRect;
}

void mge::SpriteRenderer::resetSprite()
{
	if (isActive)
		this->sprite = Resources::createSpriteFromTexture(this->textureName, this->textureRect);
	else
		delete this->sprite;
}
