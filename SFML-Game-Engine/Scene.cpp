#include "Scene.h"
#include "GameObject.h"
#include "UIGameObject.h"
#include "Collider.h"
#include "SpriteRenderer.h"
#include <algorithm>

namespace mge
{
	void Scene::updateGameObjects()
	{
		// TODO: optimize
		for (size_t i = 0; i < m_GameObjects.size(); i++)
		{
			GameObject* gameObject = m_GameObjects.at(i);
			if (gameObject->isActive())
				gameObject->update();
		}
	}

	void Scene::updateGUI()
	{
		for (auto obj : m_UIGameObjects)
		{
			if (obj->isActive())
				obj->update();
		}
	}

	void Scene::updateCollisions()
	{
		for (auto collider : this->m_Colliders)
		{
			if (collider->gameObject->isActive() && collider->isActive())
				for (auto collision : this->m_Colliders)
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

	void Scene::renderGameObjects()
	{
		// TODO: optimize
		for (auto gameObject : m_GameObjects)
		{
			if (gameObject->isActive())
				gameObject->render(this->window);
		}
	}

	void Scene::renderGUI()
	{
		for (auto obj : m_UIGameObjects)
		{
			if (obj->isActive())
				obj->render(this->window);
		}
	}

	void Scene::registerDestroys()
	{
		for (auto obj : m_DestroyedObjects)
		{
			m_DestroyGameObject(obj);
		}
		for (auto obj : m_RemovedObjects)
		{
			m_RemoveGameObject(obj);
		}
		for (auto obj : m_DestroyedUIObjects)
		{
			m_DestroyUIGameObject(obj);
		}
		for (auto obj : m_RemovedUIObjects)
		{
			m_RemoveUIGameObject(obj);
		}
	}

	Scene::Scene(sf::String name) : name(name), window(nullptr), colliderShow(false)
	{
		this->m_Colliders = std::vector<Collider*>();
	}

	void Scene::load()
	{
		for (auto gameObject : m_GameObjects)
		{
			gameObject->init(this);
		}
	}

	void Scene::lateUpdate()
	{
		this->registerDestroys();
		this->m_RemovedObjects.clear();
		this->m_DestroyedObjects.clear();
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
		gameObject->renderer->setActive(true);
		this->m_GameObjects.push_back(gameObject);
	}

	void Scene::removeGameObject(GameObject* gameObject)
	{
		if (std::find(m_RemovedObjects.begin(), m_RemovedObjects.end(), gameObject) == m_RemovedObjects.end() &&
			std::find(m_DestroyedObjects.begin(), m_DestroyedObjects.end(), gameObject) == m_DestroyedObjects.end())
			this->m_RemovedObjects.push_back(gameObject);
	}

	void Scene::destroyGameObject(GameObject* gameObject)
	{
		if (std::find(m_RemovedObjects.begin(), m_RemovedObjects.end(), gameObject) == m_RemovedObjects.end() &&
			std::find(m_DestroyedObjects.begin(), m_DestroyedObjects.end(), gameObject) == m_DestroyedObjects.end())
			this->m_DestroyedObjects.push_back(gameObject);
	}

	void Scene::addUIGameObject(UIGameObject* gameObject)
	{
		gameObject->scene = this;
		if (gameObject->renderer)
			gameObject->renderer->setActive(true);
		this->m_UIGameObjects.push_back(gameObject);
	}

	void Scene::removeUIGameObject(UIGameObject* gameObject)
	{
		if (std::find(m_RemovedUIObjects.begin(), m_RemovedUIObjects.end(), gameObject) == m_RemovedUIObjects.end() &&
			std::find(m_DestroyedUIObjects.begin(), m_DestroyedUIObjects.end(), gameObject) == m_DestroyedUIObjects.end())
			this->m_RemovedUIObjects.push_back(gameObject);
	}

	void Scene::destroyUIGameObject(UIGameObject* gameObject)
	{
		if (std::find(m_RemovedUIObjects.begin(), m_RemovedUIObjects.end(), gameObject) == m_RemovedUIObjects.end() &&
			std::find(m_DestroyedUIObjects.begin(), m_DestroyedUIObjects.end(), gameObject) == m_DestroyedUIObjects.end())
			this->m_DestroyedUIObjects.push_back(gameObject);
	}

	void Scene::m_RemoveGameObject(GameObject* gameObject)
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
	}

	void Scene::m_DestroyGameObject(GameObject* gameObject)
	{
		this->m_RemoveGameObject(gameObject);
		delete gameObject;
	}

	void Scene::m_RemoveUIGameObject(UIGameObject* gameObject)
	{
		for (int i = m_UIGameObjects.size() - 1; i >= 0; i--)
		{
			if (m_UIGameObjects.at(i) == gameObject)
			{
				m_UIGameObjects.erase(m_UIGameObjects.begin() + i);
			}
		}
	}

	void Scene::m_DestroyUIGameObject(UIGameObject* gameObject)
	{
		this->m_RemoveUIGameObject(gameObject);
		delete gameObject;
	}

	void Scene::setGameObjects(std::vector<GameObject*> gameObjects)
	{
		this->m_GameObjects = gameObjects;
		for (auto gameObject : gameObjects)
		{
			gameObject->scene = this;
		}
	}

	void Scene::showColliders(bool show)
	{
		this->colliderShow = show;
	}

	void Scene::renderColliders()
	{
		if (colliderShow)
		{
			for (auto collider : this->m_Colliders)
			{
				sf::RectangleShape box;
				box.setPosition(collider->gameObject->renderer->getPosition() + collider->gameObject->renderer->offset);
				box.setSize(collider->gameObject->renderer->getSize());
				box.setFillColor(sf::Color::Transparent);
				box.setOutlineThickness(2);
				box.setOutlineColor(sf::Color::Green);
				window->draw(box);
			}
		}
	}

	void Scene::addCollider(Collider* collider)
	{
		this->m_Colliders.push_back(collider);
	}

	void Scene::removeCollider(Collider* collider)
	{
		m_Colliders.erase(std::remove(m_Colliders.begin(), m_Colliders.end(), collider), m_Colliders.end());
	}

	void Scene::setWindow(sf::RenderWindow* window)
	{
		this->window = window;
	}
}