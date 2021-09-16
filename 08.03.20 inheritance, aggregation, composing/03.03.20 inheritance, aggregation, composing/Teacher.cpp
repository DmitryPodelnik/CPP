#include "Header.h"
#include <algorithm>

void Teacher::AddDiscipline(string name, size_t hours, bool isExam)
{
	Discipline* discipline = new Discipline;
	discipline->SetName(name);
	discipline->SetExam(isExam);
	discipline->SetHourse(hours);
	_disciplines.push_back(discipline);
}

void Teacher::RemoveDiscipline(string name)
{
	//remove(_disciplines.begin(), _disciplines.end(), discipline);
	size_t pos = 0;
	for (size_t i = 0; i < _disciplines.size(); i++)
	{
		if (name == _disciplines[i]->GetName())
		{
			pos = i;
		}
	}
	_disciplines.erase(_disciplines.begin() + pos);
}

void Teacher::Print()
{
	cout << "Teacher name: " << GetName() << endl;
	cout << "Teacher age: " << GetAge() << endl;
	cout << "Teachers' disciplines: ";
	for (size_t i = 0; i < _disciplines.size(); i++)
	{
		if (i != _disciplines.size() - 1)
		{
			cout << _disciplines[i]->GetName() << ", ";
		}
		else
		{
			cout << _disciplines[i]->GetName();
		}
	}
}

