#include "sfwdraw.h"
#include "flops.h"
#include "vec2.h"
#include "Transform.h"
#include "RigidBody.h"
#include "spaceShipLocomotion.h"
void main()
{
	float H = 800;
	float W = 800;
	sfw::initContext(W,H);
	

	Transform playerTransform(400,400);
	Rigidbody playerRigidbody;
	playerRigidbody.velocity = vec2{ 0, 0 };
	

	SpaceShipLocomotion playerLoco;
	while (sfw::stepContext())
	{
		float deltaTime = sfw::getDeltaTime();
	
		playerLoco.update(playerRigidbody, deltaTime);
		playerRigidbody.integrate(playerTransform, deltaTime);

		playerTransform.debugDraw();

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
