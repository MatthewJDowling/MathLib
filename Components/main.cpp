#include "sfwdraw.h"
#include "flops.h"
#include "vec2.h"
#include "Transform.h"
#include "RigidBody.h"
#include "spaceShipLocomotion.h"
#include "SpaceshipController.h"

void main()
{
	float H = 800;
	float W = 800;
	sfw::initContext(W,H);
	

	Transform playerTransform(400,400);
	Rigidbody playerRigidbody;
	playerRigidbody.velocity = vec2{ 0, 0 };
	
	SpaceshipController spacectrl;
	SpaceShipLocomotion playerLoco;
	while (sfw::stepContext())
	{
		float deltaTime = sfw::getDeltaTime();
		playerRigidbody.integrate(playerTransform, deltaTime);
		playerTransform.debugDraw();
		spacectrl.update(playerLoco);
		playerLoco.update(playerTransform, playerRigidbody, deltaTime);
		playerRigidbody.debugDraw(playerTransform);

		if (playerTransform.position.x < 0)
		{
			playerTransform.position.x = 800;
		}

		else if (playerTransform.position.x > 800)
		{
			playerTransform.position.x = 0;
		}

		if (playerTransform.position.y < 0)
		{
			playerTransform.position.y = 800;
		}

		else if (playerTransform.position.y > 800)
		{
			playerTransform.position.y = 0;
		}
		
	}
	sfw::termContext();
}
