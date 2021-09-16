#pragma once
#include "Header.h"


class Discipline
{
public:
	
	Discipline() = default;
	~Discipline();

	bool isExam() const { return _isExam; }
	string GetName() const { return _name; }
	size_t GetHourse() const { return _quantityHours; }

	void SetExam(const bool& isExam) { _isExam = isExam; }
	void SetHourse(const size_t& hours) { _quantityHours = hours; }
	void SetName(const string& name) { _name = name; }

	virtual void Print();

private:

	string _name;
	size_t _quantityHours;
	bool _isExam;

};

