#include <iostream>
#include <string>

#include "Game.h"
#include "Console.h"

int main()
{
	srand((unsigned)time(NULL));
	Console::HideCursor();

	Game* game = new Game(10, 20);
	while (true)
	{
		game->Start();
		delete game;
		std::cout << "y (Y) �� �Է��Ͽ� ������մϴ�. :\n";

		char input;
		std::cin >> input;
		if (input != 'Y' && input != 'y')
			break;

		game = new Game(10, 20);
	}

	return 0;
}