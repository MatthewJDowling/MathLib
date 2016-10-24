#pragma once
#include "spaceShipLocomotion.h"

class SpaceshipController
{
public:
	char CTR_LEFT, CTR_RIGHT, CTR_UP, CTR_DOWN, CTR_BREAK;

	SpaceshipController(char a_CTR_LEFT, char a_CTR_RIGHT,
		char a_CTR_UP, char a_CTR_DOWN , char a_CTR_BREAK);

	void update(SpaceShipLocomotion &loco);


};