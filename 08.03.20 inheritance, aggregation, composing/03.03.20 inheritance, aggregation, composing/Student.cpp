#include "Header.h"

void Student::NextCourse()
{
	_course++;
}

void Student::Print()
{
	cout << "Student name: " << GetName() << endl;
	cout << "Student group: " << GetGroup() << endl;
	cout << "Student age: " << GetAge() << endl;
	cout << "Student course: " << GetCourse() << endl;
}