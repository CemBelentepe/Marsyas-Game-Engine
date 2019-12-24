#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Camera.h"

namespace mge
{
	class GameObject;
	class UIGameObject;
	class Collider;
	class Scene;

	class Layer
	{
	private:
		Scene* parentScene;
		std::vector<GameObject*> m_GameObjects;
		std::vector<UIGameObject*> m_UIGameObjects;
		std::vector<Collider*> m_Colliders;

		std::vector<GameObject*> m_DestroyQueue;
		std::vector<UIGameObject*> m_UIDestroyQueue;

		std::vector<GameObject*> m_AddQueue;
		std::vector<UIGameObject*> m_UIAddQueue;

		void m_DestroyGameObject(GameObject* gameObject);
		void m_DestroyUIGameObject(UIGameObject* gameObject);

		void updateGameObjects();
		void updateCollisions();
		void updateGUI();

		void renderGameObjects(sf::RenderWindow& window, Camera& mainCam);
		void renderGUI(sf::RenderWindow& window, Camera& mainCam);
		
		void registerAdds();
	public:
		sf::String name;
		bool renderEnabled;
		bool updateEnabled;

		Layer(sf::String name, Scene* parentScene);
		Layer(sf::String name, Scene* parentScene, const std::vector<GameObject*>& gameObjects);
		// ~Layer();

		void init();
		void update();
		void render(sf::RenderWindow& window, Camera& mainCam);

		void pushGameObject(GameObject* gameObject);
		void popGameObject(GameObject* gameObject);

		void pushUIGameObject(UIGameObject* gameObject);
		void popUIGameObject(UIGameObject* gameObject);

		void pushCollider(Collider* collider);
		void popCollider(Collider* collider);

		GameObject* findGameObject(sf::String name);
		std::vector<GameObject*> findGameObjects(sf::String name);

		inline Scene* getScene() { return parentScene; };
	};
}
