#pragma once
#include<stdlib.h>
#include <utility>
#include <stdlib.h>

using namespace std;

#define NULL_TVALUE -1

template<typename TValue> class Node
{
private:

	Node<TValue > *prev = NULL;
	Node<TValue > *next = NULL;
	TValue info; //here we keep the information

public:

	Node() = default;
	Node(TValue v) { this->info = v; };

	Node<TValue>* getPrev() { return prev; };
	Node<TValue>* getNext() { return next; };
	TValue getInfo() { return info; };

	void setPrev(Node<TValue>* newPrev) { this->prev = newPrev; };
	void setNext(Node<TValue>* newNext){ this->next = newNext; };
	void setInfo(TValue newInfo) { this->info = newInfo; };
};

