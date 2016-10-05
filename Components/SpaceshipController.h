#pragma once
#include "spaceShipLocomotion.h"

class SpaceshipController
{
public:
	char CTR_LEFT, CTR_RIGHT, CTR_UP, CTR_DOWN, CTR_BREAK;

	SpaceshipController(char a_CTR_LEFT = 'A', char a_CTR_RIGHT = 'D',
		char a_CTR_UP = 'W', char a_CTR_DOWN = 'S', char a_CTR_BREAK = ' ');

	void update(SpaceShipLocomotion &loco);


};