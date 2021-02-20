#pragma once
#include<vector>
#include<utility>
#include "MultiMapIterator.h"

using namespace std;

class MultiMapIterator;

typedef int TKey;
typedef int TValue;


typedef std::pair<TKey, TValue> TElem;

#define NULL_TVALUE -1

typedef int(*TFunction)(TKey, int);

typedef bool(*Condition)(TKey);

struct Node {
	TElem elem;
	Node *next;
};

struct HashTable
{
	Node **arr;
	int m;
	TFunction hash;

	void resize();
};

class MultiMap
{
	friend class MultiMapIterator;
private:
	/* representation of the MultiMap */
	int _size;
	HashTable ht;

public:
	//constructor
	MultiMap();

	//adds a key value pair to the multimap
	void add(TKey c, TValue v);

	//removes a key value pair from the multimap
	//returns true if the pair was removed (if it was in the multimap) and false otherwise
	bool remove(TKey c, TValue v);

	//returns the vector of values associated to a key. If the key is not in the MultiMap, the vector is empty
	vector<TValue> search(TKey c) const;

	//returns the number of pairs from the multimap
	int size() const;

	//checks whether the multimap is empty
	bool isEmpty() const;

	//returns an iterator for the multimap
	MultiMapIterator iterator() const;

	//keeps in the multimap only those pairs whose key respects the given condition
	void filter(Condition cond);

	//descturctor
	~MultiMap();
};


