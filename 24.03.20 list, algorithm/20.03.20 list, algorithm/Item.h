#pragma once
#include "Headers.h"

class Item
{
public:

	Item(string category, string name, double price, const size_t amount = 1);

	void SetCategory(const string& category) { _category = category; }
	void SetName(const string& name) { _name = name; }
	void SetAmount(const size_t amount) { _amount = amount; }
	void SetPrice(const double price) { _price = price; }
	void IncreaseAmount(const size_t amount = 1) { _amount += amount; }
	void DecreaseAmount(const size_t amount = 1) 
	{ 
		int tmp = _amount - amount;
		if (tmp >= 0)
		{
			_amount -= amount;
		}
		else
		{
			throw exception(("Incorrect the amount"));
		}
	}

	string GetCategory() { return _category; }
	string GetName() { return _name; }
	double GetPrice() { return _price; }
	size_t GetAmount() { return _amount; }


private:

	string _category;
	string _name = ("");
	double _price;
	size_t _amount = 1;

};

