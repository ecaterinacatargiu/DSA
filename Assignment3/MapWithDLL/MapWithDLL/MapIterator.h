#pragma once
#include "DLL.h"
#include <stdlib.h>

template < typename TValue> class MapIterator
{
	friend class Map;
private:

	Node<TValue>* nod;

public:

	MapIterator(DLL<TValue> dll) { nod = dll.getHead(); }

	void next() { if (valid()) nod = nod->getNext(); }
	void getPrev() { if (valid()) nod = nod->getPrev(); }
	void getCurrent() { if (valid()) return nod->getInfo(); else nod = NULL; }
	
	bool valid() { if (nod != NULL) return true; else return false; }



};
