#include "CollisionInt.h"
#include <iostream>

void PlayerPlatformCollision(PlayerShip & player, Platform plat)
{
	CollisionData result =
		StaticResolution(player.transform, player.rigidbody, player.collider,
			plat.transform, plat.collider,0);

	if (result.result())
	{
		//result.collisionNormal

		float angler = rad2deg(angleBetween(vec2{ 0,1 }, -result.collisionNormal));

	//	std::cout << "GROUND NORMAL:" << angler << "\n";

		player.grounded = player.grounded || angler < 30.f;
	}
}

void PlayerRockCollision(PlayerShip & player, Rock a_rock)
{
	CollisionData result =
		StaticResolution(player.transform, player.rigidbody, player.collider,
			a_rock.transform, a_rock.collider, 1);
		
}

void GrappleRockCollision(Grapple & a_grapple, Rock & a_rock, PlayerShip player)
{
	CollisionData result =
		StaticResolution(a_grapple.transform, a_grapple.rigidbody, a_grapple.collider,
												a_rock.transform, a_rock.collider, 0);
	
	if (result.result())
	{
		a_grapple.isAttached = true; 
	}
}

void PlayerSpikeCollision(PlayerShip & player, Spike a_spike)
{
	CollisionData result =
		StaticResolution(player.transform, player.rigidbody, player.collider,
			a_spike.transform, a_spike.collider, 1);

}