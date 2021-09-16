#include "Headers.h"

void Repository::AddItem(const string&category, const string& name, const double price, size_t amount)
{
	Item tmp_item(category, name, price, amount);

	auto posIt = _items.begin();
	for (; posIt != _items.end(); posIt++)
	{
		if (name == posIt->GetName())
		{
			posIt->IncreaseAmount();
			return;
		}
	}

	_items.push_back(tmp_item);
}

void Repository::SellItem(const string& name, const size_t amount)
{
	if (!_items.empty())
	{
		bool check = false;

		auto posIt = _items.begin();
		for (; posIt != _items.end(); posIt++)
		{
			if (name == posIt->GetName())
			{
				check = true;
				posIt->DecreaseAmount(amount);
				break;
			}
		}

		if (check)
		{
			check = false;
			Item item_tmp = *posIt;
			item_tmp.SetAmount(0);

			_soldItems.push_back(item_tmp);

			for (size_t i = 0; i < _soldItems.size(); i++)
			{
				if (item_tmp.GetName() == _soldItems[i].GetName())
				{
					check = true;
					_soldItems[i].IncreaseAmount(amount);
					break;
				}
			}

			if (check == false)
			{
				_soldItems.back().SetAmount(1);
			}
			
			if (posIt->GetAmount() == 0)
			{
				_items.erase(posIt);
			}
		}
		else
		{
			throw exception(("Such item doesn't exist in the repository"));
		}
	}
	else
	{
		throw exception(("The list is empty"));
	}
}

double Repository::CalculateYield()
{
	double yield = 0;

	for (size_t i = 0; i < _soldItems.size(); i++)
	{
		yield += _soldItems[i].GetPrice() * _soldItems[i].GetAmount();
	}

	return yield;
}

size_t Repository::CountCategories()
{
	size_t counter = 1;
	bool check = false;

	list<Item> tmpList;

	auto posIt = _items.begin();
	tmpList.push_back(*posIt);
	posIt++;
	auto tmpPosIt = tmpList.begin();
	for (; posIt != _items.end(); posIt++)
	{
		for (tmpPosIt = tmpList.begin(); tmpPosIt != tmpList.end(); tmpPosIt++)
		{
			if (posIt->GetCategory() == tmpPosIt->GetCategory())
			{
				check = true;
				tmpList.push_back(*posIt);
				break;
			}
		}
		if (check == false)
		{
			counter++;
		}
		check = false;
	}

	return counter;
}

size_t Repository::CountUniqueSoldItems()
{
	size_t counter = 1;
	bool check = false;

	vector<Item> tmpVector;

	auto posIt = _soldItems.begin();
	tmpVector.push_back(*posIt);
	posIt++;
	auto tmpPosIt = tmpVector.begin();
	for (; posIt != _soldItems.end(); posIt++)
	{
		for (tmpPosIt = tmpVector.begin(); tmpPosIt != tmpVector.end(); tmpPosIt++)
		{
			if (posIt->GetName() == tmpPosIt->GetName())
			{
				check = true;
				tmpVector.push_back(*posIt);
				break;
			}
		}
		if (check == false)
		{
			counter++;
		}
		check = false;
	}

	return counter;
}

void Repository::ShowCountUniqueItemsInCategory()
{
	size_t counter = 0;

	bool check = false;

	auto posIt = _items.begin();
	auto posIt2 = _items.begin();
	for (; posIt != _items.end(); posIt++)
	{
		for (posIt2 = _items.begin(); posIt2 != _items.end(); posIt2++)
		{
			if (posIt->GetCategory() == posIt2->GetCategory())
			{
				counter++;
			}
		}
		cout << "Count of items in category " << posIt->GetCategory() << " : " << counter << endl;
		counter = 0;
	}
	cout << endl;
}

void Repository::ShowSellingItems()
{
	auto posIt = _items.begin();
	auto posvIt = _soldItems.begin();

	cout << "Items is in stock: \n";

	for (; posIt != _items.end(); posIt++)
	{
		for (; posvIt != _soldItems.end(); posvIt++)
		{
			if (posIt->GetName() != posvIt->GetName())
			{
				cout << posIt->GetName() << " ";
				break;
			}
		}
	}
	cout << endl << endl;
}

void Repository::ShowNotSoldItems()
{
	bool check = false;

	auto posIt = _items.begin();

	cout << "Items which have not been sold: \n";

	for (; posIt != _items.end(); posIt++)
	{
		for (auto posvIt = _soldItems.begin(); posvIt != _soldItems.end(); posvIt++)
		{
			if (posIt->GetName() == posvIt->GetName())
			{
				check = true;
				break;
			}
		}
		if (check == false)
		{
			cout << posIt->GetName() << " ";
		}
		check = false;
	}
	cout << endl << endl;
}

double Repository::GetPrice(const string& name)
{
	double price = 0;

	auto posIt = _items.begin();
	for (; posIt != _items.end(); posIt++)
	{
		if (name == posIt->GetName())
		{
			price = posIt->GetPrice();
			return price;
		}
	}

	if (price == 0)
	{
		throw exception(("Such item doesn't exist in the repository"));
	}
}

