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

CollisionData planeBoxCollision(const Plane & P, const AABB & B)
{
	CollisionData retval;

	vec2 BL{ B.min().x, B.min().y },
		 BR{ B.max().x, B.min().y },
		 TL{ B.min().x, B.max().y },
		 TR{ B.max().x, B.max().y };

	float Pmax = dot(P.pos, P.dir);


	float FBL = dot(P.dir, BL),
		  FBR = dot(P.dir, BR),
		  FTL = dot(P.dir, TL),
		  FTR = dot(P.dir, TR);

	float Amin = fminf(fminf(FBL, FBR), fminf(FTL, FTR));
	float Amax = fmaxf(fmaxf(FBL, FBR), fmaxf(FTL, FTR));

	retval.penetrationDepth = Pmax - Amin;
	retval.collisionNormal =  P.dir;

	return retval;
}

CollisionDataSwept planeBoxCollisionSwept(const Plane & P, const AABB & B, const vec2 & vel)
{
	{
		CollisionDataSwept retval;

		vec2 BL{ B.min().x, B.min().y },
			BR{ B.max().x, B.min().y },
			TL{ B.min().x, B.max().y },
			TR{ B.max().x, B.max().y };

		float Pmax = dot(P.pos, P.dir);
		float Bvel = dot(P.pos, vel);

		float FBL = dot(P.dir, BL),
			FBR = dot(P.dir, BR),
			FTL = dot(P.dir, TL),
			FTR = dot(P.dir, TR);

		float Amin = fminf(fminf(FBL, FBR), fminf(FTL, FTR));
		float Amax = fmaxf(fmaxf(FBL, FBR), fmaxf(FTL, FTR));

		retval.entryTime = (Amin - Pmax) / (0 - Bvel);

		retval.exitTime = (Amax - Pmax) / (0 - Bvel);

		return retval;
	}

}

CollisionData HullCollision(const Hull & A, const Hull & B)
{
	int size = 0;
	vec2 axes[32];

	for (int j = 0; j < A.size; j++)
		axes[size++] = A.normal1[j];

	for (int j = 0; j < B.size; j++)
		axes[size++] = B.normal1[j];

	CollisionData retval;
	retval.penetrationDepth = INFINITY;

	for (int j = 0; j < size; j++)
	{
		vec2 axis = axes[j];
		float amin = INFINITY, amax = -INFINITY;
		float bmin = INFINITY, bmax = -INFINITY;

		for (int i = 0; i < A.size; i++)
		{
			float proj = dot(axis, A.vertices[i]);
			amin = fminf(proj, amin);
			amax = fmaxf(proj, amax);
		}

		for (int i = 0; i < B.size; i++)
		{
			float proj = dot(axis, B.vertices[i]);
			bmin = fminf(proj, bmin);
			bmax = fmaxf(proj, bmax);
		}

		float pDR, pDl, pD, H;
		pDR = amax - bmin; 
		pDl = bmax - amin;

		pD = fminf(pDR, pDl);
		H = copysignf(1, pDl - pDR);

		if (pD < retval.penetrationDepth)
		{
			retval.penetrationDepth = pD;
			retval.collisionNormal = axis * H; 
		}
	}

	return retval;
}

CollisionData HullCollisionGroups(const Hull A[], unsigned asize, const Hull B[], unsigned bzise)
{
	CollisionData retval;
	retval.penetrationDepth = INFINITY;
	for(int i = 0; i < asize; i++)
		for (int j = 0; j < bzise; j++)
		{
			CollisionData temp = HullCollision(A[i], B[j]);

			if (temp.penetrationDepth < retval.penetrationDepth)
				retval = temp; 
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
