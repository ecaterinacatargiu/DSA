#include "SortedBag.h"
#include "SortedBagIterator.h"
#include "ShortTest.h"
#include "ExtendedTest.h"
#include <iostream>

using namespace std;

int main()
{
	testAll();
	cout << "Done short" << endl;

	testAllExtended();
	
	system("pause");
	return 0;
}