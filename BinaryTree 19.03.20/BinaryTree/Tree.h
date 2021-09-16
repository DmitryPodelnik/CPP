#pragma once
#include <iostream>
using namespace std;

template<typename TKey, typename TValue>
struct Pare
{
	TKey key;
	TValue value;
};

template<typename TKey, typename TValue>
class Tree
{
public:
	Tree() = default;
	Tree(const Tree<TKey, TValue>& obj);
	Tree(Tree<TKey, TValue>&& obj);
	Tree(const initializer_list<Pare<TKey, TValue>>& tree); 
	~Tree()
	{
		RecursiveDestruction(_root);
		_size = 0;
	}

	Tree<TKey, TValue>& operator= (const Tree<TKey, TValue>& obj);
	Tree<TKey, TValue>& operator= (Tree<TKey, TValue>&& obj);

	void Add(TKey key, TValue value);
	void Remove(TKey key);

	void Print() const;

	TKey MinKey() const;

	TValue& operator[] (TKey key);
	const TValue& operator[] (TKey key) const;

private:

	struct Node //узел дерева
	{
		Node* parent = nullptr;
		Node* left   = nullptr;
		Node* right  = nullptr;

		TKey key;
		TValue value;

		bool IsLeaf()
		{
			return left == nullptr && right == nullptr;
		}

		bool HasOnlyOneChild()
		{
			return left != nullptr && right == nullptr ||
				left == nullptr && right != nullptr;
		}

		bool HasTwoChildren()
		{
			return left != nullptr && right != nullptr;
		}
	};

	//поля 
	Node*  _root = nullptr;
	size_t _size = 0;

	//внутренние методы

	void Copy(const Tree<TKey, TValue>& obj);
	void Forward(const Tree<TKey, TValue>& obj);
	void Print(Node* node) const;
	Node* MinNode(Node* node) const
	{
		if (node == nullptr)
			return nullptr;

		Node* minNode = node;

		while (minNode->left != nullptr)
		{
			minNode = minNode->left;
		}

		return minNode;
	}
	Node* SearchNode(TKey key) const
	{
		Node* cursor = _root;
		while (cursor != nullptr)
		{
			if (key == cursor->key)
				return cursor;
			else if (key < cursor->key)
				cursor = cursor->left;
			else
				cursor = cursor->right;
		}

		return nullptr;
	}

	void RecursiveDestruction(Node* node)
	{
		if (node)
		{
			RecursiveDestruction(node->left);
			RecursiveDestruction(node->right);
			delete node;
		}
	}

public:

	void SearchTheBiggerValue(Node* node, Pare<TKey, TValue>& maxValue)
	{
		if(node->left != nullptr)
		{
			SearchTheBiggerValue(node->left, maxValue);
		}
		else if (node->right != nullptr)
		{
			SearchTheBiggerValue(node->right, maxValue);
		}

		if (maxValue.value < node->value)
		{
			maxValue.value = node->value;
			maxValue.key = node->key;
		}
	}

	void SearchTheBiggerValue()
	{
		if (_root == nullptr)
		{
			throw string("The tree is empty!");
		}

		Pare<TKey, TValue> maxValue;
		SearchTheBiggerValue(_root, maxValue);
		cout << "The max value of the tree is " << maxValue.value << endl;
		cout << "The key of the max value of the tree is " << maxValue.key << endl;
	}

	void SearchTheNode(Node* cursor, Node* objCursor)
	{
		if (objCursor)
		{
			if (cursor->left == nullptr && objCursor->left != nullptr)
			{
				Node* newItem = new Node;

				newItem->key = objCursor->left->key;
				newItem->value = objCursor->left->value;
				cursor->left = newItem;
				cursor->left->parent = cursor;

				SearchTheNode(cursor->left, objCursor->left);
			}

			if (cursor->right == nullptr && objCursor->right != nullptr)
			{
				Node* newItem = new Node;

				newItem->key = objCursor->right->key;
				newItem->value = objCursor->right->value;
				cursor->right = newItem;
				cursor->right->parent = cursor;

				SearchTheNode(cursor->right, objCursor->right);
			}
		}
	}
};

template<typename TKey, typename TValue>
inline void Tree<TKey, TValue>::Copy(const Tree<TKey, TValue>& obj)
{
	_size = obj._size;

	if (_size != 0)
	{
		Node* newItem = new Node;
		newItem->value = obj._root->value;
		newItem->key = obj._root->key;
		Node* cursor = nullptr;
		Node* objCursor = obj._root;

		_root = newItem;
		cursor = _root;

		SearchTheNode(cursor, objCursor);
	}
}

