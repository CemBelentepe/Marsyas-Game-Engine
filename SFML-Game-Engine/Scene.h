#pragma once
#include "GameObject.h"

namespace mge
{
	class Scene
	{
	private:
		sf::String name;

		sf::RenderWindow* window;
		std::vector<GameObject*> gameObjects;

		void updateGameObjects();
		void updateGUI();

		void renderGameObjects();
		void renderGUI();
	public:
		Scene(sf::String name);
		//Scene(std::vector<GameObject*> gameObjects);
		// ~Scene();

		void load();

		void update();
		void render();

		void addGameObject(GameObject* gameObject);
		void setGameObjects(std::vector<GameObject*> gameObjects);

		void setWindow(sf::RenderWindow* window);
	};
}
