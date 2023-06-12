#pragma once

#include "GameBoard.h"

class Game
{
private:
	// ���� ��
	GameBoard* board;
	// ���� �� ��¿� ����
	GameBoard* renderBuffer;

	// ���� ����
	bool Loop();

	// �Է� ó��
	void Input();

	// �� ������ ����
	void Update();

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

public:

	Game(const int boardWidth, const int boardHeight, const int fixUdtMS);
	~Game();

	void Start();
};