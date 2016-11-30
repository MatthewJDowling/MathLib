#include "CollisionInt.h"
#include <iostream>

void PlayerPlatformCollision(PlayerShip & player,  Platform  & plat)
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

void PlayerRockCollision(PlayerShip & player, Rock & a_rock)
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

void PlayerSpikeCollision(PlayerShip & player,  Spike  & a_spike)
{
	CollisionData result =
		StaticResolution(player.transform, player.rigidbody, player.collider,
			a_spike.transform, a_spike.collider, 1);

	if (result.result())
	{
		if (a_spike.transform.m_facing == 1.57f)
		{
			player.isHitLeft = true; 
			player.timer = 1.25; 
		}
		if (a_spike.transform.m_facing == 0.0f)
		{
			player.isHitUp = true;
			player.timer = 1.25;
		}
		if (a_spike.transform.m_facing == -1.57f)
		{
			player.isHitRight = true;
			player.timer = 1.25;
			
		}
		if (a_spike.transform.m_facing == 3.14f)
		{
			player.isHitDown = true;
			player.timer = 1.25;
		}
		
		
	}

}

void BadGuyBarrierCollision(BadGuy & badguy, Barrier & barrier)
{
	CollisionData result =
		StaticResolution(badguy.transform, badguy.rigidbody, badguy.collider,
			barrier.transform, barrier.collider, 1);

	if (result.result())
	{
		badguy.turnNow = true; 
	}
}
