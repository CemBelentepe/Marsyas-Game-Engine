#include <iostream>
#include "Game.h"
#include "Input.h"
#include "Resources.h"
#include "GameObject.h"
#include "Component.h"
#include "Math.h"

class PlayerMovement :public mge::Component
{
public:
	PlayerMovement(mge::GameObject* gameObject) : Component(gameObject) {}

	void update() override
	{
		float speed = 200 * mge::Game::deltaTime;

		if (mge::Input::getKeyDown(sf::Keyboard::Key::Left))
			gameObject->pos.x -= speed;
		else if (mge::Input::getKeyDown(sf::Keyboard::Key::Right))
			gameObject->pos.x += speed;

		if (mge::Input::getKeyDown(sf::Keyboard::Key::Up))
			gameObject->pos.y -= speed;
		else if (mge::Input::getKeyDown(sf::Keyboard::Key::Down))
			gameObject->pos.y += speed;

		gameObject->pos.x = mge::Math::clamp(gameObject->pos.x, 0, 700);
		gameObject->pos.y = mge::Math::clamp(gameObject->pos.y, 0, 500);

		float fps = 1.0 / mge::Game::deltaTime;
		mge::Debug::log(std::to_string(fps));
	}
	void onColliderEnter(mge::GameObject* collider) override
	{
		mge::Debug::log(collider->name + " has entered");
	}
	void onColliderLeave(mge::GameObject* collider) override
	{
		mge::Debug::log(collider->name + " has leaved");
	}
};

int main()
{
	mge::Game::createWindow("SFML Game Test", 800, 600, false);

	mge::Scene scene0("Scene 0");
	mge::Game::addScene(&scene0);

	mge::Resources::loadTexture("player", "Resources/player.png");
	mge::GameObject playerObject("Player", "player", sf::Vector2f(0, 0));
	mge::GameObject enemyObject1("Enemy1", "player", sf::Vector2f(600, 0));
	mge::GameObject enemyObject2("Enemy2", "player", sf::Vector2f(700, 0));
	scene0.addGameObject(&playerObject);
	scene0.addGameObject(&enemyObject1);
	scene0.addGameObject(&enemyObject2);

	playerObject.addComponenet<mge::BoxCollider>();
	playerObject.addComponenet<PlayerMovement>();
	
	enemyObject1.addComponenet<mge::BoxCollider>();
	enemyObject2.addComponenet<mge::BoxCollider>();

	mge::Game::startEngine();
	return 0;
}