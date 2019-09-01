#include "Debug.h"
#include <Windows.h>

void mge::Debug::log(std::string text)
{
	//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute(hConsole, 0x0F);
	std::cout << "Log: " << text << std::endl;
}
void mge::Debug::logError(std::string text)
{
	//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
	std::cout << "Error: " << text << std::endl;
}
void mge::Debug::logWarning(std::string text)
{
	//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
	std::cout << "Warning: " << text << std::endl;
}