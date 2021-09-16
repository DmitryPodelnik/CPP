#include "Dynamic_array.h"

using namespace std;

Dynamic_array::Dynamic_array()
{
	_size = 10;
	_arr = new int[_size];

	for (size_t i = 0; i < _size; i++)
	{
		_arr[i] = 0;
	}
}

Dynamic_array::Dynamic_array(size_t size)
{
	_size = size;
	_arr = new int[_size];

	for (size_t i = 0; i < _size; i++)
	{
		_arr[i] = rand() % 21;
	}
}

Dynamic_array::~Dynamic_array()
{
	delete[] _arr;
	_arr = nullptr;
	_size = 0;
}

Dynamic_array::Dynamic_array(const Dynamic_array& dynamic_array)
{
	_size = dynamic_array._size;
	_arr = new int[_size];

	for (size_t i = 0; i < _size; i++)
	{
		_arr[i] = dynamic_array._arr[i];
	}
}

Dynamic_array::Dynamic_array(Dynamic_array&& array)
{
	_arr = array._arr;
	array._arr = nullptr;

	_size = array._size;
	array._size = 0;
}

int& Dynamic_array::operator[](size_t index)
{
	if (index >= _size)
	{
		cerr << "Error: index out of range" << endl;
		return _arr[0];
	}

	return _arr[index];
}

int Dynamic_array::operator[](size_t index) const
{
	if (index >= _size)
	{
		cerr << "Error: index out of range" << endl;
		return _arr[0];
	}

	return _arr[index];
}

Dynamic_array& Dynamic_array::operator=(const Dynamic_array& array)
{
	//проверка на самоприсваиние
	if (this == &array)
	{
		return *this;
	}

	//delete[] _arr;
	this->~Dynamic_array();

	Copy(array);

	return *this;
	
}

Dynamic_array& Dynamic_array::operator=(Dynamic_array&& array)
{
	//проверка на самоприсваиние
	if (this == &array)
	{
		return *this;
	}

	//delete[] _arr;
	this->~Dynamic_array();

	//делаем перенос
	_arr = array._arr;
	array._arr = nullptr;

	_size = array._size;
	array._size = 0;
}

void Dynamic_array::OutPut() const
{
	for (size_t i = 0; i < _size; i++)
	{
		cout << _arr[i] << "\t";
	}
	cout << endl;
}

int* Dynamic_array::GetArr() const
{
	return _arr;
}

void Dynamic_array::SetArr()
{
	system("cls");
	for (size_t i = 0; i < _size; i++)
	{
		cout << "Enter the " << i + 1 << " number of array: ";
		cin >> _arr[i];
	}
	system("cls");
	cout << "You have successfully updated the array.";
	Sleep(2000);
	system("cls");
}

bool Dynamic_array::AddElements(size_t amount)
{
	if (amount < 1)
	{
		cerr << "Amount cannot be smaller than 1." << endl;
		return false;
	}

	_size += amount;

	int* temp = new int[_size];

	for (size_t i = 0; i < _size; i++)
	{
		if (i < _size - amount)
		{
			temp[i] = _arr[i];
		}
		else
		{
			temp[i] = 0;
		}
	}

	delete[] _arr;
	_arr = temp;
	temp = nullptr;

	return true;
}

bool Dynamic_array::SortArray(SortDirection direction)
{
	switch (direction)
	{
	case 1:

		for (int i = 0; i < _size - 1; i++)
		{
			for (int j = _size - 1; j > i; j--)
			{
				if (_arr[j] < _arr[j - 1])
				{
					int tmp = _arr[j - 1];
					_arr[j - 1] = _arr[j];
					_arr[j] = tmp;
				}
			}
		}
		return true;
		break;

	case 2:

		for (int i = 0; i < _size - 1; i++)
		{
			for (int j = _size - 1; j > i; j--)
			{
				if (_arr[j] > _arr[j - 1])
				{
					int tmp = _arr[j - 1];
					_arr[j - 1] = _arr[j];
					_arr[j] = tmp;
				}
			}
		}
		return true;
		break;

	default:

		cout << "Enter the correct parametr." << endl;
		return false;
	}

}

bool Dynamic_array::CopyArray(int* arr , size_t size)
{
	if (arr == nullptr)
	{
		cerr << "The array is nullptr." << endl;
		return false;
	}

	if (size < 1)
	{
		cerr << "The size cannot be smaller than 1." << endl;
		return false;
	}

	_size = size;

	int* temp = new int[_size];

	for (size_t i = 0; i < _size; i++)
	{
		temp[i] = arr[i];
	}

	delete[] _arr;
	_arr = temp;
	temp = nullptr;

	return true;
}

bool Dynamic_array::AddArrayToArray(int* arr, size_t size)
{
	if (arr == nullptr)
	{
		cerr << "The array is nullptr." << endl;
		return false;
	}

	if (size < 1)
	{
		cerr << "The size cannot be smaller than 1." << endl;
		return false;
	}

	_size += size;

	int* temp = new int[_size];

	for (size_t i = 0, j = 0; i < _size; i++)
	{
		if (i < _size - size)
		{
			temp[i] = _arr[i];
		}
		else
		{
			temp[i] = arr[j];
			j++;
		}
	}

	delete[] _arr;
	_arr = temp;
	temp = nullptr;

	return true;
}

void Dynamic_array::Copy(const Dynamic_array& array)
{
	_arr = new int[array._size];
	_size = array._size;

	for (size_t i = 0; i < _size; i++)
	{
		_arr[i] = array._arr[i];
	}
}

bool Dynamic_array::DeleteElements(size_t amount)
{
	if (amount < 1)
	{
		cerr << "Amount cannot be smaller than 1." << endl;
		return false;
	}

	_size -= amount;

	int* temp = new int[_size];

	for (size_t i = 0; i < _size; i++)
	{
		temp[i] = _arr[i];
	}

	delete[] _arr;
	_arr = temp;
	temp = nullptr;

	return true;
}

