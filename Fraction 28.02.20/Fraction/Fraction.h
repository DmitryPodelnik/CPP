#pragma once

#include<iostream>

using namespace std;

class Fraction
{
public:
	Fraction() = default;	
	//explicit Fraction(int numerator);
	explicit Fraction(int numerator, int denominator = 1) ;

	void SetNumerator(int numerator);
	void SetDenominator(int denominator);

	int GetNumerator() const;
	int GetDenominator() const;

	const char* ToString() const;


	Fraction Multiple(Fraction fr);

	Fraction operator/ (const Fraction& fr);
	Fraction operator/ (int num);

	bool operator == (const Fraction& fr);
	bool operator != (const Fraction& fr);	
	bool operator > (const Fraction& fr);
	bool operator < (const Fraction& fr);
	bool operator >= (const Fraction& fr);
	bool operator <= (const Fraction& fr);
	
	Fraction operator-();

	Fraction& operator++ ();//префиксный
	Fraction operator++ (int);//постфиксный

	Fraction& operator-- ();//префиксный
	Fraction operator-- (int);//постфиксный

	explicit operator int () const
	{
		return _numerator / _denominator;
	}

	explicit operator double () const
	{
		return (double)_numerator / _denominator;
	}

	void isBigger(Fraction fr2);
	void isSmaller(Fraction fr2);
	void isEqual(Fraction fr2);

	void Simplification();


private:
	int _numerator = 0; //числитель
	int _denominator = 1; //знаменатель
};

Fraction operator* (const Fraction& fr1, const Fraction& fr2);
Fraction operator* (const Fraction& fr1, int num);
Fraction operator* (int num, const Fraction& fr1);

Fraction operator/ (int num, const Fraction& fr1);
Fraction operator/ (const Fraction& fr1, const Fraction& fr2);
Fraction operator/ (const Fraction& fr1, int num);

Fraction operator+ (const Fraction& fr1, const Fraction& fr2);
Fraction operator+ (const Fraction& fr1, int num);
Fraction operator+ (int num, const Fraction& fr1);

Fraction operator- (const Fraction& fr1, const Fraction& fr2);
Fraction operator- (const Fraction& fr1, int num);
Fraction operator- (int num, const Fraction& fr1);


