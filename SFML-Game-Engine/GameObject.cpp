#include "GameObject.h"
#include "Component.h"
#include "Scene.h"
#include "Collider.h"
#include "Renderer.h"
#include "SpriteRenderer.h"

namespace mge
{
	void GameObject::initVariables()
	{
		this->name = "GameObject";
		this->pos = Vector2f(0, 0);
		this->scale = Vector2f(1, 1);
		this->rotation = 0;
	}

	void GameObject::updateComponents()
	{
		// Removes Colliders
		for (auto c : removedComponents)
		{
			components.erase(std::remove(components.begin(), components.end(), c), components.end());

			Collider* collider = dynamic_cast<Collider*>(c);
			if (collider)
			{
				this->scene->removeCollider(collider);
			}
		}
		removedComponents.clear();

		// Adds the new components to the all components vector then
		// Starts the components even if they are enabled or not!
		for (auto c : addedComponents)
		{
			components.push_back(c);

			Collider* collider = dynamic_cast<Collider*>(c);
			if (collider)
			{
				this->scene->addCollider(collider);
			}
		}

		for (auto c : addedComponents)
		{
			c->start();
		}

		addedComponents.clear();

		// Updates all of the components (newly added too), if they are enabled
		for (auto c : components)
		{
			if (c->isActive())
				c->update();
		}
	}

	GameObject::GameObject(const sf::String& name, const Vector2f& pos)
	{
		this->initVariables();
		this->name = name;
		this->renderer = nullptr;
	}

	GameObject::GameObject(const sf::String& name, const sf::String& textureName, const Vector2f& pos)
	{
		this->initVariables();
		this->name = name;
		this->pos = pos;
		this->renderer = new SpriteRenderer(textureName);
		this->renderer->setPosition(this->pos);
		this->renderer->setScale(this->scale);
		this->renderer->setRotation(this->rotation);
	}

	GameObject::GameObject(const sf::String& name, const sf::String& textureName, const IntRect& textureRect, const Vector2f& pos)
	{
		this->initVariables();
		this->name = name;
		this->pos = pos;
		this->renderer = new SpriteRenderer(textureName, textureRect);
		this->renderer->setPosition(this->pos);
		this->renderer->setScale(this->scale);
		this->renderer->setRotation(this->rotation);
	}

	GameObject::~GameObject()
	{
		for (auto comp : components)
		{
			delete comp;
		}
		delete renderer;
	}

	void GameObject::init(Scene* scene)
	{
		this->scene = scene;
		if (this->renderer) this->renderer->setActive(this->enabled);
		for (auto comp : components)
		{
			Collider* col = dynamic_cast<Collider*>(comp);
			if (col)
			{
				scene->addCollider(col);
			}
		}
	}

	void GameObject::update()
	{
		this->updateComponents();
	}

	void GameObject::render(sf::RenderWindow& window, Camera& camera)
	{
		this->renderer->setPosition(this->pos);
		this->renderer->setScale(this->scale);
		this->renderer->setRotation(this->rotation);
		this->renderer->render(window, camera);
	}

	void GameObject::setActive(bool active)
	{
		this->enabled = active;
	}
}