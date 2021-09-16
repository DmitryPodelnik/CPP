#pragma once
#include "Headers.h"

class Ghost : public Character
{
public:

	virtual void ReleaseGhost() = 0;

	static void SetDefaultValues();

	static size_t GetAmount();
	virtual void Clear() override;
	virtual void Draw() override;
	virtual bool isWall(bool condition = false) override;
	virtual bool isDot() override;
	virtual bool isBigDot() override;
	bool isPacman(Character* pacman);
	bool isPacmanNext(Character* pacman);

	virtual void MoveUp() override;
	virtual void MoveDown() override;
	virtual void MoveLeft() override;
	virtual void MoveRight() override;

protected:

	static void DecreaseGhost();

	bool _is_released = false;
	bool _is_eaten = false;

private:

	static size_t _amount;
};

