#include "RigidBody.h"


Rigidbody::Rigidbody()
{
	velocity = vec2{ 0,0 };
	angularVelocity = 0.0f;
	acceleration = vec2{ 0,0 };
	angularAcceleration = 0.0f; 
}


void Rigidbody::integrate(Transform & trans, float deltatime)
{
	velocity += acceleration * deltatime;
	angularVelocity = angularVelocity + angularAcceleration * deltatime;



	trans.position = trans.position + velocity * deltatime;
	trans.facing = trans.facing + angularVelocity * deltatime;
}
