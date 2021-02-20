#include "SortedBagIterator.h"
#include <iostream>

SortedBagIterator::SortedBagIterator(SortedBag &bag) :bag{ bag }, current{ bag.root }{
	first();
}


///Worst case: O(n), Best Case: O(1), Average case: O(n)
void SortedBagIterator::first()
{
	s = std::stack<BSTNode*>();
	auto node = bag.root;
	while (node != nullptr)
	{
		s.push(node);
		node = node->left;
	}
	if (!s.empty())
	{
		current = s.top();
		currentIdx = current->info.second;
	}
	else
		node = nullptr;
}

///Worst case: O(n), Best Case: O(1), Average case: O(n)
void SortedBagIterator::next()
{
	if (!valid())
		throw runtime_error("Invalid!");
	if (s.empty()) {
		current = nullptr;
		return;
	}
	if (currentIdx > 1) {
		currentIdx--;
		return;
	}
	BSTNode *node = s.top();
	s.pop();
	if (node->right != nullptr)
	{
		node = node->right;
		while (node != nullptr) 
		{
			s.push(node);
			node = node->left;
		}
	}
	if (!s.empty()) {
		current = s.top();
		currentIdx = current->info.second;
	}
	else
		current = nullptr;
}


///Worst case: O(1), Best Case: O(1), Average case: Theta(n)
bool SortedBagIterator::valid() const
{
	return current != nullptr;
}


///Worst case: O(1), Best Case: O(1), Average case: Theta(n)
TComp SortedBagIterator::getCurrent()
{
	if (!valid())
		throw runtime_error("Invalid");
	return current->info.first;
}

///Worst case: O(1), Best Case: O(1), Average case: Theta(n)
TComp SortedBagIterator::getCurrentFr()
{
	return current->info.second;
}
