#include "flops.h"
#include "vec2.h"
#define _USE_MATH_DEFINES
#include <cmath>

bool fequals(float lhs, float rhs)
{
	if (fabs(lhs - rhs) < 0.000001)
	{
		return true;
	}
	else
	{
		return false; 
	}
}


float deg2rad(float deg)
{
	return deg * M_PI / 180;
}

float rad2deg(float rad)
{
	return rad * 100 / 3.14;
}

float linearHalf(float x)
{
	return 0.5f*x;
}

float accelerate(float x)// function a
{
	return x*x*x*x;
}

float slow(float x) //function b
{
	return 1 - accelerate(1 - x);
}

float steady(float x) // function c
{
	return -abs(2*(x)-1) + 1;
}

float bounce(float x)
{
	return abs(cos(x * 10) * (1 - x));
}

float bounceFlip(float x)
{
	return 1 - bounce(x);
}

float parabFlip(float x)
{
	return 0  ;
}

//float quadBezier(float start, float mid, float end, float alpha)
//{
//	return
//	lerp(lerp(start,mid,alpha),
//	lerp(mid,end,alpha),alpha);
//
//}

float hermiteSpline(float start, float s_tan, float en, float e_tan, float alpha)
{
	float tsq = alpha*alpha;
	float tcub = tsq* tsq;

	float h00 = 2 * tcub - 3 * tsq + 1;
	float h01 = -2 * tcub + 3 * tsq;
	float h10 = tcub - 2 * tsq + alpha;
	float h11 = tcub - tsq;

	float point = h00 * start + h10 * en + h01 * s_tan + h11 * e_tan;

	return point; 

}

//float cardinalSpline(float start, float mid, float end,float a,float alpha)
//{
//	float tangent0 = (mid - start)* a;
//	float tangent1 = (end - mid) * a;
//	
//	float tsq = alpha * alpha; 
//	float tcub = tsq * alpha;
//
//	float h00 = 2 * tcub - 3 * tsq + 1;
//	float h01 = -2 * tcub + 3 * tsq;
//	float h10 = tcub - 2 * tsq + alpha; 
//	float h11 = tcub - tsq; 
//
//	float point = h00 *start + h10 * tangent0 + h01 * point;
//		return point;
//}
//
//float kittySpline(float start, float mid, float end, float alpha)
//{
//	float tangent0 = (mid - start)* .5;
//	float tangent1 = (end - mid) * .5;
//
//	float tsq = alpha * alpha;
//	float tcub = tsq * alpha;
//
//	float h00 = 2 * tcub - 3 * tsq + 1;
//	float h01 = -2 * tcub + 3 * tsq;
//	float h10 = tcub - 2 * tsq + alpha;
//	float h11 = tcub - tsq;
//
//	float point = h00 *start + h10 * tangent0 + h01 * point;
//	return point;
//}



float lerp(float start, float end, float alpha)
{
	return (1 - alpha) * start + (alpha)* end;

	
}

