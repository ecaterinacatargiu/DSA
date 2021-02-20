#pragma once
#include "Set.h"

class Set;
class SetIterator
{
	friend class Set;
private:
	SetIterator(const Set& set);
	const Set& set;

	int index;
	int nrElems;
	

public:
	//SetIterator(const Set& set);
	void first();
	void next();
	bool valid() const;
	TElem getCurrent() const;

	
};

