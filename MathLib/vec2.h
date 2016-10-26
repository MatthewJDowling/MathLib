#pragma once

union vec2
{
	float v[2];
	struct 
	{
		float x, y;
	};

	float operator[](unsigned idx) const;
	float &operator[](unsigned idx);
}; 

vec2 operator+(const vec2&lhs, const vec2 &rhs);
vec2 operator*(const vec2 &lhs, float rhs);
vec2 operator/(const vec2 &lhs, float rhs);
vec2 operator-(const vec2 &v);

vec2 operator-(const vec2 & lhs, const vec2 & rhs); //Component Subtraction



vec2 &operator+=(vec2 &lhs, const vec2 &rhs);
vec2 &operator-=(vec2 &lhgs, const vec2 &rhs);
vec2 &operator*=(vec2 &lhs, float rhs);
vec2 &operator/=(vec2 &lhs, float rhs);

bool operator==(const vec2 &lhs, const vec2 &rhs);
float magnitude(const vec2 &v);

// make the vector have a length of 1
// v/magnitude(v)
vec2 normal(const vec2 & v);

// cosine of the angle between two vectors.
// scalar projection- how far two vectors share the same direction.
float dot(const vec2 &rhs, const vec2 &lhs);

// acos(dot(normal(rhs),normal(lhs))) ( radians )
float angleBetween(const vec2 &rhs, const vec2 &lhs);

// (y,-x)
vec2 perp(const vec2 & v);

vec2 fromAngle(float a);
// tan(a) = Y/X
// arctan(tan(a)) = arctan(Y/X)
// a = arctan(Y/X)
// cmath has a function : atan2f(y,x)
float angle(const vec2 &v);


vec2 lerp(const vec2 &start, const vec2 &end, float alpha);


vec2 min(const vec2 &A, const vec2 &B);
vec2 max(const vec2 &A, const vec2 &B);