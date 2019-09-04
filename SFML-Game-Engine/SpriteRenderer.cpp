#include "SpriteRenderer.h"
#include "Resources.h"
#include "Debug.h"

namespace mge
{
	SpriteRenderer::SpriteRenderer()
	{
		this->textureName = "default";
		this->textureRect = IntRect();
		this->setActive(false);
	}

	SpriteRenderer::~SpriteRenderer()
	{
		delete sprite;
	}

	void SpriteRenderer::render(sf::RenderWindow* window)
	{
		if (enabled)
		{
			this->sprite->setPosition(this->pos);
			this->sprite->setScale(this->scale);
			this->sprite->setRotation(this->rotation);

			window->draw(*this->sprite);
		}
	}

	void SpriteRenderer::setActive(bool isActive)
	{
		this->enabled = isActive;

		if (isActive) this->resetSprite();
		else delete sprite;
	}

	void SpriteRenderer::setTexture(sf::String textureName)
	{
		this->textureName = textureName;
		sf::Vector2u textureRect = Resources::getTexture(textureName).getSize();
		this->textureRect = IntRect(0, 0, textureRect.x, textureRect.y);
		this->resetSprite();
	}

	void SpriteRenderer::setTexture(sf::String textureName, IntRect textureRect)
	{
		this->textureName = textureName;
		this->textureRect = textureRect;
		this->resetSprite();
	}

	void SpriteRenderer::setTexureRect(IntRect textureRect)
	{
		this->textureRect = textureRect;
		this->resetSprite();
	}


	sf::FloatRect SpriteRenderer::getGlobalBounds()
	{
		if (this->enabled)
			return this->sprite->getGlobalBounds();
		else
		{
			Debug::logWarning("Renderer is inactive.");
			return sf::FloatRect();
		}
	}

	void SpriteRenderer::resetSprite()
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
}