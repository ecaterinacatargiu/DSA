#include "BinaryHeap.h"
#include <algorithm>
#include <iostream>

using namespace std;

void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

BinaryHeap::BinaryHeap(const int maxi):
	cap { maxi },
	sum { 0 },
	size{ 0 }
{
	elems = new int[cap];
}

void BinaryHeap::add(int e)
{
	// Add an element. If the capacity it's reached, replace
	// the smallest element with the new one ONLY IF the new
	// element to be added is greater than the smallest in
	// the heap.

	// Complexity: O(logn) - n = heap capacity

	int i = size - 1;

	if (size == cap) {
		if (e > getRoot())
		{
			sum -= elems[0];
			elems[0] = e;
			sum += e;
		}
		MinHeapify(0);
	}
	else {
		size++;
		i = size - 1;
		elems[i] = e;
		sum += e;
	}
	
	//// Recreate heap properties
	//while (i != 0 && elems[parent(i)] > elems[i])
	//{
	//	swap(&elems[i], &elems[parent(i)]);
	//	i = parent(i);
	//}
}

int BinaryHeap::get_sum()
{
	// Return the sum of the k elements
	// Complexity: Theta(1)
	return this->sum;
}

void BinaryHeap::show()
{
	// Display the vector
	// Complexity: Theta(n)

	for (int i = 0; i < this->size; i++)
	{
		cout << this->elems[i] << ' ';
	}
	cout << '\n';
}

void BinaryHeap::MinHeapify(int p)
{
	// Turn the heap into a MinHeap by comparing the
	// leaves with the parent (both leaves)

	// Complexity: O(logn) - n = heap size

	int l = left(p);
	int r = right(p);
	int smallest = p;

	if (l < size && elems[l] < elems[p])
	{
		smallest = l;
	}

	if (r < size && elems[r] < elems[smallest])
	{
		smallest = r;
	}

	if (smallest != p)
	{
		swap(&elems[p], &elems[smallest]);
		MinHeapify(smallest);
	}
}

BinaryHeap::~BinaryHeap()
{
	delete elems;
}