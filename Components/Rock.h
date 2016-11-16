#pragma once
#include "Transform.h"
#include "Collider.h"
#include "RigidBody.h"

class Rock
{
public:
	Transform	transform;
	Collider	collider;
	Rigidbody	rigidbody;

	Rock();

	void update(float deltaTime, class  Gamestate &gs);
	void draw(const mat3 & camera);

};