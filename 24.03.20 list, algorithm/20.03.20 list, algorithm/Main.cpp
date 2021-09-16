#include "Headers.h"

using namespace std;

bool isAFirstCharacter(string str)
{
	return str[0] == 'a';
}

template <typename T>
void print(const list<T>& list)
{
	for (auto el : list)
	{
		cout << el << "\t";
	}
	cout << endl;
}

int main()
{
	///1
	/*
	list<string> list1;
	list1.push_back(("awljda"));
	list1.push_back(("wljda"));
	list1.push_back(("kwljda"));
	list1.push_back(("alwljda"));

	print(list1);

	list1.remove_if(isAFirstCharacter);

	print(list1);
	*/

	///2
	/*
	list<string> list1{ ("BOOK1"), ("BOOK2"), ("BOOK3"), ("BOOK4"), ("BOOK5") };
	list<string> list2{ ("BOOK6"), ("BOOK7"), ("BOOK3"), ("BOOK4"), ("BOOK8") };

	list<string> list3;
	
	auto it = list3.begin();
	list3.splice(it, list1);
	list3.splice(it, list2);
	list3.sort();
	list3.unique();

	print(list3);
	*/

	///3

	Repository repository;

	try
	{
		repository.AddItem(("1"), "a", 5);
		repository.AddItem(("1"), "ab", 5);
		repository.AddItem(("2"), "b", 6, 3);
		repository.AddItem(("3"), "c", 7);
		repository.AddItem(("4"), "d", 8, 3);
		repository.AddItem(("5"), "e", 9);
		repository.AddItem(("6"), "f", 10);
		repository.AddItem(("7"), "g", 12);

		repository.SellItem(("b"));
		repository.SellItem(("e"));
		repository.SellItem(("d"), 2);
		double yield = repository.CalculateYield();
		cout << "Yield for day: " << yield << endl;
		size_t countUniqueItems = repository.CountCategories();
		cout << "Count of unique categories: " << countUniqueItems << endl;
		size_t countUniqueSoldItems = repository.CountUniqueSoldItems();
		cout << "Count of unique sold items: " << countUniqueSoldItems << endl;
		double itemPrice = repository.GetPrice(("c"));
		cout << "Price of the item: " << itemPrice << endl << endl;
		repository.ShowCountUniqueItemsInCategory();
		repository.ShowSellingItems();
		repository.ShowNotSoldItems();

	}
	catch (exception & ex)
	{
		cout << ex.what() << endl;
	}







	return 0;
}