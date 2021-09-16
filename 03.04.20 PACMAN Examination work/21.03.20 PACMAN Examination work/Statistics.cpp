#include "Headers.h"

void Statistics::SetDefaultValues(size_t level, size_t lives)
{
	_level = level;
	_lives = lives;
	_score = 0;
}

void Statistics::IncreaseLevel()
{
	if (_level <= 10)
	{
		_level++;
	}
}

void Statistics::IncreaseLives()
{
	if (_lives < 5)
	{
		_lives++;
	}
}

void Statistics::IncreaseScore(size_t points)
{
	_score += points;
}

void Statistics::DecreaseLives()
{
	if (_lives > 0)
	{
		_lives--;
	}
}

void Statistics::SetColorForLevel()
{
	if (_level <= 3)
	{
		Console::SetColor(ForegroundColor::GREEN);
	}
	else if (_level <= 6)
	{
		Console::SetColor(ForegroundColor::MAGENTA);
	}
	else
	{
		Console::SetColor(ForegroundColor::RED);
	}
}

void Statistics::ShowLevel()
{
	Console::SetColor(ForegroundColor::GREY);
	Console::SetCoord(29, 16);
	cout << "Level: ";
	SetColorForLevel();
	cout << Statistics::GetLevel();
	Console::SetColor(ForegroundColor::GREY);
}

void Statistics::ShowLives()
{
	Console::SetColor(ForegroundColor::GREY);
	Console::SetCoord(71, 16);
	cout << "Lives: ";

	Console::SetColor(ForegroundColor::RED);
	for (size_t i = 0; i < Statistics::GetLives(); i++)
	{
		if (i < Statistics::GetLives())
		{
			cout << (char)LIVE;
		}
		else
		{
			cout << ' ';
		}
	}
	Console::SetColor(ForegroundColor::GREY);
}

void Statistics::ShowScore()
{
	Console::SetColor(ForegroundColor::GREY);
	Console::SetCoord(45, 34);
	cout << "Your score: ";

	if (_score <= 1100)
	{
		Console::SetColor(ForegroundColor::GREEN);
	}
	else if (_score <= 2200)
	{
		Console::SetColor(ForegroundColor::MAGENTA);
	}
	else
	{
		Console::SetColor(ForegroundColor::RED);
	}

	cout << Statistics::GetScore();
}

void Statistics::ShowStatistic()
{
	Statistics::ShowLevel();
	Statistics::ShowLives();
	Statistics::ShowScore();
}

size_t Statistics::_level = 1;
size_t Statistics::_lives = 3;
size_t Statistics::_score = 0;