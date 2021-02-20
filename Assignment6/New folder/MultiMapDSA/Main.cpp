#include "ShortTest.h"
#include "ExtendedTest.h"
#include "TestMaxKey.h"
#include <iostream>
#include <Windows.h>

//using namespace std;

int main() {
	testAll();
	std::cout << "test short passed\n";
	testMaxKey();
	std::cout << "test max key\n";
	testAllExtended();
	std::cout << "passed extended\n";
	system("pause"); 
	
	return 0;
}