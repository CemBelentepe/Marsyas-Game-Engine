#pragma once
#include "UIComponent.h"
#include <vector>
#include "Math.h"
#include "UIGameObject.h"

namespace mge
{
	class Button : public UIComponent
	{
	private:
		FloatRect rect;
		AlignMode align;
		std::vector<void(*)(GameObject*)> onClickedEvents;
		std::vector<void(*)(GameObject*)> onHoveredEvents;
	public:

		Button(UIGameObject* gameObject) : UIComponent(gameObject), rect(gameObject->pos, {250, 50}), align(AlignMode::TOP_LEFT) {}
		// ~Button();

		void AddOnClickedEvent(void(*onClickedEvent)(GameObject*));
		void RemoveOnClickedEvent(void(*onClickedEvent)(GameObject*));

		void AddOnHoveredEvent(void(*onHoveredEvent)(GameObject*));
		void RemoveOnHoveredEvent(void(*onHoveredEvent)(GameObject*));

		void update() override;

		void setRect(const FloatRect& rect) { this->rect = rect; }
		FloatRect* getRect() { return &rect; }

		void setSize(const Vector2f& size) { this->rect.setSize(size); }
		const Vector2f& getSize() { return this->rect.getSize(); }

		void setAlign(AlignMode align) { this->align = align; }
		AlignMode getAlign(AlignMode align) { return this->align; }
	};
}
