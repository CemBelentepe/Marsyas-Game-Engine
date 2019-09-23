#pragma once
#include <SFML/Graphics.hpp>
#include "Camera.h"

namespace mge
{
	class GameObject;
	class UIGameObject;
	class Collider;

	class Scene
	{
	public:
		sf::String name;
		Camera*	mainCam;
	private:
		sf::RenderWindow* window;

		//Game Objects
		std::vector<GameObject*> m_GameObjects;
		std::vector<Collider*> m_Colliders;

		std::vector<GameObject*> m_DestroyedObjects;
		std::vector<GameObject*> m_RemovedObjects;

		std::vector<GameObject*> m_AddedGameObjects;

		bool colliderShow;

		// UI Game Objects
		std::vector<UIGameObject*> m_UIGameObjects;

		std::vector<UIGameObject*> m_DestroyedUIObjects;
		std::vector<UIGameObject*> m_RemovedUIObjects;

		std::vector<UIGameObject*> m_AddedUIObjects;

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
		void registerAdds();
	public:
		Scene(const sf::String& name);
		//~Scene();

		/// <summary>
		/// Loads the scene.
		/// </summary>
		void load();
		/// <summary>
		/// Removes the scene from the active scene slot.
		/// </summary>
		void unload();

		/// <summary>
		/// Updates everything in the scene, then calls the abstract update function of the scene.
		/// </summary>
		void sceneUpdate();
		/// <summary>
		/// Renders all the Game Object in the scene.
		/// </summary>
		void render();

		/// <summary>
		/// Called in the start of the Scene.
		/// </summary>
		virtual void start() = 0;
		/// <summary>
		/// Calls after all the updates done.
		/// </summary>
		virtual void update() = 0;

		/// <summary>
		/// Adds a game object to the scene. Game Object registers at the start of the next update.
		/// </summary>
		/// <param name="gameObject">Pointer of the game object to add.</param>
		void addGameObject(GameObject* gameObject);
		/// <summary>
		/// Removes the game object from the scene, doesn't destroys the object. Game Object registers at the start of the next update. Use with a shared pointer maybe, not sure, sorry.
		/// </summary>
		/// <param name="gameObject">Pointer of the game object to remove.</param>
		void removeGameObject(GameObject* gameObject);
		/// <summary>
		/// Removes the game object from the scene, destroys the object. Game Object registers at the start of the next update.
		/// </summary>
		/// <param name="gameObject">Pointer of the game object to remove.</param>
		void destroyGameObject(GameObject* gameObject);

		/// <summary>
		/// Adds a ui game object to the scene. Game Object registers at the start of the next update.
		/// </summary>
		/// <param name="gameObject">Pointer of the game object to add.</param>
		void addUIGameObject(UIGameObject* gameObject);
		/// <summary>
		/// Removes the ui game object from the scene, doesn't destroys the object. Game Object registers at the start of the next update. Use with a shared pointer maybe, not sure, sorry.
		/// </summary>
		/// <param name="gameObject">Pointer of the game object to remove.</param>
		void removeUIGameObject(UIGameObject* gameObject);
		/// <summary>
		/// Removes the ui game object from the scene, destroys the object. Game Object registers at the start of the next update.
		/// </summary>
		/// <param name="gameObject">Pointer of the game object to remove.</param>
		void destroyUIGameObject(UIGameObject* gameObject);

		/// <summary>
		/// Sets the game objects of the scene. Removes the old ones on the go. Not safe while in a update.
		/// </summary>
		/// <param name="gameObjects"></param>
		void setGameObjects(std::vector<GameObject*> gameObjects);

		/// <summary>
		/// Shows the colliders in the game.
		/// </summary>
		/// <param name="show">Show/Hide</param>
		void showColliders(bool show);

		/// <summary>
		/// Renders the colliders.
		/// </summary>
		void renderColliders();

		/// <summary>
		/// Adds a collider component to the scene.
		/// </summary>
		/// <param name="collider">Pointer to the collider.</param>
		void addCollider(Collider* collider);
		/// <summary>
		/// Removes a collider from the scene.
		/// </summary>
		/// <param name="collider">Pointer to the collider.</param>
		void removeCollider(Collider* collider);

		/// <summary>
		/// Sets the window of the scene.
		/// </summary>
		/// <param name="window">Pointer to the window.</param>
		void setWindow(sf::RenderWindow* window);

		/// <summary>
		/// Find a game object in the scene by name.
		/// </summary>
		/// <param name="name">Name of the game object.</param>
		/// <returns>Game Object with the name.</returns>
		GameObject* findGameObject(sf::String name);
		/// <summary>
		/// Finds all of the game objects in the scene by name.
		/// </summary>
		/// <param name="name">Name of the game objects.</param>
		/// <returns>A Vector containing the game objects with the name</returns>
		std::vector<GameObject*> findGameObjects(sf::String name);
	};
}
