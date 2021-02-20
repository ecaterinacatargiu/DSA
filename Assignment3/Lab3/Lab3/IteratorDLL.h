#pragma once
#include "DLL.h"
#include <stdlib.h>

template < typename TValue> class IteratorDLL {

private:

	Node<TValue>* nod;

public:

	IteratorDLL(DLL<TValue> dll) {
		nod = dll.getHead();
	};

	void next() {
		if (valid())
			nod = nod->getNext();
	};
	void getPrev() {
		if (valid())
			nod = nod->getPrev();
	};


	TValue getCurrent() {
		if (valid())
			return nod->getInfo();

		return NULL;
	};

	bool valid() {
		if (nod != NULL)
			return true;
		return false;
	};

};

