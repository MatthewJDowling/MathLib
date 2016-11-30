#include "Collider.h"
#include "shapeDraw.h"
#include <cmath>
Collider::Collider()
{
}
Collider::Collider(const vec2 * verts, int size)
	:hull(verts, size)
{
	int maxX = -INFINITY;
	int minx =  INFINITY;
	int maxY = -INFINITY;
	int minY =  INFINITY;
	
	for (int i = 0; i < size; i++)
	{
		if (verts[i].x < minx)
		{
			minx = verts[i].x;
		}
		if (verts[i].x > maxX)
		{
			maxX = verts[i].x;
		}
		if (verts[i].y < minY)
		{
			minY = verts[i].y;
		}
		if (verts[i].y > maxY)
		{
			maxY = verts[i].y;
		}
	}
	vec2 min{ minx, minY };
	vec2 max{ maxX, maxY };

	box.pos =(min + max) / 2;
	box.he  =(max - min) / 2;



	
}

void Collider::DebugDraw(const mat3 & T, const Transform & Trans)
{
	mat3 glob = T * Trans.getGlobalTransform();

	//drawAABB(glob * box, WHITE);
	drawHull(glob * hull, WHITE);
}

CollisionData ColliderCollision(const Transform & AT, const Collider & AC, const Transform & BT, const Collider & BC)
{
	CollisionData retval;

	retval = boxCollision(AT.getGlobalTransform() * AC.box,
				 BT.getGlobalTransform() *  BC.box);

	if (retval.penetrationDepth >= 0)
	{
		retval = HullCollision(AT.getGlobalTransform() * AC.hull,
			BT.getGlobalTransform() *  BC.hull);
	}

	return retval; 
}

CollisionData StaticResolution(Transform & AT, Rigidbody & AR, const Collider & AC, const Transform & BT, const Collider & BC, float bounciness)
{
	CollisionData results =
		ColliderCollision(AT, AC, BT, BC);

	if (results.penetrationDepth >= 0)
	{

		vec2 a_MTV = results.penetrationDepth * results.collisionNormal;
		AT.m_position -= a_MTV;

		AR.velocity = reflect(AR.velocity, results.collisionNormal) * bounciness ;

	}
	return results;
}

CollisionData DynamicResolution(Transform & AT, Rigidbody & AR, const Collider & AC, Transform & BT, Rigidbody & BR, const Collider &BC, float bounciness)
{
	CollisionData results = ColliderCollision(AT, AC, BT, BC);
	if (results.penetrationDepth >= 0)
	{
		vec2 MTV = results.penetrationDepth * results.collisionNormal;

		float am = magnitude(AR.mass * AR.velocity);
		float bm = magnitude(BR.mass * BR.velocity);
		float cm = am + bm;

		AT.m_position -= MTV * (1 - am / cm);
		BT.m_position += MTV * (1 - bm / cm);

		vec2 &A = AR.velocity;
		float &P = AR.mass;
		vec2 X; 

		vec2 &B = BR.velocity;
		float &Q = BR.mass;
		vec2 Y;

		X = (A*P + B * Q + -bounciness *(A - B)*Q) / (Q + P);
		
		Y = bounciness*(A - B) + X; 

		AR.velocity = X; 
		BR.velocity = Y;
	}
	return results;
}
