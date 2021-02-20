#pragma once
#include "MultiMap.h"

class MultiMap;


class IteratorMultiMap {

	friend class MultiMap;

private:
	IteratorMultiMap(const MultiMap& m);
	const MultiMap& m;
	DLL* dllMap;
	node* currentNode;
public:
	void first();
	void next();
	bool valid() const;
	TElem getCurrent() const;


};