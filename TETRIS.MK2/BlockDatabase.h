#pragma once

#include <vector>
#include "BlockType.h"
#include "Console.h"

class BlockDatabase
{
private:
	static BlockDatabase* instance;

	std::vector<BlockType*> blocks;

	BlockDatabase();
public:

	// 싱글톤 인스턴스 반환
	static BlockDatabase& GetInstance();
	~BlockDatabase();

	// 각각 블록 행렬 / 색상 반환
	const Matrix& GetBlockMatrix(int index) const;
	const Console::Color& GetBlockColor(int index) const;

	// 저장된 데이터의 수 반환
	int GetSize() const;
	// 옳은 인덱스 접근인지 확인
	bool IsIndexValid(int index) const;

	// 새 블록 유형 추가
	void AddNewBlock(Console::Color color, Matrix matrix);
};