#include <iostream>
#include "String.h"
#include <string.h>

using namespace std;

typedef unsigned short ushort;

String::String()
{
	_length = 100;
	_str = new char[_length];
	_str[0] = '\0';
	strcpy_s(_str, _length, "321321");
}

String::String(const char* str, size_t length)
{
	if (length < 1)
	{
		cerr << "The length cannot be smaller than 1." << endl;
		_length = 0;
		_str = new char[100];
	}
	else
	{
		_length = length;
		_str = new char[_length];
	}

	if (str == nullptr)
	{
		cerr << "The string is nullptr." << endl;
		_str[0] = '\0';
	}
	else
	{
		strcpy_s(_str, _length, str);
	}
}

String::String(const String& str)
{
	_length = str._length;
	_str = new char[_length];

	for (size_t i = 0; i < _length; i++)
	{
		_str[i] = str._str[i];
	}
}

String::String(String&& str)
{
	_str = str._str;
	str._str = nullptr;

	_length = str._length;
	str._length = 0;
}

String::~String()
{
	delete[] _str;
	_str = nullptr;
}

String& String::operator=(const String& str)
{
	if (this == &str)
	{
		return *this;
	}

	this->~String();

	Copy(str);

	return *this;
}

String& String::operator=(String&& str)
{
	if (this == &str)
	{
		return *this;
	}

	this->~String();

	_str = str._str;
	str._str = nullptr;

	_length = str._length;
	str._length = 0;
}

char& String::operator[](size_t index)
{
	if (index >= _length)
	{
		cerr << "Error: index out of range" << endl;
		return _str[0];
	}

	return _str[index];
}

char String::operator[](size_t index) const
{
	if (index >= _length)
	{
		cerr << "Error: index out of range" << endl;
		return _str[0];
	}

	return _str[index];
}

void String::OutPut() const
{
	cout << "String: " << this->_str << endl;
}

void String::Copy(const String& str)
{
	_length = str._length;
	_str = new char[_length];

	for (size_t i = 0; i < _length; i++)
	{
		_str[i] = str._str[i];
	}
}

bool String::Initialization(size_t length)
{
	if (length < 1)
	{
		cerr << "A length of the string must be bigger than 0." << endl;
		return false;
	}
	_str = new char[length];

	return true;
}

void String::Concat(char* str)
{
	if (str == nullptr)
	{
		cerr << "The string is nullptr." << endl;
		return;
	}

	if (strlen(str) < 1)
	{
		cerr << "The passing string is NULL" << endl;
		return;
	}

	if ((strlen(_str) + strlen(str)) > _length)
	{
		_length = strlen(_str) + strlen(str) + 1;
		char* str1 = new char[_length];
		strcpy_s(str1, _length, _str);
		delete[] _str;
		_str = str1;
		strcat_s(_str, _length, str);
	}
	else
	{
		strcat_s(_str, _length, str);
	}
}

void String::Copy(char* str)
{
	if (str == nullptr)
	{
		cerr << "The string is nullptr." << endl;
		return;
	}

	if (strlen(str) < 1)
	{
		cerr << "The passing string is NULL" << endl;
		return;
	}

	if (strlen(str) > _length)
	{
		_length = strlen(str);
		char* str1 = new char[_length];
		strcpy_s(str1, _length, str);
		delete[] _str;
		_str = str1;
	}
	else
	{
		strcpy_s(_str, _length, str);
	}
}

void String::Insert(int index, char* str)
{
	if (str == nullptr)
	{
		cerr << "The string is nullptr." << endl;
		return;
	}

	if (strlen(str) < 1)
	{
		cerr << "The passing string is NULL" << endl;
		return;
	}

	if (index < 0)
	{
		cerr << "The index cannot be smaller than 0." << endl;
		return;
	}

	if (index > strlen(_str))
	{
		cerr << "You cannot insert the string using that index." << endl;
		return;
	}

	if ((strlen(_str) + strlen(str)) + 1 > _length)
	{
		_length = strlen(_str) + strlen(str) + 1;
		char* temp = new char[_length];
		strcpy_s(temp, _length, _str);
		delete[] _str;
		_str = temp;
	}	

	size_t size = strlen(_str) - index + 1;

	char* str1 = new char[size];

	for (size_t i = index, j = 0; j < size; i++, j++)
	{
		if (j < size - 1)
		{
			str1[j] = _str[i];
		}
		else
		{
			str1[j] = '\0';
		}
	}

	for (size_t i = index, j = 0; j < strlen(str) + 1; i++, j++)
	{
		_str[i] = str[j];
	}
	strcat_s(_str, _length, str1);
	delete[] str1;
	str1 = nullptr;
}

void String::Remove(int index, size_t length)
{
	if (index < 0)
	{
		cerr << "The index cannot be smaller than 0." << endl;
		return;
	}

	if (index > strlen(_str))
	{
		cerr << "You cannot remove the symbols using that index." << endl;
		return;
	}

	if (length < 1)
	{
		cerr << "The length cannot be smaller than 1." << endl;
		return;
	}

	if (length > strlen(_str) - index)
	{
		cerr << "Incorrect length." << endl;
		return;
	}

	size_t size = strlen(_str) - index - length + 1;

	char* str_end = new char[size];

	for (size_t i = index + length, j = 0; j < size; i++, j++)
	{
		if (j < size - 1)
		{
			str_end[j] = _str[i];
		}
		else
		{
			str_end[j] = '\0';
		}
	}

	size = strlen(_str) - length + 1;

	char* str_start = new char[size];


	for (size_t i = 0; i < index + 1; i++)
	{
		if (i < index)
		{
			str_start[i] = _str[i];
		}
		else
		{
			str_start[i] = '\0';
		}
	}
	strcat_s(str_start, size, str_end);
	delete[] str_end;
	delete[] _str;
	_str = str_start;
	str_end = nullptr;
	str_start = nullptr;
}

char* String::GetStr() const
{
	return _str;
}

size_t String::GetLength() const
{
	return _length;
}

bool String::SetStr(const char* str)
{
	if (str == nullptr)
	{
		cerr << "Error: the string is nullptr." << endl;
		return false;
	}
	strcpy_s(_str, _length, str);
	return true;
}

bool String::SetAge(size_t length)
{
	if (length < 1)
	{
		cerr << "The length cannot be smaller than 1." << endl;
		return false;
	}

	_length = length;
	return true;
}
