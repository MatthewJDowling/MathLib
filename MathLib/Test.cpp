#include "Test.h"
#include <cmath>
#include "vec2.h"
//feature vector branch
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

float distance(vec2 first, vec2 second)
{


	// TODO: how to square root?!!!
	float distancex = (second.x - first.x) * (second.x - first.x);
	float distancey = (second.y - first.y) * (second.y - first.y);

	double findDistance = sqrt(distancex + distancey);

	return findDistance;
}

