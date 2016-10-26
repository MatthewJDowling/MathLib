#pragma once

#include "RigidBody.h"
class SpaceShipLocomotion
{
	

	float vertThrust; //Forward movement
	float horzThrust; // turn
	float stopAction;
	
	float speed;//movement speed
	float maxSpeed; 

	float turnSpeed;
	
public:

	SpaceShipLocomotion();

	void doThrust(float);
	void doTurn(float);

	void update(const Transform &trans, Rigidbody &rigidbody);
	void doStop(float value);
};