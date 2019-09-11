#pragma once
#include "UIComponent.h"
#include <vector>

namespace mge
{
	class Button : public UIComponent
	{
	private:
		std::vector<void(*)()> clickedEvents;

	public:
		Button(GameObject* gameObject) : UIComponent(gameObject) {}
		~Button();

		void AddOnClickedEvent(void(*onClickedEvent)());

		void update() override;
		void render(sf::RenderWindow* window) override;
	};
}
