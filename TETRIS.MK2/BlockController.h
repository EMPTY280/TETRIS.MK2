#pragma once

#include <utility>

#include "BlockDatabase.h"
#include "BlockType.h"
#include "GameBoard.h"

class BlockController
{
private:
	std::pair<int, int> position = { 4, 0 };
	Matrix matrix;
	int type = 0;

	GameBoard* board = nullptr;

public:
	BlockController(GameBoard* b);

	const std::pair<int, int>& GetPosition() const;
	const int GetType() const;

	bool Move(int x, int y);
	bool Rotate(bool clockwork);
	void Place();

	// 생성 시 충돌이면 = 게임 오버이면 false 반환
	bool NewBlock(int type);

	Matrix GetMatrix();

	bool IsValid();
};