#include "Headers.h"

Field::Field()
{
	CopyField();
}

void Field::PrintField()
{
	size_t y = 2;
	Console::SetCoord(40, y);

	for (size_t i = 0; i < _HEIGHT; i++)
	{
		for (size_t j = 0; j < _WIDTH; j++)
		{
			if (_field[i][j] == LUC || _field[i][j] == RUC || _field[i][j] == LDC || _field[i][j] == RDC || _field[i][j] == HL || _field[i][j] == VL)
			{
				Console::SetColor(ForegroundColor::DARKBLUE);
			}
			else if (_field[i][j] == DOT)
			{
				Console::SetColor(ForegroundColor::DARKYELLOW);
			}
			else if (_field[i][j] == BD)
			{
				Console::SetColor(ForegroundColor::YELLOW);
			}
			else
			{
				Console::SetColor(ForegroundColor::GREY);
			}

			cout << _field[i][j];
		}
		Console::SetCoord(40, ++y);
	}
	Console::SetColor(ForegroundColor::GREY);
}

void Field::SetValue(char z, short x, short y)
{
	_field[y - 2][x - 40] = z;
}

char Field::GetValue(short x, short y)
{
	return _field[y][x];
}

void Field::CopyField(size_t choice)
{
	if (choice == 0)
	{
		for (size_t i = 0; i < _HEIGHT; i++)
		{
			for (size_t j = 0; j < _WIDTH; j++)
			{
				_tmp_field[i][j] = _field[i][j];
			}
		}
	}
	else
	{
		for (size_t i = 0; i < _HEIGHT; i++)
		{
			for (size_t j = 0; j < _WIDTH; j++)
			{
				_field[i][j] = _tmp_field[i][j];
			}
		}
	}
}

