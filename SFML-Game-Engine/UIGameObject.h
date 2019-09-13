#pragma once
#include "GameObject.h"

namespace mge
{
	class UIComponent;

	class UIGameObject : public GameObject
	{
	private:
		std::vector<UIComponent*> newUIComponents;
		std::vector<UIComponent*> UIComponents;

		void updateUIComponents();
	public:
		UIGameObject(sf::String name): GameObject(name){}

		void update() override;
		void render(sf::RenderWindow* window) override;

		template <class T>
		void addUIComponent()
		{
			bool contains = false;
			for (auto comp : UIComponents)
			{
				T* x = dynamic_cast<T*>(comp);
				if (x)
				{
					contains = true;
					break;
				}
			}

			if (!contains)
			{
				UIComponent* component = new T(this);
				this->newUIComponents.push_back(component);
			}
			else
				Debug::logWarning("Gameobject contains the same UI component already.");
		}

		template <class T>
		T* getUIComponent()
		{
			for (auto comp : UIComponents)
			{
				T* component = dynamic_cast<T*>(comp);
				if (component) return component;
			}
			for (auto comp : newUIComponents)
			{
				T* component = dynamic_cast<T*>(comp);
				if (component) return component;
			}
			return nullptr;
		}

	};
}
