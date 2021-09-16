/*
–еализовать класс String, который представл€ет динамическую строку.
¬ классе содержитс€ два пол€, указатель на строку и размер строки.–еализовать следующие методы :
Х	bool Initialization(size_t length) Ц выдел€ет в пам€ти строку указанного размера
Х	void Concat(char* str) Ц добавл€ет str в конец строки
Х	void Copy(char* str) Ц копирует str в строку
Х	void Insert(int index, char* str) Ц вставл€ет str в строку по указанному индексу
Х	void Remove(int index, size_t length) Ц удал€ет из строки length символов начина€ с index
*/
/*
¬ класс строки добавить:
Х	конструктор копировани€
Х	оператор присваивани€
Х	семантику переноса
Х	оператор индексации
ћетоды которые не измен€ют состо€ние объекта объ€вить константными.
*/

#include <iostream>
#include <ctime>
#include <windows.h>
#include "String.h"

using namespace std;

typedef unsigned short ushort;



int main()
{
	String string;

	char str[256] = "Hello Ukraine";
	//string.Concat(str);
	//string.OutPut();
	//string.Copy(str);
	//string.OutPut();
	//string.Insert(2, str);
	//string.OutPut();
	//string.Remove(2, 2);
	//string.OutPut();













	return 0;
}