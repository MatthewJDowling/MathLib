#include "collision.h"
#include <cmath>
CollisionData1D collisionDection1D(float Amin, float Amax, float Bmin, float Bmax)
{
	CollisionData1D retval; 

	float duck = (Amax - Bmin);
	float luck = (Bmax - Amin);

	retval.penetrationDepth = fmin(duck, luck);

    retval.collisionNormal = copysignf(1, luck - duck);

	return retval; 
}

SweptCollisionData1D sweptDectection1D(float Amin, float Amax, float Avel,
	float Bmin, float Bmax, float Bvel)
{
	SweptCollisionData1D retval; 

	float shucks, bucks; 
	
	shucks = (Amin - Bmax) / (Bvel - Avel);
	bucks = (Bmin - Amax) / (Avel - Bvel);

	retval.entryTime = fmin(shucks, bucks);
	retval.exitTime =  fmax(shucks, bucks);

	retval.collisionNormal = copysignf(1, shucks - bucks);

	return retval; 
}

CollisionData boxCollision(const AABB & A, const AABB & B)
{
	CollisionData retval;

	CollisionData1D XCD = 
			collisionDection1D(A.min().x, A.max().x,
							   B.min().x, B.max().x);
	CollisionData1D YCD =
		collisionDection1D(A.min().y, A.max().y,
			               B.min().y, B.max().y);
	if (XCD.penetrationDepth < YCD.penetrationDepth)
	{
		retval.penetrationDepth = XCD.penetrationDepth;
		retval.collisionNormal = vec2{ 1,0 } *XCD.collisionNormal;
	}
	else
	{
		retval.penetrationDepth = YCD.penetrationDepth;
		retval.collisionNormal = vec2{ 0,1 } *YCD.collisionNormal;
	}
	return retval;
}

CollisionDataSwept boxCollisionSwept(const AABB & A, const vec2 & dA, const AABB & B, const vec2 & dB)
{
	CollisionDataSwept retval;
	/*

	float Ducks = (A.min().x - B.max().x) / (dB.x - dA.x);
	float Chucks = (B.min().x - A.max().x) / (dA.x - dB.x);
	float entryX;
	float exitX;
	float entryY;
	float exitY;

	entryX = fminf(Ducks, Chucks);
	exitX = fmaxf(Ducks, Chucks);
	retval.collisionNormal.x = copysignf(1, Chucks - Ducks);

	float Shucks = (A.min().y - B.max().y) / (dB.y - dA.y);
	float Bucks = (B.min().y - A.max().y) / (dA.y - dB.y);

	entryY = fminf(Shucks, Bucks);
	exitY = fmaxf(Shucks, Bucks);



	retval.collisionNormal.y = copysignf(1, Bucks - Shucks);

	retval.entryTime = fmaxf(entryX, entryY);
	retval.exitTime = fminf(exitX, exitY);*/

	SweptCollisionData1D Xres = sweptDectection1D(
		A.min().x, A.max().x, dA.x, B.min().x, B.max().x, dB.x);

	SweptCollisionData1D Yres = sweptDectection1D(
		A.min().y, A.max().y, dA.y, B.min().y, B.max().y, dB.y);

	vec2 axis;
	float hand;

	if (Yres.entryTime < Xres.entryTime && !isinf(Xres.entryTime))
	{
		retval.collisionNormal = vec2{ 1,0 } *Xres.collisionNormal;
		retval.entryTime = Xres.entryTime;
	}
	else
	{
		retval.collisionNormal = vec2{ 0,1 } *Yres.collisionNormal;
		retval.entryTime = Yres.entryTime;
	}

	if (Yres.exitTime < Xres.exitTime && isinf(Yres.exitTime))
	{
		retval.exitTime = Yres.exitTime;
	}
	else
	{
		retval.exitTime = Xres.exitTime;
	}

	return retval;

					
}

bool CollisionData::result() const
{
	return penetrationDepth >= 0; 
}



bool SweptCollisionData1D::result() const
{
	return entryTime >= 0 && entryTime <= 1;
}

bool CollisionData1D::result() const
{
	return penetrationDepth >= 0;
}
