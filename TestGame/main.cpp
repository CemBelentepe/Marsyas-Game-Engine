#include "../SFML-Game-Engine/MarsyasGameEngine.h"

using namespace mge;

Scene* scene0;
Scene* scene1;

class PlayerController;
class GameController;
class LaserController;
class EnemyController;

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

	void onColliderEnter(GameObject* collider) override
	{
		if (collider->name == "EnemyLaser")
		{
			// Debug::log("Player is dead");
			Game::getActiveScene()->destroyGameObject(collider);
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
	void onColliderEnter(GameObject* collider) override
	{
		if (collider->name == "PlayerLaser")
		{
			score++;
			Game::getActiveScene()->destroyGameObject(this->gameObject);
			Game::getActiveScene()->destroyGameObject(collider);
		}
	}
};

class GameController :public Component
{
public:
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

		if (Input::getKeyDown(Input::A))
		{
			// Do Stuff Here --------------------------------------------------------------------------------
			Game::timeScale *= 0.5f;
			Debug::log(Game::timeScale);
		}
		if (Input::getKeyDown(Input::B))
		{
			// Do Stuff Here --------------------------------------------------------------------------------
			Game::timeScale *= 2.f;
			Debug::log(Game::timeScale);
		}
		if (Input::getKeyDown(Input::C))
		{
			// Do Stuff Here --------------------------------------------------------------------------------
			Game::setFPS(48);
			Debug::log(Game::timeScale);
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
			Game::exitGame();
		}
		sf::String s_score = "Score: " + std::to_string(score);
		scoreText->setText(s_score);
	}
};

void onClickFunc()
{
	Debug::log("Clicked");
}

int main()
{
	Game::createWindow("Game Engine Test", 1200, 900);
	Game::setFPS(144);
	// Game::showFPS();

	Resources::loadFont("arial", "Resources/arial.ttf");
	Resources::loadTexture("button", "Resources/button.png");

	Resources::loadTexture("player", "Resources/player.png");
	Resources::loadTexture("enemy", "Resources/enemy.png");
	Resources::loadTexture("laserPlayer", "Resources/laser1.png");
	Resources::loadTexture("laserEnemy", "Resources/laser2.png");

	scene0 = new Scene("Scene 0");
	scene1 = new Scene("Scene 1");
	Game::addScene(scene0);
	Game::addScene(scene1);

	GameObject player("Player", "player", Vector2f(600, 850));
	scene0->addGameObject(&player);
	player.addComponent<AABBCollider>();
	player.addComponent<PlayerController>();
	player.addComponent<GameController>();

	UIGameObject scoreText("ScoreText");
	scene0->addUIGameObject(&scoreText);
	scoreText.pos = Vector2f(0, 0);
	scoreText.addUIComponent<Text>();
	scoreText.getUIComponent<Text>()->setText("Score");
	scoreText.getUIComponent<Text>()->setFontSize(36);

	/*UIGameObject button0("Button");
	scene0->addUIGameObject(&button0);
	button0.pos = Vector2f(600, 450);
	button0.addUIComponent<Button>();
	button0.addUIComponent<Image>();
	button0.addUIComponent<Text>();
	button0.getUIComponent<Button>()->setAlign(AlignMode::CENTER);
	button0.getUIComponent<Button>()->setSize(Vector2f(300, 60));
	button0.getUIComponent<Button>()->AddOnClickedEvent(onClickFunc);
	button0.getUIComponent<Image>()->setTexture("button");
	button0.getUIComponent<Image>()->setAlign(AlignMode::CENTER);
	button0.getUIComponent<Image>()->setSize(Vector2f(300, 60));
	button0.getUIComponent<Text>()->setAlign(AlignMode::CENTER);
	button0.getUIComponent<Text>()->setText("Restart");
	button0.getUIComponent<Text>()->setFontSize(36);
	button0.getUIComponent<Text>()->setColor(sf::Color::Black);*/

	player.getComponent<GameController>()->scoreText = scoreText.getUIComponent<Text>();

	Game::startEngine();
	return 0;
}