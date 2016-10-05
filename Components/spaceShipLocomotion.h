#pragma once

#include "RigidBody.h"
class SpaceShipLocomotion
{
	

	float vertThrust; //Forward movement
	float horzThrust; // turn
	
	
	float speed;//movement speed
	float maxSpeed; 
	
public:

	SpaceShipLocomotion();

	void doThrust(float);
	void doTurn(float);

	void update(Rigidbody &rigidbody, float deltaTime);
};