#pragma once

#include "mat3.h"

struct Circle 
{ 
	vec2 pos; 
	float rad;  
};
struct AABB   
{
	vec2 pos, he;

	vec2 min() const;
	vec2 max() const;
};
////////////////////////////////////////////////
struct Plane  
{
	vec2 pos, dir; 
};

Plane operator*(const mat3 &T, const Plane &P);
bool operator==(const Plane &A, const Plane &B);

///////////////////////////////////////////////
struct Ray    { };
struct Hull   
{ 
	
	vec2 vertices[16];
	vec2 normal1[16];
	unsigned int size;

	float min(const vec2 &axis) const; 
	float max(const vec2 &axis) const; 

	Hull(const vec2 * a_vertices, unsigned a_vsize);
	Hull();

};



Hull   operator*(const mat3 &T, const Hull   &H);

Circle operator*(const mat3 &T, const Circle &C);

AABB   operator*(const mat3 &T, const AABB   &B);

Plane  operator*(const mat3 &T, const Plane  &P);



bool operator== (const Circle &A, const Circle & B);
bool operator== (const Hull &A, const Hull & H);