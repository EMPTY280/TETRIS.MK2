#include "BlockController.h"

BlockController::BlockController(GameBoard* b) : board(b)
{
	NewBlock(rand() % 7);
}

const std::pair<int, int>& BlockController::GetPosition() const
{
    return position;
}

const int BlockController::GetType() const
{
    return type;
}

bool BlockController::Move(int x, int y)
{
    position.first += x;
    position.second += y;
	
	if (IsValid())
		return true;
	else
	{
		position.first -= x;
		position.second -= y;
		return false;
	}
}

bool BlockController::Rotate(bool clockwork)
{
	for (int i = 0; i < 4; i++)
	{
		if (clockwork)
		{
			int temp = -matrix.at(i).second;
			matrix.at(i).second = matrix.at(i).first;
			matrix.at(i).first = temp;
			continue;
		}

		int temp = -matrix.at(i).first;
		matrix.at(i).first = matrix.at(i).second;
		matrix.at(i).second = temp;
	}

	if (IsValid())
		return true;
	else
	{
		for (int i = 0; i < 4; i++)
		{
			if (!clockwork)
			{
				int temp = -matrix.at(i).second;
				matrix.at(i).second = matrix.at(i).first;
				matrix.at(i).first = temp;
				continue;
			}

			int temp = -matrix.at(i).first;
			matrix.at(i).first = matrix.at(i).second;
			matrix.at(i).second = temp;
		}
		return false;
	}
}

void BlockController::NewBlock(int type)
{
	this->type = type;
	matrix = BlockDatabase::GetInstance().GetBlockMatrix(type);
	position = { 4, 0 };
}

Matrix BlockController::GetMatrix()
{
	return matrix;
}

void BlockController::Place()
{
	for (int i = 0; i < 4; i++)
	{
		int xx = position.first + matrix.at(i).first;
		int yy = position.second + matrix.at(i).second;

		board->SetData(xx, yy, type);
	}
	NewBlock(rand() % 7);
}

bool BlockController::IsValid()
{
	if (board == nullptr)
		return false;

	for (int i = 0; i < 4; i++)
	{
		int xx = position.first + matrix.at(i).first;
		int yy = position.second + matrix.at(i).second;

		if (yy < 0)
			continue;

		if (board->GetData(xx, yy) != -1 ||
			xx < 0 ||
			xx >= board->GetWidth() ||
			yy >= board->GetHeight())
			return false;
	}
	return true;
}
