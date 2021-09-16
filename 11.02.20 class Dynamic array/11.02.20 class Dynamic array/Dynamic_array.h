#pragma once
#include <iostream>
#include <windows.h>
#include <ctime>

class Dynamic_array
{
public:

	Dynamic_array();
	Dynamic_array(size_t size);
	~Dynamic_array();
	Dynamic_array(const Dynamic_array& dynamic_array);

	void OutPut();

	const int* GetArr();
	size_t GetSize();

	void SetArr();

	bool DeleteElements(size_t amount);
	bool AddElements(size_t amount);
	bool SortArray(short parametr);
	bool CopyArray(int* arr, size_t size);
	bool AddArrayToArray(int* arr, size_t size);

private:

	int* _arr = nullptr;
	size_t _size;

};

