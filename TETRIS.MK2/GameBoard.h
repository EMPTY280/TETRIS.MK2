#pragma once

class GameBoard
{
private:
	// �� ��ġ������ ��� Ÿ�� �ε���
	int* board;

	int boardWidth, boardHeight;

public:
	GameBoard(const int boardWidth, const int boardHeight);
	~GameBoard();

	void Copy(const GameBoard& target);

	// ���� �ʺ�, ����, �� ��ġ�� ���� ��ȯ
	const int& GetWidth() const;
	const int& GetHeight() const;
	const int& GetData(int x, int y) const;

	void SetData(int x, int y, int data);

	// ��ȿ�� ��ǥ�ΰ�?
	const bool IsValidCoord(int x, int y) const;
};