#include <iostream>
#include "Game.h"

class PlayerMoveComponent :public mge::Component
{
public:
	PlayerMoveComponent(mge::GameObject* gameObject) :Component(gameObject) {}

	void update() override
	{
		float speed = 800 * mge::Game::deltaTime;

		if (mge::Input::isKeyPressed(sf::Keyboard::Key::Up))
			gameObject->pos.y -= speed;
		else if (mge::Input::isKeyPressed(sf::Keyboard::Key::Down))
			gameObject->pos.y += speed;

		if (mge::Input::isKeyPressed(sf::Keyboard::Key::Left))
			gameObject->pos.x -= speed;
		else if (mge::Input::isKeyPressed(sf::Keyboard::Key::Right))
			gameObject->pos.x += speed;
	}
};

int main()
{
	mge::Game::createWindow("SFML Game Test", 800, 600, false);

	mge::Scene scene0("Scene 0");
	mge::Game::addScene(&scene0);
	
	mge::Resources::loadTexture("player", "Resources/player.png");

	mge::GameObject gameObject("Player", "player", sf::Vector2f(0, 0));
	gameObject.addComponenet<PlayerMoveComponent>();
	
	scene0.addGameObject(&gameObject);

	mge::Game::startEngine();
	return 0;
}