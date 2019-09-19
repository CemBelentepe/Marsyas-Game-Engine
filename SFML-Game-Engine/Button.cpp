#include "Button.h"
#include "Debug.h"
#include "Input.h"
#include <algorithm>

void mge::Button::AddOnClickedEvent(void(*onClickedEvent)(GameObject*))
{
	if (std::find(onClickedEvents.begin(), onClickedEvents.end(), onClickedEvent) == onClickedEvents.end())
		onClickedEvents.push_back(onClickedEvent);
	else
		Debug::logWarning("Button has the same function already");
}
void mge::Button::RemoveOnClickedEvent(void(*onClickedEvent)(GameObject*))
{
	onClickedEvents.erase(std::remove(onClickedEvents.begin(), onClickedEvents.end(), onClickedEvent), onClickedEvents.end());
}
void mge::Button::AddOnHoveredEvent(void(*onHoveredEvent)(GameObject*))
{
	if (std::find(onHoveredEvents.begin(), onHoveredEvents.end(), onHoveredEvent) == onHoveredEvents.end())
		onHoveredEvents.push_back(onHoveredEvent);
	else
		Debug::logWarning("Button has the same function already");
}
void mge::Button::RemoveOnHoveredEvent(void(*onHoveredEvent)(GameObject*))
{
	onHoveredEvents.erase(std::remove(onHoveredEvents.begin(), onHoveredEvents.end(), onHoveredEvent), onHoveredEvents.end());
}

void mge::Button::update()
{
	// Setting position
	Vector2f pos = gameObject->pos;
	switch (align)
	{
	case AlignMode::TOP_LEFT:
		break;
	case AlignMode::TOP_CENTER:
		pos.x -= rect.getSize().x / 2;
		break;
	case AlignMode::TOP_RIGHT:
		pos.x -= rect.getSize().x;
		break;

	case AlignMode::CENTER_LEFT:
		pos.y -= rect.getSize().y / 2;
		break;
	case AlignMode::CENTER:
		pos.y -= rect.getSize().y / 2;
		pos.x -= rect.getSize().x / 2;
		break;
	case AlignMode::CENTER_RIGHT:
		pos.y -= rect.getSize().y / 2;
		pos.x -= rect.getSize().x;
		break;

	case AlignMode::BOTTOM_LEFT:
		pos.y -= rect.getSize().y;
		break;
	case AlignMode::BOTTOM_CENTER:
		pos.y -= rect.getSize().y;
		pos.x -= rect.getSize().x / 2;
		break;
	case AlignMode::BOTTOM_RIGHT:
		pos.x -= rect.getSize().x;
		pos.y -= rect.getSize().y;
		break;
	}
	rect.setPosition(pos);

	// Function calls
	if (rect.contains(Input::getMousePosition()))
	{
		// Hover
		for (auto func : onHoveredEvents)
			func(this->gameObject);

		// Click
		if (Input::getMouseButtonDown(Input::MouseButton::MouseLeft))
			for (auto func : onClickedEvents)
				func(this->gameObject);
	}
}
