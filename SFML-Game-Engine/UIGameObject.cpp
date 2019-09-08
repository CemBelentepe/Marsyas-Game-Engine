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
		for (auto c : UIComponents)
		{
			if (c->isActive())
				c->update();
		}
	}
	void UIGameObject::update()
	{
		this->updateComponents();
		this->updateUIComponents();
	}
	void UIGameObject::render(sf::RenderWindow* window)
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
