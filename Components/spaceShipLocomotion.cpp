#include "spaceShipLocomotion.h"
#include "RigidBody.h"
#include "sfwdraw.h"
SpaceShipLocomotion::SpaceShipLocomotion()
{
	vertThrust = 0.0f;
	horzThrust = 0.0f;

	speed = 900.0f; 
	maxSpeed = 1000.0f;
}



void SpaceShipLocomotion::doThrust(float value)
{
	vertThrust = value;
}

void SpaceShipLocomotion::doTurn(float value)
{
	horzThrust = value; 
}

void SpaceShipLocomotion::update(Rigidbody & rigidbody, float deltatime)
{
	/*doThrust();
	doTurn();*/

	rigidbody.acceleration.x = horzThrust * speed;
	rigidbody.acceleration.y = vertThrust * speed;



	if (magnitude(rigidbody.velocity) > maxSpeed)
	{
		vec2 dir = normal(rigidbody.velocity);

		rigidbody.velocity = dir * maxSpeed;
	}
	vertThrust = 0.0f; 
	horzThrust = 0.0f; 
}

