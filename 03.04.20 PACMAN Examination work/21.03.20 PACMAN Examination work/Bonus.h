#pragma once
#include "Headers.h"

class Bonus
{
public:

	static void EatenDot();
	static void EatenBigDot();
	static void EatenGhost();

	static void IncreaseEnergyNumber();
	static void CopyEnergyNumber();
	static void SetDefaultValues();

	static size_t GetEnergyCondition();

private:

	static size_t _number_energy;
	static size_t _tmp_number_energy;

};

