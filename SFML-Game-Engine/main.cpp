#include "Game.h"
#include <iostream>

int main()
{
	sf::Texture texture;
	texture.loadFromFile("Resources/player.png");

	GameObject gameObject(&texture, sf::Vector2f(0, 0));
	std::vector<GameObject*> gameObjects;
	gameObjects.push_back(&gameObject);

	Scene scene0(gameObjects);
	std::vector<Scene*> scenes;
	scenes.push_back(&scene0);

	Game game("SFML Game Test", 800, 600, scenes, false);
	game.startEngine();
	return 0;
}