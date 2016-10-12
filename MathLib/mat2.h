#pragma once
#include "vec2.h"

 union mat2
{
	float m[4];
	float k[2][2];
	vec2 c[2];

	vec2 operator[](unsigned idx) const;
	vec2 operator[](unsigned idx);

};

 bool operator == (const mat2 & A, const mat2 & B);

 bool operator !=(const mat2 & A, const mat2 & B);

 mat2 transpose(const mat2 & A);

 mat2 operator+(const mat2 & A, const mat2 & B);

 mat2 operator-(const mat2 & A, const mat2 & B);

 mat2 operator - (const mat2 & A);

 mat2 operator * (const mat2 & A, const mat2 & B);

 mat2 operator * (const mat2 & A, const mat2 & B);

 vec2 operator *(const mat2 & A, const vec2 & B);

 mat2 operator *(const mat2 & A, const float & B);

 mat2 operator * (const float & A, const mat2 & B);







