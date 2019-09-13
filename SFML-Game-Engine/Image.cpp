#include "Image.h"
#include "Resources.h"

void mge::Image::render(sf::RenderWindow* window)
{
	// Setting position
	Vector2f size = ((FloatRect)sprite.getGlobalBounds()).getSize();
	pos = gameObject->pos;

	switch (align)
	{
	case AlignMode::TOP_LEFT:
		break;
	case AlignMode::TOP_CENTER:
		pos.x -= size.x / 2;
		break;
	case AlignMode::TOP_RIGHT:
		pos.x -= size.x;
		break;

	case AlignMode::CENTER_LEFT:
		pos.y -= size.y / 2;
		break;
	case AlignMode::CENTER:
		pos.y -= size.y / 2;
		pos.x -= size.x / 2;
		break;
	case AlignMode::CENTER_RIGHT:
		pos.y -= size.y / 2;
		pos.x -= size.x;
		break;

	case AlignMode::BOTTOM_LEFT:
		pos.y -= size.y;
		break;
	case AlignMode::BOTTOM_CENTER:
		pos.y -= size.y;
		pos.x -= size.x / 2;
		break;
	case AlignMode::BOTTOM_RIGHT:
		pos.x -= size.x;
		pos.y -= size.y;
		break;
	}

	sprite.setPosition(pos);

	window->draw(sprite);
}

void mge::Image::setTexture(std::string name)
{
	this->sprite = *Resources::createSpriteFromTexture(name);
	const sf::Texture* texture = sprite.getTexture();
	FloatRect bounds = sprite.getGlobalBounds();
	float x = texture->getSize().x / bounds.getSize().x;
	float y = texture->getSize().y / bounds.getSize().y;
	this->sprite.setScale(x, y);
}

void mge::Image::setSize(const Vector2f& size)
{
	FloatRect bounds = sprite.getGlobalBounds();
	float x = size.x / bounds.getSize().x;
	float y = size.y / bounds.getSize().y;
	this->sprite.setScale(x, y);
}
