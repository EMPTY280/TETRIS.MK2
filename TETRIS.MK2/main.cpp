#include <iostream>
#include <string>

#include "Game.h"
#include "Console.h"

int main()
{
	Console::HideCursor();

	Game* game = new Game(10, 20, 1000);
	game->Start();
	delete game;

	return 0;
}