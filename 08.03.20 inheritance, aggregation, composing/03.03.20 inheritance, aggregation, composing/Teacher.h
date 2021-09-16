#pragma once
#include "Header.h"


class Teacher : public Person 
{
public:
	Teacher() = default;
	Teacher(const Teacher&) = delete;
	Teacher& operator =(const Teacher&) = delete;
	~Teacher();

	void AddDiscipline(string name, size_t hours, bool isExam);
	void RemoveDiscipline(string name);
	virtual void Print();



private:
	vector<Discipline*> _disciplines;

};


