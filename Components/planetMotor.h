#pragma once
#include "RigidBody.h"

class PlanetaryMotor
{
public:
	float m_rotatespeed;

	void update(Rigidbody &planentRbody);
};