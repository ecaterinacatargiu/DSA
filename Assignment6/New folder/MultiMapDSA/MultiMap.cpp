#include "MultiMap.h"
#include "IteratorMultiMap.h"
#include <iostream>

// MultiMap constructor- complexity theta(1)
MultiMap::MultiMap() {
	dllMap = new DLL();
	dllMap->head = NULL;
	dllMap->tail = NULL;
	
}
//The complexity of add is theta(1)
void MultiMap::add(TKey c, TValue v) {
	
	node* current = dllMap->head;
	node* newNode = new node();
	newNode->element.first = c;
	newNode->element.second = v;
	newNode->next = NULL;
	newNode->prev = dllMap->tail;
	if (dllMap->head == NULL)
	{
		dllMap->head = newNode;
		dllMap->tail = newNode;
	}
	else {
		dllMap->tail->next = newNode;
		dllMap->tail = newNode;
	}
}

//for remove the complexity is BC: theta(1) WC: theta(n) AC: theta(n)
bool MultiMap::remove(TKey c, TValue v) {
	node* n = dllMap->head;
	while (n!=NULL) {
		if (n->element.first == c && n->element.second == v)
		{
			//if the node is head
			if (dllMap->head == n)
				dllMap->head = n->next;

			//change the next and prev only if they are not null
			if (n->next != NULL)
				n->next->prev = n->prev;


			if (n->prev != NULL)
				n->prev->next = n->next;
			
			//delete(n);
			return true;//delete the node
		//	if (n == dllMap->head)
		//	{
		//		//dllMap->head = n->next;
		//		n->next->prev = NULL;
		//		n->next = NULL;
		//		n->prev = NULL;
		//		return true;
		//	}
		//	else if (n == dllMap->tail)
		//	{
		//		//dllMap->tail = n->prev;
		//		n->prev->next = NULL;
		//		n->next = NULL;
		//		n->prev = NULL;
		//		return true;
		//	}
		//	else {
		//		n->next->prev = n->prev;
		//		n->prev->next = n->next;
		//		n->next = NULL;
		//		n->prev = NULL;
		//		return true;
		//	}
		}
		
		n = n->next;
	}
	return false;
}

//the complexity for search is theta(n)
vector<TValue> MultiMap::search(TKey c) const {
	vector<TValue> v;
	node* n = dllMap->head;
	while (n != NULL) {
		if (n->element.first == c)
		{
			v.push_back(n->element.second);
		}
		n = n->next;
	}
	return v;
}

//complexity is theta(n)
int MultiMap::size() const {
	node* n = dllMap->head;
	int count = 0;
	while (n != NULL) {
		count++;
		n = n->next;
	}
	return count;
}

//theta(1)
bool MultiMap::isEmpty() const
{
	return size() == 0;
}

//finds the maximum key from the map
//Complexity: BC: theta(n) 
//            WC: theta(n) 
//            AC: theta(n)
TKey MultiMap::maxKey() const {
	int maxKey = 0;
	node* n = dllMap->head;
	if (n == NULL)
		return NULL_Tkey;
	while (n != NULL) {
		if (n->element.first > maxKey) {
			maxKey = n->element.first;
		}
		n = n->next;
	}
	return maxKey;
}

IteratorMultiMap MultiMap::iterator() const {
	return IteratorMultiMap(*this);
}
//theta(n)
MultiMap::~MultiMap() {
	node* n = dllMap->head;
	while (n)
	{
		node* nextNode = n->next;
		delete n;
		n = nextNode;
	}
	
}


