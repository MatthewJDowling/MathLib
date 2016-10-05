#include "vec2.h"
#include <cmath>
#include "flops.h"
vec2 operator+(const vec2 & lhs, const vec2 & rhs) //Component Additions
{
	return vec2{ lhs.x + rhs.x, lhs.y + rhs.y };
}
vec2 operator/(const vec2 & lhs, float rhs)
{
	return vec2{ lhs.x/rhs,lhs.y/rhs };
}
vec2 operator-(const vec2 & v)
{
	return v * -1;
}
vec2 operator*(const vec2 &lhs, const vec2 &rhs) // Component Multiplication
{
	return vec2{ lhs.x * rhs.x, lhs.y * rhs.y };
}
vec2 operator/(const vec2 &rhs, const vec2 &lhs ) // Component Divison 
{
	return vec2{ lhs.x / rhs.x, lhs.y / rhs.y };
}
vec2 operator-(const vec2 & lhs, const vec2 & rhs) //Component Subtraction
{
	return vec2{ lhs.x - rhs.x, lhs.y - rhs.y };
}

vec2 & operator+=(vec2 & lhs, const vec2 & rhs)//Assignment Component Addition
{
	return lhs = lhs + rhs; 
}

vec2 & operator-=(vec2 & lhs, const vec2 & rhs)//Assignment Component Subtraction
{
	return lhs = lhs - rhs;
}

vec2 operator *(const vec2 &lhs, float rhs)
{
	return vec2{ lhs.x * rhs, lhs.y * rhs };
}
//vec2 & operator-=(vec2 & lhs, const vec2 & rhs)//Assignment Component Subtraction
//{
//	return lhs = lhs - rhs;
//}

bool operator==(const vec2 & lhs, const vec2 & rhs)// Component Equivalence
{
	return fequals(lhs.x, rhs.x)
		&& fequals(lhs.y, rhs.y);
	//return lhs.x == rhs.x && lhs.y == rhs.y;
}

bool operator!=(const vec2 & lhs, const vec2 & rhs)// Component Non-Equivalence
{
	return !(lhs == rhs);
}

float magnitude(const vec2 &v) //Magnitude 
{
	return sqrt((v.x*v.x) + (v.y * v.y));
}
//divide vector by magnitude 
vec2 normal(const vec2 & v)
{
	return v / magnitude(v);
}

float dot(const vec2 & rhs, const vec2 & lhs)
{
	return lhs.x * rhs.x + lhs.y * rhs.y;
}

float angleBetween(const vec2 & rhs, const vec2 & lhs)
{
	return acos(dot(normal(rhs), normal(lhs)));
}
//(y,-x)
vec2 perp(const vec2 & v)
{
	return{ v.y,-v.x };
}
vec2 fromAngle(float a)
{
	return vec2{ cos(a), sin(a) };
}
// tan(a) = Y/X
// arctan(tan(a)) = arctan(Y/X)
// a = arctan(Y/X)
// cmath has a function : atan2f(y,x)
float angle(const vec2 & v)
{
	return atan2f(v.y, v.x);
}
