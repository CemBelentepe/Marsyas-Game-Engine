#include "Layer.h"
#include "Scene.h"
#include "GameObject.h"
#include "UIGameObject.h"
#include "Collider.h"
#include "SpriteRenderer.h"

namespace mge
{
	Layer::Layer(sf::String name, Scene* parentScene) :parentScene(parentScene), name(name), renderEnabled(true), updateEnabled(true)
	{
	}
	Layer::Layer(sf::String name, Scene* parentScene, const std::vector<GameObject*>& gameObjects) : parentScene(parentScene), name(name), renderEnabled(true), updateEnabled(true)
	{
		for (int i = 0; i < gameObjects.size(); i++)
			m_GameObjects.push_back(gameObjects[i]);
	}
	void Layer::m_DestroyGameObject(GameObject* gameObject)
	{
		for (int i = m_Colliders.size() - 1; i >= 0; i--)
		{
			Collider* collider = m_Colliders.at(i);
			if (collider->gameObject == gameObject)
			{
				m_Colliders.erase(m_Colliders.begin() + i);
			}
		}

		for (int i = m_GameObjects.size() - 1; i >= 0; i--)
		{
			if (m_GameObjects.at(i) == gameObject)
			{
				m_GameObjects.erase(m_GameObjects.begin() + i);
			}
		}
		delete gameObject;
	}
	void Layer::m_DestroyUIGameObject(UIGameObject* gameObject)
	{
		for (int i = m_UIGameObjects.size() - 1; i >= 0; i--)
		{
			if (m_UIGameObjects.at(i) == gameObject)
			{
				m_UIGameObjects.erase(m_UIGameObjects.begin() + i);
			}
		}
		delete gameObject;
	}
	void Layer::updateGameObjects()
	{
		// TODO: Check for duplicate
		this->registerAdds();
		// Update Objects
		for (auto& gameObject : m_GameObjects)
		{
			if (gameObject->isActive())
				gameObject->update();
		}
	}
	void Layer::updateCollisions()
	{
		for (auto& collider : this->m_Colliders)
		{
			if (collider->gameObject->isActive() && collider->isActive())
				for (auto& collision : this->m_Colliders)
				{
					if (collision->gameObject->renderer->isActive() && collider != collision)
					{
						if (collider->intersects(collision))
							collider->colliderUpdate(collision->gameObject);
						else
							collider->colliderUpdate(nullptr);
					}
				}
		}
	}
	void Layer::updateGUI()
	{
		for (auto obj : m_UIGameObjects)
		{
			if (obj->isActive())
				obj->update();
		}
	}
	void Layer::renderGameObjects(sf::RenderWindow& window, Camera& mainCam)
	{
		for (auto& gameObject : m_GameObjects)
		{
			if (gameObject->isActive())
				gameObject->render(window, mainCam);
		}
	}
	void Layer::renderGUI(sf::RenderWindow& window, Camera& mainCam)
	{
		for (auto& obj : m_UIGameObjects)
		{
			if (obj->isActive())
				obj->render(window, mainCam);
		}
	}
	void Layer::registerAdds()
	{
		// Add objects
		for (auto& gameObject : m_AddQueue)
		{
			gameObject->init(this);
			this->m_GameObjects.push_back(gameObject);
		}
		this->m_AddQueue.clear();
		for (auto& gameObject : m_UIAddQueue)
		{
			gameObject->init(this);
			this->m_UIGameObjects.push_back(gameObject);
		}
		this->m_UIAddQueue.clear();

		// Destroy Objects
		for (auto& obj : m_DestroyQueue)
		{
			m_DestroyGameObject(obj);
		}
		for (auto& obj : m_UIDestroyQueue)
		{
			m_DestroyUIGameObject(obj);
		}
		m_DestroyQueue.clear();
		m_UIDestroyQueue.clear();

	}
	void Layer::init()
	{
		this->registerAdds();
		for (auto gameObject : m_GameObjects)
		{
			gameObject->init(this);
		}
	}
	void Layer::update()
	{
		if (this->updateEnabled)
		{
			this->updateGameObjects();
			this->updateCollisions();
			this->updateGUI();
		}
	}
	void Layer::render(sf::RenderWindow& window, Camera& mainCam)
	{
		if (this->renderEnabled)
		{
			this->renderGameObjects(window, mainCam);
			this->renderGUI(window, mainCam);
		}
	}
	void Layer::pushGameObject(GameObject* gameObject)
	{
		// bool found = false;
		// for (int i = 0; i < m_AddQueue.size(); i++)
		// 	if (m_AddQueue[i]->name == gameObject->name) { found = true; break; }
		// 
		// if (!found)
		// 	for (int i = 0; i < m_GameObjects.size(); i++)
		// 		if (m_GameObjects[i]->name == gameObject->name) { found = true; break; }
		// 
		// if (!found)
		m_AddQueue.push_back(gameObject);
	}
	void Layer::popGameObject(GameObject* gameObject)
	{
		// bool found = false;
		// for (int i = 0; i < m_AddQueue.size(); i++)
		// 	if (m_AddQueue[i]->name == gameObject->name) { found = true; break; }
		// 
		// if (!found)
		// 	for (int i = 0; i < m_GameObjects.size(); i++)
		// 		if (m_GameObjects[i]->name == gameObject->name) { found = true; break; }
		// 
		// if (found)
		m_DestroyQueue.push_back(gameObject);
	}
	void Layer::pushUIGameObject(UIGameObject* gameObject)
	{
		// bool found = false;
		// for (int i = 0; i < m_UIAddQueue.size(); i++)
		// 	if (m_UIAddQueue[i]->name == gameObject->name) { found = true; break; }
		// 
		// if (!found)
		// 	for (int i = 0; i < m_UIGameObjects.size(); i++)
		// 		if (m_UIGameObjects[i]->name == gameObject->name) { found = true; break; }
		// 
		// if (!found)
		m_UIAddQueue.push_back(gameObject);
	}
	void Layer::popUIGameObject(UIGameObject* gameObject)
	{
		// bool found = false;
		// for (int i = 0; i < m_UIAddQueue.size(); i++)
		// 	if (m_UIAddQueue[i]->name == gameObject->name) { found = true; break; }
		// 
		// if (!found)
		// 	for (int i = 0; i < m_UIGameObjects.size(); i++)
		// 		if (m_UIGameObjects[i]->name == gameObject->name) { found = true; break; }
		// 
		// if (found)
		m_UIDestroyQueue.push_back(gameObject);
	}
	void Layer::pushCollider(Collider* collider)
	{
		this->m_Colliders.push_back(collider);
	}
	void Layer::popCollider(Collider* collider)
	{
		m_Colliders.erase(std::remove(m_Colliders.begin(), m_Colliders.end(), collider), m_Colliders.end());
	}
	GameObject* Layer::findGameObject(sf::String name)
	{
		for (auto gameObject : m_GameObjects)
		{
			if (gameObject->name == name)
				return gameObject;
		}
		return nullptr;
	}
	std::vector<GameObject*> Layer::findGameObjects(sf::String name)
	{
		std::vector<GameObject*> gameObjects;
		for (auto gameObject : m_GameObjects)
		{
			if (gameObject->name == name)
				gameObjects.push_back(gameObject);
		}
		return gameObjects;
	}
}