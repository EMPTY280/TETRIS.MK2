#pragma once

#include "GameBoard.h"
#include "BlockController.h"

class Game
{
private:
	// ���� ��
	GameBoard* board;
	// ���� �� ��¿� ����
	GameBoard* renderBuffer;
	// �÷��̾ �����ϴ� ��
	BlockController* bControl;

	bool gameOver = false;

	// ���� ����
	void Loop();
	// �Է� ó��
	void Input();
	// �� ������ ����
	void Update(int tick);
	// �ֱ� ������
	double prevTime = 0;
	double curtTime = 0;
	double updateDelay = 0;
	// ȭ�� ���
	const void Render();

	// ��� �ڵ� �ϰ�
	int blockDropDelay = 0;
	int blockDropTime = 1000;

	// �� ������, ��ġ�Ǹ� false ��ȯ
	bool DropBlock();

public:

	Game(const int boardWidth, const int boardHeight);
	~Game();

	void Start();
};