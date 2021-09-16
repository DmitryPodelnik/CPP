#pragma once
#include "Headers.h"

class Field
{
public:

	Field();

	static void PrintField();
	
	static void SetValue(char z, short x, short y);

	static char GetValue(short x, short y);

	static const size_t _HEIGHT = 31;
	static const size_t _WIDTH = 28;

	static void CopyField(size_t choice = 0);
	
private:

	static char _field[_HEIGHT][_WIDTH];
	static char _tmp_field[_HEIGHT][_WIDTH];

};

