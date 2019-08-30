#include "Scene.h"
#include "GameObject.h"

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

void mge::Scene::updateCollisions()
{
	for (auto collider : this->colliders)
	{
		if (collider->gameObject->renderer.isActive())
			for (auto collision : this->colliders)
			{
				if (collision->gameObject->renderer.isActive() && collider != collision)
				{
					if (collider->intersects(collision))
						collider->onColliderStay(collision->gameObject);
					else
						collider->onColliderStay(nullptr);
				}
			}
	}
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
	this->colliders = std::vector<Collider*>();
}

void mge::Scene::load()
{
	for (auto gameObject : gameObjects)
	{
		gameObject->init(this);
	}
}

void Scene::update()
{
	this->updateGameObjects();
	this->updateCollisions();
	this->updateGUI();
}

void Scene::render()
{
	this->renderGameObjects();
	this->renderGUI();
}

void Scene::addGameObject(GameObject* gameObject)
{
	gameObject->scene = this;
	this->gameObjects.push_back(gameObject);
}

void mge::Scene::setGameObjects(std::vector<GameObject*> gameObjects)
{
	this->gameObjects = gameObjects;
}

void mge::Scene::addCollider(Collider* collider)
{
	this->colliders.push_back(collider);
}

void Scene::setWindow(sf::RenderWindow* window)
{
	this->window = window;
}
