#include <iostream>
#include "List.h"

int main()
{
    List<int> list;
    list.Print();
    list.ReversePrint();

    cout << "Insert first item" << endl;
    list.InsertItem(0, 100);
    list.Print();
    list.ReversePrint();

    cout << "Add items" << endl;
    list.AddItem(10);
    list.AddItem(20);
    list.AddItem(30);
    list.Print();
    list.ReversePrint();

    cout << "Insert to end" << endl;
    list.InsertItem(3, 100);
    list.Print();
    list.ReversePrint();

    cout << "Insert to start" << endl;
    list.InsertItem(0, 200);
    list.Print();
    list.ReversePrint();

    cout << "Insert in the midst" << endl;
    list.InsertItem(2, 300);
    list.Print();
    list.ReversePrint();

    cout << "Remove at" << endl;
    list.RemoveAt(5);
    list.Print();
    list.ReversePrint();
    cout << endl << endl;

    List<int> list2{ 1,2,3,4,5 };
    cout << "Initializer list: \n";
    list2.Print();
    list2.ReversePrint();
    cout << endl << endl;

    List<int> list3 = list2;
    cout << "Copy constructor: \n";
    list3.Print();
    list3.ReversePrint();
    cout << endl << endl;

    List<int> list4;
    list4 = list3;
    cout << "Assignment operator: \n";
    list4.Print();
    list4.ReversePrint();
    cout << endl << endl;

    List<int> list5{ 1 };
    list5.Print();
    list5.RemoveAt(0);
    cout << endl << endl;
    list5.Print();
    list5.ReversePrint();
    
}
