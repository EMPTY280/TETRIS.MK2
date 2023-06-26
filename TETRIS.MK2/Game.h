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

	// ���� ����
	bool Loop();
	// �Է� ó��
	void Input();
	// �� ������ ����
	void Update(int tick);
	// ���� �ֱ� ����
	void FixedUpdate();
	// FIXED UPDATE �ֱ�
	const int FIXED_UPDATE_MS;
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

	Game(const int boardWidth, const int boardHeight, const int fixUdtMS);
	~Game();

	void Start();
};