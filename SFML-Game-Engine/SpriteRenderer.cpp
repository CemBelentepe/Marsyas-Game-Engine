#include "SpriteRenderer.h"
#include "Resources.h"
#include "Debug.h"

mge::SpriteRenderer::SpriteRenderer()
{
	this->textureName = "default";
	this->textureRect = sf::IntRect();
	this->setActive(false);
}

mge::SpriteRenderer::~SpriteRenderer()
{
	delete sprite;
}

void mge::SpriteRenderer::render(sf::RenderWindow* window)
{
	if (enabled)
	{
		this->sprite->setPosition(this->pos);
		this->sprite->setScale(this->scale);
		this->sprite->setRotation(this->rotation);

		window->draw(*this->sprite);
	}
}

void mge::SpriteRenderer::setActive(bool isActive)
{
	this->enabled = isActive;

	if (isActive) this->resetSprite();
	else delete sprite;
}

void mge::SpriteRenderer::setTexture(sf::String textureName)
{
	this->textureName = textureName;
	sf::Vector2u textureRect = mge::Resources::getTexture(textureName).getSize();
	this->textureRect = sf::IntRect(0, 0, textureRect.x, textureRect.y);
	this->resetSprite();
}

void mge::SpriteRenderer::setTexture(sf::String textureName, sf::IntRect textureRect)
{
	this->textureName = textureName;
	this->textureRect = textureRect;
	this->resetSprite();
}

void mge::SpriteRenderer::setTexureRect(sf::IntRect textureRect)
{
	this->textureRect = textureRect;
	this->resetSprite();
}


sf::FloatRect mge::SpriteRenderer::getGlobalBounds()
{
	if (this->enabled)
		return this->sprite->getGlobalBounds();
	else
	{
		Debug::logWarning("Renderer is inactive.");
		return sf::FloatRect();
	}
}

void mge::SpriteRenderer::resetSprite()
{
	if (enabled)
	{
		this->sprite = Resources::createSpriteFromTexture(this->textureName, this->textureRect);

		this->sprite->setPosition(this->pos);
		this->sprite->setScale(this->scale);
		this->sprite->setRotation(this->rotation);
	}
	else
		delete this->sprite;
}
