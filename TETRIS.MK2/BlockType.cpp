#include "BlockType.h"

BlockType::BlockType(Console::Color color, Matrix matrix) : color(color), matrix(matrix) { }

const Console::Color& BlockType::GetColor() const
{
	return color;
}

const Matrix& BlockType::GetMatrix() const
{
	return matrix;
}