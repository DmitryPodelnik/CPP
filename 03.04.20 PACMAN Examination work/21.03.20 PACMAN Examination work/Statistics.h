#pragma once
#include "Headers.h"

class Statistics
{
public:

	static void SetDefaultValues(size_t level = 1, size_t lives = 3);

	static size_t GetLevel() { return _level; }
	static size_t GetLives() { return _lives; }
	static size_t GetScore() { return _score; }

	static void IncreaseLevel();
	static void IncreaseLives();
	static void IncreaseScore(size_t points);

	static void DecreaseLives();

	static void SetColorForLevel();

	static void ShowLevel();
	static void ShowLives();
	static void ShowScore();
	static void ShowStatistic();

private:

	static size_t _level;
	static size_t _lives;
	static size_t _score;

};

