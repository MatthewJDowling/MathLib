#include "mat3.h"
#include "flops.h"
#include <cmath>

#include "vec3.h"

vec3 mat3::operator[](unsigned idx) const
{
	return c[idx];
}

vec3 &mat3::operator[](unsigned idx)
{
	return c[idx];
}

bool operator==(const mat3 & A, const mat3 & B)
{
	return fequals(A.m[0], B.m[0]) &&
		fequals(A.m[1], B.m[1]) &&
		fequals(A.m[2], B.m[2]) &&
		fequals(A.m[3], B.m[3]) &&
		fequals(A.m[4], B.m[4]) &&
		fequals(A.m[5], B.m[5]) &&
		fequals(A.m[6], B.m[6]) &&
		fequals(A.m[7], B.m[7]) &&
		fequals(A.m[8], B.m[8]);
}

bool operator != (const mat3 & A, const mat3 & B)
{
return  !fequals(A.m[0], B.m[0]) ||
		!fequals(A.m[1], B.m[1]) ||
		!fequals(A.m[2], B.m[2]) ||
		!fequals(A.m[3], B.m[3]) ||
		!fequals(A.m[4], B.m[4]) ||
		!fequals(A.m[5], B.m[5]) ||
		!fequals(A.m[6], B.m[6]) ||
		!fequals(A.m[7], B.m[7]) ||
		!fequals(A.m[8], B.m[8]);

}

mat3 transpose(const mat3 & A)
{
	mat3 retVal = A;

	retVal.m[0] = A.m[0];
	retVal.m[3] = A.m[1];
	retVal.m[6] = A.m[2];

	retVal.m[1] = A.m[3];
	retVal.m[4] = A.m[4];
	retVal.m[7] = A.m[5];

	retVal.m[2] = A.m[6];
	retVal.m[5] = A.m[7];
	retVal.m[8] = A.m[8];

	return retVal;
	
}

mat3 operator +(const mat3 & A, const mat3 & B)
{
	return{ A.m[0] + B.m[0], A.m[1] + B.m[1],
		    A.m[2] + B.m[2], A.m[3] + B.m[3],
			A.m[4] + B.m[4], A.m[5] + B.m[5],
			A.m[7] + B.m[7], A.m[7] + B.m[7],
			A.m[8] + B.m[8] };
}

mat3 operator -(const mat3 & A, const mat3 & B)
{
	return{ A.m[0] - B.m[0], A.m[1] - B.m[1],
		A.m[2] - B.m[2], A.m[3] - B.m[3],
		A.m[4] - B.m[4], A.m[5] - B.m[5],
		A.m[7] - B.m[7], A.m[7] - B.m[7],
		A.m[8] - B.m[8] };
}

mat3 operator - (const mat3 & A)
{
	return mat3{ -A.m[0], -A.m[1], -A.m[2], -A.m[3]
		- A.m[4], -A.m[5], -A.m[6], -A.m[7] 
		- A.m[8]};
}

mat3 operator*(const mat3 & A, const mat3 & B)
{
	return mat3{(A.m[0] * B.m[0]) + (A.m[3] * B.m[1]) + (A.m[6] * B.m[2]),
				(A.m[1] * B.m[0]) + (A.m[4] * B.m[1]) + (A.m[7] * B.m[2]),
				(A.m[2] * B.m[0]) + (A.m[5] * B.m[1]) + (A.m[8] * B.m[2]),

				(A.m[0] * B.m[3]) + (A.m[3] * B.m[4]) + (A.m[6] * B.m[5]),
				(A.m[1] * B.m[3]) + (A.m[4] * B.m[4]) + (A.m[7] * B.m[5]),
				(A.m[2] * B.m[3]) + (A.m[5] * B.m[4]) + (A.m[8] * B.m[5]),

				(A.m[0] * B.m[6]) + (A.m[3] * B.m[7]) + (A.m[6] * B.m[8]),
				(A.m[1] * B.m[6]) + (A.m[4] * B.m[7]) + (A.m[7] * B.m[8]),
				(A.m[2] * B.m[6]) + (A.m[5] * B.m[7]) + (A.m[8] * B.m[8]) };
}

mat3 operator * (const mat3 & A, const float & B)
{
	return{ A.m[0] * B,
			A.m[1] * B,
			A.m[2] * B,
			A.m[3] * B,
			A.m[4] * B,
			A.m[5] * B,
			A.m[6] * B,
			A.m[7] * B,
			A.m[8] * B };
}

vec3 operator * (const mat3 & A, const vec3 & B)
{
	return vec3{ (A.m[0] * B.x) + (A.m[3] * B.y) + (A.m[6] * B.z),
				 (A.m[1] * B.x) + (A.m[4] * B.y) + (A.m[7] * B.z),
				 (A.m[2] * B.x) + (A.m[5] * B.y) + (A.m[8] * B.z) };
		
}

mat3 operator * (const float & A, const mat3 & B)
{
	return B*A;
}

mat3 mat3Identity()
{
	return{ 1,0,0,0,1,0,0,0,1 };
}

float determinant(const mat3 &A)
{
	float B = { (A.m[0] * A.m[4] * A.m[8]) +
		(A.m[3] * A.m[7] * A.m[2]) +
		(A.m[6] * A.m[1] * A.m[5]) -
		(A.m[6] * A.m[4] * A.m[2]) -
		(A.m[3] * A.m[1] * A.m[8]) -
		(A.m[0] * A.m[7] * A.m[5]) };

	return B;
}

mat3 inverse(const mat3 &A)
{

	mat3 retVal;

	retVal[0] = cross(A[1], A[2]);
	retVal[1] = cross(A[2], A[0]);
	retVal[2] = cross(A[0], A[1]);

	return 1 / determinant(A) * transpose(retVal);
}

mat3 scale(float w, float h)
{

	return mat3{ w,0,0,0,h,0,0,0,1 };
	//mat3 retval = mat3Identity();
	//retval[0][0] = w;
	//retval[1][1] = h;
	//return retval; 
}

mat3 translate(float x, float y)
{
	/*mat3 retval = mat3Identity();
	retval[2][0] = a;
	retval[2][1] = b;
	return retval;*/
	return mat3{ {1,0,0,0,1,0,x,y,1} };
}

mat3 rotate(float a)
{
	return mat3{ { cos(a), sin(a), 0,
					-sin(a), cos(a), 0, 
						0,0,1 } };
}
