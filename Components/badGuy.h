#pragma once
#include "Transform.h"
#include "Collider.h"
#include "RigidBody.h"


class BadGuy
{
public:
	Transform	transform;
	Collider	collider;
	Rigidbody	rigidbody;

	BadGuy();

	void update(float deltaTime, class Gamestate & gs);
	void draw(const mat3 & camera);

	vec2 badGuyMS;

	bool turnNow; 

};