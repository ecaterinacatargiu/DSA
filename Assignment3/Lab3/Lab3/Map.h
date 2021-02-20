#pragma once
#include<stdlib.h>
#include<utility>
#include"DLL.h"
#include "IteratorDLL.h"

#define NULL_TVALUE -1

typedef int TKey;
typedef int TValue;

typedef std::pair<TKey, TValue> TElem;


/*template <typename TKey, typename TValue>
class Pair {
private:
	TKey key;
	TValue val;

	Pair<TKey, TValue>* next = NULL;
	Pair<TKey, TValue>* prev = NULL;


public:
	Pair() = default;
	Pair(TKey key, TValue val) {
		this->key = key;
		this->val = val;
	}

	TKey getKey() { return key; }
	TValue getValue() { return val; }
	void setKey(TKey key) { this->key = key; }
	void setValue(TValue val) { this->val = val; }



	Pair<TKey, TValue>* getNext() { return next; }
	Pair<TKey, TValue>* getPrev() { return prev; }

	Pair<TKey, TValue>* getPairP() { return key; return val; }

};*/

template <typename TKey, typename TValue>
class Map
{
private:

	DLL<pair<TKey, TValue>>* list = new DLL<pair<TKey, TValue>>();

public:

	Map() = default;

	// adds a pair (key,value) to the map
	//if the key already exists in the map, then the value associated to the key is replaced by the new value and the old value is returned
	//if the key does not exist, a new pair is added and the value null is returned
	TValue add(TKey c, TValue v)
	{
		Node<pair<TKey, TValue>>* current = list->getHead();
		while (current) {
			if (current->getInfo().getKey() == c) {
				TValue val = current->getInfo().getValue();
				current->getInfo().setValue(v);
				return val;
			}
		}
		list->addToBegining(pair<TKey, TValue>(c, v));
		return NULL;
	};


	//searches for the key and returns the value associated with the key if the map contains the key or null: NULL_TELEM otherwise
	TValue search(TKey c) const
	{
		Node<pair<TKey, TValue>>* current = list->getHead();
		//TValue val = 0;
		while (current)
			if (current->getInfo().gettKey() == c) {
				TValue val = current->getInfo().getValue();
				return val;
			}
		return NULL;
	};


	//removes a key from the map and returns the value associated with the key if the key existed ot null: NULL_TELEM otherwise
	TValue remove(TKey c)
	{
		Node<pair<TKey, TValue>>* current = list->getHead();
		while (current) {
			if (current->getInfo().getKey() == c) {
				TValue val = current->getInfo().getValue();
				current->getInfo().setValue(v);
				return val;
			}
		}
		list->removeElem(TValue v);
		return NULL;
	};


	int size() const
	{
		return list->getSize();
	}


	bool isEmpty() const {
		if (list->getSize() == 0)
			return true;
		return false;
	};

	/*Pair getPair(TKey key, TValue val) {
		return Pair<TKey key, TValue val>;
	}*/


	MapIterator iterator() const {
		{
			return IteratorDLL(*this);
		}


		~Map()
		{
		}
};