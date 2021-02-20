#pragma once


typedef int TElem;


class DynamicArray {


private:

	/*representation of Dynamic Array*/
	int size, capacity;
	TElem* elems;

	DynamicArray(const DynamicArray& v); //copy constructor


public:

	//DynamicArray() = default;

	//constructor
	//throws exception if capacity is 0 or negative
	DynamicArray(int capacity);

	

	//returns the size (number of elements) from the DynamicArray
	int getSize() const;

	//returns the element from a given position (indexing starts from 0)
	//throws exception if pos is not a valid position
	TElem getElement(int pos) const;


	//changes the element from a pozition to a different value
	//returns the old element from pozition poz
	//throws exception if pos is not a valid position
	TElem setElement(int pos, TElem newElem);

	//adds a new element to the end of the DynamicArray
	void addToEnd(const TElem& newElem);

	//adds a new element to a given position in a DynamicArray
	//throws exception if pos is not a valid position
	void addToPosition(int pos, const TElem& newElem);

	//removes an element from a given position
	//returns the removed element
	//throws exception if pos is not a valid position
	TElem remove(int pos);

	//checks if the elem is in the dynamic array or not(returns true or false)
	bool checkElement(const TElem elem) const;

	//returns the position of a given element and -1 otherwise
	int getPosition(const TElem elem);

	//returns an iterator for the DynamicArray
	//int iterator() const;

	//check if the dynamic array is empty or not(true/false)
	bool isEmpty() const;

	//destructor
	~DynamicArray();

private:
	void resize(double mulFac = 2);

};
