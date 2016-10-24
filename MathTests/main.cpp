#include <cassert>
#include <cstdio>
#include "Test.h"
#include <cstdlib>
#include "flops.h"
#include <vec2.h>
#include <vec3.h>
#include <mat3.h>
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
	/*assert(fequals(angleBetween(vec2{ 0,1 }, vec2{ 1,0 }), deg2rad(90)));

	assert(fequals(angleBetween(vec2{ 1,1 }, vec2{ 0,1 }), deg2rad(45)));

	assert(fequals(angleBetween(vec2{ 1,1 }, vec2{ 0,1 }), angle(vec2{ 1,1 })));

	assert(fequals(lerp(.23, 124, 0), .23));
	assert(fequals(lerp(.23, 124, 1), 124));

	assert(fequals(quadBezier(15, 40, 21, 0), 15));
	assert(fequals(quadBezier(15, 40, 21, 1), 21));
*/
	///////////////////////////////////////////////////////////////////////////////////

	//vec3 test
	//	= rotate(deg2rad(-90)) * translate(10, 0) *
	//	rotate(deg2rad(45))* translate(4, 0) *
	//	rotate(deg2rad(45))*translate(-6, 0) *
	//	translate(6, 4)		* vec3 { 0, 0, 1 };

	//assert((test == vec3{ 2 * sqrtf(2), -6 - 2 * sqrtf(2), 1 }));
	

	vec2 WP[8] = { {12,-8},{15,18},{5,8},{-22,-5}, {4,-2}, {-6,9},{18,88},{-22,90} };
	mat3 RES = mat3Identity();
	for (int i = 0; i < 7; ++i)
	{
		vec2 bet = WP[i + 1] - WP[i];
		
		mat3 R = rotate(angle(bet) - angle(RES[0].xy));
		

		mat3 T = translate(magnitude(bet), 0);

		RES = RES * R * T ;

		assert((RES[2].xy == WP[i + 1]));
	}

	

	return 0;
}