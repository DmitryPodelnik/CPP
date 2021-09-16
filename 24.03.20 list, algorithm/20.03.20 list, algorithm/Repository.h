#pragma once
#include "Headers.h"


class Repository
{
public:

	void AddItem(const string& category, const string& name, const double price, size_t amount = 1);
	void SellItem(const string& name, const size_t amount = 1);
	void ShowCountUniqueItemsInCategory();
	void ShowSellingItems();
	void ShowNotSoldItems();
	double CalculateYield();
	size_t CountCategories();
	size_t CountUniqueSoldItems();
	double GetPrice(const string& name);

private:

	list<Item> _items;
	vector<Item> _soldItems;
};

