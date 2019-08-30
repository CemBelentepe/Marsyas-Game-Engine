#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Scene.h"
#include "Input.h"
#include "Debug.h"

namespace mge
{
	class Game
	{
	private:
		static sf::VideoMode videoMode;
		static sf::RenderWindow window;
		static sf::String title;

		static sf::Clock clock;

		static std::vector<Scene*> scenes;
		static Scene* activeScene;
		static int activeSceneID;

		static void initScenes(std::vector<Scene*> scenes);

		static void updateEvents();
		static void update();
		static void render();

	public:
		static sf::Time tDeltaTime;
		static float deltaTime;

		Game() {}
		//virtual ~Game();

		static void loadScenes(std::vector<Scene*> scenes);
		static void createWindow(const char* title, int width, int height, bool fullscreen = false);
		static void startEngine(int startSceneID = 0);

		static void addScene(Scene* scene);
		static void setScene(int sceneID);
		static void setScene(Scene* scene);
	};
}