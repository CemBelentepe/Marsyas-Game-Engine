#include "SpriteRenderer.h"
#include "Resources.h"
#include "Debug.h"

namespace mge
{
	SpriteRenderer::SpriteRenderer(sf::String textureName) : Renderer()
	{
		this->setTexture(textureName);
		this->setAlign(AlignMode::CENTER);
		this->setActive(false);
	}

	SpriteRenderer::SpriteRenderer(sf::String textureName, IntRect textureRect)
	{
		this->setTexture(textureName, textureRect);
		this->setAlign(AlignMode::CENTER);
		this->setActive(false);
	}

	SpriteRenderer::~SpriteRenderer()
	{
		delete sprite;
	}

	void SpriteRenderer::render(sf::RenderWindow& window, Camera& camera)
	{
		if (enabled)
		{
			Vector2f size = ((FloatRect)this->sprite->getGlobalBounds()).getSize();
			this->offset = Vector2f();

			switch (align)
			{
			case AlignMode::TOP_LEFT:
				break;
			case AlignMode::TOP_CENTER:
				this->offset.x -= size.x / 2;
				break;
			case AlignMode::TOP_RIGHT:
				this->offset.x -= size.x;
				break;

			case AlignMode::CENTER_LEFT:
				this->offset.y -= size.y / 2;
				break;
			case AlignMode::CENTER:
				this->offset.y -= size.y / 2;
				this->offset.x -= size.x / 2;
				break;
			case AlignMode::CENTER_RIGHT:
				this->offset.y -= size.y / 2;
				this->offset.x -= size.x;
				break;

			case AlignMode::BOTTOM_LEFT:
				this->offset.y -= size.y;
				break;
			case AlignMode::BOTTOM_CENTER:
				this->offset.y -= size.y;
				this->offset.x -= size.x / 2;
				break;
			case AlignMode::BOTTOM_RIGHT:
				this->offset.x -= size.x;
				this->offset.y -= size.y;
				break;
			}

			this->sprite->setPosition(this->pos + this->offset - camera.pos);
			this->sprite->setScale(this->scale.x, this->scale.y);
			this->sprite->setRotation(this->rotation);

			window.draw(*this->sprite);
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
		sf::Vector2u textureRect = Resources::getTexture(textureName)->getSize();
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

			this->sprite->setPosition(this->pos + this->offset);
			this->sprite->setScale(this->scale);
			this->sprite->setRotation(this->rotation);
		}
		else
			delete this->sprite;
	}
	Vector2f SpriteRenderer::getSize()
	{
		FloatRect rect = sprite->getGlobalBounds();
		return Vector2f(rect.width, rect.height);
	}
	FloatRect SpriteRenderer::getBoundingBox()
	{
		return this->sprite->getGlobalBounds();
	}
}