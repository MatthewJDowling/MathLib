#include "Player.h"

PlayerShip::PlayerShip()
{
	vec2 hullVrts[] = { { 5,0 },{ -1,2 },{ -1,-2 } };
	collider = Collider(hullVrts, 3);

	transform.m_scale = vec2{ 10,10 };
}

void PlayerShip::update(float deltaTime, Gamestate & gs, PlayerShip &player)
{
	locomotion.update(transform, rigidbody);
	controller.update(locomotion);
	rigidbody.integrate(transform, deltaTime);

	rigidbody.addForce(vec2{0,-500});

	if (player.grounded == true)
	{
		if (sfw::getKey(controller.CTR_UP))
		{
			rigidbody.addForce(vec2{ 0,300 });
			player.grounded = false; 
		}
	}
	
}

void PlayerShip::draw(const mat3 &camera)
{
	//transform.debugDraw(camera);
	collider.DebugDraw(camera, transform);
	//rigidbody.debugDraw(camera, transform);*/
	render.draw(camera, transform);
}
