#pragma once
#include "UIComponent.h"
#include "Math.h"
#include "Renderer.h"
#include "UIGameObject.h"

namespace mge
{
	class Image :public UIComponent
	{
	private:
		Vector2f pos;
		AlignMode align;
		sf::Sprite sprite;
	public:
		Image(UIGameObject* gameObject) : UIComponent(gameObject), pos(gameObject->pos), align(AlignMode::TOP_LEFT), sprite() {}
		//~Image();

		//void update() override;
		void render(sf::RenderWindow* window) override;

		void setTexture(std::string name);
		const sf::Texture* getTexture() { return this->sprite.getTexture(); }

		void setSize(const Vector2f& size);
		const Vector2f& getSize() { return ((FloatRect)sprite.getGlobalBounds()).getSize(); }

		void setAlign(AlignMode align) { this->align = align; }
		AlignMode getAlign(AlignMode align) { return this->align; }
	};
}
