#include "Game.h"

Game::Game(const char* title, int width, int height, std::vector<Scene*> scenes, bool fullscreen)
{
	this->title = title;
	this->createWindow(title, width, height, fullscreen);
	this->input = new Input(&this->window);
	this->initScenes(scenes);
}

void Game::createWindow(const char* title, int width, int height, bool fullscreen)
{
	if (fullscreen)
	{
		std::vector<sf::VideoMode> videoModes = sf::VideoMode::getFullscreenModes();
		this->window.create(videoModes.at(0), title, sf::Style::Fullscreen);
	}
	else
		this->window.create(sf::VideoMode(width, height), title, sf::Style::Titlebar | sf::Style::Close);

	this->window.setFramerateLimit(5);
}

void Game::addScene(Scene* scene)
{
	this->scenes.push_back(scene);
	scene->setWindow(&window);
}

void Game::setScene(int sceneID)
{
	this->activeSceneID = sceneID;
	if (sceneID < static_cast<int>(scenes.size()))
	{
		this->activeScene = scenes.at(sceneID);
	}
	else
	{
		std::cout << "Scene Loading Error: Scene with id didn't found: " << sceneID << std::endl;
	}
}

void Game::startEngine(int startSceneID)
{
	this->input->reset();
	setScene(startSceneID);
	while (this->window.isOpen())
	{
		this->updateEvents();
		this->update();
		this->render();
	}
}

void Game::initScenes(std::vector<Scene*> scenes)
{
	this->scenes = scenes;
	for (size_t i = 0; i < scenes.size(); i++)
	{
		scenes.at(i)->setWindow(&window);
	}
}

void Game::updateEvents()
{
	// TODO: Do events

	sf::Event event;
	while (this->window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			this->window.close();
			break;
		case sf::Event::KeyPressed:
			this->input->updateKeyPressed(event.key.code, 1);
			break;
		case sf::Event::KeyReleased:
			this->input->updateKeyPressed(event.key.code, -1);
			break;
		case sf::Event::MouseButtonPressed:
			this->input->updateMouseButtonPressed(event.mouseButton.button, 1);
			break;
		case sf::Event::MouseButtonReleased:
			this->input->updateMouseButtonPressed(event.mouseButton.button, -1);
			break;
		}
	}
}

void Game::update()
{
	this->activeScene->update();
	if (input->getKeyDown(sf::Keyboard::Key::A))
		std::cout << "Key Down\n";
	if (input->getKeyUp(sf::Keyboard::Key::A))
		std::cout << "Key Up\n";
}

void Game::render()
{
	this->window.clear();

	this->activeScene->render();

	this->window.display();
}
