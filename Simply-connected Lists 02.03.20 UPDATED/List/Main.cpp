/*
¬ класс односв€зного списка, реализованного на паре, добавить следующие методы:
Х	конструстор копировани€
Х	конструктор переноса
Х	операторы присваивани€ с копированием и переносом
Х	деструктор
Х	оператор []
Х	InsertItem (вставка элемента по индексу)
Х	GetSize
Х	конструктор принимающий initializer_list

*/


#include <iostream>
#include "List.h"

using namespace std;

int main()
{
    List<int> list;
    list.AddItem(10);
    list.AddItem(20);
    list.AddItem(30);

    list.Print();

    list.RemoveAt(4);
    list.Print();
    cout << endl << endl;

    List<int> list2{ 2,3,5,4,5 };
    list2.Print();

    List<int> list3 = list2;
    list3.Print();
    cout << endl << endl;;
    cout<<list3[4];
    cout << endl << endl;

    list3.InsertItem(3, 11);
    list3.Print();
    cout << endl << endl;

    List<int> list4;
    list4 = list3;
    list4.Print();
}
