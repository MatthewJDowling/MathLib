#pragma once

#include "Transform.h"
#include "Collider.h"
#include "RigidBody.h"
#include "SpaceshipController.h"
#include "spaceShipLocomotion.h"
#include "SpaceShipRenderer.h"
#include "sfwdraw.h"
#include "Grapple.h"



class PlayerShip
{
public:
	Transform	transform;
	Collider	collider;
	Rigidbody	rigidbody;
	Grapple grapple;
	
	SpaceShipLocomotion locomotion;
	SpaceshipRenderer render;

	PlayerShip();

	void update(float deltaTime, class  Gamestate &gs, PlayerShip &player);
	void draw(const mat3 & camera);

	bool grounded;
};