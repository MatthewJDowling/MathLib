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
