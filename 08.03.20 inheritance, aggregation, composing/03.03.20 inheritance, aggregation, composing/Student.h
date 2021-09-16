#pragma once
#include "Header.h"

class Student : public Person
{
public:

	Student() = default;

	string GetGroup() const { return _group; }
	size_t GetCourse() const { return _course; }

	void SetCourse(const size_t& course) { _course = course; }
	void SetGroup(const string& group) { _group = group; }

	void NextCourse();
	virtual void Print();


private:
	size_t _course = 0;
	string _group;

};

