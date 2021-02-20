#include "Map.h"
#include <iostream>

TValue Map::add(TKey k, TValue v)
{
	std::cout << "Start";
	Node<pair<TKey, TValue>>* current = map->getHead();

	while (current!=NULL)
	{	
		if (current->getInfo()->first == k)
		{
			TValue val = current->getInfo()->second;
			return val;
		}
		current = current->getNext();
	}

	std::cout << "Intermediar";
	map->addToBegining(new pair<TKey, TValue>(k, v));
	std::cout << "Done";

	return NULL_TVALUE;

}


TValue Map::search(TKey k) const
{
	Node<pair<TKey, TValue>>* current = map->getHead();
	while (current != NULL)
	{
		if (current->getInfo()->first == k)
		{
			TValue val = current->getInfo()->second;
			return val;
		}
		current = current->getNext();
	}

	return NULL;
}

TValue Map::remove(TKey k)
{
	Node<pair<TKey, TValue>>*  current = map->getHead();
	while (current != NULL)
	{
		if (current->getInfo()->first == k)
		{
			TValue val = current->getInfo()->second;
			map->removeElem(pair<TKey, TValue>(k, val));
			return val;
		}
		current = current->getNext();
	}
	//map->removeElem(TKey k);
	return NULL;
}



int Map::size() const
{
	return map->getSize();
}

bool Map::isEmpty() const
{
	if (map->getSize() == 0)
		return true;
	return false;
}

MapIterator<pair<TKey, TValue>>* Map::iterator() const
{
	return new MapIterator<pair<TKey, TValue>>( *map );
}

Map::~Map()
{
}
