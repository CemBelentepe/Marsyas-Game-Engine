#pragma once
#include <SFML/Graphics.hpp>
#include "UIComponent.h"
#include "Math.h"
#include "Renderer.h"

namespace mge
{
	class Text : public UIComponent
	{
	private:
		sf::Text sfText;
		AlignMode align;
		Vector2f renderPos;

	public:
		sf::Font font;

		Text(GameObject* gameObject) 
			:UIComponent(gameObject), align(AlignMode::TOP_LEFT), renderPos(Vector2f(0,0))
		{
			font.loadFromFile("Resources/arial.ttf");
			sfText = sf::Text("", font);
			sfText.setCharacterSize(18);
		}
		Text(GameObject* gameObject, sf::String text) 
			:UIComponent(gameObject), align(AlignMode::TOP_LEFT), renderPos(Vector2f(0, 0))
		{
			font.loadFromFile("Resources/arial.ttf");
			sfText = sf::Text(text, font);
			sfText.setCharacterSize(18);
		}

		void render(sf::RenderWindow* window);

		void setText(sf::String text);
		void setFontSize(unsigned int fontSize);
		void setAlign(AlignMode align);

		sf::String getText();
		unsigned int getFontSize();
		AlignMode getAlign();
	};
}
