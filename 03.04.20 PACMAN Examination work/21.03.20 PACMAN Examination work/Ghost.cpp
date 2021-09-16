#include "Headers.h"

size_t Ghost::_amount = 4;

void Ghost::DecreaseGhost()
{
	if (_amount > 0)
	{
		_amount--;
	}
}

void Ghost::SetDefaultValues()
{
	_amount = 4;
}

size_t Ghost::GetAmount()
{
	return _amount;
}

void Ghost::MoveUp()
{
	Clear();
	_yPos--;
	Draw();
}

void Ghost::MoveDown()
{
	Clear();
	_yPos++;
	Draw();
}

void Ghost::MoveLeft()
{
	Clear();
	_xPos--;
	Draw();
}

void Ghost::MoveRight()
{
	Clear();
	_xPos++;
	Draw();
}

void Ghost::Clear()
{
	Console::SetColor(_color);
	Console::SetCoord(_xPos, _yPos);
	if (isDot())
	{
		Console::SetColor(ForegroundColor::DARKYELLOW);
		cout << DOT;
	}
	else if (isBigDot())
	{
		Console::SetColor(ForegroundColor::YELLOW);
		cout << BD;
	}
	else
	{
		cout << " ";
	}
}

void Ghost::Draw()
{
	if (!_is_eaten)
	{
		if (Game::GetBigDotCondition())
		{
			Console::SetColor(ForegroundColor::BLUE);
		}
		else
		{
			Console::SetColor(_color);
		}
		Console::SetCoord(_xPos, _yPos);
		cout << _symbol;
	}
}

bool Ghost::isPacmanNext(Character* pacman)
{
	switch (GetDirection())
	{
	case Keys::UP:

		if (_xPos == pacman->GetXPos() && _yPos - 1 == pacman->GetYPos())
		{
			return true;
		}
		else
		{
			return false;
		}

	case Keys::DOWN:

		if (_xPos == pacman->GetXPos() && _yPos + 1 == pacman->GetYPos())
		{
			return true;
		}
		else
		{
			return false;
		}

	case Keys::LEFT:

		if (_xPos + 1 == pacman->GetXPos() && _yPos == pacman->GetYPos())
		{
			return true;
		}
		else
		{
			return false;
		}

	case Keys::RIGHT:

		if (_xPos - 1 == pacman->GetXPos() && _yPos == pacman->GetYPos())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool Ghost::isPacman(Character* pacman)
{
	if (_xPos == pacman->GetXPos() && _yPos == pacman->GetYPos() || isPacmanNext(pacman))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Ghost::isWall(bool condition)
{
	if (condition == false)
	{
		switch (GetDirection())
		{
		case Keys::UP:

			if (!CheckForWalls(GetXPos(), GetYPos() - 1))
			{
				return false;
			}
			else
			{
				return true;
			}

		case Keys::DOWN:

			if (!CheckForWalls(GetXPos(), GetYPos() + 1))
			{
				return false;
			}
			else
			{
				return true;
			}

		case Keys::LEFT:

			if (!CheckForWalls(GetXPos() - 1, GetYPos()))
			{
				return false;
			}
			else
			{
				return true;
			}

		case Keys::RIGHT:

			if (!CheckForWalls(GetXPos() + 1, GetYPos()))
			{
				return false;
			}
			else
			{
				return true;
			}
		case Keys::ESC:

			Game::FinishTheGame();
		}
	}
	else
	{
		size_t random = rand() % 2 + 1;
		switch (GetDirection())
		{
		case Keys::UP:
		case Keys::DOWN:

			switch (random)
			{
			case 1:

				if (!CheckForWalls(GetXPos() - 1, GetYPos()))
				{
					_dir = Direction::LEFT;
				}

				return true;

			case 2:

				if (!CheckForWalls(GetXPos() + 1, GetYPos()))
				{
					_dir = Direction::RIGHT;
				}

				return true;
			}

		case Keys::LEFT:
		case Keys::RIGHT:

			switch (random)
			{
			case 1:

				if (!CheckForWalls(GetXPos(), GetYPos() - 1))
				{
					_dir = Direction::UP;
				}

				return true;

			case 2:

				if (!CheckForWalls(GetXPos(), GetYPos() + 1))
				{
					_dir = Direction::DOWN;
				}

				return true;
			}
		}
	}
}

bool Ghost::isDot()
{
	if (CheckForDot(GetXPos(), GetYPos()))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Ghost::isBigDot()
{
	if (CheckForBigDot(GetXPos(), GetYPos()))
	{
		return true;
	}
	else
	{
		return false;
	}
}
