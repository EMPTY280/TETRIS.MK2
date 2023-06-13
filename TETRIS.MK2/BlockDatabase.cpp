#include "BlockDatabase.h"

BlockDatabase* BlockDatabase::instance = nullptr;

BlockDatabase& BlockDatabase::GetInstance()
{
	if (!instance)
		instance = new BlockDatabase();

	return *instance;
}

BlockDatabase::BlockDatabase()
{
	AddNewBlock(Console::Color::SKYBLUE, { {0, 0}, {0, -1}, {0, -2}, {0, 1} });		// I
	AddNewBlock(Console::Color::WHITE, { {0, 0}, {0, -1}, {1, -1}, {1, 0} });		// O
	AddNewBlock(Console::Color::VIOLET, { {0, 0}, {-1, 0}, {1, 0}, {0, 1} });		// T
	AddNewBlock(Console::Color::GREEN, { {0, 0}, {1, 0}, {0, 1}, {-1, 1} });		// S
	AddNewBlock(Console::Color::RED, { {0, 0}, {-1, 0}, {0, 1}, {1, 1} });			// Z
	AddNewBlock(Console::Color::YELLOW, { { 0, 0 },  {0, -1}, {0, 1}, {1, 1} });	// L 
	AddNewBlock(Console::Color::BLUE, { {0, 0}, {0, -1}, {0, 1}, {-1, 1} });		// J
}

BlockDatabase::~BlockDatabase()
{
	for (auto ele : blocks)
	{
		delete ele;
	}
}

const Matrix& BlockDatabase::GetBlockMatrix(int index) const
{
	if (!IsIndexValid(index))
		return Matrix();

	return blocks.at(index)->GetMatrix();
}

const Console::Color& BlockDatabase::GetBlockColor(int index) const
{
	if (!IsIndexValid(index))
		return Console::Color::BLACK;

	return blocks.at(index)->GetColor();
}

int BlockDatabase::GetSize() const
{
	return blocks.size();
}

bool BlockDatabase::IsIndexValid(int index) const
{
	if (index < 0 || index >= GetSize())
		return false;
	return true;
}

void BlockDatabase::AddNewBlock(Console::Color color, Matrix matrix)
{
	BlockType* newBlock = new BlockType(color, matrix);

	blocks.push_back(newBlock);
}