#include "Header.h"

using namespace std;

int main()
{
	Student* student1 = new Student;
	student1->SetAge(18);
	student1->SetCourse(1);
	student1->SetGroup("KH-181");
	student1->SetName("Ivan Ivanov");
	student1->Print();
	cout << endl << endl;

	Teacher* teacher1 = new Teacher;
	teacher1->SetAge(35);
	teacher1->SetName("Petr Petrov");
	teacher1->AddDiscipline("Math", true, 30);
	teacher1->AddDiscipline("C++", true, 80);
	teacher1->Print();
	cout << endl << endl;
	teacher1->RemoveDiscipline("Math");
	teacher1->Print();

	delete student1;
	delete teacher1;



	 





	return 0;
}