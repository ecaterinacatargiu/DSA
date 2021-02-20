#include "MultiMap.h"
#include <iostream>

///Worst case: O(1), Best Case: O(1), Average case: Theta(1)
int hashT(TKey key, int m) 
{
	double nr = (double)key * 0.6180339887;
	double frac = nr - std::floor(nr);
	return std::floor(m * frac);
}

///Worst case: O(1), Best Case: O(1), Average case: Theta(1)
MultiMap::MultiMap() :_size { 0 }, ht{}
{
	ht.m = 1000;
	ht.arr = new Node*[ht.m]();
	for (int i = 0; i < ht.m; i++)
		ht.arr[i] = nullptr;
	ht.hash = hashT;
}

///Worst case: O(n), Best Case: O(1), Average case: O(n)
void MultiMap::add(TKey c, TValue v)
{
	if ((double)_size / ht.m > 0.7) {
		ht.resize();
	}
	int pos = ht.hash(c, ht.m);
	auto currentN = ht.arr[pos];
	Node *node = new Node;
	node->elem = { c, v };
	node->next = ht.arr[pos];
	ht.arr[pos] = node;
	_size++;
}

///Worst case: O(n), Best Case: O(1), Average case: O(n)
bool MultiMap::remove(TKey c, TValue v)
{
	int poz = ht.hash(c, ht.m);
	auto currentN = ht.arr[poz];
	Node *previous = nullptr;
	while (currentN != nullptr)
	{
		if (currentN->elem.first == c and currentN->elem.second == v)
			break;
		previous = currentN;
		currentN = currentN->next;
	}
	if (currentN == nullptr)
		return false;
	else {
		if (previous != nullptr)
			previous->next = currentN->next;
		else
			ht.arr[poz] = currentN->next;
		delete currentN;
		_size--;
		return true;
	}
}

///Worst case: O(n), Best Case: O(1), Average case: O(n)
vector<TValue> MultiMap::search(TKey c) const
{
	std::vector<TValue> value;
	auto pos = ht.hash(c, ht.m);
	auto currentN = ht.arr[pos];
	while (currentN != nullptr) {
		if (currentN->elem.first == c)
			value.push_back(currentN->elem.second);
		currentN = currentN->next;
	}
	return value;
}

///Worst case: O(1), Best Case: O(1), Average case: Theta(1)
int MultiMap::size() const
{
	return _size;
}

///Worst case: O(1), Best Case: O(1), Average case: Theta(1)
bool MultiMap::isEmpty() const
{
	return _size == 0;
}

///Worst case: O(1), Best Case: O(1), Average case: Theta(1)
MultiMapIterator MultiMap::iterator() const
{
	return MultiMapIterator{ *this };
}

///Worst case: O(n), Best Case: O(1), Average case: O(n)
void MultiMap::filter(Condition cond)
{
	auto currentN = ht.arr[0];
	if (currentN != nullptr && currentN->elem.first == cond(currentN->elem.first))
	{
		TKey c = currentN->elem.first;
		TValue v = currentN->elem.second;
		remove(c, v);
		if (remove(c,v) == true)
			currentN = currentN->next;
	}
}

///Worst case: O(n), Best Case: O(n), Average case: Theta(n)
MultiMap::~MultiMap()
{
	for (int i = 0; i < ht.m; i++) {
		auto currentN = ht.arr[i];
		Node *nextNode = nullptr;
		while (currentN != nullptr) {
			nextNode = currentN->next;
			delete currentN;
			currentN = nextNode;
		}
	}
	delete[] ht.arr;
}

///Worst case: O(n), Best Case: O(n), Average case: Theta(n)
void HashTable::resize()
{
	m *= 2;
	auto **newArr = new Node*[m]();
	int count = m / 2;
	for (int i = 0; i < count; i++) {
		auto currentN = arr[i];
		while (currentN != nullptr) {
			int newPos = hash(currentN->elem.first, m);
			auto nextPos = currentN->next;
			currentN->next = newArr[newPos];
			newArr[newPos] = currentN;
			currentN = nextPos;
		}
	}
	delete[] arr;
	arr = newArr;
}
