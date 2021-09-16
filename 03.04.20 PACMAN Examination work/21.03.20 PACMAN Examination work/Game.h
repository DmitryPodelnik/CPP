#pragma once
#include "Headers.h"

class Game
{
public:

	Game();
	~Game();

	void Run();
	static void FinishTheGame();
	void ReleaseEveryGhost();

	static void SetBigDotCondition(bool cond);
	static void SetPacmanCondition(bool cond);
	static void SetKey(Keys key);
	static void IncreaseCount();

	static Keys GetKey();
	static size_t GetSpeed();
	static bool GetBigDotCondition();

private:
	
	static Field _field;
	static Keys _key;
	static size_t _count;
	static size_t _prev_count;
	static size_t _speed;
	static bool _release_check;
	static bool _is_pacman_eaten;
	static bool _is_bigdot_eaten;

	Pacman* pacman;
	StupidGhost* Inky;
	StupidGhost* Pinky;
	CleverGhost* Blinky;
	CleverGhost* Clyde;

	Direction DirectionMoving();

	void ShowPosition();
	void ShowPrivateInfo();
	void DrawEverybody();
	void MovingEverybody(bool& wall);
	void CheckForCorrectKey();
	void SetSpeed();
	static void TransitionAfterDeath();
	static void TransitionToNewLevel();
	static void SuccessfulEndGame();
	static void UnsuccessfulEndGame();
	static bool isWin();
	static bool isLose();
	void SetInitialData(bool condition = false);
	void SetDataAfterDeath();

};

