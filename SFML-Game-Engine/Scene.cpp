#include "Scene.h"
#include "GameObject.h"
#include "Collider.h"

using namespace mge;

void Scene::updateGameObjects()
{
	// TODO: optimize
	for (size_t i = 0; i < gameObjects.size(); i++)
	{
		GameObject* gameObject = gameObjects.at(i);
		if (gameObject->isActive())
			gameObject->update();
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
		if (collider->gameObject->isActive() && collider->isActive())
			for (auto collision : this->colliders)
			{
				if (collision->gameObject->renderer.isActive() && collider != collision)
				{
					if (collider->intersects(collision))
						collider->colliderUpdate(collision->gameObject);
					else
						collider->colliderUpdate(nullptr);
				}
			}
	}
}

void Scene::renderGameObjects()
{
	// TODO: optimize
	for (auto gameObject : gameObjects)
	{
		if (gameObject->isActive())
			gameObject->render(window);
	}
}

void Scene::renderGUI()
{
	// TODO: implement later
}

void mge::Scene::registerDestroys()
{
	for (auto obj : destroyedObjects)
	{
		privDestroyGameObject(obj);
	}
	for (auto obj : removedObjects)
	{
		privRemoveGameObject(obj);
	}
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

void mge::Scene::lateUpdate()
{
	this->registerDestroys();
	this->removedObjects.clear();
	this->destroyedObjects.clear();
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
	gameObject->renderer.setActive(true);
	this->gameObjects.push_back(gameObject);
}

void mge::Scene::removeGameObject(GameObject* gameObject)
{
	if (std::find(removedObjects.begin(), removedObjects.end(), gameObject) == removedObjects.end() &&
		std::find(destroyedObjects.begin(), destroyedObjects.end(), gameObject) == destroyedObjects.end())
		this->removedObjects.push_back(gameObject);
}

void mge::Scene::destroyGameObject(GameObject* gameObject)
{
	if (std::find(removedObjects.begin(), removedObjects.end(), gameObject) == removedObjects.end() &&
		std::find(destroyedObjects.begin(), destroyedObjects.end(), gameObject) == destroyedObjects.end())
		this->destroyedObjects.push_back(gameObject);
}

void mge::Scene::privRemoveGameObject(GameObject* gameObject)
{
	for (int i = colliders.size() - 1; i >= 0; i--)
	{
		Collider* collider = colliders.at(i);
		if (collider->gameObject == gameObject)
		{
			colliders.erase(colliders.begin() + i);
		}
	}

	for (int i = gameObjects.size() - 1; i >= 0; i--)
	{
		if (gameObjects.at(i) == gameObject)
		{
			gameObjects.erase(gameObjects.begin() + i);
		}
	}
}

void mge::Scene::privDestroyGameObject(GameObject* gameObject)
{
	this->privRemoveGameObject(gameObject);
	delete gameObject;
}

void mge::Scene::setGameObjects(std::vector<GameObject*> gameObjects)
{
	this->gameObjects = gameObjects;
	for (auto gameObject : gameObjects)
	{
		gameObject->scene = this;
	}
}

void mge::Scene::addCollider(Collider* collider)
{
	this->colliders.push_back(collider);
}

void Scene::setWindow(sf::RenderWindow* window)
{
	this->window = window;
}
