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
		static float timeScale;
		static float deltaTime;

		Game() {}
		
		static void loadScenes(std::vector<Scene*> scenes);
		static void createWindow(const char* title, int width, int height, bool fullscreen = false);
		static void startEngine(int startSceneID = 0);
		static void showFPS(bool show = true);
		static void setFPS(unsigned int fps);
		static void setVerticalSyncEnabled(bool enabled);

		static void exitGame();

		static void addScene(Scene* scene);
		static void setScene(int sceneID);
		static void setScene(Scene* scene);
		static Scene* getActiveScene();
	};
}