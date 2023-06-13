#pragma once

#include <vector>
#include "Console.h"

typedef std::vector<std::pair<int, int>> Matrix;

class BlockType
{
private:
	Console::Color color;
	Matrix matrix;

public:
	BlockType(Console::Color color, Matrix matrix);
	const Console::Color& GetColor() const;
	const Matrix& GetMatrix() const;
};