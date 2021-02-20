#pragma once
#include <stdlib.h>
#include "Node.h"

template <typename TValue> class DLL {

private:

	Node<TValue>* head = NULL;
	Node<TValue>* tail = NULL;
	int size = 0;

public:

	DLL() = default;

	void addToBegining(TValue v) {

		Node<TValue>* nod = new Node<TValue>(v);

		if (head == NULL)
			tail = nod;

		nod->setNext(head);
		head = nod;
		size++;

	};


	void addToEnd(TValue v) {
		Node<TValue>* nod = new Node<TValue>(v);

		if (head == NULL)
			head = nod;

		nod->setPrev(tail);
		tail = nod;
		size++;
	};


	void addToPos(TValue v, int pos) {
		Node<TValue>* nod = new Node<TValue>(v);

		if (pos == 0)
			addToBegining(v);

		if (pos == size)
			addToEnd(v);

		if (pos < size && pos > 0)
		{
			Node<TValue>* current = head;
			for (int i = 1; i < size; i++) {
				current = current->getNext();
			}

			current->getPrev()->setNext(nod);
			current->setPrev(nod);

			nod->setPrev(current->getPrev());
			nod->setNext(current);

			size++;
		}
	};

	void removeElem(TValue v) {
		Node<TValue>* current = head;

		while (current != NULL && current->getInfo() != v)
		{
			current = current->getPrev();
		}


		if (current->getPrev() == NULL)
			head = current->getNext();
		else
			current->getPrev()->setNext(current->getNext());


		if (current->getNext == NULL)
			tail = current->getPrev();
		else
			current->getNext()->setPrev(current->getPrev());

		size--;
	};


	TValue getElem(int pos) {
		if (pos < size && pos>0)
		{
			Node<TValue>* current = head;
			for (int i; i < pos; i++)
				current = current->getNext();

			return current->getInfo();
		}
	};

	Node<TValue>* getHead() {
		return head;
	};

	Node<TValue>* getTail() {
		return tail;
	};


	int getSize() { return size; };
};

