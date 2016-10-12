#include "mat2.h"
#include "flops.h"



vec2 mat2::operator[](unsigned idx) const
{
	return c[idx];
}

vec2 mat2::operator[](unsigned idx)
{
	return c[idx];
}


bool operator == (const mat2 & A, const mat2 & B)
{
	return fequals(A.m[0], B.m[0]) &&
		fequals(A.m[1], B.m[1]) &&
		fequals(A.m[2], B.m[2]) &&
		fequals(A.m[3], B.m[3]);

	
}

mat2 transpose(const mat2 & A)
{
	mat2 retval = A;

	retval.m[1] = A.m[2];
	retval.m[2] = A.m[1];

	return A; 
}


mat2 operator+(const mat2 & A, const mat2 & B)
{
	return mat2{ A.m[0] + B.m[0], A.m[1] + B.m[1],
		A.m[2] + B.m[2], A.m[3] + B.m[3]};
}

mat2 operator-(const mat2 & A, const mat2 & B)
{
	return mat2{ A.m[0] - B.m[0], A.m[1] - B.m[1],
		A.m[2] - B.m[2], A.m[3] - B.m[3] };
}

mat2 operator - (const mat2 & A)
{
	return mat2{ -A.m[0], -A.m[1], -A.m[2], -A.m[3] };
}

mat2 operator * (const mat2 & A, const mat2 & B)
{
	return mat2{ (A.m[0] * B.m[0]) + (A.m[2] * B.m[1]),
				 (A.m[1] * B.m[0]) + (A.m[3] * B.m[1]),
				 (A.m[0] * B.m[2]) + (A.m[2] * B.m[3]),
				 (A.m[1] * B.m[2]) + (A.m[3] * B.m[3]) };
}

vec2 operator * (const mat2 & A, const vec2 & B)
{
	return vec2 { (A.m[0] * B.x) + (A.m[1] * B.y),
			(A.m[2] * B.x) + (A.m[3] * B.y) };
}

mat2 operator * (const mat2 & A, const float & B)
{
	return{ A.m[0] * B,
			A.m[1] * B,
			A.m[2] * B,
			A.m[3] * B };
}

mat2 operator * (const float & A, const mat2 & B)
{
	return B*A;
}


bool operator != (const mat2 & A, const mat2 & B)
{
	return  !fequals(A.m[0], B.m[0]) ||
		    !fequals(A.m[1], B.m[1]) ||
			!fequals(A.m[2], B.m[2]) ||
			!fequals(A.m[3], B.m[3]);
		   
}