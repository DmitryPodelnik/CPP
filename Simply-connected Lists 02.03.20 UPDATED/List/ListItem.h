#pragma once

template <typename TValue >
class ListItem
{	
public:
	ListItem() = default;
	ListItem(TValue value) 
	{
		this->value = value;
	}
	
	ListItem<TValue>* next = nullptr;
	TValue value;	
};

