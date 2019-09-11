#pragma once
#include <SFML/Graphics.hpp>
#include "UIComponent.h"

namespace mge
{
	class Text : public UIComponent
	{
	private:
	public:
		sf::Text sfText;
		enum AlignMode
		{
			TOP_LEFT, TOP_CENTER, TOP_RIGHT,
			CENTER_LEFT, CENTER, CENTER_RIGHT,
			BOTTOM_LEFT, BOTTOM_CENTER, BOTTOM_RIGHT
		};

		sf::Font font;

		Text(GameObject* gameObject) :UIComponent(gameObject)
		{
			font.loadFromFile("Resources/arial.ttf");
			sfText = sf::Text("", font);
			sfText.setCharacterSize(18);
		}
		Text(GameObject* gameObject, sf::String text) : UIComponent(gameObject)
		{
			font.loadFromFile("Resources/arial.ttf");
			sfText = sf::Text(text, font);
			sfText.setCharacterSize(18);
		}

		void update();
		void render(sf::RenderWindow* window);

		void setText(sf::String text);
		void setAlign(AlignMode align);
		void setFontSize(unsigned int fontSize);

		sf::String getText();
		AlignMode getAlign();
		unsigned int getFontSize();
	};
}
