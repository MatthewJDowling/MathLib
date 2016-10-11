#include "RigidBody.h"


Rigidbody::Rigidbody()
{
	force = vec2{ 0,0 };
	impulse = vec2{ 0,0 };
	velocity = vec2{ 0,0 };

	angularVelocity = 0.0f;
	acceleration = vec2{ 0,0 };
	angularAcceleration = 0.0f; 
	torque = 0;
	mass = 1.0f;
	drag = .25f;
	angularDrag = 1.f;
}




void Rigidbody::addForce(const vec2 & a_force)
{
	force += a_force;
}

void Rigidbody::addImpulse(const vec2 & a_impulse)
{
	impulse += a_impulse;
}

void Rigidbody::addTorque(float a_toruqe)
{
	torque += a_toruqe;
}

void Rigidbody::integrate(Transform & trans, float deltatime)
{
	acceleration    = force / mass;
	velocity        += acceleration * deltatime + impulse / mass;
	trans.position  += velocity * deltatime;
	force = impulse = { 0 ,0 };

	//dampening force
	force = -velocity * drag;

	angularAcceleration = torque / mass;
	angularVelocity     += angularAcceleration * deltatime;
	trans.facing        += angularVelocity * deltatime;
	torque			    = 0;

	torque = -angularVelocity * angularDrag;
}

void Rigidbody::debugDraw(const Transform & trans)
{
	vec2 p = trans.position;
	vec2 v = p + velocity; 
	vec2 a = acceleration + p;

	sfw::drawLine(p.x, p.y, v.x, v.y, RED);
	sfw::drawLine(p.x, p.y, a.x, a.y, RED);
}