#include "BlockType.h"

BlockType::BlockType(Console::Color color, vector<pair<int, int>> matrix) : color(color), matrix(matrix) { }

const Console::Color& BlockType::GetColor() const
{
	return color;
}

const vector<pair<int, int>>& BlockType::GetMatrix() const
{
	return matrix;
}
