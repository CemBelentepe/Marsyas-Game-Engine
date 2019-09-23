#pragma once
#include "Components.h"

class GameScene : public Scene
{
public:
	GameScene(sf::String name) : Scene(name) {}

	void start() override
	{
		this->mainCam = new Camera({ 0, 0}, { 1, 1 }, 0);

		GameObject* player;
		UIGameObject* scoreText, * resumeButton, * menuButton, * exitButton;

		player = new GameObject("Player", "player", Vector2f(600, 850));
		player->addComponent<AABBCollider>();
		player->addComponent<PlayerController>();
		player->addComponent<GameController>();

		scoreText = new UIGameObject("ScoreText");
		scoreText->pos = Vector2f(0, 0);
		scoreText->addUIComponent<Text>();
		scoreText->getUIComponent<Text>()->setText("Score");
		scoreText->getUIComponent<Text>()->setFontSize(36);

		resumeButton = new UIGameObject("resumeButton");
		resumeButton->setActive(false);
		resumeButton->pos = Vector2f(600, 350);
		resumeButton->addUIComponent<Button>();
		resumeButton->addUIComponent<Image>();
		resumeButton->addUIComponent<Text>();
		resumeButton->getUIComponent<Button>()->setAlign(AlignMode::CENTER);
		resumeButton->getUIComponent<Button>()->setSize(Vector2f(300, 60));
		resumeButton->getUIComponent<Button>()->AddOnClickedEvent(resumeGame);
		resumeButton->getUIComponent<Image>()->setTexture("button");
		resumeButton->getUIComponent<Image>()->setAlign(AlignMode::CENTER);
		resumeButton->getUIComponent<Image>()->setSize(Vector2f(300, 60));
		resumeButton->getUIComponent<Text>()->setAlign(AlignMode::CENTER);
		resumeButton->getUIComponent<Text>()->setText("Resume");
		resumeButton->getUIComponent<Text>()->setFontSize(36);
		resumeButton->getUIComponent<Text>()->setColor(sf::Color::Black);

		menuButton = new UIGameObject("menuButton");
		menuButton->setActive(false);
		menuButton->pos = Vector2f(600, 450);
		menuButton->addUIComponent<Button>();
		menuButton->addUIComponent<Image>();
		menuButton->addUIComponent<Text>();
		menuButton->getUIComponent<Button>()->setAlign(AlignMode::CENTER);
		menuButton->getUIComponent<Button>()->setSize(Vector2f(300, 60));
		menuButton->getUIComponent<Button>()->AddOnClickedEvent(openMenu);
		menuButton->getUIComponent<Image>()->setTexture("button");
		menuButton->getUIComponent<Image>()->setAlign(AlignMode::CENTER);
		menuButton->getUIComponent<Image>()->setSize(Vector2f(300, 60));
		menuButton->getUIComponent<Text>()->setAlign(AlignMode::CENTER);
		menuButton->getUIComponent<Text>()->setText("Menu");
		menuButton->getUIComponent<Text>()->setFontSize(36);
		menuButton->getUIComponent<Text>()->setColor(sf::Color::Black);

		exitButton = new UIGameObject("exitButton");
		exitButton->setActive(false);
		exitButton->pos = Vector2f(600, 550);
		exitButton->addUIComponent<Button>();
		exitButton->addUIComponent<Image>();
		exitButton->addUIComponent<Text>();
		exitButton->getUIComponent<Button>()->setAlign(AlignMode::CENTER);
		exitButton->getUIComponent<Button>()->setSize(Vector2f(300, 60));
		exitButton->getUIComponent<Button>()->AddOnClickedEvent(exitGame);
		exitButton->getUIComponent<Image>()->setTexture("button");
		exitButton->getUIComponent<Image>()->setAlign(AlignMode::CENTER);
		exitButton->getUIComponent<Image>()->setSize(Vector2f(300, 60));
		exitButton->getUIComponent<Text>()->setAlign(AlignMode::CENTER);
		exitButton->getUIComponent<Text>()->setText("Exit");
		exitButton->getUIComponent<Text>()->setFontSize(36);
		exitButton->getUIComponent<Text>()->setColor(sf::Color::Black);


		this->addGameObject(player);
		this->addUIGameObject(scoreText);
		this->addUIGameObject(resumeButton);
		this->addUIGameObject(menuButton);
		this->addUIGameObject(exitButton);


		player->getComponent<GameController>()->menuButtons.push_back(resumeButton);
		player->getComponent<GameController>()->menuButtons.push_back(menuButton);
		player->getComponent<GameController>()->menuButtons.push_back(exitButton);

		player->getComponent<GameController>()->scoreText = scoreText->getUIComponent<Text>();
	}

