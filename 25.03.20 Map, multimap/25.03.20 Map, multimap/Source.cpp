#include <iostream>
#include <map>
#include <functional>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{

	///1
	/*
	map<string, string> contacts;

	contacts.insert(pair<string, string>(("Ivanov"), ("380501235673")));
	contacts.insert(pair<string, string>(("Petrov"), ("380501235674")));
	contacts.insert(pair<string, string>(("Pushkin"), ("380501235675")));
	contacts.insert(pair<string, string>(("Lermontov"), ("380501235676")));
	contacts.insert(pair<string, string>(("Shevchenko"), ("380501235677")));

	auto it = contacts.find(("Ivanov"));
	cout << it->second << endl;

	it = contacts.find(("Petrov"));
	cout << it->second << endl;

	it = contacts.find(("Pushkin"));
	cout << it->second << endl;

	it = contacts.find(("Lermontov"));
	cout << it->second << endl;

	it = contacts.find(("Shevchenko"));
	cout << it->second << endl;
	*/
	
	///2
	
	multimap<string, vector<short>> students;

	students.insert({ ("Petrov"), {5,2,3,4,4,4,5} });
	students.insert({ ("Ivanov"), {5,5,5,5,5,5,5} });
	students.insert({ ("Shevchenko"), {5,5,5,5,5,5,5} });
	students.insert({ ("Lermontov"), {5,4,3,5,4,5,3} });
	students.insert({ ("Pushkin"), {2,3,2,3,2,3,3} });

	for (auto p : students)
	{
		cout << p.first << setw(3);
		for (auto pI : p.second)
		{
			cout << pI << "\t";
		}
		cout << endl << endl;
	}

	students.erase(("Pushkin"));
	cout << endl << endl << endl;

	for (auto p : students)
	{
		cout << p.first << setw(3);
		for (auto pI : p.second)
		{
			cout << pI << "\t";
		}
		cout << endl << endl;
	}
	

	return 0;
}