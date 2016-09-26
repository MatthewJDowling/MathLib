#include "Test.h"
#include <cmath>
int doNothing(int x)
{
	return x*x + 2*x + 5;
}

float test_quad(float x)
{
	return x*x +2*x - 7;
}

float quadadd(float a, float b, float c)
{
	if (sqrt(b*b - 4 * a * c) > 0)
	{
		float add = (-1 * b + sqrt(b*b - 4 * a * c) / 2 * a);
		
		return add;
	}
	else
	{
		return 0;
	}
}

float quadsub(float a, float b, float c)
{
	if (sqrt(b*b - 4 * a * c) > 0)
	{
		float sub = (-1 * b - sqrt(b*b - 4 * a * c) / 2 * a);

		return sub;
	}
	else
	{
		return 0;
	}; 
}

float lerp(float s, float t, float e)
{
	s + t*(e - s);
}
