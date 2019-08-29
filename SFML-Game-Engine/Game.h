#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Scene.h"
#include "Input.h"

class Game
{
private:
	sf::VideoMode videoMode;
	sf::RenderWindow window;
	sf::String title;

	Input* input = nullptr;

	std::vector<Scene*> scenes;
	Scene* activeScene;
	int activeSceneID;

	void initScenes(std::vector<Scene*> scenes);

	void updateEvents();
	void update();
	void render();

public:
	Game(const char* title, int width, int height, std::vector<Scene*> scenes, bool fullscreen = false);
	//virtual ~Game();

	void createWindow(const char* title, int width, int height, bool fullscreen = false);
	void startEngine(int startSceneID = 0);
	
	void addScene(Scene* scene);
	void setScene(int sceneID);
};