template<typename TKey, typename TValue>
inline Tree<TKey, TValue>::Tree(const initializer_list<Pare<TKey, TValue>>& tree)
{
	auto pEl = tree.begin();

	for (size_t i = 0; i < tree.size(); i++)
	{
		Add(pEl->key, pEl->value);
		pEl++;
	}
}

template<typename TKey, typename TValue>
inline Tree<TKey, TValue>::Tree(const Tree<TKey, TValue>& obj)
{
	Copy(obj);
}

template<typename TKey, typename TValue>
inline void Tree<TKey, TValue>::Add(TKey key, TValue value)
{
	Node* newNode = new Node;
	newNode->key = key;
	newNode->value = value;

	if (_root == nullptr)
	{
		_root = newNode;
	}
	else
	{
		Node* cursor = _root;
		Node* current = _root;

		while (cursor != nullptr)
		{
			current = cursor;
			if (key < cursor->key)
			{
				cursor = cursor->left;
			}
			else
			{
				cursor = cursor->right;
			}
		}

		newNode->parent = current;
		if (key < current->key)
		{
			current->left = newNode;
		}
		else
		{
			current->right = newNode;
		}
	}

	_size++;
}

template<typename TKey, typename TValue>
inline Tree<TKey, TValue>::Tree(Tree<TKey, TValue>&& obj)
{
	Forward(obj);
}

template<typename TKey, typename TValue>
inline Tree<TKey, TValue>& Tree<TKey, TValue>::operator=(const Tree<TKey, TValue>& obj)
{
	if (this == &obj)
	{
		return *this;
	}

	if (_root != nullptr)
	{
		this->~Tree();
	}

	Copy(obj);

	return *this;
}

template<typename TKey, typename TValue>
inline Tree<TKey, TValue>& Tree<TKey, TValue>::operator=(Tree<TKey, TValue>&& obj)
{
	if (this == &obj)
	{
		return *this;
	}

	if (_root != nullptr)
	{
		this->~Tree();
	}

	Forward(obj);
}

template<typename TKey, typename TValue>
inline void Tree<TKey, TValue>::Remove(TKey key)
{
	Node* delNode = SearchNode(key);

	if (delNode == nullptr) return;

	if (delNode->HasTwoChildren())
	{
		Node* currentNode = delNode;
		delNode = MinNode(delNode->right);
		
		currentNode->key = delNode->key;
		currentNode->value = delNode->value;
	}

	if (delNode->IsLeaf())
	{
		Node* parent = delNode->parent;
		
		if (parent == nullptr)
			_root = nullptr;
		else
		{
			if (parent->left == delNode)
				parent->left = nullptr;
			else
				parent->right = nullptr;
		}

		delete delNode;
		_size--;
	}
	else if (delNode->HasOnlyOneChild())
	{
		Node* parent = delNode->parent;
		Node* child = delNode->left != nullptr ? delNode->left : delNode->right;

		if (parent == nullptr)
		{
			_root = child;
			child->parent = nullptr;
		}
		else
		{
			if (parent->left == delNode)
				parent->left = child;
			else
				parent->right = child;

			child->parent = parent;
		}

		delete delNode;
		_size--;
	}

}

template<typename TKey, typename TValue>
inline void Tree<TKey, TValue>::Print() const 
{
	Print(_root);
}

template<typename TKey, typename TValue>
inline void Tree<TKey, TValue>::Forward(const Tree<TKey, TValue>& obj)
{
	_root = obj._root;
	obj._root = nullptr;

	_size = obj._size;
	obj._size = 0;
}

template<typename TKey, typename TValue>
inline void Tree<TKey, TValue>::Print(Node* node)const
{
	if (node == nullptr)
		return;

	if (node->left != nullptr)
		Print(node->left);

	cout << node->key << " => " << node->value << endl;

	if (node->right != nullptr)
		Print(node->right);
}

template<typename TKey, typename TValue>
inline TKey Tree<TKey, TValue>::MinKey() const
{
	return MinNode(_root)->key;
}

template<typename TKey, typename TValue>
inline TValue& Tree<TKey, TValue>::operator[](TKey key)
{
	Node* node = SearchNode(key);
	if (node == nullptr)
	{
		cerr << "Error: key not found" << endl;
	}

	return node->value;
}

template<typename TKey, typename TValue>
inline const TValue& Tree<TKey, TValue>::operator[](TKey key) const
{
	Node* node = SearchNode(key);
	if (node == nullptr)
	{
		cerr << "Error: key not found" << endl;
	}

	return node->value;
}
