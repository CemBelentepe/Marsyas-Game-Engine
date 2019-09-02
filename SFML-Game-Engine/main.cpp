#include "Game.h"
#include "GameObject.h"
#include "Resources.h"
#include "Input.h"
#include "Math.h"

using namespace mge;

Scene* scene0;

class PlayerController;
class GameController;
class LaserController;
class EnemyController;

int main()
{
	Game::createWindow("Game Engine Test", 1200, 900, false);
	scene0 = new Scene("Scene 0");
	Game::addScene(scene0);

	Resources::loadTexture("player", "Resources/player.png");
	Resources::loadTexture("enemy", "Resources/enemy.png");
	Resources::loadTexture("laserPlayer", "Resources/laser1.png");
	Resources::loadTexture("laserEnemy", "Resources/laser2.png");

	GameObject player("Player", "player", sf::Vector2f(550, 800));
	scene0->addGameObject(&player);


	player.addComponenet<BoxCollider>();
	player.addComponenet<PlayerController>();
	player.addComponenet<GameController>();


	Game::startEngine();
	return 0;
}

class PlayerController :public Component
{
public:
	PlayerController(GameObject* gameObject) : Component(gameObject) {}

	float cooldown = .2f;
	float leftTime = cooldown;

	void update() override
	{
		float speed = 900 * Game::deltaTime;
		if (leftTime > 0)
			leftTime -= Game::deltaTime;

		if (Input::getKeyDown(sf::Keyboard::Key::Left))
			gameObject->pos.x -= speed;
		else if (Input::getKeyDown(sf::Keyboard::Key::Right))
			gameObject->pos.x += speed;

		gameObject->pos.x = Math::clamp(gameObject->pos.x, 0, 1100);

		if (leftTime < 0 && Input::getKeyDown(sf::Keyboard::Key::Space))
			shoot();
	}

	void shoot()
	{
		leftTime = cooldown;
		sf::Vector2f lPos = gameObject->pos;
		lPos.x += 50;

		GameObject* laser = new GameObject("PlayerLaser", "laserPlayer", lPos);
		scene0->addGameObject(laser);
		laser->renderer.resetSprite();		
		laser->renderer.setActive(true);
		laser->addComponenet<BoxCollider>();
		laser->addComponenet<LaserController>();
	}

	void onColliderEnter(GameObject* collider) override
	{
		if (collider->name == "EnemyLaser")
		{
			Debug::log("Player is dead");
		}
	}

};

class GameController :public Component
{
public:
	GameController(GameObject* gameObject) : Component(gameObject) {}

	float cooldown = 1.f;
	float leftTime = 0;

	void update() override
	{
		if (leftTime > 0)
			leftTime -= Game::deltaTime;
		else
		{
			GameObject* enemy = new GameObject("Enemy", "enemy", sf::Vector2f(rand() * 1100 / RAND_MAX, 0));
			scene0->addGameObject(enemy);
			enemy->renderer.setActive(true);
			enemy->addComponenet<BoxCollider>();
			enemy->addComponenet<EnemyController>();
			leftTime = cooldown;
		}

		if (Input::getKeyDown(sf::Keyboard::Escape))
			Game::exitGame();
	}
};

class LaserController :public Component
{
public:
	LaserController(GameObject* gameObject) : Component(gameObject) {}
	void update()
	{
		float speed = 500;
		if (gameObject->name == "PlayerLaser") speed *= -1;
		gameObject->pos.y += speed * Game::deltaTime;

		if (gameObject->pos.y < 0 && gameObject->pos.y > 1000) scene0->destroyGameObject(gameObject);
	}

};

class EnemyController :public Component
{
public:
	EnemyController(GameObject* gameObject) : Component(gameObject) {}

	float cooldown = 1.f;
	float leftTime = cooldown;

	void update() override
	{
		if (gameObject->pos.y < 450)
		{
			gameObject->pos.y += 200 * Game::deltaTime;
		}

		if (leftTime > 0)
			leftTime -= Game::deltaTime;
		else
			shoot();

	}
	void shoot()
	{
		leftTime = cooldown;
		sf::Vector2f lPos = gameObject->pos;
		lPos.x += 50;

		GameObject* laser = new GameObject("EnemyLaser", "laserEnemy", lPos);
		gameObject->scene->addGameObject(laser);
		laser->renderer.setActive(true);
		laser->addComponenet<BoxCollider>();
		laser->addComponenet<LaserController>();
	}
	void onColliderEnter(GameObject* collider) override
	{
		if (collider->name == "PlayerLaser")
		{
			scene0->destroyGameObject(this->gameObject);
			scene0->destroyGameObject(collider);
		}
	}
};
