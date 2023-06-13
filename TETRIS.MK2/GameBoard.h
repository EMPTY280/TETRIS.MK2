#pragma once

class GameBoard
{
private:
	// 각 위치마다의 블록 타입 인덱스
	int* board;

	int boardWidth, boardHeight;

public:
	GameBoard(const int boardWidth, const int boardHeight);
	~GameBoard();

	void Copy(const GameBoard& target);

	// 각각 너비, 높이, 그 위치의 정보 반환
	const int& GetWidth() const;
	const int& GetHeight() const;
	const int& GetData(int x, int y) const;

	void SetData(int x, int y, int data);

	// 유효한 좌표인가?
	const bool IsValidCoord(int x, int y) const;
};