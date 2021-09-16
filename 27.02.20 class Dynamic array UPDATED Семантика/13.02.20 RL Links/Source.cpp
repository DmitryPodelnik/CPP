#include<iostream>

using namespace std;




int main()
{
	int a = 123;
	int& ra = a;

	const int c = 10;
	const int& rc = c;

	int&& res = a + c;
	int&& rValue = 10;


	// a + c = 123;// выражение нельзя использовать слева от знака =
	res = a + c + rValue;
	rValue = 12;

	cout << res << endl;
	cout << rValue << endl;








	return 0;
}