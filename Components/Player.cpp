#include "Player.h"

PlayerShip::PlayerShip()
{
	vec2 hullVrts[] = { { 5,0 },{ -1,2 },{ -1,-2 } };
	collider = Collider(hullVrts, 4);

	transform.m_scale = vec2{ 10,10 };
}

void PlayerShip::update(float deltaTime, GameState & gs)
{
	locomotion.update(transform, rigidbody);
	controller.update(locomotion);
	rigidbody.integrate(transform, deltaTime);
}

void PlayerShip::draw(const mat3 &camera)
{
	transform.debugDraw(camera);
	collider.DebugDraw(camera, transform);
	rigidbody.debugDraw(camera, transform);
}
