#pragma once
#include "GameObject.h"

namespace mge
{
	class Scene
	{
	private:
		sf::RenderWindow* window;
		std::vector<GameObject*> gameObjects;

		void updateGameObjects();
		void updateGUI();

		void renderGameObjects();
		void renderGUI();
	public:
		Scene(std::vector<GameObject*> gameObjects);
		// ~Scene();

		void update();
		void render();
		void addGameObject(GameObject* gameObject);

		void setWindow(sf::RenderWindow* window);
	};
}
