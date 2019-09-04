#include "MarsiasGameEngine.h"

using namespace mge;

Scene* scene0;
Scene* scene1;

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
	scene1 = new Scene("Scene 1");
	Game::addScene(scene0);
	Game::addScene(scene1);
	GameObject player("Player", "player", Vector2f(550, 800));
	scene0->addGameObject(&player);
	scene1->addGameObject(&player);
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

		if (gameObject->pos.y < 0 || gameObject->pos.y > 1000) Game::getActiveScene()->destroyGameObject(gameObject);
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

		gameObject->pos.x = Mathf::clamp(gameObject->pos.x, 0, 1100);

		if (leftTime < 0 && Input::getKeyDown(sf::Keyboard::Key::Space))
			shoot();
	}

	void shoot()
	{
		leftTime = cooldown;
		Vector2f lPos = gameObject->pos;
		lPos.x += 50;

		GameObject* laser = new GameObject("PlayerLaser", "laserPlayer", lPos);
		Game::getActiveScene()->addGameObject(laser);
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
		Vector2f lPos = gameObject->pos;
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
			Game::getActiveScene()->destroyGameObject(this->gameObject);
			Game::getActiveScene()->destroyGameObject(collider);
		}
	}
};

class GameController :public Component
{
public:
	GameController(GameObject* gameObject) : Component(gameObject) {}

	float cooldown = 1.f;
	float leftTime = 0;

	std::vector<float> fpsRecords;
	float fpsTimer = 0.1f;

	void update() override
	{
		if (leftTime > 0)
			leftTime -= Game::deltaTime;
		else
		{
			GameObject* enemy = new GameObject("Enemy", "enemy", Vector2f(rand() * 1100 / RAND_MAX, 0));
			Game::getActiveScene()->addGameObject(enemy);
			enemy->addComponenet<BoxCollider>();
			enemy->addComponenet<EnemyController>();
			leftTime = cooldown;
		}

		if (Input::getKeyDown(sf::Keyboard::A))
		{
			// Do testing here-------------------------------------------------------------------------------
			Game::setScene(scene1);
		}

		if (fpsTimer > 0)
			fpsTimer -= Game::deltaTime;
		else
		{
			fpsTimer = .1f;
			fpsRecords.push_back(1 / Game::deltaTime);
		}
		if (Input::getKeyDown(sf::Keyboard::Escape))
		{
			float rec = 0;
			for (auto f : fpsRecords)
			{
				rec += f / fpsRecords.size();
			}
			Debug::log("FPS: " + std::to_string(rec));
			Game::exitGame();
		}
	}
};