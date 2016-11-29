#include "Platform.h"

Platform::Platform()
{
	vec2 hullvrts[] = { { 0,0 },{ 50,0 }, {50,-10}, {0,-10} };

	collider = Collider(hullvrts, 4);

	transform.m_scale = vec2{ 10,10 };
	rigidbody.drag = 0.0f;
	rigidbody.angularDrag = 0.0f;
	rigidbody.mass = 10;
}

void Platform::update(float deltaTime, Gamestate & gs)
{
	rigidbody.integrate(transform, deltaTime);
}

void Platform::draw(const mat3 & camera)
{
	collider.DebugDraw(camera, transform);
}
