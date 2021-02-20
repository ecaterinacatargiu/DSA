#include "IteratorMultiMap.h"
#include "MultiMap.h"
#include <stdexcept>

//Iterator constructure - complexity theta(1)
IteratorMultiMap::IteratorMultiMap(const MultiMap& m) : m(m) {
	dllMap = m.dllMap;
	currentNode = m.dllMap->head;
	
}
//point to the first elem - complexity theta(1)
void IteratorMultiMap::first() {
	currentNode = m.dllMap->head;
}

//next elem - complexity theta(1)
void IteratorMultiMap::next() {
	if (!valid()) {
		throw std::runtime_error("Invalid iterator");
	}
	if (currentNode != NULL) {
		currentNode = currentNode->next;
	}
}
//validator - complexity theta(1)
bool IteratorMultiMap::valid() const {
	
	if (currentNode!= NULL)
		return true;
	return false;
	
}
//current elem - complexity theta(1)
TElem IteratorMultiMap::getCurrent() const {
	if (!valid()) {
		throw std::runtime_error("Invalid iterator");
	}
	return currentNode->element;
}