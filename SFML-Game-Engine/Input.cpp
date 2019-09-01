#include "Input.h"

using namespace mge;

sf::RenderWindow* Input::window = nullptr;

std::map<sf::Keyboard::Key, int> Input::keyState;
std::map<sf::Mouse::Button, int> Input::mouseButtonState;

void Input::start(sf::RenderWindow* window)
{
	Input::setWindow(window);
	Input::reset();
}

void Input::setWindow(sf::RenderWindow* window)
{
	Input::window = window;
}

void Input::reset()
{
	for (auto key : mouseButtonState)
		key.second = 0;

	for (auto key : keyState)
		key.second = 0;
}

void Input::updateMouseButtonPressed(sf::Mouse::Button button, int value)
{
	mouseButtonState[button] = value;
}

void Input::updateKeyPressed(sf::Keyboard::Key key, int value)
{
	keyState[key] = value;
}

sf::Vector2i Input::getMousePosition()
{
	return sf::Mouse::getPosition(*Input::window);
}

bool Input::isMouseButtonPressed(sf::Mouse::Button button)
{
	return sf::Mouse::isButtonPressed(button);
}

bool Input::getMouseButtonDown(sf::Mouse::Button button)
{
	return mouseButtonState[button] > 0;
}

bool Input::getMouseButtonUp(sf::Mouse::Button button)
{
	return mouseButtonState[button] < 0;
}

bool Input::isKeyPressed(sf::Keyboard::Key key)
{
	return sf::Keyboard::isKeyPressed(key);
}

bool Input::getKeyDown(sf::Keyboard::Key key)
{
	return keyState[key] > 0;
}

bool Input::getKeyUp(sf::Keyboard::Key key)
{
	return keyState[key] < 0;
}
