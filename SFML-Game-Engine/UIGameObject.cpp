#include "UIGameObject.h"
#include "UIComponent.h"

namespace mge
{
	void UIGameObject::updateUIComponents()
	{
		// Adds the new components to the all components vector then
		// Starts the components even if they are enabled or not!
		for (auto c : newUIComponents)
		{
			UIComponents.push_back(c);
		}

		for (auto c : newUIComponents)
		{
			c->start();
		}

		newUIComponents.clear();

		// Updates all of the components (newly added too), if they are enabled
		for (size_t i = 0; i < UIComponents.size(); i++)
		{
			UIComponent*& c = UIComponents.at(i);
			if (c->isActive())
				c->update();
		}
	}
	UIGameObject::~UIGameObject()
	{
		for (auto p : UIComponents)
		{
			delete p;
		}
	}
	void UIGameObject::update()
	{
		this->updateComponents();
		this->updateUIComponents();
	}
	void UIGameObject::render(sf::RenderWindow& window, Camera& camera)
	{
		for (auto uiComp : UIComponents)
		{
			if (uiComp->isActive())
			{
				uiComp->render(window);
			}
		}
	}
}
