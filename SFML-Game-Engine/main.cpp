#include "Game.h"
#include "GameObject.h"
#include "Resources.h"
#include "Input.h"
#include "Math.h"
#include "Collider.h"

using namespace mge;

Scene* scene0;

class PlayerController;
class GameController;
class LaserController;
class EnemyController;

int main()
{
	Game::createWindow("Game Engine Test", 1200, 900);

	Resources::loadTexture("player", "Resources/player.png");
	Resources::loadTexture("enemy", "Resources/enemy.png");
	Resources::loadTexture("laserPlayer", "Resources/laser1.png");
	Resources::loadTexture("laserEnemy", "Resources/laser2.png");

	scene0 = new Scene("Scene 0");
	Game::addScene(scene0);

	GameObject player("Player", "player", sf::Vector2f(550, 800));
	scene0->addGameObject(&player);

	player.addComponenet<BoxCollider>();
	player.addComponenet<PlayerController>();
	player.addComponenet<GameController>();

	Game::startEngine();
	return 0;
}


class LaserController :public Component
{
public:
	LaserController(GameObject* gameObject) : Component(gameObject) {}

	float speed = 500;
	void start() override
	{
		if (gameObject->name == "PlayerLaser") speed *= -1;
	}
	void update() override
	{
		gameObject->pos.y += speed * Game::deltaTime;

		if (gameObject->pos.y < 0 || gameObject->pos.y > 1000) scene0->destroyGameObject(gameObject);
	}

};

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
		if (Input::getKeyDown(sf::Keyboard::Key::Right))
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

class GameController :public Component
{
public:
	GameController(GameObject* gameObject) : Component(gameObject) {}

	float cooldown = 1.f;
	float leftTime = 0;
	float totalFPS = 0;
	int fpsCount = 0;

	void update() override
	{
		if (leftTime > 0)
			leftTime -= Game::deltaTime;
		else
		{
			GameObject* enemy = new GameObject("Enemy", "enemy", sf::Vector2f(rand() * 1100 / RAND_MAX, 0));
			scene0->addGameObject(enemy);
			enemy->addComponenet<BoxCollider>();
			enemy->addComponenet<EnemyController>();
			leftTime = cooldown;
		}

		totalFPS += 1 / Game::deltaTime;
		fpsCount++;

		if (Input::getKeyDown(sf::Keyboard::A))
		{
			PlayerController* pc = this->gameObject->getComponent<PlayerController>();
			pc->setActive(!pc->isActive());
		}

		if (Input::getKeyDown(sf::Keyboard::Escape))
		{
			totalFPS /= fpsCount;
			std::string s = std::to_string(totalFPS);
			Debug::log("FPS: " + s);
			Game::exitGame();
		}
	}
};