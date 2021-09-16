#include "Headers.h"

Pacman::Pacman()
{
	SetDefaultValues();
}

void Pacman::SetDefaultValues()
{
	_symbol = (char)2;
	_xPos = 53;
	_yPos = 25;
	_color = ForegroundColor::YELLOW;
}

void Pacman::MoveUp()
{
	Clear();
	_yPos--;
	Draw();
}

void Pacman::MoveDown()
{
	Clear();
	_yPos++;
	Draw();
}

void Pacman::MoveLeft()
{
	Clear();
	_xPos--;
	Draw();
}

void Pacman::MoveRight()
{
	Clear();
	_xPos++;
	Draw();
}

void Pacman::Moving(Character* pacman, bool& wall)
{
	if (!isWall())
	{
		if (isDot())
		{
			Bonus::EatenDot();
			Game::IncreaseCount();
		}
		else if (isBigDot())
		{
			Game::SetBigDotCondition(TRUE);
			Timer::SetTmpMin();
			Bonus::EatenBigDot();
			Game::IncreaseCount();
		}

		switch (_dir)
		{
		case Direction::UP:

			MoveUp();

			break;

		case Direction::DOWN:

			MoveDown();

			break;

		case Direction::RIGHT:

			MoveRight();

			break;

		case Direction::LEFT:

			MoveLeft();

			break;
		}
		Field::SetValue(SPACE_, _xPos, _yPos);
	}
	else if (_xPos == 67 && _yPos == 16 && _dir == Direction::RIGHT)
	{
		MoveRight();
		Sleep(Game::GetSpeed());
		Clear();
		_xPos = 40;
	}
	else if (_xPos == 40 && _yPos == 16 && _dir == Direction::LEFT)
	{
		MoveLeft();
		Sleep(Game::GetSpeed());
		Clear();
		_xPos = 67;
	}
	else
	{
		wall = true;
	}
}

bool Pacman::isWall(bool condition)
{
	switch (Game::GetKey())
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

bool Pacman::isDot()
{
	switch (Game::GetKey())
	{
	case Keys::UP:

		if (CheckForDot(GetXPos(), GetYPos() - 1))
		{
			return true;
		}
		else
		{
			return false;
		}

	case Keys::DOWN:

		if (CheckForDot(GetXPos(), GetYPos() + 1))
		{
			return true;
		}
		else
		{
			return false;
		}

	case Keys::LEFT:

		if (CheckForDot(GetXPos() - 1, GetYPos()))
		{
			return true;
		}
		else
		{
			return false;
		}

	case Keys::RIGHT:

		if (CheckForDot(GetXPos() + 1, GetYPos()))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool Pacman::isBigDot()
{
	switch (Game::GetKey())
	{
	case Keys::UP:

		if (CheckForBigDot(GetXPos(), GetYPos() - 1))
		{
			return true;
		}
		else
		{
			return false;
		}

	case Keys::DOWN:

		if (CheckForBigDot(GetXPos(), GetYPos() + 1))
		{
			return true;
		}
		else
		{
			return false;
		}

	case Keys::LEFT:

		if (CheckForBigDot(GetXPos() - 1, GetYPos()))
		{
			return true;
		}
		else
		{
			return false;
		}

	case Keys::RIGHT:

		if (CheckForBigDot(GetXPos() + 1, GetYPos()))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}



