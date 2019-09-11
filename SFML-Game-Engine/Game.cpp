#include "Game.h"
#include "Input.h"
#include "Debug.h"

using namespace mge;

sf::RenderWindow Game::window;
sf::String Game::title = "";
bool Game::isShowFPS = false;
float Game::lastFPSs[10] = { 0,0,0,0,0,0,0,0,0 };
int Game::fpsInc = 0;

sf::Clock Game::clock = sf::Clock::Clock();
sf::Time Game::tDeltaTime = sf::Time::Zero;

std::vector<Scene*> Game::scenes;
Scene* Game::activeScene = nullptr;
int Game::activeSceneID = 0;

float Game::deltaTime = 0;

void Game::loadScenes(std::vector<Scene*> scenes)
{
	initScenes(scenes);
}

void Game::createWindow(const char* title, int width, int height, bool fullscreen)
{
	Game::title = title;
	if (fullscreen)
	{
		std::vector<sf::VideoMode> videoModes = sf::VideoMode::getFullscreenModes();
		Game::window.create(videoModes.at(0), title, sf::Style::Fullscreen);
	}
	else
		Game::window.create(sf::VideoMode(width, height), title, sf::Style::Titlebar | sf::Style::Close);
}

void Game::addScene(Scene* scene)
{
	scenes.push_back(scene);
	scene->setWindow(&window);
}

void Game::setScene(int sceneID)
{
	activeSceneID = sceneID;
	if (sceneID < static_cast<int>(scenes.size()))
	{
		activeScene = scenes.at(sceneID);
		activeScene->load();
	}
	else
	{
		Debug::logError("Scene with id did not found: " + sceneID);
	}
}

void Game::setScene(Scene* scene)
{
	bool loaded = false;
	for (size_t i = 0; i < scenes.size(); i++)
	{
		if (scenes.at(i) == scene)
		{
			activeSceneID = i;
			activeScene = scenes.at(i);
			activeScene->load();
			loaded = true;
			break;
		}
	}
	if (!loaded)
	{
		Debug::logError("Scene did not found."); // Add the id of the name of the scene later. TODO
	}
}

Scene* mge::Game::getActiveScene()
{
	return Game::activeScene;
}

void Game::startEngine(int startSceneID)
{
	window.setKeyRepeatEnabled(false);
	initScenes(scenes); // Inits the scenes
	Input::start(&Game::window); // Starts the input system
	srand(time(NULL)); // Sets the random seed

	setScene(startSceneID); // Sets the active scene

	// Main Game Loop
	while (window.isOpen())
	{
		// Calculates deltaTime := time between frames 
		tDeltaTime = clock.getElapsedTime();
		clock.restart();
		deltaTime = tDeltaTime.asSeconds();


		Input::update();
		updateEvents(); // Updates SFML events
		update(); // Updates the active scene
		render(); // Renders the active scene

		 // Shows FPS alongside with the title
		if (isShowFPS)
		{
			float currentFps = 1.0 / deltaTime;
			lastFPSs[fpsInc] = currentFps;
			fpsInc++;
			if (fpsInc == 10)
				fpsInc = 0;

			float fps = 0;
			for (float f : lastFPSs)
				fps += f;
			fps /= 10;
			int fpsi = (int)(100.0 * fps);
			fps = fpsi / 100.0;
			window.setTitle(title + " - " + std::to_string(fps) + "fps");
		}
	}
}

void mge::Game::showFPS(bool show)
{
	Game::isShowFPS = show;
}

void mge::Game::setLimitFPS(int fps)
{
	Game::window.setFramerateLimit(fps);
}

void mge::Game::setVerticalSyncEnabled(bool enabled)
{
	Game::window.setVerticalSyncEnabled(enabled);
}

void mge::Game::exitGame()
{
	Game::window.close();
}

void Game::initScenes(std::vector<Scene*> scenes)
{
	Game::scenes = scenes;
	for (size_t i = 0; i < scenes.size(); i++)
	{
		scenes.at(i)->setWindow(&window);
	}
}

void Game::updateEvents()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::KeyPressed:
			Input::updateKeyPressed(event.key.code, 1);
			break;
		case sf::Event::KeyReleased:
			Input::updateKeyPressed(event.key.code, -1);
			break;
		case sf::Event::MouseButtonPressed:
			Input::updateMouseButtonPressed(event.mouseButton.button, 1);
			break;
		case sf::Event::MouseButtonReleased:
			Input::updateMouseButtonPressed(event.mouseButton.button, -1);
			break;
		}
	}
}

void Game::update()
{
	activeScene->update();
	activeScene->lateUpdate();
}

void Game::render()
{
	window.clear();
	activeScene->render();
	activeScene->renderColliders(); // TODO: Delete it before release
	window.display();
}
