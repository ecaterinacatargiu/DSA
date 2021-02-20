#pragma once
#include<stdlib.h>
#include<utility>
#include"DLL.h"
#include "MapIterator.h"

#define NULL_TVALUE -1

typedef int TKey;
typedef int TValue;

typedef std::pair<TKey, TValue> TElem;

//class MapIterator;

class Map
{
private:
	DLL<pair<TKey, TValue>>* map = new DLL<pair<TKey,TValue>>();

public: 
	 
	Map() = default;

	TValue add(TKey k, TValue v);
	TValue search(TKey k) const;
	TValue remove(TKey k);

	int size() const;
	bool isEmpty() const;

	MapIterator<pair<TKey, TValue>>* iterator() const;

	~Map();

};