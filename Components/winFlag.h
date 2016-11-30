#pragma once
#include "Transform.h"
#include "Collider.h"
#include "RigidBody.h"

class Flag
{
public:
	Transform	transform;
	Collider	collider;
	Rigidbody	rigidbody;

	Flag();

	void update(float deltaTime, class  Gamestate &gs);
	void draw(const mat3 & camera);

};