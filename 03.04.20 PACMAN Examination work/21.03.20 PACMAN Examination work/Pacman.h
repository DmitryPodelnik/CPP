#pragma once
#include "Headers.h"

class Pacman : public Character
{
public:

	Pacman();

	void SetDefaultValues();

	virtual void Moving(Character* pacman, bool& wall) override;
	virtual bool isWall(bool condition = false) override;
	virtual bool isDot() override;
	virtual bool isBigDot() override;

	virtual void MoveUp() override;
	virtual void MoveDown() override;
	virtual void MoveLeft() override;
	virtual void MoveRight() override;

private:





};

