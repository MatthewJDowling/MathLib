#include "Player.h"
#include "Gamestate.h"



PlayerShip::PlayerShip()
{
	vec2 hullVrts[] = { { 1,1 },{ -1,1 },{ -1,-1 }, {1,-1} };
	collider = Collider(hullVrts, 4);

	transform.m_scale = vec2{ 10,10 };
}

void PlayerShip::update(float deltaTime, Gamestate & gs, PlayerShip &player)
{
	player.timer -= deltaTime;

	locomotion.update(transform, rigidbody);

	rigidbody.integrate(transform, deltaTime);

	if (player.transform.m_position.y <= -300)
	{
		player.transform.m_position = vec2{ 45,10 };
	}
	if (player.isWin == true)
	{
		player.transform.m_position = vec2{ 45,10 };
		player.isWin = false; 
	}

	if (rigidbody.isGravity == true)
	{
		rigidbody.addForce(vec2{ 0,-500 });
	}
	
	if (player.timer <= 0)
	{
		if (player.grounded == true)
		{
			if (sfw::getKey('W'))
			{
				rigidbody.addImpulse(vec2{ 0,500 });

				player.grounded = false;
			}
		}
		if (grapple.isAttached == false)
		{
			if (sfw::getKey('D'))
				rigidbody.addForce(vec2{ 15000,0 });
			if (sfw::getKey('A'))
				rigidbody.addForce(vec2{ -15000,0 });
		}
		if (sfw::getKey(' ') && !gs.grapple.isAlive)
		{
			// gs.grapple.rigidbody.isGravity = false; 
			gs.grapple.timer = 1.0f;

			gs.grapple.transform.m_position = transform.getGlobalPosition();
			gs.grapple.transform.m_facing = transform.m_facing - 50.f;

			gs.grapple.rigidbody.velocity = vec2{ 0,0 };
			gs.grapple.rigidbody.addImpulse(transform.getDirection() * 2000.f);
		}
	}
	
	if (player.isHitUpBadG == true)
	{
		rigidbody.addImpulse(vec2{ 0,2500 });
		player.isHitUpBadG = false; 
	}
	if (player.isHitRightBadG == true)
	{
		rigidbody.addImpulse(vec2{ -2000,2500 });
		player.isHitRightBadG = false;
	}
	if (player.isHitLeftBadG == true)
	{
		rigidbody.addImpulse(vec2{ 2000,2500 });
		player.isHitLeftBadG = false;
	}
	//////////////////////////////////////
	if (player.isHitUpSpike == true)
	{
		rigidbody.addImpulse(vec2{ 0,750 });
		player.isHitUpSpike = false;
	}
	if (player.isHitRightSpike == true)
	{
		rigidbody.addImpulse(vec2{ 1000,0 });
		player.isHitRightSpike= false;
	}
	if (player.isHitLeftSpike == true)
	{
		rigidbody.addImpulse(vec2{ -1000,0 });
		player.isHitLeftSpike = false;
	}
	
	
	/*if (sfw::getKey('D'))
		rigidbody.addForce(vec2{ 20000,0 });
	if (sfw::getKey('A'))
		rigidbody.addForce(vec2{ -20000,0 });*/


	
		
}

void PlayerShip::draw(const mat3 &camera)
{
	//transform.debugDraw(camera);
	collider.DebugDraw(camera, transform);
	//rigidbody.debugDraw(camera, transform);
	//render.draw(camera, transform);
	collider.color = BLUE;
}
