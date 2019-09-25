#pragma once
#include "UIComponent.h"
#include "Math.h"
#include "Resources.h"

namespace mge
{
	class Text : public UIComponent
	{
	private:
		sf::Text sfText;
		AlignMode align;
		Vector2f renderPos;
		sf::Font* font;
		sf::Color color;
	public:
		Text(UIGameObject* gameObject) 
			:UIComponent(gameObject), align(AlignMode::TOP_LEFT), renderPos(Vector2f(0,0))
		{
			font = Resources::getFont("arial");
			sfText = sf::Text("", *font);
			sfText.setCharacterSize(18);
			color = sf::Color::White;
		}

		void render(sf::RenderWindow& window);

		void setText(sf::String text);
		void setFont(std::string name);
		void setFontSize(unsigned int fontSize);
		void setAlign(AlignMode align);

		void setColor(const sf::Color& color) { this->color = color; }
		const sf::Color& getColor() { return this->color; }

		sf::String getText();
		unsigned int getFontSize();
		AlignMode getAlign();
	};
}
