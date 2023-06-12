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
			errStr = "��� �����ͺ��̽� ���� ������ ������ϴ�.";
			break;
		case 1:
			errStr = "���� ũ�Ⱑ �ٸ� ���Ӻ����� ���簡 �õ��Ǿ����ϴ�.";
			break;
		case 2:
			errStr = "���� ���� ���� ������ ������ϴ�.";
			break;
		default:
			errStr = "�� �� ���� ����";
			break;
		}

		std::cout << "���� �߻� : �ڵ� " << err << std::endl;
		std::cout << errStr << std::endl;
	}

	return 0;
}