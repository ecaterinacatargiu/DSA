#pragma once
#include "DynamicArray.h"


typedef int TElem;

class SetIterator;

class Set {

private:

	/* representation of Set*/
	DynamicArray set{10};

public:

	//implicit constructor
	Set();

	//adds an element to the  set
	//if the element was added, the operation returns true, otherwise (if the element was already in the set) 
	//it returns false
	bool add(TElem e);



	//removes an element from the set
	//if the element was removed, it returns true, otherwise false
	bool remove(TElem e);



	//checks if an element is in the  set
	bool search(TElem elem) const;


	//returns the number of elements;
	int size() const;

	const int getElem(int pos) const;

	//checks if the set is empty
	bool isEmpty() const;

	//returns an iterator for the set
	SetIterator iterator() const;



	//destructor
	~Set();



};











