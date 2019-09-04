#include "Debug.h"
#include <Windows.h>

void mge::Debug::setColor(LogState state)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	switch (state)
	{
	case mge::Debug::LOG:
		SetConsoleTextAttribute(hConsole, 0x0F);
		break;
	case mge::Debug::ERR:
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		break;
	case mge::Debug::WARN:
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
		break;
	default:
		break;
	}
}
