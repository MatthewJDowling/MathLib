#pragma once

#include "Transform.h"
#include "Collider.h"
#include "RigidBody.h"
#include "SpaceshipController.h"
#include "spaceShipLocomotion.h"




class PlayerShip
{
public:
	Transform	transform;
	Collider	collider;
	Rigidbody	rigidbody;
	SpaceshipController controller;
	SpaceShipLocomotion locomotion;

	PlayerShip();

	void update(float deltaTime, class  GameState &gs);
	void draw(const mat3 & camera);

};