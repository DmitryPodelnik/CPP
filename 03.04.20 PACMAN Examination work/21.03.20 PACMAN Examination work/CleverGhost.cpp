#include "Headers.h"

CleverGhost::CleverGhost()
{
	_symbol = (char)1;
	_xPos = 53;
	_yPos = 16;
	_color = ForegroundColor::RED;
	_dir = Direction::LEFT;
}

CleverGhost::CleverGhost(ForegroundColor color, short y, Direction dir)
{
	SetDefaultValues(color, y, dir);
}

void CleverGhost::Moving(Character* pacman, bool& wall)
{
	if (_is_released && !_is_eaten)
	{
		if (!isWall())
		{
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

			if (isPacman(pacman))
			{
				if (Game::GetBigDotCondition() == false)
				{
					Game::SetPacmanCondition(TRUE);
				}
				else
				{
					DecreaseGhost();
					Bonus::EatenGhost();
					_is_eaten = true;
					Ghost::Clear();
					_xPos = -1;
					_yPos = -1;
				}
			}
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
			isWall(TRUE);
		}
	}
}

void CleverGhost::ReleaseGhost()
{
	if (_is_released == false)
	{
		Clear();
		_yPos = 13;
		Draw();
		_is_released = true;
	}
}

void CleverGhost::SetDefaultValues(ForegroundColor color, short y, Direction dir, bool cond)
{
	if (cond == 0)
	{
		_color = color;
		_symbol = (char)1;
		_dir = dir;
		_is_released = false;
		_xPos = 53;
		_yPos = y;
		_is_eaten = false;
		return;
	}
	if (!_is_eaten)
	{
		_color = color;
		_symbol = (char)1;
		_dir = dir;
		_is_released = false;
		_xPos = 53;
		_yPos = y;
	}
}


