#include "Player.h"
#include "Gamestate.h"
PlayerShip::PlayerShip()
{
	vec2 hullVrts[] = { { 5,0 },{ -1,2 },{ -1,-2 } };
	collider = Collider(hullVrts, 3);

	transform.m_scale = vec2{ 10,10 };
}

void PlayerShip::update(float deltaTime, Gamestate & gs, PlayerShip &player)
{
	locomotion.update(transform, rigidbody);

	rigidbody.integrate(transform, deltaTime);

	if (rigidbody.isGravity == true)
	{
		rigidbody.addForce(vec2{ 0,-500 });
	}
	

	if (player.grounded == true)
	{
		if (sfw::getKey('W'))
		{
			rigidbody.addForce(vec2{ 0,50000 });
			
			player.grounded = false; 
		}
	}
	
	if (sfw::getKey('D'))
		rigidbody.addForce(vec2{ 20000,0 });
	if (sfw::getKey('A'))
		rigidbody.addForce(vec2{ -20000,0 });

	if (sfw::getKey(' ') && !gs.grapple.isAlive)
	{
		gs.grapple.rigidbody.isGravity = false; 
		gs.grapple.timer = 3.f; 

		gs.grapple.transform.m_position = transform.m_position;
		gs.grapple.transform.m_facing = transform.m_facing - 50.f;

		gs.grapple.rigidbody.velocity = vec2{ 0,0 };
		gs.grapple.rigidbody.addImpulse(transform.getDirection() * 1500.f);
	}
	
		
}

void PlayerShip::draw(const mat3 &camera)
{
	//transform.debugDraw(camera);
	//collider.DebugDraw(camera, transform);
	//rigidbody.debugDraw(camera, transform);
	render.draw(camera, transform);
}
