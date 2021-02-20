#pragma once
#include "DLL.h"
#include <stdlib.h>

template <typename TValue> class MapIterator
{
	friend class Map;
private:

	Node<TValue>* nod;

public:

	MapIterator(DLL<TValue> dll) { nod = dll.getHead(); }

	//void first() { if (valid()) nod = dll.nod.getInfo(); }
	void next() { if (valid()) nod = nod->getNext(); }
	void getPrev() { if (valid()) nod = nod->getPrev(); }
	TValue* getCurrent() { if (valid()) return nod->getInfo(); else return NULL; }
	
	bool valid() { if (nod != NULL) return true; else return false; }



};
