#include <iostream>
#include <ctime>
#include <string>
#include <conio.h>

#include "Game.h"
#include "Console.h"
#include "BlockDatabase.h"

using namespace std;

void Game::Start()
{
	Console::Clear();
	prevTime = clock();

	while(Loop());
}

bool Game::Loop()
{
	curtTime = clock();
	int tick = curtTime - prevTime;
	updateDelay += tick;
	prevTime = curtTime;

	Input();
	Update(tick);
	FixedUpdate();
	Render();

	return true;
}

void Game::Input()
{
	if (!_kbhit())
		return;

	int key = _getch();

	switch (key)
	{
	case 32: // SPACE
		while (DropBlock());
		break;
	case 75: // LEFT
		bControl->Move(-1, 0);
		break;
	case 77: // RIGHT
		bControl->Move(1, 0);
		break;
	case 72: // UP
		bControl->Rotate(false);
		break;
	case 80: // DOWN
		DropBlock();
		blockDropDelay = 0;
		break;
	}
}

void Game::Update(int tick)
{
	blockDropDelay += tick;

	if (blockDropDelay >= blockDropTime)
	{
		blockDropDelay -= blockDropTime;
		DropBlock();
	}
}

void Game::FixedUpdate()
{
	if (updateDelay < FIXED_UPDATE_MS)
		return;
	updateDelay -= FIXED_UPDATE_MS;


}

const void Game::Render()
{
	// Copy Screen to renderBuffer
	renderBuffer->Copy(*board);

	pair<int, int> bContolPos = bControl->GetPosition();
	int bControlType = bControl->GetType();

	Matrix matrix = bControl->GetMatrix();

	for (int i = 0; i < matrix.size(); i++)
	{
		int xx = matrix.at(i).first + bContolPos.first;
		int yy = matrix.at(i).second + bContolPos.second;

		renderBuffer->SetData(xx, yy, bControlType);
	}

	
	int width = renderBuffer->GetWidth();
	int height = renderBuffer->GetHeight();

	Console::Move(0, 0);
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			string marker = "бр";
			Console::SetColor(Console::Color::DARK_GRAY);

			int blockTypeIndex = renderBuffer->GetData(x, y);
			if (blockTypeIndex != -1)
			{
				marker = "бс";
				Console::Color c = BlockDatabase::GetInstance().GetBlockColor(blockTypeIndex);
				Console::SetColor(c);
			}
			cout << marker;
		}

		cout << endl;
	}
}

bool Game::DropBlock()
{
	if (!bControl->Move(0, 1))
	{
		bControl->Place();
		board->TryRemoveLine();
		return false;
	}
	return true;
}

Game::Game(const int boardWidth, const int boardHeight, const int fixUdtMS) : FIXED_UPDATE_MS(fixUdtMS)
{
	board = new GameBoard(boardWidth, boardHeight);
	renderBuffer = new GameBoard(boardWidth, boardHeight);
	bControl = new BlockController(board);
}

Game::~Game()
{
	delete board;
	delete renderBuffer;
	delete bControl;
}
