#include <iostream>
#include <string>

#include "Game.h"
#include "Console.h"

int main()
{
	Console::HideCursor();

	try
	{
		Game* game = new Game(10, 20, 1000);
		game->Start();
		delete game;
	}
	catch (int err)
	{
		std::string errStr = "";

		switch (err)
		{
		case 0:
			errStr = "블록 데이터베이스 참조 범위를 벗어났습니다.";
			break;
		case 1:
			errStr = "서로 크기가 다른 게임보드의 복사가 시도되었습니다.";
			break;
		case 2:
			errStr = "게임 보드 참조 범위를 벗어났습니다.";
			break;
		default:
			errStr = "알 수 없는 오류";
			break;
		}

		std::cout << "오류 발생 : 코드 " << err << std::endl;
		std::cout << errStr << std::endl;
	}

	return 0;
}