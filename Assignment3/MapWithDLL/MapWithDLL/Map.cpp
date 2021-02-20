#include "Map.h"

TValue Map::add(TKey k, TValue v)
{
	Node<pair<TKey, TValue>>* current = map->getHead();
	while (current)
		if (current->getInfo().first == k)
		{
			TValue val = current->getInfo().second;
			return val;
		}
	map->addToBegining(pair<TKey, TValue>(k, v));
	return NULL;
}

TValue Map::search(TKey k) const
{
	Node<pair<TKey, TValue>>* current = map->getHead();
	while(current)
		if (current->getInfo().first == k)
		{
			TValue val = current->getInfo().second;
			return val;
		}

	return NULL;
}

TValue Map::remove(TKey k)
{
	Node<pair<TKey, TValue>>*  current = map->getHead();
	while (current)
		if (current->getInfo().first == k)
		{
			TValue val = current->getInfo().second;
			map->removeElem(pair<TKey, TValue>(k, val));
			return val;
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
	return new MapIterator<pair<TKey, TValue>>(*map);
}


Map::~Map()
{
}