	void update() override
	{

	}

	static void resumeGame(GameObject* sender)
	{
		for (auto button : Game::getActiveScene()->findGameObject("Player")->getComponent<GameController>()->menuButtons)
		{
			button->setActive(!(button->isActive()));
		}
		if (Game::timeScale <= 0.1f) Game::timeScale = 1;
		else Game::timeScale = 0.1f;
	}

	static void openMenu(GameObject* sender)
	{
		Game::setActiveScene(0);
	}

	static void exitGame(GameObject* sender)
	{
		Game::exitGame();
	}
};


class MenuScene : public Scene
{
public:
	MenuScene(sf::String name) : Scene(name) {}

	void start() override
	{
		this->mainCam = new Camera({ 0, 0}, { 1, 1 }, 0);

		UIGameObject* startButton = new UIGameObject("startButton");
		startButton->pos = Vector2f(600, 400);
		startButton->addUIComponent<Button>();
		startButton->addUIComponent<Image>();
		startButton->addUIComponent<Text>();
		startButton->getUIComponent<Button>()->setAlign(AlignMode::CENTER);
		startButton->getUIComponent<Button>()->setSize(Vector2f(300, 60));
		startButton->getUIComponent<Button>()->AddOnClickedEvent(startGame);
		startButton->getUIComponent<Image>()->setTexture("button");
		startButton->getUIComponent<Image>()->setAlign(AlignMode::CENTER);
		startButton->getUIComponent<Image>()->setSize(Vector2f(300, 60));
		startButton->getUIComponent<Text>()->setAlign(AlignMode::CENTER);
		startButton->getUIComponent<Text>()->setText("Start Game");
		startButton->getUIComponent<Text>()->setFontSize(36);
		startButton->getUIComponent<Text>()->setColor(sf::Color::Black);

		UIGameObject* endButton = new UIGameObject("endButton");
		endButton->pos = Vector2f(600, 500);
		endButton->addUIComponent<Button>();
		endButton->addUIComponent<Image>();
		endButton->addUIComponent<Text>();
		endButton->getUIComponent<Button>()->setAlign(AlignMode::CENTER);
		endButton->getUIComponent<Button>()->setSize(Vector2f(300, 60));
		endButton->getUIComponent<Button>()->AddOnClickedEvent(exitGame);
		endButton->getUIComponent<Image>()->setTexture("button");
		endButton->getUIComponent<Image>()->setAlign(AlignMode::CENTER);
		endButton->getUIComponent<Image>()->setSize(Vector2f(300, 60));
		endButton->getUIComponent<Text>()->setAlign(AlignMode::CENTER);
		endButton->getUIComponent<Text>()->setText("Exit Game");
		endButton->getUIComponent<Text>()->setFontSize(36);
		endButton->getUIComponent<Text>()->setColor(sf::Color::Black);
		
		this->addGameObject(endButton);
		this->addGameObject(startButton);
	}

	void update() override
	{

	}

	static void startGame(GameObject* sender)
	{
		Game::setActiveScene(1);
	}

	static void exitGame(GameObject* sender)
	{
		Game::exitGame();
	}
};
