#pragma once

#include "Transform.h"
#include "Collider.h"
#include "RigidBody.h"

class Wall
{
public:
	Transform	transform;
	Collider	collider;
	Rigidbody	rigidbody;

	Wall();

	void update(float deltaTime, class  Gamestate &gs);
	void draw(const mat3 & camera);

};