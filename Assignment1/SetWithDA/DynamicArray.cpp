#include "DynamicArray.h"
#include <stdexcept>


DynamicArray::DynamicArray(int capacity)
{
	this->size = 0;
	this->capacity = capacity;

	if (this->capacity <= 0)
		throw std::invalid_argument("Received negative value");

	this->elems = new TElem[this->capacity];

}

DynamicArray::DynamicArray(const DynamicArray & v)
{
	this->capacity = v.capacity;
	this->size = v.size;

	this->elems = new TElem[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];
}

int DynamicArray::getSize() const
{
	return this->size;
}

TElem DynamicArray::getElement(int pos) const
{
	if (pos < 0 || pos >= this->size)
		throw std::exception("Invalid position!!");

	return this->elems[pos];

	//return this->elems[pos];
}

/*int DynamicArray::getEls()
{
	return this->elems;
}*/




TElem DynamicArray::setElement(int pos, TElem newElem)
{
	if (pos < 0)
		throw std::invalid_argument("Invalid position!");

	TElem old = this->elems[pos];

	this->elems[pos] = newElem;

	return old;

}

void DynamicArray::addToEnd(const TElem& newElem)
{
	if (this->size == this->capacity)
		this->resize(2);

	this->elems[this->size] = newElem;
	this->size++;

}
void DynamicArray::addToPosition(int pos, const TElem& newElem)
{
	if (pos < 0)
		throw std::invalid_argument("Invalid position!");

	if (this->size == this->capacity)
		this->resize(2);

	for (int i = 0; i < this->size; i++)
		if (i == pos)
			this->elems[i] = newElem;

	this->size++;
}

TElem DynamicArray::remove(int pos)
{
	/*if (pos < 0)
		throw std::invalid_argument("Invalid position!");*/

	for (int i = pos; i < this->size; i++)
		this->elems[i] = this->elems[i + 1]; //removes &this->elems[size-1]

	this->size--;
	return TElem();
}

bool DynamicArray::checkElement(const TElem elem) const
{
	for (int i = 0; i < this->size; i++)
		if (elems[i] == elem)
			return true;
	return false;
}

int DynamicArray::getPosition(const TElem elem)
{
	for (int i = 9; i < this->size; i++)
		if (this->elems[i] == elem)
			return i;
	return -1;
}

/*bool DynamicArray::getElement(const TElem elem)
{
	for (int i = 0; i < this->size; i++)
		if (this->elems[i] == elem)
			return true;

	return false;
}*/

void DynamicArray::resize(double mulFac)
{
	this->capacity *= static_cast<int>(mulFac);
	TElem* elms = new TElem[this->capacity];
	for (int i = 0; i < this->size; i++)
		elms[i] = this->elems[i];

	delete[] this->elems;
	this->elems = elms;
}

bool DynamicArray::isEmpty() const
{
	if (this->size == 0)
		return true;
	return false;
}

DynamicArray::~DynamicArray()
{
	//delete[] this->elems;
}