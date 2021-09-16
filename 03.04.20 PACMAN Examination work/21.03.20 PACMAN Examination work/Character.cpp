#include "Headers.h"

size_t Character::GetAM()
{
	if (_activeMesh > 1000)
	{
		return 999;
	}
	return _activeMesh;
}

Keys Character::GetDirection()
{
	switch (_dir)
	{
	case Direction::UP:

		return Keys::UP;

	case Direction::DOWN:

		return Keys::DOWN;

	case Direction::LEFT:

		return Keys::LEFT;

	case Direction::RIGHT:

		return Keys::RIGHT;
	}
}

void Character::SetPos(short x, short y)
{
	_xPos = x;
	_yPos = y;
}

void Character::SetDirection(Direction dir)
{
	if (dir == Direction::UP || dir == Direction::DOWN || dir == Direction::LEFT || dir == Direction::RIGHT)
	{
		_dir = dir;
	}
}

void Character::Clear()
{
	Console::SetColor(_color);
	Console::SetCoord(_xPos, _yPos);
	cout << " ";
}

void Character::CalculatePos()
{
	_activeMesh = (Field::_WIDTH * (_yPos - 2)) + (_xPos - 40);
}

void Character::Draw()
{
	Console::SetColor(_color);
	Console::SetCoord(_xPos, _yPos);
	cout << _symbol;
}

bool Character::CheckForWalls(short x, short y)
{
	if (Field::GetValue(x - 40, y - 2) != LUC && Field::GetValue(x - 40, y - 2) != RUC && Field::GetValue(x - 40, y - 2) != LDC && Field::GetValue(x - 40, y - 2) != RDC && Field::GetValue(x - 40, y - 2) != HL && Field::GetValue(x - 40, y - 2) != VL && Field::GetValue(x - 40, y - 2) != '-')
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Character::CheckForDot(short x, short y)
{
	if (Field::GetValue(x - 40, y - 2) == DOT)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Character::CheckForBigDot(short x, short y)
{
	if (Field::GetValue(x - 40, y - 2) == BD)
	{
		return true;
	}
	else
	{
		return false;
	}
}


