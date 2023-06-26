#pragma once

#include "GameBoard.h"
#include "BlockController.h"

class Game
{
private:
	// 게임 판
	GameBoard* board;
	// 게임 판 출력용 버퍼
	GameBoard* renderBuffer;
	// 플레이어가 조작하는 블럭
	BlockController* bControl;

	bool gameOver = false;

	// 게임 루프
	void Loop();
	// 입력 처리
	void Input();
	// 매 프레임 연산
	void Update(int tick);
	// 주기 판정용
	double prevTime = 0;
	double curtTime = 0;
	double updateDelay = 0;
	// 화면 출력
	const void Render();

	// 블록 자동 하강
	int blockDropDelay = 0;
	int blockDropTime = 1000;

	// 블럭 내리기, 설치되면 false 반환
	bool DropBlock();

public:

	Game(const int boardWidth, const int boardHeight);
	~Game();

	void Start();
};