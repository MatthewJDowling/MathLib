#include "Grapple.h"
#include "Player.h"
Grapple::Grapple()
{
	vec2 hullvrts[] = { {0,0},{5,5} };

	collider = Collider(hullvrts, 2);

	transform.m_scale = vec2{ 8,8 };
	
	rigidbody.mass = 10;
}

void Grapple::update(float deltaTime, Gamestate & gs)
{
	timer -= deltaTime;
	isAlive = timer > 0; 

	if (!isAlive) return;
	rigidbody.integrate(transform, deltaTime);

}

void Grapple::draw(const mat3 & camera)
{
	if (!isAlive) return;
	
	//transform.debugDraw(camera);
	collider.DebugDraw(camera, transform);
	//rigidbody.debugDraw(camera, transform);

}
