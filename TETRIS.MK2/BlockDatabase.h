#pragma once

#include <vector>
#include "BlockType.h"
#include "Console.h"

class BlockDatabase
{
private:
	static BlockDatabase* instance;

	std::vector<BlockType*> blocks;

public:

	// �̱��� �ν��Ͻ� ��ȯ
	static BlockDatabase& GetInstance();

	BlockDatabase();
	~BlockDatabase();

	// ���� ��� ��� / ���� ��ȯ
	const Matrix& GetBlockMatrix(int index) const;
	const Console::Color& GetBlockColor(int index) const;

	// ����� �������� �� ��ȯ
	int GetSize() const;
	// ���� �ε��� �������� Ȯ��
	bool IsIndexValid(int index) const;

	// �� ��� ���� �߰�
	void AddNewBlock(Console::Color color, Matrix matrix);
};