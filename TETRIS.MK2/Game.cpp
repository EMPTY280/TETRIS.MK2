#include <iostream>
#include <ctime>
#include <string>

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
	updateDelay += curtTime - prevTime;
	prevTime = curtTime;

	Input();
	Update();
	FixedUpdate();
	Render();

	return true;
}

void Game::Input()
{
}

void Game::Update()
{
}

void Game::FixedUpdate()
{
	if (updateDelay < FIXED_UPDATE_MS)
		return;
}

const void Game::Render()
{
	renderBuffer->Copy(*board);
	
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
				Console::Color c = BlockDatabase::Data().GetBlockColor(blockTypeIndex);
				Console::SetColor(c);
			}
			cout << marker;
		}
		cout << endl;
	}
}

Game::Game(const int boardWidth, const int boardHeight, const int fixUdtMS) : FIXED_UPDATE_MS(fixUdtMS)
{
	board = new GameBoard(boardWidth, boardHeight);
	renderBuffer = new GameBoard(boardWidth, boardHeight);
}

Game::~Game()
{
	delete board;
	delete renderBuffer;
}
