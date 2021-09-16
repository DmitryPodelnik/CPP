#pragma once
#include <iostream>
#include <windows.h>
#include <ctime>

enum SortDirection
{
	ASC = 1,
	DESC
};

class Dynamic_array
{
public:

	Dynamic_array();
	Dynamic_array(size_t size);
	~Dynamic_array();
	Dynamic_array(const Dynamic_array& dynamic_array);
	Dynamic_array(Dynamic_array&& array);

	int& operator[] (size_t index);
	int operator[] (size_t index) const;

	Dynamic_array& operator= (const Dynamic_array& array);
	Dynamic_array& operator= (Dynamic_array&& array);

	void OutPut() const;

	int* GetArr() const;
	size_t GetSize() const { return _size; }

	void SetArr();

	bool DeleteElements(size_t amount);
	bool AddElements(size_t amount);
	bool SortArray(SortDirection direction);
	bool CopyArray(int* arr, size_t size);
	bool AddArrayToArray(int* arr, size_t size);

private:

	int* _arr = nullptr;
	size_t _size;

	void Copy(const Dynamic_array& array);

};

