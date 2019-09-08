#include "Text.h"
#include "GameObject.h"

void mge::Text::update()
{
	sfText.setPosition(gameObject->pos);
}

void mge::Text::render(sf::RenderWindow* window)
{
	window->draw(sfText);
}
