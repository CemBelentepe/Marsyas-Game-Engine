#pragma once
#include <SFML/Graphics.hpp>
#include "Component.h"

class GameObject
{
private:
	sf::Sprite* sprite;
	sf::Vector2f pos;
	sf::Vector2f scale;
	float rotation;

	std::vector<Component*> components;

	void initVariables();
	void updateComponents();
public:
	GameObject(sf::Texture* texture, sf::Vector2f pos);
	GameObject(sf::Texture* texture, sf::Vector2f pos, sf::IntRect textureRect);

	virtual void update();
	virtual void render(sf::RenderWindow* window);
};

