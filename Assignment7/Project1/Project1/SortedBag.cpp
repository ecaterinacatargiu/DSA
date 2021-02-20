#include "SortedBag.h"
#include <iostream>
using namespace std;
SortedBag::SortedBag(Relation r) : r{ r }, root{ nullptr }, sizee{ 0 }{}


///Worst case: O(1), Best Case: O(1), Average case: Theta(n)
void SortedBag::initNode(TComp e)
{
	auto newNode = new BSTNode;
	newNode->right = nullptr;
	newNode->left = nullptr;
	newNode->info.first = e;

}


///Worst case: O(n), Best Case: O(1), Average case: O(n)
void SortedBag::add(TComp e)
{
	if (root == nullptr) {
		auto newNode = new BSTNode;
		newNode->right = nullptr;
		newNode->left = nullptr;
		newNode->info.first = e;
		newNode->info.second = 1;
		root = newNode;
	}
	else
	{
		auto node = root;
		bool left = false;
		BSTNode *prev = nullptr;
		while (node != nullptr)
		{
			prev = node;
			if (node->info.first == e)
			{
				node->info.second++;
				sizee++;
				return;
			}
			else if (r(e, node->info.first))
			{
				node = node->left;
				left = true;
			}
			else
			{
				node = node->right;
				left = false;
			}
		}
		auto newNode = new BSTNode;
		newNode->right = nullptr;
		newNode->left = nullptr;
		newNode->info.first = e;
		newNode->info.second = 1;
		if (left)
			prev->left = newNode;
		else
			prev->right = newNode;
	}
	sizee++;
}


///Worst case: O(1), Best Case: O(1), Average case: Theta(n)
int SortedBag::size() const
{
	return sizee;
}

SortedBagIterator SortedBag::iterator()
{
	return SortedBagIterator{ *this };
}


///Worst case: O(1), Best Case: O(1), Average case: Theta(n)
bool SortedBag::isEmpty() const
{
	if (this->sizee == 0)
		return true;
	return false;
}

void SortedBag::addOccurences(int nr, TComp elem)
{
	bool ok = search(elem);
	if (nr < 0)
		throw runtime_error("Negative number");
	else
	{
		if (ok)
		{
			add(nr);
		}
	}
}

SortedBag::~SortedBag()
{
}

static bool search_rec(BSTNode *node, TComp e, Relation r)
{
	if (node== NULL)
		return false;
	else
	{
		if (node->info.first == e)
			return true;
		else
			if (r(e,node->info.first))
				return search_rec(node->left, e,r);
			else
				return search_rec(node->right, e,r);
	}
}


bool SortedBag::search(TComp e)
{
	return search_rec(root, e,r);
}



static BSTNode* remove_rec(BSTNode *node, TComp e, Relation r)
{
	if (node == nullptr)
		return node;
	if (e == node->info.first) {
		if (node->left == nullptr)
		{
			auto tmp = node->right;
			delete node;
			return tmp;
		}
		else if (node->right == nullptr)
		{
			auto tmp = node->left;
			delete node;
			return tmp;
		}
		auto tmp = node->right;
		while (tmp->left != nullptr)
		{
			tmp = tmp->left;
		}
		node->info = tmp->info;
		node->right = remove_rec(node->right, tmp->info.first, r);
	}
	else if (r(e, node->info.first))
		node->left = remove_rec(node->left, e, r);
	else if (!r(e, node->info.first))
		node->right = remove_rec(node->right, e, r);
	return node;
}


bool SortedBag::remove(TComp e)
{
	int before = nrOccurrences(e);
	if (before == 0)
		return false;
	if (before > 1) 
	{
		auto node = root;
		while (node != nullptr) {
			if (node->info.first == e) {
				node->info.second--;
				sizee--;
				break;
			}
			else if (r(e, node->info.first)) {
				node = node->left;
			}
			else {
				node = node->right;
			}
		}
		return true;
	}
	root = remove_rec(root,e,r);
	sizee--;
	return true;
}

///Worst case: O(n), Best Case: O(1), Average case: O(n)
int SortedBag::nrOccurrences(TComp e)
{
	auto it = iterator();
	while (it.valid()) {
		if (it.getCurrent() == e)
		{
			return it.getCurrentFr();
		}
		if (!r(it.getCurrent(), e))
			break;
		it.next();
	}
	return 0;
}
