#include <iostream>
#include <string>

#include "Game.h"
#include "Console.h"

int main()
{
	srand((unsigned)time(NULL));
	Console::HideCursor();

	Game* game = new Game(10, 20, 1000);
	game->Start();
	delete game;

	return 0;
}