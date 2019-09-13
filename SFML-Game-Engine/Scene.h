#pragma once
#include <SFML/Graphics.hpp>

namespace mge
{
	class GameObject;
	class UIGameObject;
	class Collider;

	class Scene
	{
	private:
		sf::String name;
		sf::RenderWindow* window;

		//Game Objects
		std::vector<GameObject*> m_GameObjects;
		std::vector<Collider*> m_Colliders;

		std::vector<GameObject*> m_DestroyedObjects;
		std::vector<GameObject*> m_RemovedObjects;

		bool colliderShow;

		// UI Game Objects
		std::vector<UIGameObject*> m_UIGameObjects;

		std::vector<UIGameObject*> m_DestroyedUIObjects;
		std::vector<UIGameObject*> m_RemovedUIObjects;

		// Functions
		void updateGameObjects();
		void updateGUI();
		void updateCollisions();

		void renderGameObjects();
		void renderGUI();

		void m_RemoveGameObject(GameObject* gameObject);
		void m_DestroyGameObject(GameObject* gameObject);

		void m_RemoveUIGameObject(UIGameObject* gameObject);
		void m_DestroyUIGameObject(UIGameObject* gameObject);

		void registerDestroys();
	public:
		Scene(sf::String name);
		//~Scene();

		void load();

		void lateUpdate();
		void update();
		void render();

		void addGameObject(GameObject* gameObject);
		void removeGameObject(GameObject* gameObject);
		void destroyGameObject(GameObject* gameObject);

		void addUIGameObject(UIGameObject* gameObject);
		void removeUIGameObject(UIGameObject* gameObject);
		void destroyUIGameObject(UIGameObject* gameObject);

		void setGameObjects(std::vector<GameObject*> gameObjects);

		void showColliders(bool show);
		void renderColliders();

		void addCollider(Collider* collider);
		void removeCollider(Collider* collider);

		void setWindow(sf::RenderWindow* window);
	};
}
