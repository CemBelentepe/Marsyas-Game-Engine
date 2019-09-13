#pragma once
#include "UIComponent.h"
#include <vector>
#include "Math.h"
#include "Renderer.h"
#include "UIGameObject.h"

namespace mge
{
	class Button : public UIComponent
	{
	private:
		FloatRect rect;
		AlignMode align;
		std::vector<void(*)()> onClickedEvents;
		std::vector<void(*)()> onHoveredEvents;
	public:

		Button(UIGameObject* gameObject) : UIComponent(gameObject), rect(gameObject->pos, {250, 50}), align(AlignMode::TOP_LEFT) {}
		// ~Button();

		void AddOnClickedEvent(void(*onClickedEvent)());
		void RemoveOnClickedEvent(void(*onClickedEvent)());

		void AddOnHoveredEvent(void(*onHoveredEvent)());
		void RemoveOnHoveredEvent(void(*onHoveredEvent)());

		void update() override;

		void setRect(const FloatRect& rect) { this->rect = rect; }
		FloatRect* getRect() { return &rect; }

		void setSize(const Vector2f& size) { this->rect.setSize(size); }
		const Vector2f& getSize() { return this->rect.getSize(); }

		void setAlign(AlignMode align) { this->align = align; }
		AlignMode getAlign(AlignMode align) { return this->align; }
	};
}
