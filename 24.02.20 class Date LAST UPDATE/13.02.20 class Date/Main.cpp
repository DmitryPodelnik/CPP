#include "Date.h"

using namespace std;

void printTime(Date date)
{
    cout << "Date: " << date.getYear() << ".";

    if (date.getMonth() > 9)
    {
        cout << date.getMonth() << ".";
    }
    else
    {
        cout << "0" << date.getMonth() << ".";
    }

    if (date.getDay() > 9)
    {
        cout << date.getDay() << endl;
    }
    else
    {
        cout << "0" << date.getDay() << endl;
    }
}

int main()
{

    Date date1;
    printTime(date1);
    cout << endl;

    Date date2(2020, 2, 29);
    printTime(date2);
    cout << endl;

    Date date3(2012, 12);
    printTime(date3);
    cout << endl;

    Date date4 = Date::getCurrentDate();
    printTime(date4);
    cout << endl;

    date2.setYear(2021);
    printTime(date2);
    cout << endl;

    date2.AddYears(5);
    printTime(date2);
    cout << endl;

    Date date5(2020, 3, 31);
    printTime(date5);
    cout << endl;

    date5.AddMonths(1);
    printTime(date5);
    cout << endl;

    Date date6(2020, 2, 25);
    printTime(date6);
    cout << endl;

    date6.AddDays(6);
    printTime(date6);
    cout << endl;

    Date date7(2021, 1, 29);
    printTime(date7);
    cout << endl;

    date7.AddMonths(1);
    printTime(date7);
    cout << endl;




	return 0;
}