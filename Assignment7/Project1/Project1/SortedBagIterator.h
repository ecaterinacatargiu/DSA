#pragma once
#include "SortedBag.h"
#include <vector>
#include <stack>

struct BSTNode;

typedef int TComp;
typedef TComp TElem;
typedef int TFrequency;
typedef std::pair<TComp, TFrequency> TPair;

typedef bool(*Relation)(TComp, TComp);
class SortedBag;


class SortedBagIterator {
	friend class SortedBag;
private:
	const SortedBag &bag;
	BSTNode *current;
	std::stack <BSTNode*> s;
	int currentIdx;
	SortedBagIterator(SortedBag &bag);

public:

	void first();
	void next();
	bool valid() const;
	TComp getCurrent();
	TComp getCurrentFr();
	
};
