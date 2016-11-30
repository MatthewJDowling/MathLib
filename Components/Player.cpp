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
			//gs.grapple.rigidbody.isGravity = false; 
			gs.grapple.timer = 1.f;

			gs.grapple.transform.m_position = transform.m_position;
			gs.grapple.transform.m_facing = transform.m_facing - 50.f;

			gs.grapple.rigidbody.velocity = vec2{ 0,0 };
			gs.grapple.rigidbody.addImpulse(transform.getDirection() * 2000.f);
		}
	}
	
	if (player.isHitUp == true)
	{
		rigidbody.addImpulse(vec2{ 0,2500 });
		player.isHitUp = false; 
	}
	if (player.isHitRight == true)
	{
		rigidbody.addImpulse(vec2{ 2500,0 });
		player.isHitRight = false;
	}
	if (player.isHitLeft == true)
	{
		rigidbody.addImpulse(vec2{ -2500,0 });
		player.isHitLeft = false;
	}

	
	
	/*if (sfw::getKey('D'))
		rigidbody.addForce(vec2{ 20000,0 });
	if (sfw::getKey('A'))
		rigidbody.addForce(vec2{ -20000,0 });*/


	
		
}

void PlayerShip::draw(const mat3 &camera)
{
	//transform.debugDraw(camera);
	//collider.DebugDraw(camera, transform);
	//rigidbody.debugDraw(camera, transform);
	render.draw(camera, transform);
}
