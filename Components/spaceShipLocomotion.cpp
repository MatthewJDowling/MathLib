#include "spaceShipLocomotion.h"
#include "RigidBody.h"
#include "sfwdraw.h"
SpaceShipLocomotion::SpaceShipLocomotion()
{
	vertThrust = 0.0f;
	horzThrust = 0.0f;

	speed = 900.0f; 
	maxSpeed = 1000.0f;
	turnSpeed = 4.0f;
}



void SpaceShipLocomotion::doThrust(float value)
{
	vertThrust += value;
}

void SpaceShipLocomotion::doTurn(float value)
{
	horzThrust += value; 
}

void SpaceShipLocomotion::doStop(float value)
{
	stopAction += value;
}

void SpaceShipLocomotion::update(const Transform &trans, Rigidbody &rigidbody)
{
	
	rigidbody.addForce(trans.getDirection() * speed *vertThrust);
	rigidbody.addTorque(horzThrust * turnSpeed);
	
	horzThrust = vertThrust = 0;


	rigidbody.addForce(-rigidbody.velocity);

	if (rigidbody.velocity.x > 200.0f) rigidbody.velocity.x = 200.0f;
	if (rigidbody.velocity.x < -200.0f) rigidbody.velocity.x = -200.0f;
	if (rigidbody.velocity.y > 200.0f) rigidbody.velocity.y = 200.0f;
	if (rigidbody.velocity.y < -200.0f) rigidbody.velocity.y = -200.0f;
	
}

