#pragma once
#include <SFML/Graphics.hpp>
#include <map>

class Input
{
private:
	sf::RenderWindow* window;

	std::map<sf::Keyboard::Key, int> keyState;
	std::map<sf::Mouse::Button, int> mouseButtonState;

public:
	Input(sf::RenderWindow* window);

	void setWindow(sf::RenderWindow* window);

	void reset();

	void updateMouseButtonPressed(sf::Mouse::Button button, int value);
	void updateKeyPressed(sf::Keyboard::Key key, int value);

	sf::Vector2i getMousePosition();
	bool isMouseButtonPressed(sf::Mouse::Button button);
	bool getMouseButtonDown(sf::Mouse::Button button);
	bool getMouseButtonUp(sf::Mouse::Button button);

	bool isKeyPressed(sf::Keyboard::Key key);
	bool getKeyDown(sf::Keyboard::Key key);
	bool getKeyUp(sf::Keyboard::Key key);
};

