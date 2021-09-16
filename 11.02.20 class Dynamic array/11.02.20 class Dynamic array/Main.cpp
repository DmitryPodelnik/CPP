/*
Реализовать класс динамического массива.В классе реализовать методы : 
добавления и удаления эелементов, конструкторы и деструктор.
А так же необходимые методы для работы с динамическим массивом на ваше усмотрение.
*/

#include "Dynamic_array.h"

using namespace std;

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

	array2.SortArray(1);
	cout << endl;
	array2.OutPut();

	array2.SortArray(2);
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








	return 0;
}