#pragma once
#include "Header.h"

class Person
{
public:
	Person() = default;

	string GetName() const { return _name; }
	size_t GetAge() const { return _age; }

	void SetName(const string& name);
	void SetAge(const size_t& age);
	virtual void Print() = 0;

private:
	string _name;
	size_t _age = 0;

};

