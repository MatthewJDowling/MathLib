#include "SpaceshipController.h"

#include "sfwdraw.h"


void SpaceshipController::update(SpaceShipLocomotion & loco)
{
	float hInput;
	hInput -= sfw::getKey('A');
	hInput += sfw::getKey('D');

	float vInput;
	vInput -= sfw::getKey('S');
	vInput += sfw::getKey('W');

	loco.doTurn(hInput);
	loco.doThrust(vInput);
}
