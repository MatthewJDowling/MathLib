#include <cassert>
#include <cstdio>
#include "Test.h"
#include <cstdlib>
// what the flim flam
int main()
{
	// unit tests
	assert(doNothing(0) == 5);
	assert(doNothing(-1) == 4);
	assert(doNothing(1) == 8);

	assert(test_quad(0.f) == -7);
	assert(test_quad(1) == -4);
	assert(test_quad(-1) == -8);
	
	assert(quadadd(1, 2, 3) == 0);


	return 0;
}