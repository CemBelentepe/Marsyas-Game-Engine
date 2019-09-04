#pragma once
#include "SFML/Graphics.hpp"
#include <map>
#include "Math.h"

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

		/// <summary>
		/// Starts the Input system at the window.
		/// </summary>
		/// <param name="window">Window to listen.</param>
		static void start(sf::RenderWindow* window);

		/// <summary>
		/// Sets the listening window.
		/// </summary>
		/// <param name="window">Window to listen.</param>
		static void setWindow(sf::RenderWindow* window);
		/// <summary>
		/// Resets the Input system.
		/// </summary>
		static void reset();

		/// <summary>
		/// Updates mouse button state.
		/// </summary>
		/// <param name="button">Button to update.</param>
		/// <param name="value">State of the button.</param>
		static void updateMouseButtonPressed(sf::Mouse::Button button, int value);
		/// <summary>
		/// Updates the keyboard button state.
		/// </summary>
		/// <param name="key">Key to update.</param>
		/// <param name="value">State of the key</param>
		static void updateKeyPressed(sf::Keyboard::Key key, int value);

		/// <summary>
		/// Returns the mouse position.
		/// </summary>
		/// <returns>Mouse position.</returns>
		static Vector2i getMousePosition();
		/// <summary>
		/// Returns if the mouse button is pressed.
		/// </summary>
		/// <param name="button">Mouse button.</param>
		/// <returns>State of the mouse button.</returns>
		static bool isMouseButtonPressed(sf::Mouse::Button button);
		/// <summary>
		/// Returns whether if the mouse buton is pressed at that frame. Some kind of trigger.
		/// </summary>
		/// <param name="button">Mouse button.</param>
		/// <returns>Returns if it is pressed at that frame.</returns>
		static bool getMouseButtonDown(sf::Mouse::Button button);
		/// <summary>
		/// Returns whether if the mouse buton is released at that frame. Some kind of trigger.
		/// </summary>
		/// <param name="button">Mouse button.</param>
		/// <returns>Returns if it is released at that frame</returns>
		static bool getMouseButtonUp(sf::Mouse::Button button);

		/// <summary>
		/// Returns if the key is pressed.
		/// </summary>
		/// <param name="key">Keyboard key to control</param>
		/// <returns>Returns the state of the key.</returns>
		static bool isKeyPressed(sf::Keyboard::Key key);
		/// <summary>
		/// Returns whether if the key is pressed at that frame. Some kind of trigger.
		/// </summary>
		/// <param name="key">Keyboard key to control</param>
		/// <returns>Returns if it is pressed at that frame.</returns>
		static bool getKeyDown(sf::Keyboard::Key key);
		/// <summary>
		/// Returns whether if the key is released at that frame. Some kind of trigger.
		/// </summary>
		/// <param name="key">Keyboard key to control</param>
		/// <returns>Returns if it is released at that frame.</returns>
		static bool getKeyUp(sf::Keyboard::Key key);
	};
}
