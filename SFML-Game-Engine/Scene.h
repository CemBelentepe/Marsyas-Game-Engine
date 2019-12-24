#pragma once
#include <SFML/Graphics.hpp>
#include "Camera.h"
#include "Layer.h"

namespace mge
{
	class GameObject;
	class UIGameObject;
	class Collider;

	class Scene
	{
	public:
		sf::String name;
		Camera* mainCam;
	private:
		sf::RenderWindow* window;

		// Layers
		std::vector<Layer*> layers;

	public:
		Scene(const sf::String& name);
		// ~Scene();

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
		void addGameObject(GameObject* gameObject, int layerID = 0);
		/// <summary>
		/// Removes the game object from the scene, destroys the object. Game Object registers at the start of the next update.
		/// </summary>
		/// <param name="gameObject">Pointer of the game object to remove.</param>
		void destroyGameObject(GameObject* gameObject, int layerID = 0);

		/// <summary>
		/// Adds a ui game object to the scene. Game Object registers at the start of the next update.
		/// </summary>
		/// <param name="gameObject">Pointer of the game object to add.</param>
		void addUIGameObject(UIGameObject* gameObject, int layerID = 0);
		/// <summary>
		/// Removes the ui game object from the scene, destroys the object. Game Object registers at the start of the next update.
		/// </summary>
		/// <param name="gameObject">Pointer of the game object to remove.</param>
		void destroyUIGameObject(UIGameObject* gameObject, int layerID = 0);

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

		Layer* pushLayer(sf::String name);
		void popLayer(sf::String name);
		Layer* getLayer(int layerID);
		Layer* getLayer(sf::String name);
	};
}
