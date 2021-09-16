#include <iostream>
#include "Fraction.h"
using namespace std;

void foo(Fraction fr)
{
	cout << fr.ToString() << endl;
}

void bar(int i)
{
	cout << i << endl;
}


int main()
{
	/*
	Fraction fr1(1, 2);	 
	cout << "fr1: " << fr1.ToString() << endl;

	Fraction fr2(2, 5);
	cout << "fr2: " << fr2.ToString() << endl;
	
	Fraction fr3 = fr1.Multiple(fr2);
	cout << "fr1.Multiple(fr2): " << fr3.ToString() << endl;

#pragma region global functions
	fr3 = fr1 * fr2; //operator*(fr1, fr2)
	cout << "fr1 * fr2 = " << fr3.ToString() << endl;

	fr3 = fr1 * 2; //operator*(fr1, 2)
	cout << "fr1 * 2 = " << fr3.ToString() << endl;	

	fr3 = 2 * fr1; //operator*(2, fr1)
	cout << "2 * fr2 = " << fr3.ToString() << endl;	
#pragma endregion

#pragma region methods
	fr3 = fr1 / fr2; // fr1.operator/(fr2)
	cout << "fr1 / fr2 = " << fr3.ToString() << endl;

	fr3 = fr1 / 2; //fr1.operator/(2)
	cout << "fr1 / 2 = " << fr3.ToString() << endl;
#pragma endregion

#pragma region only global function

	fr3 = 2 / fr1; //operator/(2, fr1)
	cout << "2 / fr1 = " << fr3.ToString() << endl;

#pragma endregion

#pragma region operators
	if (fr1 == fr2)
		cout << "fr1 == fr2" << endl;
	else
		cout << "fr1 != fr2" << endl;

	fr3 = -fr1; // fr1.operator-()
	cout << "-fr1  = " << fr3.ToString() << endl;

	cout << "++fr1: " << (++fr1).ToString() << endl; // fr1.operator++();
	cout << "fr1++: " << fr1++.ToString() << endl; // fr1.operator++(0);
	cout << "fr1  : " << fr1.ToString() << endl;
#pragma endregion
*/

	Fraction fr = (Fraction)2; // 2 / 1
	cout << fr.ToString() << endl;

	foo((Fraction)3);

	Fraction fr2;
	fr2 = (Fraction)4;

	int a = (int)fr;
	bar((int)fr);

	Fraction fr3;
	fr3.SetNumerator(3);
	fr3.SetDenominator(5);


	Fraction fr4;
	fr4.SetNumerator(6);
	fr4.SetDenominator(10);

	Fraction fr5;
	fr5.SetNumerator(3);
	fr5.SetDenominator(7);

	Fraction fr6;
	fr6.SetNumerator(6);
	fr6.SetDenominator(14);
	
	fr5.isEqual(fr6);
	cout << endl << endl;
	fr5.isBigger(fr6);
	cout << endl << endl;
	fr5.isSmaller(fr6);
	cout << endl << endl;

	Fraction fr7;
	fr7.SetNumerator(2);
	fr7.SetDenominator(7);

	Fraction fr8;
	fr8.SetNumerator(3);
	fr8.SetDenominator(5);
	foo(fr7 / fr8);
	foo(fr7 * fr8);
	foo(fr7 + fr8);
	foo(fr7 - fr8);
	foo(++fr7);
	foo(--fr7);

	Fraction fr9;
	fr9.SetNumerator(24);
	fr9.SetDenominator(50);
	fr9.Simplification();
	foo(fr9);

}
