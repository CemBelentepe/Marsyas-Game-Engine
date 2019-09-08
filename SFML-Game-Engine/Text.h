#pragma once
#include <SFML/Graphics.hpp>
#include "UIComponent.h"

namespace mge
{
	class Text : public UIComponent
	{
	public:
		sf::Text sfText;
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
	};
}