const size_t Field::_HEIGHT;
const size_t Field::_WIDTH;
char Field::_tmp_field[_HEIGHT][_WIDTH];
char Field::_field[_HEIGHT][_WIDTH]
{
	{LUC, HL, HL, HL,  HL,  HL,  HL,  HL,  HL,  HL,  HL,  HL,  HL, RUC, LUC, HL,  HL,  HL,  HL,  HL,  HL,  HL,  HL,  HL,  HL,  HL,  HL, RUC},
	{VL, DOT,  DOT,  DOT,  DOT,  DOT,  DOT,  DOT,  DOT,  DOT,  DOT,  DOT,  DOT, VL, VL,  DOT,  DOT,  DOT,  DOT,  DOT,  DOT,  DOT,  DOT,  DOT,  DOT,  DOT,  DOT, VL},
	{VL, DOT, LUC, HL, HL, RUC, DOT, LUC, HL, HL, HL, RUC, DOT, VL, VL, DOT, LUC, HL, HL, HL, RUC, DOT, LUC, HL, HL, RUC, DOT, VL },
	{VL, BD, VL, ' ', ' ', VL, DOT, VL, ' ', ' ', ' ', VL, DOT, VL, VL, DOT, VL, ' ', ' ', ' ', VL, DOT, VL,' ', ' ' , VL, BD, VL},
	{VL, DOT, LDC, HL, HL, RDC, DOT, LDC, HL, HL, HL, RDC, DOT, LDC, RDC, DOT, LDC, HL, HL,HL,RDC, DOT,LDC,HL,HL,RDC,DOT,VL},
	{VL, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,VL},
	{VL, DOT, LUC, HL, HL,RUC, DOT, LUC, RUC, DOT, LUC, HL,HL,HL,HL,HL,HL,RUC, DOT,LUC,RUC,DOT,LUC,HL,HL,RUC,DOT,VL},
	{VL, DOT, LDC, HL, HL,RDC, DOT, VL, VL, DOT, LDC,HL,HL,RUC,LUC,HL,HL,RDC,DOT,VL,VL,DOT,LDC,HL,HL,RDC,DOT,VL},
	{VL, DOT, DOT, DOT, DOT, DOT, DOT, VL, VL, DOT,DOT,DOT,DOT,VL,VL,DOT,DOT,DOT,DOT,VL,VL,DOT,DOT,DOT,DOT,DOT,DOT,VL},
	{LDC, HL, HL, HL, HL, RUC, DOT, VL, LDC, HL,HL,RUC,' ',VL,VL,' ',LUC, HL,HL,RDC,VL,DOT,LUC, HL,HL,HL,HL,RDC},
	{' ', ' ', ' ', ' ', ' ', VL, DOT, VL,LUC,HL,HL,RDC,' ',LDC,RDC,' ',LDC, HL,HL,RUC,VL,DOT,VL,' ',' ',' ',' ',' '},
	{' ', ' ', ' ', ' ', ' ', VL, DOT, VL,VL,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',VL,VL,DOT,VL,' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',VL,DOT,VL,VL,' ',LUC,HL,HL,'-','-',HL,HL,RUC,' ',VL,VL,DOT,VL,' ',' ',' ',' ',' '},
	{HL,HL,HL,HL,HL,RDC,DOT,LDC,RDC,' ',VL,' ',' ',' ',' ',' ',' ',VL,' ',LDC,RDC,DOT,LDC,HL,HL,HL,HL,HL},
	{' ',' ',' ',' ',' ',' ',DOT, ' ',' ', ' ',VL,' ',' ',' ',' ',' ',' ',VL, ' ',' ',' ',DOT, ' ',' ',' ',' ',' ', ' '},
	{HL,HL,HL,HL,HL,RUC,DOT, LUC,RUC, ' ',VL,' ',' ',' ',' ',' ',' ',VL, ' ',LUC,RUC,DOT, LUC,HL,HL,HL,HL,HL},
	{' ',' ',' ',' ',' ',VL,DOT,VL,VL,' ',LDC,HL,HL,HL,HL,HL,HL,RDC,' ',VL,VL,DOT,VL,' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',VL,DOT,VL,VL, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', VL, VL, DOT, VL, ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', VL, DOT, VL, VL, ' ', LUC, HL, HL, HL, HL, HL, HL, RUC, ' ', VL, VL, DOT, VL, ' ', ' ', ' ', ' ', ' '},
	{LUC,HL,HL,HL, HL,RDC,DOT, LDC,RDC,' ',LDC,HL,HL,RUC,LUC,HL,HL,RDC, ' ',LDC,RDC,DOT,LDC,HL,HL,HL,HL, RUC},
	{VL, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, VL, VL, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, VL},
	{VL, DOT, LUC, HL,HL,RUC,DOT,LUC,HL,HL,HL,RUC, DOT,VL,VL,DOT,LUC,HL,HL,HL,RUC,DOT,LUC,HL,HL,RUC,DOT,VL},
	{VL, DOT,LDC,HL,RUC,VL,DOT,LDC,HL,HL,HL,RDC,DOT,LDC,RDC,DOT,LDC,HL,HL,HL,RDC,DOT,VL,LUC,HL,RDC,DOT,VL},
	{VL,BD,DOT,DOT,VL,VL,DOT,DOT,DOT,DOT,DOT,DOT,DOT,' ',' ',DOT,DOT,DOT,DOT,DOT,DOT,DOT,VL,VL,DOT,DOT, BD,VL},
	{LDC,HL,RUC,DOT,VL,VL,DOT,LUC,RUC,DOT,LUC,HL,HL,HL,HL,HL,HL,RUC,DOT,LUC,RUC,DOT,VL,VL,DOT,LUC,HL,RDC},
	{LUC,HL,RDC,DOT,LDC,RDC,DOT,VL,VL,DOT, LDC,HL,HL,RUC,LUC,HL,HL,RDC,DOT,VL,VL,DOT,LDC,RDC,DOT,LDC,HL,RUC},
	{VL,DOT,DOT,DOT,DOT,DOT,DOT,VL,VL,DOT,DOT,DOT,DOT,VL,VL,DOT,DOT,DOT,DOT,VL,VL,DOT,DOT,DOT,DOT,DOT,DOT,VL},
	{VL,DOT,LUC,HL,HL,HL,HL,RDC,LDC,HL,HL,RUC,DOT,VL,VL,DOT,LUC,HL,HL,RDC,LDC,HL,HL,HL,HL,RUC,DOT,VL},
	{VL,DOT,LDC,HL,HL,HL,HL,HL,HL,HL,HL,RDC,DOT,LDC,RDC,DOT,LDC,HL,HL,HL,HL,HL,HL,HL,HL,RDC,DOT,VL},
	{VL,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,VL},
	{LDC,HL,HL,HL,HL,HL,HL,HL,HL,HL,HL,HL,HL,HL,HL,HL,HL,HL,HL,HL,HL,HL,HL,HL,HL,HL,HL,RDC}
};
