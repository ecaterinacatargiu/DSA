#include "SetIterator.h"
#include <iostream>
#include <stdlib.h>



SetIterator::SetIterator(const Set& set): set(set)
{
	this->index = 0;
	this->nrElems = 1;
}

void SetIterator::first()
{
	this->index = 0;
	this->nrElems = 1;
}

void SetIterator::next()
{
	if (this->valid())
	{
		this->index++;
		this->nrElems++;
	}
}

bool SetIterator::valid() const
{
	if (this->index >= this->set.size())
		return false;
	return true;
}

TElem SetIterator::getCurrent() const
{
	if (this->valid())
		return this->set.getElem(this->index);
	else
		throw std::exception();
}

