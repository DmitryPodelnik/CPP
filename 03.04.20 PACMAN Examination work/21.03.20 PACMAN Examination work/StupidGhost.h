#pragma once
#include "Headers.h"

class StupidGhost : public Ghost
{
public:

	StupidGhost();
	StupidGhost(ForegroundColor color, short y = 16, Direction dir = Direction::RIGHT);

	virtual void Moving(Character* pacman, bool& wall) override;
	virtual void ReleaseGhost() override;

	void SetDefaultValues(ForegroundColor color, short y, Direction dir = Direction::RIGHT, bool cond = 0);

	


private:





};

