#include <cassert>
#include <cstdio>
#include "Test.h"
#include <cstdlib>
#include "flops.h"
#include <vec2.h>
// All of my reeeeeeeeeeeeeeeeeeeeeeeeeeeeee
int main()
{
	// unit tests
	assert(fequals(1, .99999999f));
	assert(fequals(5.f, 5));

	assert(fequals(dot(vec2{ 5,4 }, vec2{ 1,0 }), 5));
	assert(fequals(dot(vec2{ 5,4 }, vec2{ 0,1 }), 4));

	assert(fequals(deg2rad(90.f), 1.57079632f));





	//change
	assert(fequals(angleBetween(vec2{ 0,1 }, vec2{ 1,0 }), deg2rad(90)));

	assert(fequals(angleBetween(vec2{ 1,1 }, vec2{ 0,1 }), deg2rad(45)));

	assert(fequals(angleBetween(vec2{ 1,1 }, vec2{ 0,1 }), angle(vec2{ 1,1 })));

	assert(fequals(lerp(.23, 124, 0), .23));
	assert(fequals(lerp(.23, 124, 1), 124));

	assert(fequals(quadBezier(15, 40, 21, 0), 15));
	assert(fequals(quadBezier(15, 40, 21, 1), 21));

	///////////////////////////////////////////////////////////////////////////////////





	return 0;
}