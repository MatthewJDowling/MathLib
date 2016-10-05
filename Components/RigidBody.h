#pragma once

#include "vec2.h"
#include "Transform.h"

class Rigidbody
{
	public:
		Rigidbody();

		float mass, drag, angularDrag;
		
		vec2 force, impulse;
		vec2 velocity;
		vec2 acceleration; 
		
		
		
		float torque;
		float angularAcceleration; 
		float angularVelocity;

		void addForce(const vec2 &force);
		void addImpulse(const vec2 &impulse);

		void addTorque(float toruqe);

		void integrate(Transform &trans, float deltatime);

		void debugDraw(const Transform & trans);

};