#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <iterator>
#include <iomanip>

using namespace std;

int main()
{
	srand(time(NULL));


	///1
	/*
	string str;
	getline(cin, str);
	
	reverse_iterator<string::iterator> r = str.rbegin();

	for (; r != str.rend(); r++)
	{
		cout << *r;
	}
	cout << endl << endl;
	*/

	///2
	/*
	string str;
	getline(cin, str);

	string str2;
	string::iterator it = str.begin();
	
	for (; it != str.begin() + 10; it++)
	{
		str2 += *it;
	}
	cout << str2 << endl << endl;
	*/

	///3
	/*
	string str;
	getline(cin, str);
	
	size_t position;
	string str3;
	getline(cin, str3);
	cin >> position;
	
	string::iterator iter = str.begin();

	advance(iter, position);

	str.insert(iter, str3.begin(), str3.begin() + str3.size());
	cout << str << endl << endl;
	*/

	///4
	/*
	string str;
	getline(cin, str);

	string::iterator it1 = str.begin() + 2;
	string::iterator it2 = str.begin() + 7;

	str.erase(it1, it2);

	cout << str << endl;
	*/

	///5
	/*
	vector<int> vector1(10);

	vector<int>::iterator it = vector1.begin();
    
	for (; it != vector1.end(); it++)
	{
		*it = rand() % 10;
	}

	for (it = vector1.begin(); it != vector1.end(); it++)
	{
		cout << *it << "\t";
	}
	cout << endl << endl;

	vector<int> vector2(10);

	for (it = vector2.begin(); it != vector2.end(); it++)
	{
		*it = rand() % 11 + 10;
	}

	for (it = vector2.begin(); it != vector2.end(); it++)
	{
		cout << *it << "\t";
	}
	cout << endl << endl;

	vector<int> vector3(10);

	size_t i = 0;
	for (it = vector3.begin(); it != vector3.end(); it++, i++)
	{
		if (i < 5)
		{
			*it = vector1[i];
		}
		else
		{
			*it = vector2[i];
		}
	}

	for (it = vector3.begin(); it != vector3.end(); it++)
	{
		cout << *it << "\t";
	}
	cout << endl << endl;
	*/

    ///6
    /*
	const size_t SIZE = 10;

	vector< vector <int> > vector1(SIZE, vector<int>(SIZE));
	size_t i, j;

	for (i = 1; i < SIZE; i++)
	{
		for (j = 1; j < SIZE; j++)
		{
			vector1[i][j] = i * j;
		}
	}

	for (i = 1; i < SIZE; i++)
	{
		for (int j = 1; j < SIZE; j++)
		{
			cout << setw(3) << vector1[i][j];
		}
		cout << endl << endl << endl;
	}
	*/








	return 0;
}