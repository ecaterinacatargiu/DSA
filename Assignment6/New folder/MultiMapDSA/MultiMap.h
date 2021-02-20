#pragma once
#include <stdexcept>
#include<vector>
#define NULL_Tkey  -1
#include<utility>

using namespace std;

typedef int TKey;

typedef int TValue;

typedef std::pair<TKey, TValue> TElem;

struct node {
	TElem element;
	node* prev;
	node* next;
};

struct DLL {
	node* head;
	node* tail;
};

class IteratorMultiMap;

class MultiMap
{
	friend class IteratorMultiMap;


private:

	/* representation of the MultiMap */
	DLL* dllMap;
	


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

	IteratorMultiMap iterator() const;

	TKey maxKey() const;

	//descturctor

	~MultiMap();





};


