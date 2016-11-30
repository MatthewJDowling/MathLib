#include "barriers.h"

Barrier::Barrier()
{
	vec2 hullvrts[] = { { 0,0 },{ 0,50 } };

	collider = Collider(hullvrts, 2);

	transform.m_scale = vec2{ 10,10 };
	rigidbody.drag = 0.0f;
	rigidbody.angularDrag = 0.0f;
	rigidbody.mass = 10;
}

void Barrier::update(float deltaTime, Gamestate & gs)
{
	rigidbody.integrate(transform, deltaTime);
}

void Barrier::draw(const mat3 & camera)
{
	collider.DebugDraw(camera, transform);
}
