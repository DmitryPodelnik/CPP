#include "Date.h"

using namespace std;

Date::Date()
{
	_year = 0;
	_month = 1;
	_day = 1;
}

Date::Date(int year, int month, int day) :Date()
{
	setYear(year);
	setMonth(month);
	setDay(day);
}

int Date::getYear()
{
	return _year;
}

int Date::getMonth()
{
	return _month;
}

int Date::getDay()
{
	return _day;
}

void Date::setYear(int year)
{
	if (year >= 0 && _month > 0)
	{
		if (!isLeapYear(year))
		{
			if (_day <= _arr[_month])
			{
				_year = year;
				return;
			}
		}
		else
		{
			if (_month == 2 && _day <= _arr[0])
			{
				_year = year;
				return;
			}
			else if (_month != 2 && _day <= _arr[_month])
			{
				_year = year;
				return;
			}
		}
	}
	cerr << "Error: incorrect value in the year variable." << endl;
}

void Date::setMonth(int month)
{
	if (_year >= 0 && (month > 0 && month < 13))
	{
		if (!isLeapYear(_year))
		{
			if (_day <= _arr[month])
			{
				_month = month;
				return;
			}
		}
		else
		{
			if (month == 2 && _day <= _arr[0])
			{
				_month = month;
				return;
			}
			else if(month != 2 && _day <= _arr[month])
			{
				_month = month;
				return;
			}
		}
	}
	cerr << "Error: the month must be between 1 and 12." << endl;
}

void Date::setDay(int day)
{
	if (_month != 0)
	{
		if (!isLeapYear(_year))
		{
			if (day > 0 && day <= _arr[_month])
			{
				_day = day;
				return;
			}
		}
		else
		{
			if (_month != 2 && (day > 0 && day <= _arr[_month]))
			{
				_day = day;
				return;
			}
			else if (_month == 2 && (day > 0 && day <= _arr[0]))
			{
				_day = day;
				return;
			}
		}
	}
	cerr << "Error: incorrect value in the day variable." << endl;
}

void Date::AddDays(int days)
{
	_day += days;

	ConvertDays();
	if (isLeapYear(_year))
	{
		if (_month == 2 && _day > _arr[0])
		{
			_day -= _arr[0];
			_month++;
		}
		else if (_month != 2 && _day > _arr[_month])
		{
			_day -= _arr[_month];
			_month++;
		}
	}
}

void Date::AddMonths(int months)
{
	_month += months;

	ConvertDays();
}

void Date::AddYears(int years)
{
	_year += years;

	ConvertDays();
}

Date Date::getCurrentDate()
{
	time_t t = time(0); //получаем метку времени
	tm tm;
	localtime_s(&tm, &t); //заполняем структуру tm, датой из метки времени

	return Date(tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
}

void Date::ConvertDays()
{
	if (!isLeapYear(_year))
	{
		if (_day > _arr[_month])
		{
			_day -= _arr[_month];
			_month++;
		}
	}
}


