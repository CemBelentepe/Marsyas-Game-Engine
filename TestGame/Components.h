#pragma once
#include "../SFML-Game-Engine/MarsyasGameEngine.h"

using namespace mge;

int score = 0;

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

	void start() override
	{
		score = 0;
	}

	void update() override
	{
		float speed = 900 * Game::deltaTime;
		if (leftTime > 0)
			leftTime -= Game::deltaTime;

		if (Input::isKeyPressed(Input::Left))
			gameObject->pos.x -= speed;
		if (Input::isKeyPressed(Input::Right))
			gameObject->pos.x += speed;

		gameObject->pos.x = Mathf::clamp(gameObject->pos.x, 50, 1150);

		if (leftTime < 0 && Input::isKeyPressed(Input::Space))
			shoot();
	}

	void shoot()
	{
		leftTime = cooldown;
		Vector2f lPos = gameObject->pos;
		lPos.y -= 50;

		GameObject* laser = new GameObject("PlayerLaser", "laserPlayer", lPos);
		Game::getActiveScene()->addGameObject(laser);
		laser->addComponent<AABBCollider>();
		laser->addComponent<LaserController>();
	}

	void onColliderEnter(GameObject& collider) override
	{
		if (collider.name == "EnemyLaser")
		{
			// Debug::log("Player is dead");
			Game::getActiveScene()->destroyGameObject(&collider);
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
			gameObject->pos.y += 200 * Game::deltaTime;

		if (leftTime > 0)
			leftTime -= Game::deltaTime;
		else
			shoot();

	}
	void shoot()
	{
		leftTime = cooldown;
		Vector2f lPos = gameObject->pos;
		lPos.y += 50;

		GameObject* laser = new GameObject("EnemyLaser", "laserEnemy", lPos);
		gameObject->scene->addGameObject(laser);
		laser->addComponent<AABBCollider>();
		laser->addComponent<LaserController>();
	}
	void onColliderEnter(GameObject& collider) override
	{
		if (collider.name == "PlayerLaser")
		{
			score++;
			Game::getActiveScene()->destroyGameObject(this->gameObject);
			Game::getActiveScene()->destroyGameObject(&collider);
		}
	}
};

class GameController :public Component
{
public:
	std::vector<GameObject*> menuButtons;

	bool spawn = true;

	Text* scoreText = nullptr;

	GameController(GameObject* gameObject) : Component(gameObject) {}

	float cooldown = 1.f;
	float leftTime = 0;
	int count = 50;

	std::vector<float> fpsRecords;
	float fpsTimer = 0.1f;

	bool showingColliders = false;

	void update() override
	{
		int i = 0;
		if (leftTime > 0)
			leftTime -= Game::deltaTime;
		else if (count > 0 && spawn)
		{
			GameObject* enemy = new GameObject("Enemy", "enemy", Vector2f(Mathf::rand(50, 1150), -50));
			Game::getActiveScene()->addGameObject(enemy);
			enemy->addComponent<AABBCollider>();
			enemy->addComponent<EnemyController>();
			leftTime = cooldown;
			count--;
		}

		if (fpsTimer > 0)
			fpsTimer -= Game::deltaTime;
		else
		{
			fpsTimer = .1f;
			fpsRecords.push_back(1 / Game::deltaTime);
		}
		if (Input::getKeyDown(Input::Escape))
		{
			float rec = 0;
			for (auto f : fpsRecords)
			{
				rec += f / fpsRecords.size();
			}
			Debug::log("FPS: " + std::to_string(rec));
			for (auto button : menuButtons)
			{
				button->setActive(!(button->isActive()));
			}
			if (Game::timeScale <= 0.1f) Game::timeScale = 1;
			else Game::timeScale = 0.1f;
		}

		sf::String s_score = "Score: " + std::to_string(score);
		scoreText->setText(s_score);
	}
};