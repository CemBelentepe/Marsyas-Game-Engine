#pragma once
#include <iostream>
#include <string>

namespace mge
{
	class Debug
	{
	public:
		static void log(std::string text);
		static void logError(std::string text);
		static void logWarning(std::string text);
	};
}
