#include "shapes.h"

Circle operator*(const mat3 & T, const Circle & C)
{
	Circle retval; 

	retval.pos = (T * vec3{ C.pos.x, C.pos.y, 1 }).xy;

	float mX = magnitude(T * vec3{ 0, C.rad, 0 });
	float mY = magnitude(T * vec3{ C.rad, 0, 0 });

	retval.rad = mX > mY ? mX : mY; 

	return retval;
	
}

bool operator==(const Circle & A, const Circle & B)
{
	return (A.pos == B.pos) && fequals(A.rad, B.rad);
}

vec2 AABB::min() const
{
	return pos - he;
}

vec2 AABB::max() const
{
	return pos + he;
}

AABB operator*(const mat3 & T, const AABB & box)
{


	AABB retval = box; 

	vec3 tp[4];
	
	tp[0] = T * vec3{ box.min().x, box.min().y, 1};
	tp[1] = T * vec3{ box.max().x, box.max().y, 1 };
	tp[2] = T * vec3{ box.max().x, box.min().y, 1 };
	tp[3] = T * vec3{ box.min().x, box.max().y, 1 };

	vec2 minv = tp[0].xy;
	vec2 maxv = tp[0].xy; 

	for (int i = 1; i < 4; i++)
	{
		minv = min(minv, tp[i].xy);
		maxv = max(maxv, tp[i].xy);
	}
	retval.pos = (minv + maxv) / 2;
	retval.he = (maxv - minv)  / 2; 

	return retval; 
}
