#include "../SFML-Game-Engine/MarsyasGameEngine.h"
#include "Scenes.h"

using namespace mge;

Scene* scene0;
Scene* scene1;

int main()
{
	Game::createWindow("Game Engine Test", 1200, 900);
	// Game::createWindow("Game Engine Test");
	// Game::setFPS(144);
	// Game::showFPS();

	Resources::loadFont("arial", "Resources/arial.ttf");
	Resources::loadTexture("button", "Resources/button.png");
	Resources::loadSound("laser", "Resources/laser.wav");

	Resources::loadTexture("player", "Resources/player.png");
	Resources::loadTexture("enemy", "Resources/enemy.png");
	Resources::loadTexture("laserPlayer", "Resources/laser1.png");
	Resources::loadTexture("laserEnemy", "Resources/laser2.png");

	scene0 = new MenuScene("Scene 0");
	scene1 = new GameScene("Scene 1");
	Game::addScene(scene0);
	Game::addScene(scene1);

	Game::startEngine();
	return 0;
}