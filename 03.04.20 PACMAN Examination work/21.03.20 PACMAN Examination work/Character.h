#pragma once
#include "Headers.h"

class Character
{
public:

	virtual void Moving(Character* pacman, bool& wall) = 0;
	virtual void MoveUp() = 0;
	virtual void MoveDown() = 0;
	virtual void MoveLeft() = 0;
	virtual void MoveRight() = 0;

	short GetXPos() { return _xPos; }
	short GetYPos() { return _yPos; }
	size_t GetAM();
	Keys GetDirection();

	void SetPos(short x, short y);
	void SetDirection(Direction dir);

	virtual void Draw();
	virtual void Clear();
	void CalculatePos();

	bool CheckForWalls(short x, short y);
	virtual bool isWall(bool condition = false) = 0;
	virtual bool isDot() = 0;
	virtual bool isBigDot() = 0;
	bool CheckForDot(short x, short y);
	bool CheckForBigDot(short x, short y);


protected:

	char _symbol;
	short _xPos;
	short _yPos;
	ForegroundColor _color;
	size_t _activeMesh;
	Direction _dir;
};

