#pragma once
#include "SFML/Graphics.hpp"
#include <map>

namespace mge
{
	class Input
	{
	private:
		static sf::RenderWindow* window;

		static std::map<sf::Keyboard::Key, int> keyState;
		static std::map<sf::Mouse::Button, int> mouseButtonState;

	public:
		Input() {}

		static void start(sf::RenderWindow* window);

		static void setWindow(sf::RenderWindow* window);
		static void reset();

		static void updateMouseButtonPressed(sf::Mouse::Button button, int value);
		static void updateKeyPressed(sf::Keyboard::Key key, int value);

		static sf::Vector2i getMousePosition();
		static bool isMouseButtonPressed(sf::Mouse::Button button);
		static bool getMouseButtonDown(sf::Mouse::Button button);
		static bool getMouseButtonUp(sf::Mouse::Button button);

		static bool isKeyPressed(sf::Keyboard::Key key);
		static bool getKeyDown(sf::Keyboard::Key key);
		static bool getKeyUp(sf::Keyboard::Key key);
	};
}
