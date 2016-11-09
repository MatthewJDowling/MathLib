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

Plane operator *(const mat3 & T, const Plane & P)
{
	Plane retval; 
	retval.pos =
		(T * vec3{ P.pos.x, P.pos.y,1 }).xy;

	retval.dir =
		normal(T * vec3{ P.dir.x, P.dir.y,0 }).xy;

	return retval; 
}

bool operator==(const Plane &A, const Plane &B)
{
	return A.pos == B.pos && A.dir == B.dir;
}

Hull::Hull(const vec2 * vertices, unsigned vsize)
{
	for (int i = 0; i < vsize; i++)
	{
		vertices[vsize];

		vec2 vecBe = vertices[i] - vertices[i + 1];
		if (i >= vsize - 1)
		{
			vecBe = vertices[i] - vertices[0];
		}
		vec2 vecNorm = normal(vecBe);
		vec2 vecPerp = perp(vecNorm);

		normal1[i] = vecPerp;
			
	}
}

Hull::Hull()
{
}

//bool operator==(const mat3 & T, const Hull & B)
//{
//	return 0;
//}

Hull   operator*(const mat3 &T, const Hull &H)
{
	Hull retval;
	retval.size = H.size;
	for (int i = 0; i < H.size; ++i)
	{
		retval.vertices[i] = (T *vec3{ H.vertices[i].x, H.vertices[i].y, 1 }).xy;
		retval.normal1[i] = (T *vec3{ H.normal1[i].x, H.normal1[i].y, 1 }).xy;
	}
	return retval;
}
