#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Scene.h"

namespace mge
{
	class Game
	{
	private:
		static sf::VideoMode videoMode;
		static sf::RenderWindow window;
		static sf::String title;

		static bool isShowFPS;
		static float lastFPSs[10];
		static int fpsInc;

		static sf::Clock renderClock;
		static sf::Clock updateClock;

		static sf::Time tDeltaTime;
		static float msFrame;

		static std::vector<Scene*> scenes;
		static Scene* activeScene;
		static int activeSceneID;

		static void initScenes(std::vector<Scene*> scenes);

		static void updateEvents();
		static void update();
		static void render();

	public:
		/// <summary>
		/// Time Scale of the update functions.
		/// </summary>
		static float timeScale;
		/// <summary>
		/// Delta Time between last two updates
		/// </summary>
		static float deltaTime;

		Game() {}
		
		/// <summary>
		/// Changes the whole scenes in the game with the param scene.
		/// </summary>
		/// <param name="scenes">New scenes for the Game::scenes</param>
		static void loadScenes(std::vector<Scene*> scenes);
		/// <summary>
		/// Creates *the* window for the game.
		/// </summary>
		/// <param name="title">Title of the window.</param>
		/// <param name="width">With of the window.</param>
		/// <param name="height">Height of the window.</param>
		static void createWindow(const char* title, int width, int height);
		/// <summary>
		/// Creates *the* window for the game as fullscreen.
		/// </summary>
		/// <param name="title">Title of the window.</param>
		static void createWindow(const char* title);
		/// <summary>
		/// Starts the game from the startSceneID = 0
		/// </summary>
		/// <param name="startSceneID">Beginning scene, default 0.</param>
		static void startEngine(int startSceneID = 0);
		/// <summary>
		/// Toggles the fps on the title of the window.
		/// </summary>
		/// <param name="show">Show/don't show.</param>
		static void showFPS(bool show = true);
		/// <summary>
		/// Sets the maximum fps for the game.
		/// </summary>
		/// <param name="fps">Maximum fps.</param>
		static void setFPS(unsigned int fps);
		/// <summary>
		/// Sets V-Sync. Don't use, it's not safe :)
		/// </summary>
		/// <param name="enabled">State.</param>
		static void setVerticalSyncEnabled(bool enabled);

		/// <summary>
		/// Exits the game.
		/// </summary>
		static void exitGame();

		/// <summary>
		/// Adds scene to the game.
		/// </summary>
		/// <param name="scene">Scene to add.</param>
		static void addScene(Scene* scene);
		/// <summary>
		/// Sets the active game scene;
		/// </summary>
		/// <param name="sceneID">ID of the scene</param>
		static void setActiveScene(int sceneID);
		/// <summary>
		/// Sets the active game scene.
		/// </summary>
		/// <param name="name">Name of the scene</param>
		static void setActiveScene(const char* name);
		/// <summary>
		/// Resturns the active scene.
		/// </summary>
		/// <returns>Pointer for the active scene.</returns>
		static Scene* getActiveScene();
	};
}