#include "MultiMapIterator.h"

///Worst case: O(n), Best Case: O(1), Average case: O(n)
MultiMapIterator::MultiMapIterator(const MultiMap & mm): mm{mm}, current{nullptr}
{
	first();
}

///Worst case: O(n), Best Case: O(1), Average case: O(n)
void MultiMapIterator::first()
{
	for (currentIdx = 0; currentIdx < mm.ht.m; currentIdx++)
	{
		if (mm.ht.arr[currentIdx] != nullptr)
		{
			current = mm.ht.arr[currentIdx];
			break;
		}
	}
}

///Worst case: O(1), Best Case: O(n), Average case: O(n)
void MultiMapIterator::next()
{
	if (!valid())
		throw std::runtime_error("Iterator not valid");
	if (current->next == nullptr) {
		for (currentIdx = currentIdx + 1; currentIdx < mm.ht.m; currentIdx++)
		{
			if (mm.ht.arr[currentIdx] != nullptr)
			{
				current = mm.ht.arr[currentIdx];
				break;
			}
		}
	}
	else {
		current = current->next;
	}
}

///Worst case: O(1), Best Case: O(1), Average case: Theta(1)
bool MultiMapIterator::valid() const
{
	return current != nullptr and currentIdx < mm.ht.m;
}

///Worst case: O(1), Best Case: O(1), Average case: Theta(1)
TElem MultiMapIterator::getCurrent() const
{
	if (!valid())
		throw std::runtime_error("Iterator not valid!");
	return current->elem;
}

