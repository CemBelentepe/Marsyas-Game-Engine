#pragma once
#include "SFML/Graphics.hpp"

namespace mge
{
	class GameObject;
	class Collider;

	class Scene
	{
	private:
		sf::String name;

		sf::RenderWindow* window;
		std::vector<GameObject*> gameObjects;
		std::vector<Collider*> colliders;

		void updateGameObjects();
		void updateGUI();
		void updateCollisions();

		void renderGameObjects();
		void renderGUI();
	public:
		Scene(sf::String name);
		// ~Scene();

		void load();

		void update();
		void render();

		void addGameObject(GameObject* gameObject);
		void setGameObjects(std::vector<GameObject*> gameObjects);

		void addCollider(Collider* collider);

		void setWindow(sf::RenderWindow* window);
	};
}
