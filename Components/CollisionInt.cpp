#include "CollisionInt.h"

void PlayerPlatformCollision(PlayerShip & player, Platform plat)
{
	CollisionData result =
		StaticResolution(player.transform, player.rigidbody, player.collider,
			plat.transform, plat.collider,0);

	if (result.result())
	{
		player.grounded = true;
	}
}

void PlayerRockCollision(PlayerShip & player, Rock a_rock)
{
	CollisionData result =
		StaticResolution(player.transform, player.rigidbody, player.collider,
			a_rock.transform, a_rock.collider, 1);
		
}

