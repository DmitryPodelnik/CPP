#include "Headers.h"

void Bonus::EatenDot()
{
	Statistics::IncreaseScore(10);
}

void Bonus::EatenBigDot()
{
	Statistics::IncreaseScore(50);
}

void Bonus::EatenGhost()
{
	if (_tmp_number_energy == _number_energy)
	{
		switch (Ghost::GetAmount())
		{
		case 2:

			Statistics::IncreaseScore(400);

			break;

		case 1:

			Statistics::IncreaseScore(800);

			break;

		case 0:

			Statistics::IncreaseScore(1600);

			break;

		}
	}
	else
	{
		Statistics::IncreaseScore(200);
		_tmp_number_energy++;
	}
}

void Bonus::IncreaseEnergyNumber()
{
	_number_energy++;
}

void Bonus::CopyEnergyNumber()
{
	_tmp_number_energy = _number_energy;
}

void Bonus::SetDefaultValues()
{
	_number_energy = 1;
	_tmp_number_energy = 0;
}

size_t Bonus::GetEnergyCondition()
{
	return _number_energy;
}

size_t Bonus::_number_energy = 1;
size_t Bonus::_tmp_number_energy = 0;