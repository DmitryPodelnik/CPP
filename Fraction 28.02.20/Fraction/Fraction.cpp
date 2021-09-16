#include "Fraction.h"
#include <stdio.h>
/*
Fraction::Fraction(int numerator)
{
	SetNumerator(numerator);
	SetDenominator(1);
}
*/
Fraction::Fraction(int numerator, int denominator)
{
	SetNumerator(numerator);
	SetDenominator(denominator);
}

void Fraction::SetNumerator(int numerator)
{
	_numerator = numerator;
}
void Fraction::SetDenominator(int denominator)
{
	if (denominator != 0)
		_denominator = denominator;
	else
		_denominator = 1;
}

int Fraction::GetNumerator() const
{
	return _numerator;
}
int Fraction::GetDenominator() const
{
	return _denominator;
}


const char* Fraction::ToString() const
{
	static char str[50];
	sprintf_s(str, 50, "%d/%d", _numerator, _denominator);
	return str;
}

Fraction Fraction::Multiple(Fraction fr)
{
	Fraction res;
	res._numerator = _numerator * fr._numerator;
	res._denominator = _denominator * fr._denominator;

	return res;
}

Fraction operator* (const Fraction& fr1, const Fraction& fr2)
{
	Fraction res;
	res.SetNumerator(fr1.GetNumerator() * fr2.GetNumerator());
	res.SetDenominator(fr1.GetDenominator() * fr2.GetDenominator());
	return res;
}

Fraction operator* (const Fraction& fr1, int num)
{
	Fraction res;
	res.SetNumerator(fr1.GetNumerator() * num);
	res.SetDenominator(fr1.GetDenominator());
	return res;
}

Fraction operator* (int num, const Fraction& fr1)
{
	Fraction res;
	res.SetNumerator(fr1.GetNumerator() * num);
	res.SetDenominator(fr1.GetDenominator());
	return res;
}

Fraction Fraction::operator/ (const Fraction& fr)
{
	Fraction res;
	res._numerator = _numerator * fr._denominator;
	res._denominator = _denominator * fr._numerator;

	return res;
}

Fraction Fraction::operator/ (int num)
{
	Fraction res;
	res._numerator = _numerator;
	res._denominator = _denominator * num;
	return res;
}

Fraction operator/ (int num, const Fraction& fr1)
{
	Fraction res;
	res.SetNumerator(num * fr1.GetDenominator());
	res.SetDenominator(fr1.GetNumerator());
	return res;
}

Fraction operator/(const Fraction& fr1, const Fraction& fr2)
{
	Fraction res;
	res.SetNumerator(fr1.GetNumerator() * fr2.GetDenominator());
	res.SetDenominator(fr1.GetDenominator() * fr2.GetNumerator()); 
	return res;
}

Fraction operator/(const Fraction& fr1, int num)
{
	return Fraction();
}

Fraction operator+(const Fraction& fr1, const Fraction& fr2)
{
	Fraction res;
	res.SetNumerator(fr1.GetNumerator() * fr2.GetDenominator() + fr1.GetDenominator() * fr2.GetNumerator());
	res.SetDenominator(fr1.GetDenominator() * fr2.GetDenominator());
	return res;
}

Fraction operator+(const Fraction& fr1, int num)
{
	Fraction res;
	res.SetNumerator(fr1.GetNumerator() + (num * fr1.GetDenominator()));
	res.SetDenominator(fr1.GetDenominator());
	return res;
}

Fraction operator+(int num, const Fraction& fr1)
{
	Fraction res;
	res.SetNumerator(fr1.GetNumerator() + (num * fr1.GetDenominator()));
	res.SetDenominator(fr1.GetDenominator());
	return res;
}

Fraction operator-(const Fraction& fr1, const Fraction& fr2)
{
	Fraction res;
	res.SetNumerator(fr1.GetNumerator() * fr2.GetDenominator() - fr1.GetDenominator() * fr2.GetNumerator());
	res.SetDenominator(fr1.GetDenominator() * fr2.GetDenominator());
	return res;
}

Fraction operator-(const Fraction& fr1, int num)
{
	Fraction res;
	res.SetNumerator(fr1.GetNumerator() - (num * fr1.GetDenominator()));
	res.SetDenominator(fr1.GetDenominator());
	return res;
}

Fraction operator-(int num, const Fraction& fr1)
{
	Fraction res;
	res.SetNumerator(fr1.GetNumerator() - (num * fr1.GetDenominator()));
	res.SetDenominator(fr1.GetDenominator());
	return res;
}

Fraction Fraction::operator-()
{
	Fraction res;
	res._numerator = -_numerator;
	res._denominator = _denominator;
	return  res;
}

Fraction& Fraction::operator++ ()
{
	_numerator += _denominator;
	return *this;
}

Fraction Fraction::operator++ (int)
{
	Fraction old = *this;
	_numerator += _denominator;
	return old;
}

Fraction& Fraction::operator-- ()
{
	_numerator -= _denominator;
	return *this;
}

Fraction Fraction::operator-- (int)
{
	Fraction old = *this;
	_numerator -= _denominator;
	return old;
}

void Fraction::isBigger(Fraction fr2)
{
	Fraction fr1;
	fr1.SetNumerator(_numerator);
	fr1.SetDenominator(_denominator);

	if (fr1 > fr2)
	{
		cout << "First fraction is bigger than second";
	}
	else
	{
		cout << "First fraction is not bigger than second";
	}
}

void Fraction::isSmaller(Fraction fr2)
{
	Fraction fr1;
	fr1.SetNumerator(_numerator);
	fr1.SetDenominator(_denominator);

	if (fr1 < fr2)
	{
		cout << "First fraction is smaller than second";
	}
	else
	{
		cout << "First fraction is not smaller than second";
	}
}

void Fraction::isEqual(Fraction fr2)
{
	Fraction fr1;
	fr1.SetNumerator(_numerator);
	fr1.SetDenominator(_denominator);

	if (fr1 == fr2)
	{
		cout << "Fractions are equal";
	}
	else
	{
		cout << "Fractions are not equal";
	}
}

void Fraction::Simplification()
{
	int num;

	if (GetNumerator() > GetDenominator())
	{
		num = GetNumerator();
	}
	else
	{
		num = GetDenominator();
	}

	int counter;

	do {
		counter = 0;

		for (size_t i = 2; i <= num; i++)
		{
			if (GetNumerator() % i == 0 && GetDenominator() % i == 0)
			{
				SetNumerator(GetNumerator() / i);
				SetDenominator(GetDenominator() / i);
				counter++;
				break;
			}
		}

		if (counter == 0)
		{
			break;
		}

	} while (true);
}

bool Fraction::operator == (const Fraction& fr)
{
	return (double)_numerator / _denominator == (double)fr._numerator / fr._denominator;
}

bool Fraction::operator != (const Fraction& fr)
{
	return _numerator != fr._numerator || _denominator != fr._denominator;
}

bool Fraction::operator > (const Fraction& fr)
{
	return (double)_numerator / _denominator > (double)fr._numerator / fr._denominator;
}

bool Fraction::operator < (const Fraction& fr)
{
	return (double)_numerator / _denominator < (double)fr._numerator / fr._denominator;
}

bool Fraction::operator >= (const Fraction& fr)
{
	return (double)_numerator / _denominator >= (double)fr._numerator / fr._denominator;
}

bool Fraction::operator <= (const Fraction& fr)
{
	return (double)_numerator / _denominator <= (double)fr._numerator / fr._denominator;
}