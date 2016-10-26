#include <cassert>
#include <cstdio>
#include "Test.h"
#include <cstdlib>
#include "flops.h"
#include <vec2.h>
#include <vec3.h>
#include <mat3.h>
#include "shapes.h"
#include "collision.h"
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
	

	//vec2 WP[8] = { {12,-8},{15,18},{5,8},{-22,-5}, {4,-2}, {-6,9},{18,88},{-22,90} };
	//mat3 RES = mat3Identity();
	//for (int i = 0; i < 7; ++i)
	//{
	//	vec2 bet = WP[i + 1] - WP[i];
	//	
	//	mat3 R = rotate(angle(bet) - angle(RES[0].xy));
	//	

	//	mat3 T = translate(magnitude(bet), 0);

	//	RES = RES * R * T ;

	//	assert((RES[2].xy == WP[i + 1]));
	//}


	/*Circle c = { 0, 0, 5 };


	assert((translate(4, 0) * c == Circle{ 4, 0, 5 }));
	

	assert((scale(2, 1) * c == Circle{ 4, 0, 10 }));
	assert((scale(2, 2) * c == Circle{ 4, 0, 10 }));
	assert((scale(1, 2) * c == Circle{ 4, 0, 10 }));

	assert((scale(-1, 1) * c == Circle{ 0, 0, 5 }));
	
	assert((rotate(45) * c == Circle{ 0, 0, 5 }));
*/
	AABB testA = { 1,2,3,4 };

	assert((testA.min() == vec2{ -2,-2 }));
	assert((testA.max() == vec2{ 4,6 }));

	assert(collisionDection1D(0, 2, 1, 3).result() == true);

	assert(collisionDection1D(0, 2, 1, 3).penetrationDepth == 1);
	assert(collisionDection1D(1, 3, 0, 2).penetrationDepth == 1);

	assert(collisionDection1D(0, 2, 1, 3).collisionNormal == 1);
	assert(collisionDection1D(1, 3, 0, 2).collisionNormal == -1);

	assert(sweptDectection1D(0, 1, 5, 3, 4, 0).entryTime == .4f);

	AABB A = { 0,0, 2,4 };
	AABB B = { 2,2, 2,4 };

	assert(boxCollision(A, B).penetrationDepth == 2);
	assert((boxCollision(A, B).collisionNormal == vec2{ 1, 0 }));
	assert((boxCollision(B, A).collisionNormal == vec2{ -1, 0 }));
	getchar();
	return 0;

	
}