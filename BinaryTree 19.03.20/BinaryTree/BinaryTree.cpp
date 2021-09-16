#include "Tree.h"
#include <string>
using namespace std;

int main()
{
	Tree<int, string> tree;

	tree.Add(8, "aaaa");
	tree.Add(3, "bbbb");
	tree.Add(10, "cccc");
	tree.Add(1, "dddd");
	tree.Add(6, "eeee");
	tree.Add(9, "ffff");
	tree.Add(14, "gggg");

	tree.Print();

	int minKey = tree.MinKey();
	cout << "Min key: " << minKey << endl;
	cout << "Value for min key: " << tree[minKey] << endl;

	tree.Remove(1);
	tree.Print();

	tree.Remove(14);
	tree.Print();

	tree.Add(1, "qqqq");
	tree.Print();

	tree.Remove(10);
	tree.Print();

	tree.Remove(8);
	tree.Print();

	Tree<int, int> tree2;

	tree2.Add(1, 5);
	tree2.Add(2, 2);
	tree2.Add(3, 6);
	tree2.Add(4, 8);
	tree2.Add(5, 4);
	tree2.Add(6, 3);
	tree2.Add(7, 1);

	try
	{
		tree2.SearchTheBiggerValue();
	}
	catch (string & error)
	{
		cout << "The tree is empty!";
	}

	tree2.Print();

	Tree<int, int> tree3 = tree2;
	cout << "Copy constructor: \n";
	tree3.Print();
	cout << endl << endl;

	Tree<int, int> tree4;
	tree4.Add(5, 2);
	tree4.Add(2, 1);
	tree4.Add(7, 5);
	tree4.Add(10, 5);
	tree4.Add(1, 1);
	cout << "Tree 4:" << endl;
	tree4.Print();

	Tree<int, int> tree5 = tree4;
	cout << "Copy constructor tree4 -> tree5: \n";
	tree5.Print();
	cout << endl << endl;

	Tree<int, int> tree6;
	tree6 = tree5;
	cout << "Assignment operator tree5 -> tree6: \n";
	tree6.Print();
	cout << endl << endl;

	Tree<int, int> tree7{ {5,2},{2,1},{7,5},{10,5},{1,1} };
	cout << "Initializer list: \n";
	tree7.Print();

}
