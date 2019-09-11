#include "Text.h"
#include "GameObject.h"

namespace mge
{
	void Text::render(sf::RenderWindow* window)
	{
		Vector2f size = ((FloatRect)this->sfText.getGlobalBounds()).getSize();
		this->renderPos = gameObject->pos;

		switch (align)
		{
		case AlignMode::TOP_LEFT:
			break;
		case AlignMode::TOP_CENTER:
			this->renderPos.x -= size.x / 2;
			break;
		case AlignMode::TOP_RIGHT:
			this->renderPos.x -= size.x;
			break;

		case AlignMode::CENTER_LEFT:
			this->renderPos.y -= size.y / 2;
			break;
		case AlignMode::CENTER:
			this->renderPos.y -= size.y / 2;
			this->renderPos.x -= size.x / 2;
			break;
		case AlignMode::CENTER_RIGHT:
			this->renderPos.y -= size.y / 2;
			this->renderPos.x -= size.x;
			break;

		case AlignMode::BOTTOM_LEFT:
			this->renderPos.y -= size.y;
			break;
		case AlignMode::BOTTOM_CENTER:
			this->renderPos.y -= size.y;
			this->renderPos.x -= size.x / 2;
			break;
		case AlignMode::BOTTOM_RIGHT:
			this->renderPos.x -= size.x;
			this->renderPos.y -= size.y;
			break;
		}

		this->sfText.setPosition(renderPos);
		window->draw(sfText);
	}

	void Text::setText(sf::String text)
	{
		sfText.setString(text);
	}

	void Text::setFontSize(unsigned int fontSize)
	{
		sfText.setCharacterSize(fontSize);
	}

	void Text::setAlign(AlignMode align)
	{
		this->align = align;
	}

	sf::String Text::getText()
	{
		return sfText.getString();
	}

	unsigned int Text::getFontSize()
	{
		return sfText.getCharacterSize();
	}

	AlignMode Text::getAlign()
	{
		return this->align;
	}
}