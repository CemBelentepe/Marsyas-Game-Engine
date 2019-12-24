#include "Scene.h"
#include "GameObject.h"
#include "UIGameObject.h"
#include "Collider.h"
#include "SpriteRenderer.h"
#include <algorithm>

namespace mge
{
	Scene::Scene(const sf::String& name) : name(name), window(nullptr)
	{
	}
	void Scene::load()
	{
		this->start();

		for (auto& layer : layers)
			layer->init();
	}
	void Scene::unload()
	{
		layers.clear();
	}
	void Scene::sceneUpdate()
	{
		for (auto& layer : layers)
			layer->update();
		this->update();
	}
	void Scene::render()
	{
		for (auto& layer : layers)
			layer->render(*window, *mainCam);
	}
	void Scene::addGameObject(GameObject* gameObject, int layerID)
	{
		if (layers.size() > layerID)
			layers[layerID]->pushGameObject(gameObject);
		else
			Debug::logError("Layer with the id could not found!");
	}
	void Scene::destroyGameObject(GameObject* gameObject, int layerID)
	{
		if (layers.size() > layerID)
			layers[layerID]->popGameObject(gameObject);
		else
			Debug::logError("Layer with the id could not found!");
	}
	void Scene::addUIGameObject(UIGameObject* gameObject, int layerID)
	{
		if (layers.size() > layerID)
			layers[layerID]->pushUIGameObject(gameObject);
		else
			Debug::logError("Layer with the id could not found!");
	}
	void Scene::destroyUIGameObject(UIGameObject* gameObject, int layerID)
	{
		if (layers.size() > layerID)
			layers[layerID]->popUIGameObject(gameObject);
		else
			Debug::logError("Layer with the id could not found!");
	}
	void Scene::setWindow(sf::RenderWindow* window)
	{
		this->window = window;
	}
	GameObject* Scene::findGameObject(sf::String name)
	{
		for (auto& layer : layers)
		{
			GameObject* gameObject = layer->findGameObject(name);
			if (gameObject != nullptr)
				return gameObject;
		}
		Debug::logError("Game Object with the name x could not have found.");
		return nullptr;
	}
	std::vector<GameObject*> Scene::findGameObjects(sf::String name)
	{
		std::vector<GameObject*> gameObjects;
		for (auto& layer : layers)
		{
			std::vector<GameObject*> gameObjectsInLayer = layer->findGameObjects(name);
			if (gameObjectsInLayer.size() > 0)
				gameObjects.insert(gameObjects.end(), gameObjectsInLayer.begin(), gameObjectsInLayer.end());
		}
		Debug::logError("No Game Object with the name x could not have found.");
		return gameObjects;
	}
	Layer* Scene::pushLayer(sf::String name)
	{
		Layer* layer = new Layer(name, this);
		layers.push_back(layer);
		return layer;
	}
	void Scene::popLayer(sf::String name)
	{
		size_t pos = -1;
		for (size_t i = 0; i < layers.size(); i++)
		{
			if (layers[i]->name == name) { pos = i; break; }
		}
		for (size_t i = pos; i < layers.size() - 1; i++)
		{
			layers[i] = layers[i + 1];
		}
		layers.pop_back();
	}
	Layer* Scene::getLayer(int layerID)
	{
		if(layers.size() > layerID)
			return layers[layerID];
		else
		{
			Debug::logError("Layer with the id does not exist!");
			return nullptr;
		}
	}
	Layer* Scene::getLayer(sf::String name)
	{
		for (int i = 0; i < layers.size(); i++)
			if (layers[i]->name == name) return layers[i];

		Debug::logError("Layer with the id does not exist!");
		return nullptr;
	}
}