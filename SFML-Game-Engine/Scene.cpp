#include "Scene.h"

void Scene::updateGameObjects()
{
	// TODO: optimize
	for (size_t i = 0; i < gameObjects.size(); i++)
	{
		gameObjects.at(i)->update();
	}
}

void Scene::updateGUI()
{
	// TODO: implement later
}

void Scene::renderGameObjects()
{
	// TODO: optimize
	for (size_t i = 0; i < gameObjects.size(); i++)
	{
		gameObjects.at(i)->render(window);
	}
}

void Scene::renderGUI()
{
	// TODO: implement later
}

Scene::Scene(std::vector<GameObject*> gameObjects)
{
	this->gameObjects = gameObjects;
}

void Scene::update()
{
	this->updateGameObjects();
	this->updateGUI();
}

void Scene::render()
{
	this->renderGameObjects();
	this->renderGUI();
}

void Scene::addGameObject(GameObject* gameObject)
{
	this->gameObjects.push_back(gameObject);
}

void Scene::setWindow(sf::RenderWindow* window)
{
	this->window = window;
}
