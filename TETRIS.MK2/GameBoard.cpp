#include <iostream>

#include "GameBoard.h"

GameBoard::GameBoard(const int boardWidth, const int boardHeight) : boardWidth(boardWidth), boardHeight(boardHeight)
{
	board = new int[boardWidth * boardHeight];
	std::fill_n(board, boardWidth * boardHeight, -1);
}

GameBoard::~GameBoard()
{
	delete board;
}

void GameBoard::Copy(const GameBoard& target)
{
	if (target.boardWidth != boardWidth ||
		target.boardHeight != boardHeight)
		return;

	std::copy(&target.board[0], &target.board[0] + (boardWidth * boardHeight), board);
}

const int& GameBoard::GetWidth() const
{
	return boardWidth;
}

const int& GameBoard::GetHeight() const
{
	return boardHeight;
}

const int& GameBoard::GetData(int x, int y) const
{
	if (!IsValidCoord(x, y))
		return -1;

	return board[boardWidth * y + x];
}

void GameBoard::TryRemoveLine()
{
	for (int h = 0; h < boardHeight; h++)
	{
		bool remove = true;
		for (int w = 0; w < boardWidth; w++)
		{
			if (GetData(w, h) == -1)
			{
				remove = false;
				break;
			}
		}

		if (remove)
		{
			ClearLine(h);
			int idx = h;
			while (idx >= 0)
			{
				CopyLine(idx - 1, idx);
				idx--;
			}
			h--;
		}
	}
}

void GameBoard::CopyLine(int src, int dest)
{
	for (int i = 0; i < boardWidth; i++)
	{
		if (src == -1)
			SetData(i, dest, -1);
		else
			SetData(i, dest, GetData(i, src));
	}
}

void GameBoard::ClearLine(int idx)
{
	for (int w = 0; w < boardWidth; w++)
	{
		SetData(w, idx, -1);
	}
}

void GameBoard::SetData(int x, int y, int data)
{
	if (!IsValidCoord(x, y))
		return;

	board[boardWidth * y + x] = data;
}

const bool GameBoard::IsValidCoord(int x, int y) const
{
	if (x < 0 ||
		x >= boardWidth ||
		y < 0 ||
		y >= boardHeight)
		return false;
	return true;
}
