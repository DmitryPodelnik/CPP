#pragma once
#include "Headers.h"

class CleverGhost : public Ghost
{
public:

	CleverGhost();
	CleverGhost(ForegroundColor color, short y = 16, Direction dir = Direction::LEFT);

	virtual void Moving(Character* pacman, bool& wall) override;
	virtual void ReleaseGhost() override;

	void SetDefaultValues(ForegroundColor color, short y, Direction dir = Direction::LEFT, bool cond = 0);

private:



};

