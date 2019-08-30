#include <iostream>
#include "Game.h"
#include "Input.h"
#include "Component.h"
#include "GameObject.h"
#include "Resources.h"

int main()
{
	mge::Game::createWindow("SFML Game Test", 800, 600, false);

	mge::Game::startEngine();
	return 0;
}