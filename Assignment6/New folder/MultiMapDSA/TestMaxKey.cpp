#include "MultiMap.h"
#include <assert.h>
#include <vector>
#include<iostream>


void testMaxKey() {
	MultiMap m;

	assert(m.maxKey() == -1);

	m.add(1, 100);
	m.add(2, 200);
	m.add(3, 300);
	m.add(1, 500);
	m.add(2, 600);
	m.add(4, 800);

	assert(m.maxKey()==4);
	
}
