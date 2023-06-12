#pragma once

#include <vector>
#include "BlockType.h"
#include "Console.h"

class BlockDatabase
{
private:
	static BlockDatabase* instance;

	vector<BlockType*> blocks;
public:
	BlockDatabase();
	~BlockDatabase();

	// �̱��� �ν��Ͻ� ȣ��
	static BlockDatabase& Data();

	// ���� ��� ��� / ���� ��ȯ
	const vector<pair<int, int>>& GetBlockMatrix(int index) const;
	const Console::Color& GetBlockColor(int index) const;

	// ����� �������� �� ��ȯ
	int GetSize() const;
	// ���� �ε��� �������� Ȯ��
	bool IsIndexValid(int index) const;

	// �� ��� ���� �߰�
	void AddNewBlock(Console::Color color, vector<pair<int, int>> matrix);
};