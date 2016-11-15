#pragma once
#include "shapes.h"
#include "Transform.h"
#include "collision.h"
#include "RigidBody.h"
class Collider
{
public:
	AABB box;
	Hull hull;

	Collider(const vec2 *verts, int size);

	void DebugDraw(const mat3 &T, const Transform &Trans);

};

CollisionData ColliderCollision(const Transform &AT, const Collider &AC,
								const Transform &BT, const Collider &BC);


CollisionData StaticResolution
	(Transform &AT, Rigidbody &AR, const Collider & AC,
	const Transform &BT, const Collider &BC);

CollisionData DynamicResolution
(Transform &AT, Rigidbody &AR, const Collider &AC,
	Transform &BT, Rigidbody &BR, const Collider &BC, float bounciness = 1);