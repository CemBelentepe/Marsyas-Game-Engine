#pragma once
#include "SFML/Graphics.hpp"
#include <map>
#include "Math.h"

namespace mge
{
	class Input
	{
	public:
		static enum Key
		{
			Unknown = -1, A = 0, B, C,
			D, E, F, G,
			H, I, J, K,
			L, M, N, O,
			P, Q, R, S,
			T, U, V, W,
			X, Y, Z, Num0,
			Num1, Num2, Num3, Num4,
			Num5, Num6, Num7, Num8,
			Num9, Escape, LControl, LShift,
			LAlt, LSystem, RControl, RShift,
			RAlt, RSystem, Menu, LBracket,
			RBracket, Semicolon, Comma, Period,
			Quote, Slash, Backslash, Tilde,
			Equal, Hyphen, Space, Enter,
			Backspace, Tab, PageUp, PageDown,
			End, Home, Insert, Delete,
			Add, Subtract, Multiply, Divide,
			Left, Right, Up, Down,
			Numpad0, Numpad1, Numpad2, Numpad3,
			Numpad4, Numpad5, Numpad6, Numpad7,
			Numpad8, Numpad9, F1, F2,
			F3, F4, F5, F6,
			F7, F8, F9, F10,
			F11, F12, F13, F14,
			F15, Pause, KeyCount, Dash = Hyphen,
			BackSpace = Backspace, BackSlash = Backslash, SemiColon = Semicolon, Return = Enter
		};

		static enum MouseButton
		{
			MouseLeft, MouseRight, MouseMiddle, MouseXButton1,
			MouseXButton2, MouseButtonCount
		};

	private:
		static sf::RenderWindow* window;

		static std::map<Key, int> keyState;
		static std::map<MouseButton, int> mouseButtonState;

		Input() {}
	public:
		/// <summary>
		/// Starts the Input system at the window.
		/// </summary>
		/// <param name="window">Window to listen.</param>
		static void start(sf::RenderWindow* window);

		static void update();

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
		static bool isMouseButtonPressed(MouseButton button);
		/// <summary>
		/// Returns whether if the mouse buton is pressed at that frame. Some kind of trigger.
		/// </summary>
		/// <param name="button">Mouse button.</param>
		/// <returns>Returns if it is pressed at that frame.</returns>
		static bool getMouseButtonDown(MouseButton button);
		/// <summary>
		/// Returns whether if the mouse buton is released at that frame. Some kind of trigger.
		/// </summary>
		/// <param name="button">Mouse button.</param>
		/// <returns>Returns if it is released at that frame</returns>
		static bool getMouseButtonUp(MouseButton button);

		/// <summary>
		/// Returns if the key is pressed.
		/// </summary>
		/// <param name="key">Keyboard key to control</param>
		/// <returns>Returns the state of the key.</returns>
		static bool isKeyPressed(Key key);
		/// <summary>
		/// Returns whether if the key is pressed at that frame. Some kind of trigger.
		/// </summary>
		/// <param name="key">Keyboard key to control</param>
		/// <returns>Returns if it is pressed at that frame.</returns>
		static bool getKeyDown(Key key);
		/// <summary>
		/// Returns whether if the key is released at that frame. Some kind of trigger.
		/// </summary>
		/// <param name="key">Keyboard key to control</param>
		/// <returns>Returns if it is released at that frame.</returns>
		static bool getKeyUp(Key key);
	};
}
