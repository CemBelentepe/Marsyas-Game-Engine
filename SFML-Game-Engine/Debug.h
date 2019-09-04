#pragma once
#include <iostream>

namespace mge
{
	class Debug
	{
	private:
		enum LogState
		{
			LOG, ERR, WARN
		};

		/// <summary>
		/// Sets the color of the console based on enum type LogState.
		/// </summary>
		/// <param name="state">Console color state.</param>
		static void setColor(LogState state);
	public:

		/// <summary>
		/// Logs a white text to the console. Like literally calling the std::cout function...
		/// </summary>
		/// <param name="text">Output text.</param>
		template <class T>
		static void log(T text)
		{
			setColor(LOG);
			std::cout << "[Log]: " << text << std::endl;
		}

		/// <summary>
		/// Logs a red text with "[Error]:" prefix.
		/// </summary>
		/// <param name="text">Output text.</param>
		template <class T>
		static void logError(T text)
		{
			setColor(ERR);
			std::cout << "[Error]: " << text << std::endl;
		}

		/// <summary>
		/// Logs a yellow text with "[Warnning]:" prefix.
		/// </summary>
		/// <param name="text">Output text.</param>
		template <class T>
		static void logWarning(T text)
		{
			setColor(WARN);
			std::cout << "[Warning]: " << text << std::endl;
		}
	};
}
