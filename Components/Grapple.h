#pragma once
#include "Transform.h"
#include "Collider.h"
#include "RigidBody.h"

class Grapple
{
public:
	Transform	transform;
	Collider	collider;
	Rigidbody	rigidbody;

	float timer; 
	bool isAlive; 

	bool isAttached;
	

	Grapple();

	void update(float deltaTime, Transform & target_trans, Rigidbody &target_rbody, class  Gamestate &gs);
	void draw(const mat3 & camera);

};