#include "Set.h"
#include "DynamicArray.h"
#include <stdlib.h>
#include "SetIterator.h"


Set::Set()
{
}

bool Set::add(TElem e)
{
	
	if (this->set.checkElement(e) == false)
	{
		set.addToEnd(e);
		return true;
	}
	return false;
}

bool Set::remove(TElem e)
{
	for (int i = 0; i < this->set.getSize(); i++)
		if (this->set.getElement(i) == e)
		{
			set.remove(i);
			return true;
		}
	return false;
}

bool Set::search(TElem elem) const
{
	if(this->set.checkElement(elem)==true)
		return true;
	return false;
}

int Set::size() const
{
	return this->set.getSize();
}

const int Set::getElem(int pos) const
{
	return this->set.getElement(pos);
}

bool Set::isEmpty() const
{
	bool empty = this->set.isEmpty();
	if (empty == true)
		return true;
	return false;
}

SetIterator Set::iterator() const
{
	return SetIterator(*this);
}


Set::~Set()
{
}
