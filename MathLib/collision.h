#pragma once
#include "vec2.h"
#include "shapes.h"

struct CollisionData1D
{
	bool result() const;  // if penetrationDepth >= 0
	float penetrationDepth;
	float collisionNormal; 
	float MTV() const ;  // penetrationDepth * collisionNormal
};

CollisionData1D collisionDection1D(float Amin, float Amax, float Bmin, float Bmax);


struct SweptCollisionData1D
{
	float entryTime, exitTime;
	float collisionNormal; 

	bool result() const; 
};

SweptCollisionData1D sweptDectection1D(float Amin, float Amax, float Avel,
									   float Bmin, float Bmax, float Bvel);


struct CollisionData
{
	float penetrationDepth;
	vec2 collisionNormal;

	bool result() const;
	vec2 MTV() const; 
};

CollisionData boxCollision(const AABB &A, const AABB &B);