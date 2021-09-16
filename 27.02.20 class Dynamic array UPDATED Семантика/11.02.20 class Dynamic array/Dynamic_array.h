#pragma once
#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;

enum SortDirection
{
	ASC = 1,
	DESC
};

template<typename TValue>
class Dynamic_array
{
public:

	Dynamic_array()
	{
		_size = 10;
		_arr = new TValue[_size];

		for (size_t i = 0; i < _size; i++)
		{
			_arr[i] = 0;
		}
	}

	Dynamic_array(size_t size)
	{
		_size = size;
		_arr = new TValue[_size];

		for (size_t i = 0; i < _size; i++)
		{
			_arr[i] = rand() % 21;
		}
	}

	~Dynamic_array()
	{
		delete[] _arr;
		_arr = nullptr;
		_size = 0;
	}

	Dynamic_array(const Dynamic_array<TValue>& dynamic_array)
	{
		_size = dynamic_array._size;
		_arr = new TValue[_size];

		for (size_t i = 0; i < _size; i++)
		{
			_arr[i] = dynamic_array._arr[i];
		}
	}

	Dynamic_array(Dynamic_array&& array)
	{
		_arr = array._arr;
		array._arr = nullptr;

		_size = array._size;
		array._size = 0;
	}


	Dynamic_array(initializer_list<TValue> list)
	{
		_size = list.size();
		_arr = new TValue[_size];

		auto pEl = list.begin();

		for (size_t i = 0; i < _size; i++)
		{
			_arr[i] = pEl;
			pEl++;
		}
	}

	TValue& operator[](size_t index)
	{
		if (index >= _size)
		{
			cerr << "Error: index out of range" << endl;
			return _arr[0];
		}

		return _arr[index];
	}

	TValue operator[](size_t index) const
	{
		if (index >= _size)
		{
			cerr << "Error: index out of range" << endl;
			return _arr[0];
		}

		return _arr[index];
	}

	Dynamic_array<TValue>& operator=(const Dynamic_array& array)
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

	Dynamic_array<TValue>& operator=(Dynamic_array&& array)
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

	void OutPut() const
	{
		for (size_t i = 0; i < _size; i++)
		{
			cout << _arr[i] << "\t";
		}
		cout << endl;
	}


	TValue* GetArr() const
	{
		return _arr;
	}

	size_t GetSize() const { return _size; }

	void SetArr()
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

	bool DeleteElements(size_t amount)
	{
		if (amount < 1)
		{
			cerr << "Amount cannot be smaller than 1." << endl;
			return false;
		}

		_size -= amount;

		TValue* temp = new TValue[_size];

		for (size_t i = 0; i < _size; i++)
		{
			temp[i] = _arr[i];
		}

		delete[] _arr;
		_arr = temp;
		temp = nullptr;

		return true;
	}

	bool AddElements(size_t amount)
	{
		if (amount < 1)
		{
			cerr << "Amount cannot be smaller than 1." << endl;
			return false;
		}

		_size += amount;

		TValue* temp = new TValue[_size];

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

	bool SortArray(SortDirection direction)
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
						TValue tmp = _arr[j - 1];
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
						TValue tmp = _arr[j - 1];
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

	bool CopyArray(TValue* arr, size_t size)
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

		TValue* temp = new TValue[_size];

		for (size_t i = 0; i < _size; i++)
		{
			temp[i] = arr[i];
		}

		delete[] _arr;
		_arr = temp;
		temp = nullptr;

		return true;
	}

	bool AddArrayToArray(TValue* arr, size_t size)
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

		TValue* temp = new TValue[_size];

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

private:

	TValue* _arr = nullptr;
	size_t _size;

	void Copy(const Dynamic_array& array)
	{
		_arr = new TValue[array._size];
		_size = array._size;

		for (size_t i = 0; i < _size; i++)
		{
			_arr[i] = array._arr[i];
		}
	}

};

