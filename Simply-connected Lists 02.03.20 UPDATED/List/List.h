#pragma once
#include "ListItem.h"
#include <iostream>
using namespace std;

template <typename TValue>
class List
{
public:
	List() = default;
	List(const List<TValue>& obj);
	List(List<TValue>&& obj);
	List(initializer_list<TValue>& list);
	~List();

	TValue& operator[] (size_t index);
	TValue operator[] (size_t index) const;

	List<TValue>& operator= (const List<TValue>& obj);
	List<TValue>& operator= (List<TValue>&& obj);

	size_t GetSize() const { return _size; }

	void AddItem(TValue value);
	void RemoveAt(size_t index);
	void InsertItem(size_t index, TValue value);

	void Print() const;

private:

	ListItem<TValue>* _head = nullptr;
	size_t _size = 0;

	void Copy(const List<TValue>& obj);
	void Forward(const List<TValue>& obj);
};

template<typename TValue>
inline List<TValue>::List(const List<TValue>& obj)
{
	Copy(obj);
}

template<typename TValue>
inline List<TValue>::List(List<TValue>&& obj)
{
	Forward(obj);
}

template<typename TValue>
inline List<TValue>::List(initializer_list<TValue>& list)
{
	_size = list.size();

	auto pEl = list.begin();

	ListItem<TValue>* newItem = new ListItem<TValue>(*pEl);
	ListItem<TValue>* cursor = nullptr;

	for (size_t i = 0; i < _size; i++)
	{
		if (_head == nullptr)
		{
			_head = newItem;
			cursor = _head;
		}
		else
		{
			while (cursor->next != nullptr)
			{
				cursor = cursor->next;
			}

			newItem = new ListItem<TValue>(*pEl);
			cursor->next = newItem;
		}
		pEl++;
	}
}

template<typename TValue>
inline List<TValue>::~List()
{
	ListItem<TValue>* cursor = _head->next;

	while (cursor != nullptr)
	{
		delete _head;
		_head = cursor;
		cursor = cursor->next;
	}
	delete _head;
	_head = nullptr;
	_size = 0;
}

template<typename TValue>
inline TValue& List<TValue>::operator[](size_t index)
{
	ListItem<TValue>* cursor = _head;

	for (size_t i = 0; i < index; i++)
	{
		cursor = cursor->next;
	}

	return cursor->value;
}

template<typename TValue>
inline TValue List<TValue>::operator[](size_t index) const
{
	ListItem<TValue>* cursor = _head;

	for (size_t i = 0; i < index; i++)
	{
		cursor = cursor->next;
	}

	return cursor->value;
}

template<typename TValue>
inline List<TValue>& List<TValue>::operator=(const List<TValue>& obj)
{
	if (this == &obj)
	{
		return *this;
	}

	if (_head != nullptr)
	{
		this->~List();
	}

	Copy(obj);

	return *this;
}

template<typename TValue>
inline List<TValue>& List<TValue>::operator=(List<TValue>&& obj)
{
	if (this == &obj)
	{
		return *this;
	}

	if (_head != nullptr)
	{
		this->~List();
	}

	Forward(obj);
}

template<typename TValue>
inline void List<TValue>::AddItem(TValue value)
{
	ListItem<TValue>* newItem = new ListItem<TValue>(value);

	if (_head == nullptr)
	{
		_head = newItem;
	}
	else
	{
		//search list item
		ListItem<TValue>* cursor = _head;

		while (cursor->next != nullptr)//пока есть следующий элемент
		{
			cursor = cursor->next;
		}

		//в последний элемент записать адрес нового элемента
		cursor->next = newItem; 
	}

	_size++;
}

template<typename TValue>
inline void List<TValue>::RemoveAt(size_t index)
{
	if (index >= _size)
	{
		cerr << "Error: index out of range" << endl;
		return;
	}

	ListItem<TValue>* delItem = nullptr;
	if (index == 0)
	{
		//если удаляемый элемент первый
		delItem = _head;
		//перенапрявляем голову на второй элемент
		_head = delItem->next;
	}
	else
	{
		//поиск элемента перед удаляемым
		ListItem<TValue>* prevItem = _head;
		for (size_t i = 0; i < index - 1; i++)
		{
			prevItem = prevItem->next;
		}

		//сохраняем адрес удаляемого элемента
		delItem = prevItem->next;

		//перенаправляем указатель
		prevItem->next = delItem->next;
	}

	//удаляем элемент
	delete delItem;
	_size--;
}

template<typename TValue>
inline void List<TValue>::InsertItem(size_t index, TValue value)
{
	if (index > _size)
	{
		cerr << "Error: index out of range" << endl;
		return;
	}

	ListItem<TValue>* newItem = new ListItem<TValue>{ value };
	if (index == 0)
	{
		newItem->next = _head->next;
		_head = newItem;
	}
	else
	{
		ListItem<TValue>* prevItem = _head;
		for (size_t i = 0; i < index - 1; i++)
		{
			prevItem = prevItem->next;
		}

		newItem->next = prevItem->next;
		prevItem->next = newItem;
	}
	_size++;
}

template<typename TValue>
inline void List<TValue>::Print()const
{
	ListItem<TValue>* cursor = _head;
	while (cursor != nullptr)
	{
		cout << cursor->value << "\t";
		cursor = cursor->next;
	}
	cout << endl;
}

template<typename TValue>
inline void List<TValue>::Copy(const List<TValue>& obj)
{
	_size = obj._size;

	if (_size != 0)
	{
		ListItem<TValue>* newItem = new ListItem<TValue>(obj._head->value);
		ListItem<TValue>* cursor = nullptr;
		ListItem<TValue>* objCursor = obj._head;

		for (size_t i = 0; i < _size; i++)
		{
			if (_head == nullptr)
			{
				_head = newItem;
				cursor = _head;
			}
			else
			{
				while (cursor->next != nullptr)
				{
					cursor = cursor->next;
				}

				for (static size_t j = 0; j < i; j++)
				{
					objCursor = objCursor->next;
				}

				newItem = new ListItem<TValue>(objCursor->value);
				cursor->next = newItem;
			}
			newItem = nullptr;
		}
	}
}

template<typename TValue>
inline void List<TValue>::Forward(const List<TValue>& obj)
{
	_head = obj._head;
	obj._head = nullptr;

	_size = obj._size;
	obj._size = 0;
}

