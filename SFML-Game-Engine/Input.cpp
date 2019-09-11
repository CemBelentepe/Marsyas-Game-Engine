#include "Input.h"

namespace mge
{
	sf::RenderWindow* Input::window = nullptr;

	std::map<Input::Key, int> Input::keyState;
	std::map<Input::MouseButton, int> Input::mouseButtonState;

	void Input::start(sf::RenderWindow* window)
	{
		Input::setWindow(window);
		Input::reset();
	}

	void Input::update()
	{
		for (auto& key : keyState)
		{
			if (key.second > 0) key.second = 1;
			else key.second = -1;
		}
	}

	void Input::setWindow(sf::RenderWindow* window)
	{
		Input::window = window;
	}

	void Input::reset()
	{
		for (auto& key : mouseButtonState)
			key.second = 0;

		for (int i = -1; i < 102; i++)
			keyState[(Key)i] = -1;
	}

	void Input::updateMouseButtonPressed(sf::Mouse::Button button, int value)
	{
		mouseButtonState[(MouseButton)(int)button] = value;
	}

	void Input::updateKeyPressed(sf::Keyboard::Key key, int value)
	{
		int& x = keyState[(Input::Key)(int)key];
		if (value == 1)
		{
			if (x > 0)
			{
				x = 1;
			}
			else
			{
				x = 2;
			}
		}
		else
		{
			if (x > 0)
			{
				x = -2;
			}
			else
			{
				x = -1;
			}
		}
	}

	Vector2i Input::getMousePosition()
	{
		return sf::Mouse::getPosition(*Input::window);
	}

	bool Input::isMouseButtonPressed(MouseButton button)
	{
		return sf::Mouse::isButtonPressed((sf::Mouse::Button)button);
	}

	bool Input::getMouseButtonDown(MouseButton button)
	{
		return mouseButtonState[button] > 0;
	}

	bool Input::getMouseButtonUp(MouseButton button)
	{
		return mouseButtonState[button] < 0;
	}

	bool Input::isKeyPressed(Input::Key key)
	{
		return keyState[key] == 1;
	}

	bool Input::getKeyDown(Input::Key key)
	{
		return keyState[key] == 2;
	}

	bool Input::getKeyUp(Input::Key key)
	{
		return keyState[key] == -2;
	}
}