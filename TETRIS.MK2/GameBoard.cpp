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
		throw 1;

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
		throw 2;

	return board[boardWidth * y + x];
}

void GameBoard::SetData(int x, int y, int data)
{
	if (!IsValidCoord(x, y))
		throw 2;

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
