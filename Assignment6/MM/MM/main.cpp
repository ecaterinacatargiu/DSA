#include "MultiMap.h"
#include "MultiMapIterator.h"
#include "ShortTest.h"
#include "ExtendedTest.h"
#include <iostream>


int main()
{
	testAll();
	cout << "Done short test. :)" << endl;

	testAllExtended();
	cout << "Done extended test. :)" << endl;

	system("pause");

	return 0;
}