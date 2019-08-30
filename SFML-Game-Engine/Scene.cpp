#include "Scene.h"

using namespace mge;

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

mge::Scene::Scene(sf::String name)
{
	this->name = name;
}

void mge::Scene::load()
{
	for (auto gameObject : gameObjects)
	{
		gameObject->init();
	}
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

void mge::Scene::setGameObjects(std::vector<GameObject*> gameObjects)
{
	this->gameObjects = gameObjects;
}

void Scene::setWindow(sf::RenderWindow* window)
{
	this->window = window;
}
