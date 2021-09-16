#pragma once
#include "LIstItem.h"
#include <iostream>
#include <algorithm>
using namespace std;


template<typename TValue>
class List
{
public:
	List() = default;
	List(const List<TValue>& obj);
	List(List<TValue>&& obj);
	List(initializer_list<TValue> list);
	~List();

	List<TValue>& operator= (const List<TValue>& obj);
	List<TValue>& operator= (List<TValue>&& obj);

	void AddItem(const TValue& value);
	void InsertItem(size_t index, const TValue& value);
	void RemoveAt(size_t index);
		
	void Print();
	void ReversePrint();

	template<typename T>
	class iterator : public std::iterator<bidirectional_iterator_tag, T>
	{
		T* _p;
		int size;
	public:
		iterator()
		{
			_p = nullptr;
			_size = 0;
		}

		iterator(T* p, int size)
		{
			_p = p;
			_size = size;
		}

		iterator& operator++ ()
		{
			if (_p->next == nullptr)
			{
				_p = nullptr;
			}
			else
			{
				_p = _p->next;
			}

			return *this;
		}

		iterator operator++(int)
		{
			iterator tmp = *this;
			if (_p->next == nullptr)
			{
				_p = nullptr;
			}
			else
			{
				_p = _p->next;
			}
			return tmp;
		}

		iterator& operator-- ()
		{
			if (_p->prev == nullptr)
			{
				_p = nullptr;
			}
			else
			{
				_p = _p->prev;
			}

			return *this;
		}

		iterator operator--(int)
		{
			iterator tmp = *this;
			if (_p->prev == nullptr)
			{
				_p = nullptr;
			}
			else
			{
				_p = _p->prev;
			}
			return tmp;
		}

		T& operator* ()
		{
			return _p->value;
		}

		bool operator != (const iterator& it)
		{
			return _p != it._p;
		}

		bool operator == (const iterator& it)
		{
			return _p == it._p;
		}

		iterator begin()
		{
			return iterator(_p, _size);
		}

		iterator end()
		{
			return iterator();
		}
	};


private:
	ListItem<TValue>* _head = nullptr;
	ListItem<TValue>* _tail = nullptr;
	size_t _size = 0;

	ListItem<TValue>* FindItemAt(size_t index);
	void Copy(const List<TValue>& obj);
	void Forward(const List<TValue>& obj);
	void ClearList();
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
inline List<TValue>::List(initializer_list<TValue> list)
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
			cursor->next->prev = cursor;
		}
		pEl++;
	}
	_tail = newItem;
}

template<typename TValue>
inline List<TValue>::~List()
{
	if (_head != nullptr)
	{
		ClearList();
	}
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
inline void List<TValue>::AddItem(const TValue& value)
{
	ListItem<TValue>* newItem = new ListItem<TValue>(value);

	if (_head == nullptr)
	{
		_head = newItem;		
	}
	else
	{
		_tail->next = newItem;
		newItem->prev = _tail;		
	}
	_tail = newItem;
	_size++;
}

/*
template<typename TValue>
inline void List<TValue>::InsertItem(size_t index, const TValue& value)
{
	if (index > _size)
	{
		cerr << "Error: index out of range" << endl;
		return;
	}

	ListItem<TValue>* newItem = new ListItem<TValue>(value);

	ListItem<TValue>* prevItem = nullptr;
	ListItem<TValue>* nextItem = nullptr;

	if (_head == nullptr)
	{
		_head = newItem;
		_tail = newItem;
	}
	else if (index == _size)
	{
		prevItem = _tail;

		prevItem->next = newItem;
		newItem->prev = prevItem;

		_tail = newItem;
	}
	else if (index == 0)
	{
		nextItem = _head;
		nextItem->prev = newItem;
		newItem->next = nextItem;
		_head = newItem;
	}
	else
	{
		prevItem = FindItemAt(index - 1);
		nextItem = prevItem->next;

		prevItem->next = newItem;
		newItem->prev = prevItem;

		nextItem->prev = newItem;
		newItem->next = nextItem;
	}

	_size++;
}
*/
template<typename TValue>
inline void List<TValue>::InsertItem(size_t index, const TValue& value)
{
	if (index > _size)
	{
		cerr << "Error: index out of range" << endl;
		return;
	}

	ListItem<TValue>* newItem = new ListItem<TValue>(value);

	ListItem<TValue>* prevItem = index == 0 ? nullptr : FindItemAt(index - 1);
	ListItem<TValue>* nextItem = index == _size ? nullptr : FindItemAt(index);

	if (prevItem == nullptr)
	{
		_head = newItem;
	}
	else
	{
		prevItem->next = newItem;
		newItem->prev = prevItem;
	}

	if (nextItem == nullptr)
	{
		_tail = newItem;
	}
	else
	{
		nextItem->prev = newItem;
		newItem->next = nextItem;
	}
	_size++;
}

template<typename TValue>
inline void List<TValue>::RemoveAt(size_t index)
{
	if (index >= _size)
	{
		cerr << "Error: the index is out of the range." << endl;
		return;
	}

	ListItem<TValue>* delItem = FindItemAt(index);
	//ListItem<TValue>* prevItem = index == 0 ? nullptr : FindItemAt(index - 1);
	//ListItem<TValue>* nextItem = index == _size - 1 ? nullptr : FindItemAt(index + 1);

	if (delItem->prev == nullptr)
	{
		//delItem = _head;
		_head->prev = nullptr;
		_head = delItem->next;
	}
	else
	{
		//delItem = delItem->prev->next;
		delItem->prev->next = delItem->next;
	}

	if (delItem->next == nullptr)
	{
		_tail->next = nullptr;
		_tail = delItem->prev;
	}
	else
	{
		delItem->next->prev = delItem->prev;
	}

	delete delItem;
	_size--;
}


template<typename TValue>
inline void List<TValue>::Print()
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
inline void List<TValue>::ReversePrint()
{
	ListItem<TValue>* cursor = _tail;
	while (cursor != nullptr)
	{
		cout << cursor->value << "\t";
		cursor = cursor->prev;
	}
	cout << endl;
}

template<typename TValue>
inline ListItem<TValue>* List<TValue>::FindItemAt(size_t index)
{
	ListItem<TValue>* cursor = _head;
	for (size_t i = 0; i < index; i++)
	{
		cursor = cursor->next;
	}

	return cursor;
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
		static size_t j;
		j = 0;

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

				for (; j < i; j++)
				{
					objCursor = objCursor->next;
				}

				newItem = new ListItem<TValue>(objCursor->value);
				cursor->next = newItem;
				cursor->next->prev = cursor;
			}
		}
		_tail = newItem;
	}
}

template<typename TValue>
inline void List<TValue>::Forward(const List<TValue>& obj)
{
	_head = obj._head;
	_tail = obj._tail;
	obj._head = nullptr;
	obj._tail = nullptr;

	_size = obj._size;
	obj._size = 0;
}

template<typename TValue>
inline void List<TValue>::ClearList()
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
	_tail = nullptr;
	_size = 0;
}
