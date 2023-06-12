#include <Windows.h>

#include "console.h"

void Console::Clear()
{
	system("cls");
}

void Console::Move(int x, int y)
{
	COORD coord = { x << 1, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Console::Move(COORD pos)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Console::SetColor(Color color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)color);
}

void Console::HideCursor()
{
	CONSOLE_CURSOR_INFO csrInfo = { 0, };
	csrInfo.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csrInfo);
}
