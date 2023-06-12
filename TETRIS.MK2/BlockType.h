#pragma once

#include <vector>
#include "Console.h"

using namespace std;

class BlockType
{
private:
	Console::Color color;
	vector<pair<int, int>> matrix;

public:
	BlockType(Console::Color color, vector<pair<int, int>> matrix);
	const Console::Color& GetColor() const;
	const vector<pair<int, int>>& GetMatrix() const;
};