#pragma once
#include <vector>
#include "SortedBagIterator.h"

using namespace std;

typedef int TComp;
typedef TComp TElem;
typedef int TFrequency;
typedef std::pair<TComp, TFrequency> TPair;

typedef bool(*Relation)(TComp, TComp);

class SortedBagIterator;


struct BSTNode {
	TPair info;
	BSTNode *left;
	BSTNode *right;
};


class SortedBag {
private:

	/*representation of SortedBag*/
	friend class SortedBagIterator;
	Relation r;
	BSTNode *root;
	int sizee;


public:

	//constructor
	SortedBag(Relation r);

	void initNode(TComp e);

	//adds an element to the sorted bag
	void add(TComp e);


	//removes one occurrence of an element from a sorted bag
	//returns true if an element was removed, false otherwise (if e was not part of the sorted bag)
	bool remove(TComp e);

	//checks if an element appearch is the sorted bag
	bool search(TComp e);

	//returns the number of occurrences for an element in the sorted bag
	int nrOccurrences(TComp e);

	//returns the number of elements from the sorted bag
	int size() const;

	//returns an iterator for this sorted bag
	SortedBagIterator iterator();

	//checks if the sorted bag is empty
	bool isEmpty() const;

	//adds nr occurences of elem into the SortedBag
	//throws an exception if nr is negative
	void addOccurences(int nr, TComp elem);

	//destructor
	~SortedBag();

};
