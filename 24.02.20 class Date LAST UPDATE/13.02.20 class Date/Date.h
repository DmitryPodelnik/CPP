#pragma once
#include <iostream>
#include <ctime>

class Date
{
public:

	Date();
	Date(int year, int month, int day = 1);

	int getYear();
	int getMonth();
	int getDay();

	void setYear(int year);
	void setMonth(int month);
	void setDay(int day);

	bool isLeapYear(int year)
	{
		return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
	}

	void AddDays(int days);
	void AddMonths(int months);
	void AddYears(int years);

	static Date getCurrentDate();

private:

	const int _arr[13]{ 29,31,28,31,30,31,30,31,31,30,31,30,31 };

	int _year;
	int _month;
	int _day;

	void ConvertDays();
};



