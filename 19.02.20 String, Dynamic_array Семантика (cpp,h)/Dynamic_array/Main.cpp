/*
–еализовать класс динамического массива.¬ классе реализовать методы : 
добавлени€ и удалени€ эелементов, конструкторы и деструктор.
ј так же необходимые методы дл€ работы с динамическим массивом на ваше усмотрение.
*/
/*
¬ класс динамического массива добавить:
Х	конструктор копировани€
Х	оператор присваивани€
Х	семантику переноса
Х	оператор индексации
ћетоды которые не измен€ют состо€ние объекта объ€вить константными.
*/

#include "Dynamic_array.h"

using namespace std;

Dynamic_array CreateArray()
{
	Dynamic_array array(100000);
	return array;
}

int main()
{
	srand(time(0));

	Dynamic_array array;
	array.OutPut();

	cout << endl;

	Dynamic_array array1(10);
	array1.OutPut();
	//array1.SetArr();
	//cout << endl;
	//array1.OutPut();
	
	Dynamic_array array2 = array1;
	cout << endl;
	array2.OutPut();

	array2.AddElements(5);
	cout << endl;
	array2.OutPut();

	array2.DeleteElements(6);
	cout << endl;
	array2.OutPut();

	array2.SortArray(ASC);
	cout << endl;
	array2.OutPut();

	array2.SortArray(DESC);
	cout << endl;
	array2.OutPut();

	int arr[6]{ 1,2,3,4,5,6 };
	Dynamic_array array3;
	array3.CopyArray(arr, 6);
	cout << endl;
	array3.OutPut();

	Dynamic_array array4;
	array4.AddArrayToArray(arr, 6);
	cout << endl;
	array4.OutPut();

	//Dynamic_array array5;
	//cout << endl;

	//for (size_t i = 0; i < array.GetSize(); i++)
	//{
	//	cout << array[i] << "\t";
	//}
	//cout << endl;

	//Dynamic_array array6(5);

	//array6 = array5;

	//for (size_t i = 0; i < array6.GetSize(); i++)
	//{
	//	cout << array6[i] << "\t";
	//}


	//Dynamic_array array7 = CreateArray();

	//cout << "Size: " << array7.GetSize() << endl;


	//Dynamic_array array8;
	//array8 = CreateArray();

	//Dynamic_array arrayCopy;
	//arrayCopy = array8;
	



	return 0;
}